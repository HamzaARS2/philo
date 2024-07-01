/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:15:39 by helarras          #+#    #+#             */
/*   Updated: 2024/07/01 19:55:48 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    set_last_meal(t_shared_data *sd)
{
    pthread_mutex_lock(&sd->last_meal_mutex);
    sd->last_meal = timestamp();
    pthread_mutex_unlock(&sd->last_meal_mutex);
}

void    set_died(t_pinfo *pinfo, int boolean)
{
    pthread_mutex_lock(&pinfo->died_mutex);
    pinfo->died = boolean;
    pthread_mutex_unlock(&pinfo->died_mutex);
}