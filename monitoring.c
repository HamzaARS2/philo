/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:56:49 by helarras          #+#    #+#             */
/*   Updated: 2024/07/05 19:56:33 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void    *monitor(void *param)
{
    int i;
    t_philo **philos;
    t_pinfo *pinfo;
    
    philos = (t_philo **)param;
    pinfo = philos[0]->pinfo;
    while (!get_died(pinfo)) 
    {
        i = 0;
        while (philos[i] && get_meals(&philos[i]->sd) < pinfo->num_eats)
        {
            if (timestamp() - get_last_meal(&philos[i]->sd) >= pinfo->die_time)
            {
                set_died(pinfo, 1);
                safe_print(philos[i], DIED);
                clear_mutexes(philos);
            }
            i++;
        }
    }
    return (NULL);
}