/*                                                                            */
/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   lunch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 01:10:31 by helarras          #+#    #+#             */
/*   Updated: 2024/06/26 22:19:49 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    eat(t_philo *philo, struct timeval start_time, int eat_time)
{
    printf("%ld %i is eating\n", timestamp(start_time), philo->id);
    await(eat_time);
    pthread_mutex_unlock(philo->r_fork);
    pthread_mutex_unlock(philo->l_fork);
}

void    t_sleep(t_philo *philo, struct timeval start_time, int sleep_time)
{
    printf("%ld %i is sleeping\n", timestamp(start_time), philo->id);
    philo->pinfo.last_meal = timestamp(start_time);
    await(sleep_time);
}

void    think(t_philo *philo, struct timeval start_time)
{
    printf("%ld %i is thinking\n", timestamp(start_time), philo->id);
    pthread_mutex_lock(philo->r_fork);
    printf("%ld %i has taken a right fork\n", timestamp(start_time), philo->id);
    pthread_mutex_lock(philo->l_fork);
    printf("%ld %i has taken a left fork\n", timestamp(start_time), philo->id);
}


void    *routine(void *param)
{
    t_philo *philo = (t_philo *)param;
    t_pinfo pinfo = philo->pinfo;
    struct timeval start_time;

    gettimeofday(&start_time, NULL);
    while (1)
    {
        think(philo, start_time);
        eat(philo, start_time, pinfo.eat_time);
        t_sleep(philo, start_time, pinfo.sleep_time);
    }
}
