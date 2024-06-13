#ifndef PHILO_H
# define PHILO_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_pinfo {
    int pnumber;
    int tdie;
    int teat;
    int tsleep;
    int num_eats;
} t_pinfo;

typedef struct s_philo {
    int             id;
    pthread_t       thread;
    pthread_mutex_t *l_fork;
    pthread_mutex_t *r_fork;
} t_philo;


int	ft_atoi(const char *str);
int philo_init(t_pinfo *pinfo, int count, char **data);

#endif 