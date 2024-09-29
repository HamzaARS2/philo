/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:37:11 by helarras          #+#    #+#             */
/*   Updated: 2024/09/29 10:28:47 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_pinfo		*pinfo;
	t_philo		*philos;

	if (!philo_init(&pinfo, ac - 1, av + 1))
		return (EXIT_FAILURE);
	philos = create_philos(pinfo);
	if (!philos)
		return (0);
	assign_forks(philos, pinfo);
	start_routine(philos, pinfo);
	monitor(philos);
	join_threads(philos, pinfo);
	clear_mutexes(philos);
	free_resources(philos, pinfo);
}
