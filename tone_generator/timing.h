//Defined here is how much time in microseconds for one cycle for each pitch.
//This is calculated by dividing 1 by the hertz of each note.
#define C4 3822
#define D4 3608
#define E4 3034
#define F4 2863
#define G4 2551
#define Af 2273
#define B4 2025

void binary_pins(int amplitude) {
  if (amplitude > 255) {
    digitalWrite(0, HIGH);
    digitalWrite(1, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    return;

  } else if (amplitude < 0) {
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    return;
  }

  for (int pin = 0, amp = amplitude; pin <= 7; pin++) {
    digitalWrite(pin, amp % 2);
    amp /= 2;
  }

  return;
}

void square_wave(int note) {
  unsigned long time = micros();
  while (micros() - time < note) {
    binary_pins(255);
  }

  time = micros();
  while (micros() - time < note) {
    binary_pins(0);
  }

  return;
}


void sawtooth_wave(int note) {
  unsigned long time;
  for (int amp = 255; amp >= 0; amp--) {
    time = micros();

    while (micros() - time < note/256) {
      binary_pins(amp);
    }
  }

  return;
}

void triangle_wave(int note) {
  unsigned long time;
  for (int amp = 255; amp >= 0; amp--) {
    time = micros();

    while (micros() - time < note/512) {
      binary_pins(amp);
    }
  }

  for (int amp = 0; amp <= 255; amp++) {
    time = micros();

    while (micros() - time < note/512) {
      binary_pins(amp);
    }
  }


  return;
}

void sine_wave() {
  

}

void add_waves() {

}
