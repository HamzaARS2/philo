/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:56:49 by helarras          #+#    #+#             */
/*   Updated: 2024/07/01 19:59:27 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *monitor(void *param)
{
    t_philo **philos = (t_philo **)param;
    int i;

    while (!get_died(&philos[0]->pinfo)) {
        i = 0;
        while (philos[i])
        {
            if (timestamp() - get_last_meal(&philos[i]->sd) >= philos[i]->pinfo.die_time)
            {
                set_died(&philos[0]->pinfo, 1);
                safe_print(philos[i], DIED);
                exit(0);
            }
            i++;
        }
        
    }
    return (NULL);
}