/**
 * This example turns the ESP32 into a Bluetooth LE keyboard that writes the words, presses Enter, presses a media key and then Ctrl+Alt+Delete
 */
#include <BleKeyboard.h>

BleKeyboard bleKeyboard;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE");
  bleKeyboard.begin();
}

void loop() {
  if(bleKeyboard.isConnected()) {
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
  }else
  {
    Serial.println("Disconnected");
  }

  Serial.println("Waiting 5 seconds...");
  delay(5000);
}
