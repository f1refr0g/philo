/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:54:13 by abeaudet          #+#    #+#             */
/*   Updated: 2023/08/31 15:38:50 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	clear_sim(t_d *data)
{
	int	i;

	i = 0;
	free(data->task);
	while (i < data->nphilo)
	{
		pthread_mutex_destroy(&data->philo->rfork);
		i++;
	}
	if (data->philo != NULL)
		free(data->philo);
}

void	announcer(int state, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->msg);
	if (state == SLEEPING)
		printf("Philo %d is sleeping\n", philo->id);
	else if (state == FORK)
		printf("Philo %d has taken a fork\n", philo->id);
	else if (state == EATING)
		printf("Philo %d is eating\n", philo->id);
	else if (state == THINKING)
		printf("Philo %d is thinking\n", philo->id);
	pthread_mutex_unlock(&philo->data->msg);
}
