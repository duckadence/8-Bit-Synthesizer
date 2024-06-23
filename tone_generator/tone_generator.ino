#include "timing.h"

void setup() {
  // put your setup code here, to run once:
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (digitalRead(A0)) {
    square_wave(C4);
  }

  while (digitalRead(A1)) {
    square_wave(D4);
  }

  while (digitalRead(A2)) {
    square_wave(E4);
  }

  while (digitalRead(A3)) {
    square_wave(F4);
  }

  while (digitalRead(A4)) {
    square_wave(G4);
  }

}