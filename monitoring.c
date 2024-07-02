/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:56:49 by helarras          #+#    #+#             */
/*   Updated: 2024/07/02 16:23:35 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void    *monitor(void *param)
{
    t_philo **philos = (t_philo **)param;
    int i;
    long long s;
    
    while (!get_died(philos[0]->pinfo)) 
    {
        i = 0;
        while (philos[i])
        {
            s = timestamp() - get_last_meal(&philos[i]->sd);
            if (s >= philos[i]->pinfo->die_time)
            {
                set_died(philos[0]->pinfo, 1);
                safe_print(philos[i], DIED);
                clear_mutexes(philos);
            }
            i++;
        }
    }
    return (NULL);
}