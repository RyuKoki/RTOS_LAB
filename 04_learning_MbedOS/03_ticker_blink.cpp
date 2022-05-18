#include "mbed.h"
using namespace mbed;
using namespace rtos;
using namespace std;

DigitalOut  led1(p5), led2(p9);
Ticker      ticker1, ticker2;

void blink_led1() { led1 = !led1; }
void blink_led2() { led2 = !led2; }

int main() {
  printf("Mbed Ticker Demo...\n");
  ticker1.attach( callback(blink_led1), 1.0f );
  ticker2.attach( callback(blink_led2), 0.5f );
  while(1) {
    ThisThread::sleep_for( 1000ms );
  }
}
