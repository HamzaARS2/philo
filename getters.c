/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:23:01 by helarras          #+#    #+#             */
/*   Updated: 2024/06/30 18:36:09 by helarras         ###   ########.fr       */
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