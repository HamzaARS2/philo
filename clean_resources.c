/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_resources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:03:03 by helarras          #+#    #+#             */
/*   Updated: 2024/09/28 11:48:06 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear_mutexes(t_philo *philos)
{
	int		i;
	t_pinfo	*pinfo;

	pinfo = philos[0].pinfo;
	i = 0;
	while (i < pinfo->pnumber)
	{
		pthread_mutex_destroy(philos[i].r_fork);
		pthread_mutex_destroy(&philos[i].sd.last_meal_mutex);
		pthread_mutex_destroy(pinfo->print_mutex);
		pthread_mutex_destroy(pinfo->died_mutex);
		pthread_mutex_destroy(pinfo->full_mutex);
		i++;
	}
}

void	*free_philos(t_philo *philos, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(philos[i++].r_fork);
	free(philos);
	return (NULL);
}

void	free_resources(t_philo *philos, t_pinfo *pinfo)
{
	free(pinfo->print_mutex);
	free(pinfo->died_mutex);
	free(pinfo->full_mutex);
	free(pinfo);
	free_philos(philos, pinfo->pnumber);
}

void	unlock_mutexes(t_philo *philos)
{
	int		i;
	t_pinfo	*pinfo;

	pinfo = philos[0].pinfo;
	i = 0;
	while (i < pinfo->pnumber)
	{
		pthread_mutex_unlock(philos[i].r_fork);
		pthread_mutex_unlock(philos[i].pinfo->died_mutex);
		pthread_mutex_unlock(philos[i].pinfo->full_mutex);
		pthread_mutex_unlock(philos[i].pinfo->print_mutex);
		i++;
	}
}
