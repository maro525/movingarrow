#include <Arduino.h>
#include <pt.h>

#define CONTROL_INTERVAL 80 // 一回水滴を出すとき、開く→閉じるをする間のインターバル
#define ARRAY_INTERVAL 80 // 列ごとのインターバル
#define SENTENCE_INTERVAL 3000 // 言葉ごとのインターバル
#define BREATH_LENGTH 3000 // 息をすう長さ
#define ARROW "~"

const bool bCloseEveryPin = false; // すべてのピンを閉じるか閉じないかのフラグ

// スレッドを使うためのdefine
#define PT_WAIT(pt, timestamp, usec) PT_WAIT_UNTIL(pt, millis() - *timestamp > usec);*timestamp = millis();

static struct pt pt1, pt2;


const int pin_num = 8;
const int pins[8] = {2, 3, 4, 5, 6, 7, 8, 9};
const int breath_pin = 10;
const char *myString[7] = {"HAPPY", "NEW", "YEAR", ARROW, "GOOD", "MORNING", "2019"};
// const char *myString[7] = {ARROW,ARROW, "A", "ABC", "123", "123", ARROW};

bool bGo = true; // ループをまわしてよいかどうかのフラッグ。Serialがくると、falseになってループを抜け出す

////////////////
// thread1; control pin

const int data_len = pin_num*2;
bool array_data[data_len];

void open_all_pin(){
    for(int i=0; i<pin_num; i++){
        digitalWrite(pins[i], LOW);
    }
}

void open_pin(int pin){
    digitalWrite(pin, HIGH);
}

void close_pin(int pin){
    digitalWrite(pin, LOW);
}

int pin_index;
void write_array()
{
    // open pin
    for(int i = pin_num-1; i >= 0; i--)
    {
        if(array_data[i*2]) {
            open_pin(pins[i]);
            Serial.print('1');
        } else {
            Serial.print('0');
        }
        pin_index += 1;
    }

    delay(CONTROL_INTERVAL);

    // close pin
    for(int j = pin_num-1; j >= 0; j--)
    {
        // Serial.print("*");
        // Serial.print(j*2+1);
        // Serial.print("=");
        if(bCloseEveryPin){
            close_pin(pins[j]);
        }
        else{
            if(array_data[j*2+1]) close_pin(pins[j]);
        }
        pin_index += 1;
    }

    Serial.println();
}

// array_dataにデータをいれる.ながさ16
// 開ける開けない, 閉める閉めない、×8 = 要素数16の配列
void write_char(char c)
{
    updateArray(c);
    for(int ai=0; ai<pin_num; ai++){
        for(int i=0; i<data_len; i++){
            if (i%2==0) {
                array_data[i] = a[i/2][ai];
            } else {
                if(pin_index == pin_num-1){ array_data[i] = 1; } // 最後のピンは必ず閉める
                else{ array_data[i] = a[(i-1)/2][ai+1]; }
                pin_index +=1;
            }
            if(!bGo) { break; }
        }
        write_array();
        delay(ARRAY_INTERVAL);
    }
}

void write_sentence(const char *txt)
{
    for(int i=0; txt[i] != '\0'; i++){
        write_char(txt[i]);
        if(!bGo){ break; }
    }
}

void write_my_strings(){
    if (!bGo) { return; }

    for(int i=0; i < 7; i++) {
        write_sentence(myString[i]);
        delay(SENTENCE_INTERVAL);
        // breath();
        if(!bGo){ return; }
    }
}

// 11111111と00000000の連続
void pomp_check(){
    // 1を書く
    for(int i=0; i<pin_num*2; i++){
        if(i%2==0) array_data[i] = 1; // 開けるか開けないかの情報
        else array_data[i] = 1; // 閉めるか閉めないかの情報
    }
    write_array();
    delay(ARRAY_INTERVAL);
    // 0を書く
    for(int i=0; i<pin_num*2; i++){
        if(i%2==0) array_data[i] = 0; // 開けるか開けないかの情報
        else array_data[i] = 1;  // 閉めるか閉めないかの情報」
    }
    write_array();
}


void breath()
{
    Serial.println("breah start");
    digitalWrite(breath_pin, HIGH);
    delay(BREATH_LENGTH);
    digitalWrite(breath_pin, LOW);
    Serial.println("breath end");
}

////////////////
// thread2; read serial
void read_serial()
{
    while(Serial.available()){
        byte inChar = char(Serial.read());
        Serial.print("***");
        Serial.print(inChar);
        if (inChar == 1){
            Serial.println("go!");
            bGo = true;
        }else{
            Serial.println("stop!");
            bGo = false;
        }
    }
}


////////////
//////////

static int thread1(struct pt *pt) {
    static unsigned long timestamp = 0;
    PT_BEGIN(pt);

    while(true) {
        PT_WAIT(pt, &timestamp, 10);
        write_my_strings();
        // pomp_check();
    }

    PT_END(pt);
}

static int thread2(struct pt *pt) {
    static unsigned long timestamp = 0;
    PT_BEGIN(pt);

    while(true) {
        PT_WAIT(pt,&timestamp, 10);
        // read_serial();
    }
    PT_END(pt);
}

//////////
//////////

void setup() {

    for(int i = 0; i < 8; i++)
    {
        pinMode(pins[i], OUTPUT);
    }
    pinMode(breath_pin, OUTPUT);
    Serial.begin(115200);
    Serial.println("Start reading...");

    PT_INIT(&pt1);
    PT_INIT(&pt2);

    // breath();

    open_all_pin(); // すべてのピンを占める
}

void loop() {
    thread1(&pt1);
    thread2(&pt2);
}
