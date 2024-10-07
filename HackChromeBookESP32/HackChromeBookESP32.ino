/**
 * This example turns the ESP32 into a Bluetooth LE keyboard that writes the words, presses Enter, presses a media key and then Ctrl+Alt+Delete
 */
#include <BleKeyboard.h>

BleKeyboard bleKeyboard;
unsigned long previousMillis = 0;
unsigned long currentMillis = 0;

bool lastDelayDone = false;
bool canHack = false;
bool delayDone[7] = {false,false,false,false,false,false,false};
int delayItteration = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE");
  bleKeyboard.begin();
  pinMode(2, OUTPUT);
}

void loop() {
  currentMillis = millis();

  if(bleKeyboard.isConnected()) {
    //if(canHack == true)
    //{
      HackTheChromeBookV2();
    //}
    digitalWrite(2, HIGH);
  }else
  {
    digitalWrite(2, LOW);
    //Serial.println("Disconnected");
  }

 // Serial.println("Waiting 5 seconds...");
 // delay(5000);
}
void AsyncDelay(float delayAmount){

  if(currentMillis - previousMillis >= delayAmount){

    lastDelayDone = true;
    previousMillis = currentMillis;
    if(delayItteration == 6){

      for (bool& i : delayDone) {
        i = false;
      }

      delayItteration = 0;
    }
    delayItteration += 1;
    delayDone[delayItteration-1] = true;
    Serial.println(delayItteration + ": Delay Itteration");
  }else{

    lastDelayDone = false;
  }
}

void HackDelay(){

  AsyncDelay(6000);
  canHack = true;
}
void HackTheChromeBookV1(){

  Serial.println("New Window");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.print("n");
    delay(400);
    bleKeyboard.print("t");
    bleKeyboard.release(KEY_LEFT_CTRL);

    delay(1500);

    //bleKeyboard.press(KEY_VOLUME_UP);

    Serial.println("Sending hacked message");
    bleKeyboard.print("Your Being Hacked!");

    delay(2000);

    Serial.println("Sending Rick");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.print("t");
    bleKeyboard.release(KEY_LEFT_CTRL);
    delay(500);
    bleKeyboard.print("https://www.youtube.com/watch?v=oPLObjVAvIU");
    delay(500);
    Serial.println("Sending Enter key...");
    bleKeyboard.write(KEY_RETURN);

    delay(6500);

    Serial.println("Sending Shut Off");
    bleKeyboard.press(KEY_LEFT_CTRL);

    bleKeyboard.press(KEY_LEFT_SHIFT);
    bleKeyboard.print("q");
    delay(100);
    bleKeyboard.print("q");
    delay(500);
    bleKeyboard.releaseAll();
}

void HackTheChromeBookV2(){
    canHack = false;
    Serial.println("New Window");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.print("n");
    AsyncDelay(400);
    if(delayDone[delayItteration-1] == true)
    {bleKeyboard.print("t");
    bleKeyboard.release(KEY_LEFT_CTRL);

    AsyncDelay(1500);
    if(delayDone[delayItteration-1] == true)
    //bleKeyboard.press(KEY_VOLUME_UP);

    {Serial.println("Sending hacked message");
    bleKeyboard.print("Your Being Hacked!");

    AsyncDelay(2000);
    if(delayDone[delayItteration-1] == true)
    {Serial.println("Sending Rick");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.print("t");
    bleKeyboard.release(KEY_LEFT_CTRL);
    AsyncDelay(500);
    if(delayDone[delayItteration-1] == true)
    {bleKeyboard.print("https://www.youtube.com/watch?v=oPLObjVAvIU");
    AsyncDelay(500);
    if(delayDone[delayItteration-1] == true)
    {Serial.println("Sending Enter key...");
    bleKeyboard.write(KEY_RETURN);

    AsyncDelay(7000);
    if(delayDone[delayItteration-1] == true)
    {Serial.println("Sending Shut Off");
    bleKeyboard.press(KEY_LEFT_CTRL);

    bleKeyboard.press(KEY_LEFT_SHIFT);
    bleKeyboard.print("q");
    AsyncDelay(100);
    if(delayDone[delayItteration-1] == true)
    {bleKeyboard.print("q");
    AsyncDelay(500);
    if(delayDone[delayItteration-1] == true)
    {bleKeyboard.releaseAll();

    HackDelay();
    }}}}}}}}
}

