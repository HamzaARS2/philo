/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   await.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:46:09 by helarras          #+#    #+#             */
/*   Updated: 2024/09/28 16:46:54 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	await(unsigned long ms, t_pinfo *pinfo)
{
	unsigned long	start_time;

	start_time = timestamp();
	while (timestamp() - start_time < ms && !get_died(pinfo))
		usleep(100);
}
