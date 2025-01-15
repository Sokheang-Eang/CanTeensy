#include <Arduino.h>
// CAN Communication
#include <FlexCAN_T4.h>
// CAN1
FlexCAN_T4<CAN3, RX_SIZE_256, TX_SIZE_16> can3;
CAN_message_t can_rx;

// Define Variable
int can_id = 0x205;
int can_len = 8;

// Acces Data to CAN Buffer
int8_t _a = 0, _b = 0, _c = 0, _d = 0, _e = 0, _f = 0, _g = 0, _h = 0;

void setup()
{
  // Serial
  Serial.begin(115200);
  // CAN Communication
  can3.begin();
  can3.setBaudRate(1e6);
}

void loop()
{
  // CAN Config
  can_rx.id = can_id;
  can_rx.len = can_len;
  can3.read(can_rx);

  _h = can_rx.buf[0];
  _g = can_rx.buf[1];
  _f = can_rx.buf[2];
  _e = can_rx.buf[3];

  _d = can_rx.buf[4];
  _c = can_rx.buf[5];
  _b = can_rx.buf[6];
  _a = can_rx.buf[7];

  Serial.print(_a);
  Serial.print("\t");
  Serial.print(_b);
  Serial.print("\t");
  Serial.print(_c);
  Serial.print("\t");
  Serial.print(_d);
  Serial.print("\t");
  Serial.print(_e);
  Serial.print("\t");
  Serial.print(_f);
  Serial.print("\t");
  Serial.print(_g);
  Serial.print("\t");
  Serial.print(_h);
  Serial.print("\n");
  delay(100);
}
