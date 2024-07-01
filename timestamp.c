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

unsigned long   timestamp()
{
    struct timeval ct;
    
    gettimeofday(&ct, NULL);
    return (ct.tv_sec * 1000) + (ct.tv_usec / 1000);
}

unsigned long program_time(long start_time)
{
    return (timestamp() - start_time);
}
