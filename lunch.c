/* ************************************************************************** */
/*                                                                            */
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
    pthread_mutex_lock(philo->r_fork);
    printf("%ld %i has taken a fork\n", timestamp(start_time), philo->id);
    pthread_mutex_lock(philo->l_fork);
    printf("%ld %i has taken a fork\n", timestamp(start_time), philo->id);
    printf("%ld %i is eating\n", timestamp(start_time), philo->id);
    // update life time
    await(eat_time);
    pthread_mutex_unlock(philo->l_fork);
    pthread_mutex_unlock(philo->r_fork);
}



void    *lunch(void *param) 
{
    t_philo *philo = (t_philo *)param;
    t_pinfo pinfo = philo->pinfo;
    struct timeval start_time;

    gettimeofday(&start_time, NULL);
    
    while (1) 
    {
        //  if any philo died
        pthread_mutex_lock(philo->r_fork);
        pthread_mutex_lock(philo->l_fork);
        // add a mutex to ft_printf => {mutex + if died = 1 + printf()}
        // mutex - 
        printf("%ld %i has taken a fork\n", timestamp(start_time), philo->id);
        printf("%ld %i is eating\n", timestamp(start_time), philo->id);
        // update the philo timer
        await(pinfo.eat_time);
        pthread_mutex_unlock(philo->r_fork);
        pthread_mutex_unlock(philo->l_fork);
        printf("%ld %i is sleeping\n", timestamp(start_time), philo->id);
        await(pinfo.sleep_time);
    }
    return (NULL);
}
/*
    routine have to include all the philo habits (eat + sleep + think)
    {
        // start time of each philo (philo_timer)
        while (counter or anyphilo died){
            lunch() => eating habit
            sleep() => sleeping habit
            thinking() => thinkjing habit
        }
    }
*/