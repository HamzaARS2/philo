/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:37:11 by helarras          #+#    #+#             */
/*   Updated: 2024/06/13 15:44:24 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *run(void *param) 
{
    t_philo *philo = (t_philo *)param;
    t_pinfo pinfo = philo->pinfo;
    while (1) 
    {
        pthread_mutex_lock((philo->r_fork));
        pthread_mutex_lock((philo->l_fork));
        printf("Philosopher %i has taken a fork\n", philo->id);
        printf("Philosopher %i is eating\n", philo->id);
        await(pinfo.teat);
        pthread_mutex_unlock((philo->r_fork));
        pthread_mutex_unlock((philo->l_fork));
        printf("Philosopher %i is sleeping\n", philo->id);
        await(pinfo.tsleep);
    }
    return (NULL);
}

int main()
{
    int pnumber = 10;
    t_pinfo pinfo;
    char *data[] = {"4", "200", "500", "800", "6"};
    t_philo **philos;
    pthread_mutex_t mutex;
    philo_init(&pinfo, 4, data);
    philos = malloc((pinfo.pnumber + 1) * sizeof(t_philo *));
    if (!philos)
        return (1);
    philos[pinfo.pnumber] = 0;
    int i = 0;
    while (i < pinfo.pnumber) {
        philos[i] = malloc(sizeof(t_philo));
        philos[i]->id = i + 1;
        philos[i]->pinfo = pinfo;
        philos[i]->r_fork = malloc(sizeof(pthread_mutex_t));
        pthread_mutex_init(philos[i]->r_fork, NULL);
        i++;
    }
    int k = 0;
    while (k < pinfo.pnumber) {
        if (k == 0)
            philos[k]->l_fork = philos[pinfo.pnumber - 1]->r_fork;
        else
            philos[k]->l_fork = philos[k - 1]->r_fork;
        k++;
    }
    int j = 0;
    while (j < pinfo.pnumber) {
        pthread_create(&philos[j]->thread, NULL, run, philos[j]);
        j++;
    }
    int w = 0;
    while (w < pinfo.pnumber)
        pthread_join(philos[w++]->thread, NULL);
    

}

