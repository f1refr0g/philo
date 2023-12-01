/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:33:51 by abeaudet          #+#    #+#             */
/*   Updated: 2023/12/01 11:58:14 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//Changer lmeal pour quand je pick la 2eme fork, possible delai
//annoncer pour les deux fourchette
//unlock les fourcheo tte si le philo meurt
int	pick_fork(t_philo *philo)
{
	if (ft_checkdead(philo) == 1)
		return (1);
	if (philo->nphilo > 1)
	{
		pthread_mutex_lock(&philo->rfork);
		announcer(FORK, philo);
		pthread_mutex_lock(philo->lfork);
		pthread_mutex_lock(&philo->data->lock);
		philo->lmeal = get_time();
		pthread_mutex_unlock(&philo->data->lock);
		announcer(FORK, philo);
	}
	return (0);
}

int	drop_fork(t_philo *philo)
{
	if (ft_checkdead(philo) == 1)
	{
		pthread_mutex_unlock(&philo->rfork);
		pthread_mutex_unlock(philo->lfork);
		return (1);
	}
	pthread_mutex_unlock(&philo->rfork);
	pthread_mutex_unlock(philo->lfork);
	announcer(SLEEPING, philo);
	return (0);
}

int	check_dead(t_philo *philo)
{
	if ((philo->lmeal + philo->ttd) > get_time())
	{
		philo->dead = 1;
		return (1);
	}
	else
		return (0);
}
