#ifndef PHILO_H
# define PHILO_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

typedef enum e_status {
    FORK_TAKEN,
    EAT,
    SLEEP,
    THINK,
    DIED
} t_status;

typedef struct s_pinfo {
    long start_time;
    int pnumber;
    int die_time;
    int eat_time;
    int sleep_time;
    int num_eats;
} t_pinfo;

typedef struct s_shared_data {
    unsigned long last_meal;
    pthread_mutex_t last_meal_mutex;
    pthread_mutex_t print_mutex;
} t_shared_data;

typedef struct s_philo {
    int             id;
    pthread_t       thread;
    pthread_mutex_t *l_fork;
    pthread_mutex_t *r_fork;
    t_shared_data sd;
    t_pinfo pinfo;
} t_philo;


// setters
void    set_last_meal(t_shared_data *sd);
// getters
unsigned long get_last_meal(t_shared_data *sd);

void    safe_print(t_philo *philo, t_status status);

void    *monitor(void *param);
unsigned long   timestamp();
unsigned long program_time(long start_time);
void    await(unsigned long milies_time);
int	    ft_atoi(const char *str);
int     philo_init(t_pinfo *pinfo, int count, char **data);

void    join_threads(t_philo **philos, t_pinfo pinfo);

t_philo **create_philos(t_pinfo pinfo);
void    assign_forks(t_philo **philos, t_pinfo pinfo);
void    start_lunch(t_philo **philos, t_pinfo pinfo);

void    *routine(void *param);
#endif 