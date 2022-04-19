#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <rtthread.h>

#define THREAD_STACK_SIZE   (1024)
#define THREAD_PRIORITY     (20)
#define THREAD_TIMESLICE    (10)

static void thread_entry(void* parameter) {
    rt_uint32_t value;
    rt_uint32_t count = 0;

    value = (rt_uint32_t)parameter;
    while (1) {
        if ( 0 == (count % 5) ) {
            printf("Thread %d is running, thread %d count = %d\n", value, value, count);
            if ( count > 200 ) return;
        }
        count++;
    }
}

int main(void) {
    rt_thread_t tid1 = RT_NULL;
    rt_thread_t tid2 = RT_NULL;
    // Create Thread 1
    tid1 = rt_thread_create(    "thread1",              // thread name
                                thread_entry,           // thread function
                                (void*)1,               // parameter
                                THREAD_STACK_SIZE,      // stack size
                                THREAD_PRIORITY,        // thread priority
                                THREAD_TIMESLICE    );  // thread time slice
    // start thread 1
    if ( tid1 != RT_NULL ) rt_thread_startup( tid1 );
    // Create Thread 2
    tid2 = rt_thread_create(    "thread2",              // thread name
                                thread_entry,           // thread function
                                (void*)2,               // parameter
                                THREAD_STACK_SIZE,      // stack size
                                THREAD_PRIORITY,        // thread priority
                                THREAD_TIMESLICE-5  );  // thread time slice
    // start thread 2
    if ( tid2 != RT_NULL ) rt_thread_startup( tid2 );
    return 0;
}

