/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:26:25 by abeaudet          #+#    #+#             */
/*   Updated: 2023/10/15 13:20:24 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//Infinite loop that will check if someone die
//Voir truc modulo pour faire boucle infini (i + 1) % nphilo
int	ft_dead(t_d *data)
{
	int	i;

	i = 0;
	while (i < data->nphilo)
	{
		if ((int)(get_time() - data->philo[i].lmeal)
			> data->ttd && data->dead == 0)
		{
			data->dead = 1;
			printf("%lld ms %d died\n",
				(get_time() - data->start), data->philo[i].id);
			break ;
		}
		else if (i == data->nphilo && data->philo->dead == 0)
			i = 0;
		else
			return (1);
	}
	return (0);
}

int	ft_checkdead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock);
	if (philo->data->dead == 1)
	{
		drop_fork(philo);
		pthread_mutex_unlock(&philo->data->lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->lock);
	return (0);
}
