/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:41:57 by helarras          #+#    #+#             */
/*   Updated: 2024/06/09 15:52:55 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	skipspaces(const char *str)
{
	size_t	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

static int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_atoi(const char *str, int *error_found)
{
	size_t	i;
	int		sign;
	long	number;
	long	temp;

	number = 0;
	sign = 1;
	i = skipspaces(str);
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			*error_found = 1;
			return (0);
		}
		temp = number;
		number = (number * 10) + str[i++] - 48;
		if (number / 10 != temp && sign > 0)
			return (-1);
		if (number / 10 != temp && sign < 0)
			return (0);
	}
	return (number * sign);
}