/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:33:51 by abeaudet          #+#    #+#             */
/*   Updated: 2023/10/14 11:53:42 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//Changer lmeal pour quand je pick la 2eme fork, possible delai
//annoncer pour les deux fourchette
//unlock les fourcheo tte si le philo meurt
void	pick_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->rfork);
	announcer(FORK, philo);
	pthread_mutex_lock(philo->lfork);
	philo->lmeal = get_time();
	announcer(FORK, philo);
	// announcer(EATING, philo);
}

void	drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->rfork);
	pthread_mutex_unlock(philo->lfork);
	announcer(SLEEPING, philo);
}

int		check_dead(t_philo *philo)
{
	if ((philo->lmeal + philo->data->ttd) > get_time())
	{
		philo->dead = 1;
		return (1);
	}
	else
		return (0);
}
