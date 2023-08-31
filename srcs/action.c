/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:33:51 by abeaudet          #+#    #+#             */
/*   Updated: 2023/08/31 12:49:50 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	pick_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->rfork);
	printf("Philo %d has taken a fork.\n", philo->id);
	pthread_mutex_lock(&philo->lfork);
	printf("Philo %d has taken a fork.\n", philo->id);
}

void	drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->rfork);
	printf("Philo %d has dropped a fork.\n", philo->id);
	pthread_mutex_unlock(&philo->lfork);
	printf("Philo %d has dropped a fork.\n", philo->id);
}
