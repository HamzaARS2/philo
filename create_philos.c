/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:38:55 by helarras          #+#    #+#             */
/*   Updated: 2024/06/30 19:58:29 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *clear_arr(t_philo **philos, int size)
{
    int i;

    i = 0;
    while (philos[i] && i < size)
    {
        free(philos[i]->r_fork);
        free(philos[i++]);
    }
    free(philos);
    return (NULL);
}

t_philo **create_philos(t_pinfo pinfo) 
{
    int i;
    t_philo **philos;

    philos = malloc((pinfo.pnumber + 1) * sizeof(t_philo *));
    if (!philos)
        return (0);
    philos[pinfo.pnumber] = 0;
    i = 0;
    while (i < pinfo.pnumber) 
    {
        philos[i] = malloc(sizeof(t_philo));
        if (!philos[i])
            return (clear_arr(philos, pinfo.pnumber));
        philos[i]->id = i + 1;
        philos[i]->pinfo = pinfo;
        philos[i]->r_fork = malloc(sizeof(pthread_mutex_t));
        if (!(philos[i]->r_fork))
            return (clear_arr(philos, pinfo.pnumber));
        pthread_mutex_init(philos[i]->r_fork, NULL);
        i++;
    }
    return (philos);
}

void    assign_forks(t_philo **philos, t_pinfo pinfo)
{
    int i;

    i = 0;
    while (i < pinfo.pnumber)
    {
        if (i == 0)
            philos[i]->l_fork = philos[pinfo.pnumber - 1]->r_fork;
        else
            philos[i]->l_fork = philos[i - 1]->r_fork;
        i++;
    }
}


void    start_lunch(t_philo **philos, t_pinfo pinfo)
{
    int         i;
    pthread_t   mthread;

    i = 0;
    gettimeofday(&pinfo.start_time, NULL);
    while (i < pinfo.pnumber)
    {
        philos[i]->pinfo = pinfo;
        pthread_create(&(philos[i]->thread), NULL, routine, philos[i]);
        i++;
    }
    pthread_create(&mthread, NULL, monitor, philos);
}