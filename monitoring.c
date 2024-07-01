/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:56:49 by helarras          #+#    #+#             */
/*   Updated: 2024/06/30 19:57:14 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *monitor(void *param)
{
    t_philo **philos = (t_philo **)param;
    int died = 0;
    int i;
    long long s;

    while (!died) {
        i = 0;
        while (philos[i])
        {
            // Fix this timestamp 0 get_last_meal, it gives wrong value sometimes
            s = timestamp() - philos[i]->sd.last_meal;
            // s = timestamp() - get_last_meal(&philos[i]->sd);
            // printf(">>>>>>>%lld\n", s);
            if (s >= philos[i]->pinfo.die_time)
            {
                died = 1;
                safe_print(philos[i], DIED);
                exit(0);
            }
            i++;
        }
        
    }
    return (NULL);
}