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



int check_death(t_philo **philos) {
    t_pinfo *pinfo = philos[0]->pinfo;
    int i = 0;

    while (philos[i])
    {
        if (timestamp() - get_last_meal(&philos[i]->sd) >= pinfo->die_time)
        {
            set_died(pinfo, 1);
            safe_print(philos[i], DIED);
            return (0);
        }
        i++;
    }
    return (1);
}

static int check_meals(t_philo **philos, int *full) {
    
    t_pinfo *pinfo = philos[0]->pinfo;
    int i = 0;

    if (pinfo->num_eats == -1)
        return (1);

    while (philos[i]) {
        if (get_meals(&philos[i]->sd) >= pinfo->num_eats && !philos[i]->is_full) {
            philos[i]->is_full = 1;
            (*full)++;
        }
        if ((*full) >= pinfo->pnumber)
            return (0);
        i++;
    }
    return (1);
}

void    *monitor(void *param)
{
    int i;
    t_philo **philos;
    t_pinfo *pinfo;
    int full = 0;
    
    philos = (t_philo **)param;
    pinfo = philos[0]->pinfo;
    while (!get_died(pinfo) && check_meals(philos, &full)) 
    {
        i = 0;

        check_death(philos);

    }
    return (NULL);
}
