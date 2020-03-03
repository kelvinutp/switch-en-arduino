#include <IRremote.h>
String a;
int c;
IRrecv remote(43);
decode_results results;
void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  remote.enableIRIn();
  c = 0;
}

void loop() {
  if (remote.decode(&results))
  {
    a = String(results.value, HEX); //Convierte el valor de la variable a un valor hexadecimal
    Serial.println(a);
    switch (results.value) {
      case 0xFFA25D://para encender o apagar los puente H
        if (c == 0) {
          c = 1;
          digitalWrite(4, HIGH);
          Serial.println("enciende");
        }
        else
        {
          c = 0;
          digitalWrite(4, LOW);
          Serial.println("apaga");
        }
        break;
      case 0xFF906F:
        if (c == 1) {
          if (d < 250)
          {
            d = d + 10;
          }
        }
        break;
      case 0xFFE01F:
        if (c == 1)
        {
          if (d > 0)
          {
            d = d - 10;
          }
        }
        break;
    }
    delay(100);
    remote.resume();
  }
}
