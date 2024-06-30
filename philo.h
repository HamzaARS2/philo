#ifndef PHILO_H
# define PHILO_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_pinfo {
    struct timeval start_time;
    int pnumber;
    int die_time;
    int eat_time;
    int sleep_time;
    int num_eats;
} t_pinfo;

typedef struct s_shared_data {
    int last_meal;
    pthread_mutex_t last_meal_mutex;
} t_shared_data;

typedef struct s_philo {
    int             id;
    pthread_t       thread;
    pthread_mutex_t *l_fork;
    pthread_mutex_t *r_fork;
    t_shared_data sd;
    int last_meal;
    t_pinfo pinfo;
} t_philo;


// setters
void    set_last_meal(t_shared_data *sd ,struct timeval start_time);
// getters
int get_last_meal(t_shared_data *sd);

void    *monitor(void *param);
unsigned long   timestamp(struct timeval start_time);
void    await(unsigned long milies_time);
int	    ft_atoi(const char *str);
int     philo_init(t_pinfo *pinfo, int count, char **data);

void    join_threads(t_philo **philos, t_pinfo pinfo);

t_philo **create_philos(t_pinfo pinfo);
void    assign_forks(t_philo **philos, t_pinfo pinfo);
void    start_lunch(t_philo **philos, t_pinfo pinfo);

void    *routine(void *param);
#endif 