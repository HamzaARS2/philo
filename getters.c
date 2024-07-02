/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:23:01 by helarras          #+#    #+#             */
/*   Updated: 2024/07/02 12:09:10 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long get_last_meal(t_shared_data *sd)
{
    unsigned long last_meal;
    
    pthread_mutex_lock(&sd->last_meal_mutex);
    last_meal = sd->last_meal;
    pthread_mutex_unlock(&sd->last_meal_mutex);
    return (last_meal);
}

int get_died(t_pinfo *pinfo)
{
    int boolean;
    
    pthread_mutex_lock(pinfo->died_mutex);
    boolean = pinfo->died;
    pthread_mutex_unlock(pinfo->died_mutex);
    return (boolean);
}