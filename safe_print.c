
#include "philo.h"

void    safe_print(t_philo *philo, t_status status)
{
    t_pinfo *pinfo;

    pinfo = philo->pinfo;
    pthread_mutex_lock(pinfo->print_mutex);
    
    if (status == FORK_TAKEN && !get_died(pinfo))
        printf("%ld %i has taken a fork\n", program_time(pinfo->start_time), philo->id);
    else if (status == EAT && !get_died(pinfo))
        printf("%ld %i is eating\n", program_time(pinfo->start_time), philo->id);
    else if (status == SLEEP && !get_died(pinfo))
        printf("%ld %i is sleeping\n", program_time(pinfo->start_time), philo->id);
    else if (status == THINK && !get_died(pinfo))
        printf("%ld %i is thinking\n", program_time(pinfo->start_time), philo->id);
    else if (status == DIED)
    {
        printf("%ld %i died\n", program_time(pinfo->start_time), philo->id);
    }
    pthread_mutex_unlock(pinfo->print_mutex);
}
