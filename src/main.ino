#include <Arduino.h>
#include <pt.h>

#define CONTROL_INTERVAL 200 // 一回水滴を出すとき、開く→閉じるをする間のインターバル
#define ARRAY_INTERVAL 80 // 列ごとのインターバル
#define SENTENCE_INTERVAL 3000 // 言葉ごとのインターバル
#define BREATH_LENGTH 3000 // 息をすう長さ
#define ARROW "~"

// スレッドを使うためのdefine
#define PT_WAIT(pt, timestamp, usec) PT_WAIT_UNTIL(pt, millis() - *timestamp > usec);*timestamp = millis();

static struct pt pt1, pt2;

const int pin_num = 8;
const int pins[8] = {2, 3, 4, 5, 6, 7, 8, 9};
const int breath_pin = 10;
const char *myString[7] = {"HAPPY", "NEW", "YEAR", ARROW, "GOOD", "MORNING", "2019"};

bool bGo = true;

////////////////
// thread1; control pin

void open_pin(int pin){
    digitalWrite(pin, HIGH);
}

void close_pin(int pin){
    digitalWrite(pin, LOW);
}

void write_array(bool data[])
{
    // open pin
    int pin_index = 0;
    for(int i = pin_num; i >= 0; i--)
    {
        // control_pin(pins[pin_index], data[(i-1)*2], data[i*2-1]);
        if(data[(i-1)*2]) {
            open_pin(pins[pin_index]);
            Serial.print('1');
        } else {
            Serial.print('0');
        }
        pin_index += 1;
    }

    delay(CONTROL_INTERVAL);

    // close pin
    pin_index = 0;
    for(int j = pin_num; j >= 0; j--)
    {
        if(data[j*2-1]) close_pin(pins[pin_index]);
        pin_index += 1;
    }

    Serial.println();
}

void write_char(char c)
{
    updateArray(c);
    for(int i = 0; i < pin_num; i++)
    {
        const int data_len = pin_num*2;
        bool array_data[data_len];
        for(int j=0; j < data_len; j++){
            if(j%2 == 0){
                array_data[j] = a[j/2][i];
            } else {
                if(i == pin_num-1) { array_data[j] = 0; }
                else { array_data[j] = a[(j-1)/2][i+1]; }
            }
        }
        if(!bGo){ break; }

        write_array(array_data);
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

bool arr[8];
void write_my_strings(){
    if (!bGo) { return; }

    // for(int i=0; i < 7; i++) {
    //     write_sentence(myString[i]);
    //     delay(SENTENCE_INTERVAL);
    //     // breath();
    //     if(!bGo){ return; }
    // }

    for(int i=0; i<8; i++){
        arr[i] = 1;
    }
    write_array(arr);
    delay(ARRAY_INTERVAL);
    for(int i=0; i<8; i++){
        arr[i] = 0;
    }
    write_array(arr);
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
}

void loop() {
    thread1(&pt1);
    thread2(&pt2);
}
