#include <L298N.h> // Pastikan library L298N oleh Andrea Lombardo sudah terinstal

// Definisi pin untuk motor driver L298N
const int ENA = 5;  // Pin enable untuk motor A (kiri)
const int IN1 = 6;  // Pin IN1 untuk motor A
const int IN2 = 7;  // Pin  IN2 untuk motor A
const int ENB = 8;  // Pin enable untuk motor B (kanan)
const int IN3 = 9;  // Pin IN3 untuk motor B
const int IN4 = 10;  // Pin IN4 untuk motor B

// Inisialisasi objek L298N untuk masing-masing motor
L298N motorA(ENA, IN1, IN2); // Inisialisasi motor A
L298N motorB(ENB, IN3, IN4); // Inisialisasi motor B

int speed = 225;       // Kecepatan motor (0-255)
int time_delay = 2000; // Waktu delay dalam milidetik

void setup() {
  Serial.begin(9600); // Memulai komunikasi serial dengan baud rate 9600
  Serial.println("Mulai program kontrol motor L298N");
}

void loop() {
  // Motor maju (motor A dan motor B maju)
  Serial.println("Motor maju");
  motorA.setSpeed(speed);  // Atur kecepatan motor A
  motorB.setSpeed(speed);  // Atur kecepatan motor B
  motorA.forward();        // Motor A maju
  motorB.forward();        // Motor B maju
  delay(time_delay);       // Tunggu selama time_delay
  
  // Motor mundur (motor A dan motor B mundur)
  Serial.println("Motor mundur");
  motorA.setSpeed(speed);  // Atur kecepatan motor A
  motorB.setSpeed(speed);  // Atur kecepatan motor B
  motorA.backward();       // Motor A mundur
  motorB.backward();       // Motor B mundur
  delay(time_delay);       // Tunggu selama time_delay
}
