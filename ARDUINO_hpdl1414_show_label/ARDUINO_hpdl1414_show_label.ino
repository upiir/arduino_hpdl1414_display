// HPDL-1414 "Bubble Displays" with Arduino UNO

// created by upir, 2024
// youtube channel: https://www.youtube.com/upir_upir

// YouTube video: https://youtu.be/qZ0up4YSiyE
// Source files: https://github.com/upiir/arduino_hpdl1414_display

// Links from the video:
// Do you like this video? You can buy me a coffee ☕: https://www.buymeacoffee.com/upir
// HPDL-1414 two display module: https://s.click.aliexpress.com/e/_DdQCW4Z
// Arduino UNO: https://s.click.aliexpress.com/e/_AXDw1h
// Arduino breadboard prototyping shield: https://s.click.aliexpress.com/e/_ApbCwx
// Arduino HPDL-1414 library: https://github.com/marecl/HPDL1414
// USB to UART (cheap): https://s.click.aliexpress.com/e/_DdcIwx7
// USB to UART (better): https://s.click.aliexpress.com/e/_DD9nZ8D
// USB to UART (best): https://s.click.aliexpress.com/e/_DmOMFEH

// Related videos:
// VFD displays: https://youtu.be/g7SOxzKatCc
// 5x7 dot displays: https://youtu.be/PBaL9w5w-2c
// Unusual Displays: https://www.youtube.com/playlist?list=PLjQRaMdk7pBYsoLl49ZYPokrjdp34qP_k



void setup() {
  
  Serial.begin(9600, SERIAL_8E1); // start serial communication, speed 9600 baud, 8 data bits, even parity check, 1 stop bits

}

char message[9] = "ARDUINO!";

void loop() {

  // send the message to the display
  strcpy(message, "Arduino*"); // set the string content

  for (int pos = 0; pos < 8; pos++) { // for each character

    Serial.write(0xFE); // send header
    Serial.write(0xFD); // send header
    Serial.write(pos); // character position 0-7 (8 characters)

    if ((message[pos] >= 97) && (message[pos] <= 122)) {
      // convert the lowercase to uppercase
      Serial.write(message[pos] - 32); // send character from the message
    } else {
      // no need to convert
      Serial.write(message[pos]); // send character from the message
    }
    delay(10); // wait in between sending characters

  }

  delay(1000); // wait 1 second, this makes no difference as we only update the display once
}
