#include "philo.h"

void    await(unsigned long ms, t_pinfo *pinfo)
{
    unsigned long start_time;
    
    start_time = timestamp();
    while (timestamp() - start_time < ms && !get_died(pinfo))
        usleep(100);
}