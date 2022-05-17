#include "mbed.h"
using namespace mbed;
using namespace rtos;
using namespace std;

#define SLEEP_MS (500)

DigitalOut  led1( p5 );
Thread      thread1( osPriorityNormal );
Thread      thread2( osPriorityNormal );

typedef struct thread_args {
  uint32_t    id;
  DigitalOut *led;
} thread_args_t;

void led_update( thread_args_t *args ) {
  if ( args->id ) {
    ThisThread::sleep_for( SLEEP_MS/2 );
  } 
  while (1) {
    *(args->led) = args->id;
    Serial1.print("Thread ID : " + String(args->id));
    Serial1.println(" | Status LED : " + String(*(args->led)));
    ThisThread::sleep_for( SLEEP_MS );
  }
}

thread_args_t args1 = { 0, &led1 };
thread_args_t args2 = { 1, &led1 };

int main() {
  Serial1.begin( 115200 );
  thread1.start( callback(led_update, &args1) );
  thread2.start( callback(led_update, &args2) );
  while(1) { 
    osDelay( osWaitForever );
  }
}
