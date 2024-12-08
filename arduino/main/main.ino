// const int bp2 = 2;
// const int bp3 = 3;
// const int bp4 = 4;
// const int bp5 = 5;

// unsigned long lastPressTime2 = 0;
// unsigned long lastPressTime3 = 0;
// unsigned long lastPressTime4 = 0;
// unsigned long lastPressTime5 = 0;

// bool pressBp2 = false;
// bool pressBp3 = false;
// bool pressBp4 = false;
// bool pressBp5 = false;

// const unsigned long debounceDelay = 200;  // Throttling 간격 (200ms)

// void setup() {
//   Serial.begin(9600);

//   pinMode(bp2, INPUT_PULLUP);
//   pinMode(bp3, INPUT_PULLUP);
//   pinMode(bp4, INPUT_PULLUP);
//   pinMode(bp5, INPUT_PULLUP);
// }

// void loop() {
//   int x = analogRead(0);
//   int y = analogRead(1);

//   int bv2 = digitalRead(bp2);
//   int bv3 = digitalRead(bp3);
//   int bv4 = digitalRead(bp4);
//   int bv5 = digitalRead(bp5);

//   printJoystickValue(x, y);
//   Serial.println();

//   unsigned long currentMillis = millis();

//   // 버튼 2 처리
//   if (bv2 == LOW && (currentMillis - lastPressTime2 > debounceDelay) && !pressBp2) {
//     pressBp2 = true;
//     lastPressTime2 = currentMillis;
//     printJoystickValue(x, y);
//     Serial.print("   |");
//     Serial.println("A: O   B: X   C: X   D: X");
//   } else {
//     pressBp2 = false;
//   }

//   // 버튼 3 처리
//   if (bv3 == LOW && (currentMillis - lastPressTime3 > debounceDelay) && !pressBp3) {
//     pressBp3 = true;
//     lastPressTime3 = currentMillis;
//     printJoystickValue(x, y);
//     Serial.print("   |");
//     Serial.println("A: X   B: O   C: X   D: X");
//   } else {
//     pressBp3 = false;
//   }

//   // 버튼 4 처리
//   if (bv4 == LOW && (currentMillis - lastPressTime4 > debounceDelay) && !pressBp4) {
//     pressBp4 = true;
//     lastPressTime4 = currentMillis;
//     printJoystickValue(x, y);
//     Serial.print("   |");
//     Serial.println("A: X   B: X   C: O   D: X");
//   } else {
//     pressBp4 = false;
//   }

//   // 버튼 5 처리
//   if (bv5 == LOW && (currentMillis - lastPressTime5 > debounceDelay) && !pressBp5) {
//     pressBp5 = true;
//     lastPressTime5 = currentMillis;
//     printJoystickValue(x, y);
//     Serial.print("   |");
//     Serial.println("A: X   B: X   C: X   D: O");
//   } else {
//     pressBp5 = false;
//   }

//   delay(50);
// }

// void printJoystickValue(int x, int y) {
//   Serial.print("Joystick ");
//   Serial.print("X : ");
//   Serial.print(x);
//   Serial.print("    ");
//   Serial.print("Y : ");
//   Serial.print(y);
// }