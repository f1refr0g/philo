/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:54:13 by abeaudet          #+#    #+#             */
/*   Updated: 2023/09/30 12:19:59 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	clear_sim(t_d *data)
{
	int	i;

	i = 0;
	if (data->task != NULL)
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
	{
		usleep((philo->data->tte) * 1000);
		printf("%lld ms %d is eating\n",
			(get_time() - philo->data->start), philo->id);
	}
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

int	is_finished(t_philo *philo)
{
	if (philo->data->neat == 0)
		return (0);
	else if (philo->mcount == philo->data->neat)
	{
		philo->finished = 1;
		return (1);
	}
	return (0);
}
