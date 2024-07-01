
#include "philo.h"

void    safe_print(t_philo *philo, t_status status)
{
    t_pinfo pinfo;

    pinfo = philo->pinfo;
    pthread_mutex_lock(&philo->sd.print_mutex);
    if (status == FORK_TAKEN)
        printf("%ld %i has taken a fork\n", program_time(pinfo.start_time), philo->id);
    else if (status == EAT)
        printf("%ld %i is eating\n", program_time(pinfo.start_time), philo->id);
    else if (status == SLEEP)
        printf("%ld %i is sleeping\n", program_time(pinfo.start_time), philo->id);
    else if (status == THINK)
        printf("%ld %i is thinking\n", program_time(pinfo.start_time), philo->id);
    else if (status == DIED)
        printf("%ld %i died\n", program_time(pinfo.start_time), philo->id);
    pthread_mutex_unlock(&philo->sd.print_mutex);
}
