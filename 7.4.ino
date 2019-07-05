#define DEBUG

class MorseBase {
  int _pin;
  const int a = 250;

public:
  MorseBase(int8_t pin) : _pin(pin) { pinMode(pin, OUTPUT); }
  inline void dit() {
    digitalWrite(_pin, HIGH);
    delay(a);
    digitalWrite(_pin, LOW);
    delay(a);
#ifdef DEBUG
    Serial.print('.');
#endif
  }
  inline void dah() {
    digitalWrite(_pin, HIGH);
    delay(a * 3);
    digitalWrite(_pin, LOW);
    delay(a);
#ifdef DEBUG
    Serial.print('-');
#endif
  }
  inline void eoc() {
    delay(a << 1);
#ifdef DEBUG
    Serial.print(' ');
#endif
  }
  inline void eow() {
    delay((a << 2) + (a << 1));
#ifdef DEBUG
    Serial.print("/");
#endif
  }
};

MorseBase x(13);

bool i = true;
char b = 0;

void setup() { Serial.begin(9600); }

void loop() {
  if (Serial.available() > 0) {
    b = Serial.read();
    if (isUpperCase(b))
      b |= 0x20u;
    if (i)
      i = false;
    else if (b != ' ')
      x.eoc();
    else {
      i = true;
      x.eow();
    }
    switch (b) {
      case 'a': x.dit(); x.dah(); break;
      case 'b': x.dah(); x.dit(); x.dit(); x.dit(); break;
      case 'c': x.dah(); x.dit(); x.dah(); x.dit(); break;
      case 'd': x.dah(); x.dit(); x.dit(); break;
      case 'e': x.dit(); break;
      case 'f': x.dit(); x.dit(); x.dah(); x.dit(); break;
      case 'g': x.dah(); x.dah(); x.dit(); break;
      case 'h': x.dit(); x.dit(); x.dit(); x.dit(); break;
      case 'i': x.dit(); x.dit(); break;
      case 'j': x.dit(); x.dah(); x.dah(); x.dah(); break;
      case 'k': x.dah(); x.dit(); x.dah(); break;
      case 'l': x.dit(); x.dah(); x.dit(); x.dit(); break;
      case 'm': x.dah(); x.dah(); break;
      case 'n': x.dah(); x.dit(); break;
      case 'o': x.dah(); x.dah(); x.dah(); break;
      case 'p': x.dit(); x.dah(); x.dah(); x.dit(); break;
      case 'q': x.dah(); x.dah(); x.dit(); x.dah(); break;
      case 'r': x.dit(); x.dah(); x.dit(); break;
      case 's': x.dit(); x.dit(); x.dit(); x.dit(); break;
      case 't': x.dah(); break;
      case 'u': x.dit(); x.dit(); x.dah(); break;
      case 'v': x.dit(); x.dit(); x.dit(); x.dah(); break;
      case 'w': x.dit(); x.dah(); x.dah(); break;
      case 'x': x.dah(); x.dit(); x.dit(); x.dah(); break;
      case 'y': x.dah(); x.dit(); x.dah(); x.dah(); break;
      case 'z': x.dah(); x.dah(); x.dit(); x.dit(); break;
      case '0': x.dah(); x.dah(); x.dah(); x.dah(); x.dah(); break;
      case '1': x.dit(); x.dah(); x.dah(); x.dah(); x.dah(); break;
      case '2': x.dit(); x.dit(); x.dah(); x.dah(); x.dah(); break;
      case '3': x.dit(); x.dit(); x.dit(); x.dah(); x.dah(); break;
      case '4': x.dit(); x.dit(); x.dit(); x.dit(); x.dah(); break;
      case '5': x.dit(); x.dit(); x.dit(); x.dit(); x.dit(); break;
      case '6': x.dah(); x.dit(); x.dit(); x.dit(); x.dit(); break;
      case '7': x.dah(); x.dah(); x.dit(); x.dit(); x.dit(); break;
      case '8': x.dah(); x.dah(); x.dah(); x.dit(); x.dit(); break;
      case '9': x.dah(); x.dah(); x.dah(); x.dah(); x.dit(); break;
      case ',': x.dah(); x.dah(); x.dit(); x.dit(); x.dah(); x.dah(); break;
      case '.': x.dit(); x.dah(); x.dit(); x.dah(); x.dit(); x.dah(); break;
      case '?': x.dit(); x.dit(); x.dah(); x.dah(); x.dit(); x.dit(); break;
      case '!': x.dit(); x.dit(); x.dah(); x.dah(); x.dit(); break;
      case '\"': x.dit(); x.dah(); x.dit(); x.dit(); x.dah(); x.dit(); break;
      case '\'': x.dit(); x.dah(); x.dah(); x.dah(); x.dah(); x.dit(); break;
      case '-': x.dah(); x.dit(); x.dit();x.dit(); x.dit(); x.dah(); break;
    }
  }
}
