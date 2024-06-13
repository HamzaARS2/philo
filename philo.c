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



void    *run(void *param) {
    t_philo *philo = (t_philo *)param;
    while (1) {
        pthread_mutex_lock((philo->r_fork));
        pthread_mutex_lock((philo->l_fork));
        printf("Philosopher %i has taken a fork\n", philo->id);
        printf("Philosopher %i is eating\n", philo->id);
        sleep(1);
        pthread_mutex_unlock((philo->r_fork));
        pthread_mutex_unlock((philo->l_fork));
        printf("Philosopher %i is thinking\n", philo->id);
        sleep(2);
    }
    return (NULL);
}

int main()
{
    int pnumber = 10;
    t_philo **philos;
    pthread_mutex_t mutex;
    
    philos = malloc((pnumber + 1) * sizeof(t_philo *));
    if (!philos)
        return (1);
    philos[pnumber] = 0;
    int i = 0;
    while (i < pnumber) {
        philos[i] = malloc(sizeof(t_philo));
        philos[i]->id = i + 1;
        philos[i]->r_fork = malloc(sizeof(pthread_mutex_t));
        pthread_mutex_init(philos[i]->r_fork, NULL);
        i++;
    }
    int k = 0;
    while (k < pnumber) {
        if (k == 0)
            philos[k]->l_fork = philos[pnumber - 1]->r_fork;
        else
            philos[k]->l_fork = philos[k - 1]->r_fork;
        k++;
    }
    int j = 0;
    while (j < pnumber) {
        pthread_create(&philos[j]->thread, NULL, run, philos[j]);
        j++;
    }
    int w = 0;
    while (w < pnumber)
        pthread_join(philos[w++]->thread, NULL);
    

}




// void ft_sleep(long delay)
// {
//     time_t f;
//     time_t cur;

//     gettimeofday(&f,NULL);
//     while (gettimeofday(&cur, NULL) - f <= delay * 1000);
//     return ;
// }