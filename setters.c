/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:15:39 by helarras          #+#    #+#             */
/*   Updated: 2024/06/30 18:36:28 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    set_last_meal(t_shared_data *sd ,struct timeval start_time)
{
    pthread_mutex_lock(&sd->last_meal_mutex);
    sd->last_meal = timestamp(start_time);
    pthread_mutex_unlock(&sd->last_meal_mutex);
}