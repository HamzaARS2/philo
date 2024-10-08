/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:53:58 by helarras          #+#    #+#             */
/*   Updated: 2024/09/29 10:31:38 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef enum e_status
{
	FORK_TAKEN,
	EAT,
	SLEEP,
	THINK,
	DIED
}					t_status;

typedef struct s_pinfo
{
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*died_mutex;
	pthread_mutex_t	*full_mutex;
	int				died;
	int				full;
	long			start_time;
	int				pnumber;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				num_eats;
}					t_pinfo;

typedef struct s_shared_data
{
	pthread_mutex_t	last_meal_mutex;
	pthread_mutex_t	meals_mutex;
	unsigned long	last_meal;
	int				meals;

}					t_shared_data;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	int				is_full;
	t_shared_data	sd;
	t_pinfo			*pinfo;
}					t_philo;

// setters
void				set_last_meal(t_shared_data *sd);
void				set_died(t_pinfo *pinfo, int boolean);
void				increment_meals(t_shared_data *sd);
void				set_full(t_pinfo *pinfo, int is_full);

// getters
long long			get_last_meal(t_shared_data *sd);
int					get_died(t_pinfo *pinfo);
int					get_meals(t_shared_data *sd);
int					get_full(t_pinfo *pinfo);
// clean resources
void				*free_philos(t_philo *philos, int size);
void				clear_mutexes(t_philo *philos);
void				free_resources(t_philo *philos, t_pinfo *pinfo);
void				unlock_mutexes(t_philo *philos);

void				safe_print(t_philo *philo, t_status status);

void				*monitor(void *param);
long long			timestamp(void);
unsigned long		program_time(long start_time);
void				await(unsigned long milies_time, t_pinfo *pinfo);
int					ft_atoi(const char *str, int *error_found);
int					philo_init(t_pinfo **pinfo, int count, char **data);

void				join_threads(t_philo *philos, t_pinfo *pinfo);

t_philo				*create_philos(t_pinfo *pinfo);
void				assign_forks(t_philo *philos, t_pinfo *pinfo);
void				start_routine(t_philo *philos, t_pinfo *pinfo);

void				*routine(void *param);
#endif