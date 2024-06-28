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
    long seconds;
    long useconds;
    unsigned long timestamp;
    
    gettimeofday(&current_time, NULL);
    seconds = current_time.tv_sec - start_time.tv_sec;
    useconds = current_time.tv_usec - start_time.tv_usec;
    if (useconds < 0)
    {
        seconds -= 1;
        useconds += 1000000;
    }
    timestamp = (seconds * 1000) + (useconds / 1000);
    return (timestamp);
}
