#include "mbed.h"
using namespace mbed;
using namespace rtos;
using namespace std;

#define INTERVAL_MS (500ms)
#define START_CNT   (10)

DigitalOut led1(p5);
Timeout    timeout;

void func_cb( void *arg ) {
  uint32_t x = (uint32_t) arg;
  if ( x > 0 ) {
    led1 = !led1;
    timeout.attach( callback(func_cb, (void*)(x-1)), INTERVAL_MS );
  }
}

int main() {
  timeout.attach( callback(func_cb, (void*)START_CNT), INTERVAL_MS );
  printf("Interval = %llu msec\r\n", (uint64_t)INTERVAL_MS.count());
  // printf( "Interval = %llu usec\r\n", (uint64_t)duration_cast<microseconds>(INTERVAL_MS).count() );
  while (1) {
    osDelay( osWaitForever );
  }
}
