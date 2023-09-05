/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:33:51 by abeaudet          #+#    #+#             */
/*   Updated: 2023/09/05 11:39:14 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	pick_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->rfork);
	pthread_mutex_lock(&philo->lfork);
	announcer(FORK, philo);
}

void	drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->rfork);
	pthread_mutex_unlock(&philo->lfork);
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
