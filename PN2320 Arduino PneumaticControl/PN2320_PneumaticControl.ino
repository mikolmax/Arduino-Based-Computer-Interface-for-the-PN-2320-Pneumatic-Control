int valve1 = 8;
int valve2 = 9;
int valve3Pos = 10;
int valve3Neg = 11;

char val_byte = 0;
String val_str = "";
int val_num = 0;

volatile unsigned long time1;
volatile unsigned long time2;

volatile boolean valid1 = false;
volatile boolean valid2 = false;

void setup() {
  // put your setup code here, to run once:
  pinMode (valve1, OUTPUT);
  pinMode (valve2, OUTPUT);
  pinMode (valve3Pos, OUTPUT);
  pinMode (valve3Neg, OUTPUT);

  attachInterrupt(0,interrupt1,CHANGE);
  attachInterrupt(1,interrupt2,CHANGE);
  
  Serial.begin (115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (valid1 && valid2) {
      Serial.println(time2 - time1);
      noInterrupts();
      valid1 = valid2 = false;
      interrupts();
  }
  
  if (Serial.available() > 0) {
    val_byte = Serial.read();
    //val_num = Serial.parseInt();

    if (val_byte != ',') {
      val_str += val_byte;
    } else {
      if(val_str != "stopAll")
        val_num = Serial.parseInt();

      if (val_str == "delay") {
        delayTime(val_num);
      } else if (val_str == "stopAll") {
        emergencyStop();
      } else {
        switching(val_str, val_num);
      }

      val_str = "";
      val_num = 0;
    }
  }
}

void interrupt1() {
  if (!valid1) {
    time1 = millis();
    valid1 = true;
  }
}

void interrupt2() {
  if (!valid2 && valid1) {
    time2 = millis();
    valid2 = true;
  }
}

void switching(String str, int num) {
  if (num == 1) {
    switchOn(str);
  } else if (num == 0) {
    switchOff(str);
  } else {
    //Serial.print("Invalid Input");
  }
}

void switchOn(String str) {
  if (str == "valve1") {
    digitalWrite(valve1, HIGH);
  } else if (str == "valve2") {
    digitalWrite(valve2, HIGH);
  } else if (str == "valve3Pos") {
    digitalWrite(valve3Pos, HIGH);
  } else if (str == "valve3Neg") {
    digitalWrite(valve3Neg, HIGH);
  } else {
    //do nothing
  }
}

void switchOff(String str) {
  if (str == "valve1") {
    digitalWrite(valve1, LOW);
  } else if (str == "valve2") {
    digitalWrite(valve2, LOW);
  } else if (str == "valve3Pos") {
    digitalWrite(valve3Pos, LOW);
  } else if (str == "valve3Neg") {
    digitalWrite(valve3Neg, LOW);
  } else {
    //do nothing
  }
}

void delayTime(int num) {
  delay(num);
}

void emergencyStop() {
  digitalWrite(valve1, LOW);
  digitalWrite(valve2, LOW);
  digitalWrite(valve3Pos, LOW);
  digitalWrite(valve3Neg, LOW);
}

