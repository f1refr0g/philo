/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:54:13 by abeaudet          #+#    #+#             */
/*   Updated: 2023/09/01 12:33:18 by abeaudet         ###   ########.fr       */
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
		printf("%lld ms %d is sleeping\n",
			(get_time() - philo->data->start), philo->id);
	else if (state == FORK)
		printf("%lld ms %d has taken a fork\n",
			(get_time() - philo->data->start), philo->id);
	else if (state == EATING)
		printf("%lld ms %d is eating\n",
			(get_time() - philo->data->start), philo->id);
	else if (state == THINKING)
		printf("%lld ms %d is thinking\n",
			(get_time() - philo->data->start), philo->id);
	pthread_mutex_unlock(&philo->data->msg);
}

u_int64_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (0);
	return (((time.tv_sec * (u_int64_t)1000) + (time.tv_usec / 1000)));
}
