#include "philo.h"

void    await(unsigned long ms)
{
    unsigned long start_time;
    
    start_time = timestamp();
    while (timestamp() - start_time < ms)
        usleep(50);
}