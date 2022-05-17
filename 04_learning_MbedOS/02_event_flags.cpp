#include "mbed.h"
using namespace mbed;
using namespace rtos;
using namespace std;

Thread     *threads[4];
EventFlags  evt_flags;

void thread_func( void *arg ) {
  uint32_t id = (uint32_t) arg;
  uint32_t flags;
  while (1) {
    // clear flag after reading
    flags = evt_flags.wait_any(
      (1<<id), osWaitForever, true );
    printf("Thread: %lu, flags: 0x%lx\n", id, flags);
  }
}

int main() {
  for (uint32_t i=0; i<4; i++) {
    threads[i] = new Thread(osPriorityNormal);
    threads[i]->start( callback(thread_func, (void*)i) );
  } 
  uint32_t id = 0;
  while (1) {
    ThisThread::sleep_for( chrono::milliseconds(1000) );
    evt_flags.set( 1<<id );
    id = (id+1) % 4;
  }
  return 0;
}
