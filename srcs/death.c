/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karo <karo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:26:25 by abeaudet          #+#    #+#             */
/*   Updated: 2023/10/02 19:46:21 by karo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//Infinite loop that will check if someone die
//Voir truc modulo pour faire boucle infini (i + 1) % nphilo
int	ft_dead(t_d *data)
{
	int i;

	i = 0;
	while (i <= data->nphilo)
	{
		if ((int)(get_time() - data->philo[i].lmeal) > data->ttd)
		{
			data->dead = 1;
			pthread_mutex_lock(&data->msg);
			printf("%lld ms %d died\n",
				(get_time() - data->start), data->philo[i].id);
			pthread_mutex_unlock(&data->msg);
			break;
		}
		else if (i == data->nphilo && data->philo->dead == 0)
			i = 0;
		else
			return (1);
	}
	// printf("%lld ms %d died\n",
	// 		(get_time() - data->start), data->philo[i].id);
	// pthread_mutex_unlock(&data->msg);
	return (0);
}
