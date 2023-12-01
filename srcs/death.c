/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:26:25 by abeaudet          #+#    #+#             */
/*   Updated: 2023/12/01 12:15:16 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_checkdead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock);
	if (philo->data->dead == 1)
	{
		pthread_mutex_unlock(&philo->rfork);
		pthread_mutex_unlock(&philo->data->lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->lock);
	return (0);
}

void	ft_death(t_d *data)
{
	int	i;

	i = 0;
	usleep(500);
	while (i < data->nphilo)
	{
		pthread_mutex_lock(&data->lock);
		if (data->pfini == data->nphilo)
		{
			pthread_mutex_unlock(&data->lock);
			return ;
		}
		if (((u_int64_t)(get_time() - (data->philo[i].lmeal))
			> (uint64_t)data->ttd))
		{
			pthread_mutex_lock(&data->msg);
			data->dead = 1;
			printf("%lld ms %d died\n", (get_time() - data->start), i + 1);
			pthread_mutex_unlock(&data->msg);
			break ;
		}
		i = (i + 1) % data->nphilo;
		pthread_mutex_unlock(&data->lock);
	}
	pthread_mutex_unlock(&data->lock);
}
