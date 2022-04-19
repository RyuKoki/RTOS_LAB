#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <rtthread.h>

/* Timer Control Block */
static rt_timer_t timer1;
static rt_timer_t timer2;

static void timeout1( void *parameter ) {
    static int cnt = 0;
    rt_kprintf("Periodic timer is timeout %d\n", cnt);
    /* On the 10th time, stops periodic timer */
    if (cnt++ >= 9) {
        rt_timer_stop(timer1);
        rt_kprintf("Periodic timer was stopped! \n");
    }
}

static void timeout2(void *parameter) {
    rt_kprintf("One shot timer is timeout\n");
}

int main(void)
{
    // create timer 1 periodic timer
    timer1 = rt_timer_create(   "timer1",   // timer name
                                timeout1,   // timeout function
                                RT_NULL,    // parameter
                                10,         // tick of timer
                                RT_TIMER_FLAG_PERIODIC  );  // flag of timer
    // start timer 1
    if (timer1 != RT_NULL) rt_timer_start(timer1);
    // create timer 2 one shot timer
    timer2 = rt_timer_create(   "timer2",   // timer name
                                timeout2,   // timeout function
                                RT_NULL,    // parameter
                                30,         // tick of timer
                                RT_TIMER_FLAG_ONE_SHOT  );  // flag of timer
    // start timer 2
    if (timer2 != RT_NULL) rt_timer_start(timer2);
    return 0;
}

