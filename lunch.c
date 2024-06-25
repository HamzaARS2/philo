/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 01:10:31 by helarras          #+#    #+#             */
/*   Updated: 2024/06/25 01:14:57 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    eat()
{
    
}


void    *lunch(void *param) 
{
    t_philo *philo = (t_philo *)param;
    t_pinfo pinfo = philo->pinfo;
    while (1) 
    {
        pthread_mutex_lock((philo->r_fork));
        pthread_mutex_lock((philo->l_fork));
        printf("Philosopher %i has taken a fork\n", philo->id);
        printf("Philosopher %i is eating\n", philo->id);
        await(pinfo.eat_time);
        pthread_mutex_unlock((philo->r_fork));
        pthread_mutex_unlock((philo->l_fork));
    }
    return (NULL);
}