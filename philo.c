/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:37:11 by helarras          #+#    #+#             */
/*   Updated: 2024/06/13 15:44:24 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ff()
{
    system("leaks -q philo");
}

int main(int ac, char **av)
{
    t_pinfo     *pinfo;
    t_philo     **philos;
    pthread_t   mthread;

    atexit(ff);
    philo_init(&pinfo, ac - 1, av + 1);
    philos = create_philos(pinfo);
    if (!philos)
        return (0);
    assign_forks(philos, pinfo);
    start_lunch(philos, pinfo);
    pthread_create(&mthread, NULL, monitor, philos);
    join_threads(philos, pinfo);
    pthread_join(mthread, NULL);
    
    free_resources(philos, pinfo);
}

