/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:57:16 by helarras          #+#    #+#             */
/*   Updated: 2024/06/09 15:54:23 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_mutexes(t_pinfo *pinfo)
{
    pinfo->print_mutex = malloc(sizeof(pthread_mutex_t));
    if (!pinfo->print_mutex)
        return (0);
    pinfo->died_mutex = malloc(sizeof(pthread_mutex_t));
    if (!pinfo->died_mutex)
    {
        pthread_mutex_destroy(pinfo->print_mutex);
        return (0);
    }
    pthread_mutex_init(pinfo->print_mutex, NULL);
    pthread_mutex_init(pinfo->died_mutex, NULL);
    return (1);
}

int philo_init(t_pinfo **pinfo, int count, char **data)
{
    if (count < 4)
        return (0);
    *pinfo = malloc(sizeof(t_pinfo));
    if (!pinfo)
        return (0);
    (*pinfo)->pnumber = ft_atoi(data[0]);
    if ((*pinfo)->pnumber <= 0)
        return (0);
    (*pinfo)->die_time = ft_atoi(data[1]);
    (*pinfo)->eat_time = ft_atoi(data[2]);
    (*pinfo)->sleep_time = ft_atoi(data[3]);
    if (data[4])
        (*pinfo)->num_eats = ft_atoi(data[4]);
    else
        (*pinfo)->num_eats = -1;
    init_mutexes((*pinfo));
    return (1);
}