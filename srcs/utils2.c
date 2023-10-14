/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:54:13 by abeaudet          #+#    #+#             */
/*   Updated: 2023/10/14 13:31:18 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	clear_sim(t_d *data)
{
	int	i;

	i = 0;
	//added this instead of pputting it in main
	pthread_mutex_destroy(&data->msg);
	while (i < data->nphilo)
	{
		pthread_join(data->task[i], NULL);
		i++;
	}
	//end 
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

// modifier announcer pour quil retourne 0 si okay, 1 si mort
//Ne pas usleep dans announcer, car sa deadlock le programme
// des quil wake je call thinking, les mutex font soccuper des timing
//Modifier et utiliser la fonction usleep pimp dispo sur web
//cverifier a lentrer du announcer si dead, sinon break out of routine
//checker mes lock pour manger car les message cauyse un delai
//ne pas lock mes message et mes sleep
//donner les variable tte tts ttd a tout les philo pour eviter des lock, lock seulement
// lorsque je regarde sur data
//check dead lock check unlock pour eviter de deadlock le programme
void	announcer(int state, t_philo *philo)
{
	// pthread_mutex_lock(&philo->data->msg);
	if (philo->data->dead == 1)
		return ;
	if (state == SLEEPING && philo->data->dead == 0)
	{
		printf("%lld ms %d is sleeping\n",
			(get_time() - philo->data->start), philo->id);
		ft_usleep((philo->data->tts));
	}
	else if (state == FORK && philo->data->dead == 0)
		printf("%lld ms %d has taken a fork\n",
			(get_time() - philo->data->start), philo->id);
	else if (state == EATING && philo->data->dead == 0)
	{
		printf("%lld ms %d is eating\n",
			(get_time() - philo->data->start), philo->id);
		ft_usleep((philo->data->tte));
	}
	else if (state == THINKING && philo->data->dead == 0)
		printf("%lld ms %d is thinking\n",
			(get_time() - philo->data->start), philo->id);
	// pthread_mutex_unlock(&philo->data->msg);
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

int		ft_usleep(useconds_t time)
{
	u_int64_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
	return (0);
}