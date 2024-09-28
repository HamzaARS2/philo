/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:38:55 by helarras          #+#    #+#             */
/*   Updated: 2024/09/28 16:54:50 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*create_philos(t_pinfo *pinfo)
{
	int		i;
	t_philo	*philos;

	philos = malloc((pinfo->pnumber) * sizeof(t_philo));
	if (!philos)
		return (0);
	i = 0;
	while (i < pinfo->pnumber)
	{
		philos[i].id = i + 1;
		philos[i].pinfo = pinfo;
		philos[i].sd.meals = 0;
		philos[i].is_full = 0;
		philos[i].r_fork = malloc(sizeof(pthread_mutex_t));
		if (!(philos[i].r_fork))
			return (free_philos(philos, pinfo->pnumber));
		pthread_mutex_init(philos[i].r_fork, NULL);
		pthread_mutex_init(&philos[i].sd.last_meal_mutex, NULL);
		pthread_mutex_init(&philos[i].sd.meals_mutex, NULL);
		i++;
	}
	return (philos);
}

void	assign_forks(t_philo *philos, t_pinfo *pinfo)
{
	int	i;

	i = 0;
	while (i < pinfo->pnumber)
	{
		if (i == 0)
			philos[i].l_fork = philos[pinfo->pnumber - 1].r_fork;
		else
			philos[i].l_fork = philos[i - 1].r_fork;
		i++;
	}
}

void	start_routine(t_philo *philos, t_pinfo *pinfo)
{
	int	i;

	i = 0;
	pinfo->start_time = timestamp();
	while (i < pinfo->pnumber)
	{
		set_last_meal(&philos[i].sd);
		pthread_create(&(philos[i].thread), NULL, routine, &philos[i]);
		i++;
	}
}
