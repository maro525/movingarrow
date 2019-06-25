#include <Arduino.h>

#define INTERVAL 100
#define SENTENCE_INTERVAL 3000
#define ARROW "~"

const int pins[8] = {2, 3, 4, 5, 6, 7, 8, 9};
const char *myString[7] = {"HAPPY", "NEW", "YEAR", ARROW, "GOOD", "MORNING", "2019"};

void control_pin(int pin, bool bOpen, bool bClose)
{
    // if(bOpen){
    //     digitalWrite(pin, HIGH);
    //     delay(10);
    //     digitalWrite(pin, LOW);
    // }

    if(bOpen)
    {
        digitalWrite(pin, HIGH);
    }

    delay(10);

    if(bOpen && bClose){
        digitalWrite(pin, LOW);
    }

    Serial.print(bOpen);
}

void write_array(bool data[])
{
    for(int i = 8; i >= 0; i--)
    {
        control_pin(pins[i], data[(i-1)*2], data[i*2-1]);
    }
    Serial.println();
}

void write_char(char c)
{
    updateArray(c);
    for(int i = 0; i < 8; i++)
    {
        bool array_data[16];
        for(int j=0; j < 16; j++){
            if(j%2 == 0){
                array_data[j] = a[j/2][i];
            } else {
                if(i == 7) { array_data[j] = 0; }
                else { array_data[j] = a[(j-1)/2][i+1]; }
            }
        }
        write_array(array_data);
        delay(30);
    }
}

void write_sentence(const char *txt)
{
    for(int i=0; txt[i] != '\0'; i++){
        write_char(txt[i]);
    }
}


void setup() {

    for(int i = 0; i < 8; i++)
    {
        pinMode(pins[i], OUTPUT);
    }
    Serial.begin(38400);
}

void loop() {
    for(int i=0; i<100; i++){
        write_my_strings();
    }
}

void write_my_strings(){
    for(int i=0; i < 7; i++) {
        write_sentence(myString[i]);
        delay(SENTENCE_INTERVAL);
    }
}
