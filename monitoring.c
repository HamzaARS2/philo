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

    while (!died) {
        i = 0;
        while (philos[i])
        {
            if (timestamp(philos[i]->pinfo.start_time) - get_last_meal(&philos[i]->sd) >= philos[i]->pinfo.die_time)
            {
                died = 1;
                printf("%ld %i died\n", timestamp(philos[i]->pinfo.start_time), philos[i]->id);
                exit(0);
            }
            i++;
        }
        
    }
    return (NULL);
}