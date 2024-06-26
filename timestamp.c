/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:42:26 by helarras          #+#    #+#             */
/*   Updated: 2024/06/26 18:42:46 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long   timestamp(struct timeval start_time)
{
    struct timeval current_time;
    unsigned long seconds;
    unsigned long millis;
    unsigned long timestamp;
    
    gettimeofday(&current_time, NULL);
    seconds = (current_time.tv_sec - start_time.tv_sec);
    millis = current_time.tv_usec / 1000;
    timestamp = (seconds * 1000) + millis;
    return (timestamp);
}
