#include "philo.h"

void    await(unsigned long milies_time)
{
    struct timeval current_time;
    struct timeval end_time;
    
    gettimeofday(&current_time, NULL);
    end_time.tv_sec =  current_time.tv_sec + (milies_time / 1000);
    end_time.tv_usec = current_time.tv_usec + ((milies_time % 1000) * 1000);

    while ((current_time.tv_sec < end_time.tv_sec) 
        || ((current_time.tv_sec == end_time.tv_sec) && (current_time.tv_usec <= end_time.tv_usec)))
        {
            gettimeofday(&current_time, NULL);
        }
}