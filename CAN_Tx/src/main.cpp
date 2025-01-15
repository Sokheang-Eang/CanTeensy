#include <Arduino.h>
// CAN Communication
#include <FlexCAN_T4.h>
// CAN1
FlexCAN_T4<CAN3, RX_SIZE_256, TX_SIZE_16> can3;
CAN_message_t can_tx;

// Define Variable

int can_id = 0x205;
int can_len = 8;

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
  can_tx.id = can_id;
  can_tx.len = can_len;

  // Acces Data to CAN Buffer

  int8_t _a = 0, _b = 0, _c = 0, _d = 0, _e = 0, _f = 0, _g = 0, _h = 0;
  unsigned long prev_cmd_time = 0;
  unsigned long now = millis();

  _a = random(-127, 127);
  _b = random(-127, 127);
  _c = random(-127, 127);
  _d = random(-127, 127);
  _e = random(-127, 127);
  _f = random(-127, 127);
  _g = random(-127, 127);
  _h = random(-127, 127);

  can_tx.buf[0] = _h;
  can_tx.buf[1] = _g;
  can_tx.buf[2] = _f;
  can_tx.buf[3] = _e;
  can_tx.buf[4] = _d;
  can_tx.buf[5] = _c;
  can_tx.buf[6] = _b;
  can_tx.buf[7] = _a;
  if (millis() - prev_cmd_time >= 10)
  {
    can3.write(can_tx);
  }
  prev_cmd_time = millis();
}
