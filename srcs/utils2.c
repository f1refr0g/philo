/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:54:13 by abeaudet          #+#    #+#             */
/*   Updated: 2023/12/01 12:47:02 by abeaudet         ###   ########.fr       */
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

int	announcer(int state, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock);
	if (philo->data->dead == 1)
	{
		pthread_mutex_unlock(&philo->data->lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->lock);
	if (philo->nphilo > 1)
	{
		if (state == SLEEPING)
		{
			printf("%lld ms %d is sleeping\n", ft_ts(philo), philo->id);
			ft_usleep((philo->tts));
		}
		else if (state == FORK)
			printf("%lld ms %d has taken a fork\n", ft_ts(philo), philo->id);
		else if (state == EATING)
		{
			printf("%lld ms %d is eating\n", ft_ts(philo), philo->id);
			ft_usleep((philo->data->tte));
		}
		else if (state == THINKING)
			printf("%lld ms %d is thinking\n", ft_ts(philo), philo->id);
	}
	return (0);
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
	if (philo->neat == 0)
	{
		return (0);
	}
	else if (philo->mcount == philo->neat)
	{
		philo->finished = 1;
		return (1);
	}
	return (0);
}

int	ft_usleep(useconds_t time)
{
	u_int64_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
	return (0);
}
