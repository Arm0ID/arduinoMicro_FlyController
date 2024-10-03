#include <JoystickMHX.h>

// Создаем объект Joystick
Joystick_ joystick;

#define X_PIN A0 // Потенциометр для оси X
#define Y_PIN A1 // Потенциометр для оси Y
#define Z_PIN A2 // Потенциометр для оси Z
#define R_PIN A3 // Потенциометр для оси R

void setup() {
  // Инициализация джойстика
  joystick.begin();
}

void loop() {
  // Считываем значения с потенциометров
  int xValue = analogRead(X_PIN);
  int yValue = analogRead(Y_PIN);
  int zValue = analogRead(Z_PIN);
  int rValue = analogRead(R_PIN);

  // Масштабируем значения (от 0 до 1023 на 0 до 255 для джойстика)
  xValue = map(xValue, 0, 1023, 0, 255);
  yValue = map(yValue, 0, 1023, 0, 255);
  zValue = map(zValue, 0, 1023, 0, 255);
  rValue = map(rValue, 0, 1023, 0, 255);

  // Обновляем координаты джойстика
  joystick.setXAxis(xValue);
  joystick.setYAxis(yValue);
  joystick.setZAxis(zValue);  // Ось Z
  joystick.setRudder(rValue);  // Ось R

  // Небольшая задержка для обновления
  delay(50);
}
