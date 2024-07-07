/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:56:49 by helarras          #+#    #+#             */
/*   Updated: 2024/07/07 12:12:26 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


// int check_num_eats()

void    *monitor(void *param)
{
    int i;
    t_philo **philos;
    t_pinfo *pinfo;
    int full = 0;
    
    philos = (t_philo **)param;
    pinfo = philos[0]->pinfo;
    while (!get_died(pinfo) && (full < pinfo->pnumber || pinfo->num_eats == -1)) 
    {
        i = 0;
        int meals = get_meals(&philos[i]->sd);
        while (philos[i] && (meals < pinfo->num_eats || pinfo->num_eats == -1))
        {
            if (timestamp() - get_last_meal(&philos[i]->sd) >= pinfo->die_time)
            {
                set_died(pinfo, 1);
                safe_print(philos[i], DIED);
                break;
            }
            if (get_meals(&philos[i]->sd) < pinfo->num_eats && pinfo->num_eats != -1)
                full++;
            i++;
        }
    }
    return (NULL);
}
