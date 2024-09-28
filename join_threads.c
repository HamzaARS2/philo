/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 01:01:08 by helarras          #+#    #+#             */
/*   Updated: 2024/09/28 13:56:38 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    join_threads(t_philo *philos, t_pinfo *pinfo)
{
    int i;

    i = 0;
    while (i < pinfo->pnumber)
        pthread_join(philos[i++].thread, NULL);
}