int incomingByte = 0;  // 受信データ用

void setup() {
  Serial.begin(9600); // 9600bpsでシリアルポートを開く
}

void loop() {
  if (Serial.available() > 0) { // 受信したデータが存在する
    incomingByte = Serial.read(); // 受信データを読み込む

    Serial.print("I received: "); // 受信データを送りかえす
    Serial.println(incomingByte, DEC);
  }
}
