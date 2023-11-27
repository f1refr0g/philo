/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:26:25 by abeaudet          #+#    #+#             */
/*   Updated: 2023/11/27 05:20:11 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_checkdead(t_philo *philo)
{
		// printf("Je regarde dead 1\n");
	pthread_mutex_lock(&philo->data->lock);
	// printf("je garde apres mort\n");
	
	if (philo->data->dead == 1)
	{
		// printf("Je suis avant drop fork\n");
		// drop_fork(philo);
		pthread_mutex_unlock(&philo->data->lock);
	// printf("Je suis la fin de checkdead \n");
		return (1);
	}
	// printf("unlock dead != 1 \n");
	pthread_mutex_unlock(&philo->data->lock);
	return (0);
}

void	ft_death(t_d *data)
{
	int	i;

	i = 0;
	while (i < data->nphilo)
	{
		pthread_mutex_lock(&data->lock);
		// if (is_finished(data->philo))
		// 	break ;
		if (((u_int64_t)(get_time() - (data->philo[i].lmeal))
			> (uint64_t)data->ttd))
		{
			pthread_mutex_lock(&data->msg);
			data->dead = 1;
			printf("%lld ms %d died\n",
				(get_time() - data->start), i + 1);
			pthread_mutex_unlock(&data->msg);
			// printf("fin de death\n");
			break ;
		}
		i = (i + 1) % data->nphilo;
		pthread_mutex_unlock(&data->lock);
	}
	// printf("je unlock a ma mort\n");
	pthread_mutex_unlock(&data->lock);
}
