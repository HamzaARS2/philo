/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 01:10:31 by helarras          #+#    #+#             */
/*   Updated: 2024/07/07 11:55:10 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    eat(t_philo *philo)
{
    t_pinfo *pinfo;

    pinfo = philo->pinfo;
    pthread_mutex_lock(philo->l_fork);
    safe_print(philo, FORK_TAKEN);
    pthread_mutex_lock(philo->r_fork);
    safe_print(philo, FORK_TAKEN);
    safe_print(philo, EAT);
    set_last_meal(&philo->sd);
    await(pinfo->eat_time);
    increment_meals(&philo->sd);
    pthread_mutex_unlock(philo->r_fork);
    pthread_mutex_unlock(philo->l_fork);
}

void    t_sleep(t_philo *philo)
{
    t_pinfo *pinfo;

    pinfo = philo->pinfo;
    safe_print(philo, SLEEP);
    await(pinfo->sleep_time);
}

void    think(t_philo *philo)
{
    safe_print(philo, THINK);
}

int check_meals(t_philo *philo)
{
    t_pinfo *pinfo;
    
    pinfo = philo->pinfo;
    return (get_meals(&philo->sd) < pinfo->num_eats || pinfo->num_eats == -1);
}

void    *routine(void *param)
{
    t_philo *philo = (t_philo *)param;
    t_pinfo *pinfo = philo->pinfo;

    if (philo->id % 2 == 0)
        t_sleep(philo);
    while (!get_died(pinfo) && check_meals(philo))
    {
        think(philo);
        eat(philo);
        t_sleep(philo);
    }
    return (NULL);
}