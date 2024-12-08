void setup() {
    Serial.begin(9600); // 9600 baud rate로 시리얼 포트 초기화
}

void loop() {
    // PC에서 명령이 오면 읽기
    if (Serial.available() > 0) {
        String message = Serial.readStringUntil('\n'); // 개행 문자까지 읽기
        Serial.print("Received: ");
        Serial.println(message); // 받은 메시지를 다시 전송 (에코)
    }

    // 2초마다 자동 메시지 전송
    delay(2000);
    Serial.println("Hello from Arduino!"); // Arduino에서 PC로 전송
}