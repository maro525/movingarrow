#include <Arduino.h>

#define P0 2
#define P1 3
#define P2 4
#define P3 5
#define P4 6
#define P5 7
#define P6 8
#define P7 9

void write_array(bool data[])
{
    digitalWrite(P0, data[0]);
    digitalWrite(P1, data[1]);
    digitalWrite(P2, data[2]);
    digitalWrite(P3, data[3]);
    digitalWrite(P4, data[4]);
    digitalWrite(P5, data[5]);
    digitalWrite(P6, data[6]);
    digitalWrite(P7, data[7]);
}

void write_char(char c)
{
    updateArray(c);
    for(int i = 0; i < 8; i++)
    {
        write_array(a[i]);
    }
}

void write_sentence(String txt)
{
    unsigned int string_length = txt.length();
    char buf[string_length];
    txt.toCharArray(buf, string_length+1);
    for(int i=0; i<string_length; i++){
        write_char(buf[i]);
    }
}


void setup() {
    pinMode(P0, OUTPUT);
    pinMode(P1, OUTPUT);
    pinMode(P2, OUTPUT);
    pinMode(P3, OUTPUT);
    pinMode(P4, OUTPUT);
    pinMode(P5, OUTPUT);
    pinMode(P6, OUTPUT);
    pinMode(P7, OUTPUT);

    String text = "alpha";
    write_sentence(text);
}

void loop() {

}
