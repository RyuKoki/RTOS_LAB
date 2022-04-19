#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <rtthread.h>

static rt_thread_t thread_1 = RT_NULL;

static void thread1_entry( void *parameter ) {
    int count = 0;
    // infinite loop
    while (1) {
        printf("Thread 1 count: %d\n", count++);
        rt_thread_mdelay( 500 );
    }
}

int main(void) {
   thread_1 = rt_thread_create("Thread1",       // thread name
                                thread1_entry,  // thread entry (function)
                                RT_NULL,        // parameter
                                1024,           // stack size
                                25,             // priority
                                5);             // time slice in tick
    rt_thread_startup(thread_1);
    return 0;
}

