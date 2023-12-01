/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:45:31 by abeaudet          #+#    #+#             */
/*   Updated: 2023/12/01 12:14:49 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//Need to add a condition to check if philo is dead if yes close everything 
//faire while (1) pour sauver des ligne et break out dla boucle X
void	*routine(void *input)
{
	t_philo	*philo;

	philo = (t_philo *) input;
	if (philo->id % 2 == 0)
		ft_usleep((philo->tte) / 2);
	while (1)
	{
		if (pick_fork(philo) == 1)
			break ;
		if (announcer(EATING, philo) == 1)
			break ;
		if (drop_fork(philo) == 1)
			break ;
		philo->mcount++;
		if (philo->mcount == philo->neat)
			break ;
		if (announcer(THINKING, philo) == 1)
			break ;
	}
	pthread_mutex_lock(&philo->data->lock);
	philo->data->pfini += 1;
	pthread_mutex_unlock(&philo->data->lock);
	pthread_mutex_unlock(&philo->rfork);
	return (input);
}

void	philo_init(t_d *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = malloc(sizeof (t_philo) * data->nphilo);
	if (philo == NULL)
		ft_error("Malloc error");
	while (i < data->nphilo)
	{
		pthread_mutex_init(&philo[i].rfork, NULL);
		set_philo(&philo[i], data, i);
		i++;
	}
	philo[0].lfork = &philo[i - 1].rfork;
	i = 1;
	while (i < data->nphilo)
	{
		philo[i].lfork = &philo[i - 1].rfork;
		i++;
	}
	data->philo = philo;
}

void	thread_init(t_d *data)
{
	int	i;

	data->task = malloc((sizeof (pthread_t *) * (data->nphilo)));
	i = 0;
	while (i < data->nphilo)
	{
		pthread_create(&data->task[i], NULL, &routine, &data->philo[i]);
		i++;
	}
	ft_usleep(100);
}

int	main(int ac, char **av)
{
	t_d		data;
	int		i;

	if (!(ac == 5 || ac == 6))
		ft_error("Wrong number of arguments.\n");
	validate_args(av);
	ft_memset(&data, 0, sizeof(t_d));
	data_init(&data, av);
	philo_init(&data);
	pthread_mutex_init(&data.msg, NULL);
	pthread_mutex_init(&data.lock, NULL);
	thread_init(&data);
	ft_death(&data);
	i = 0;
	while (i < data.nphilo)
	{
		pthread_join(data.task[i], NULL);
		i++;
	}
	clear_sim(&data);
	return (0);
}

void	ft_close(t_d *data)
{
	int	i;

	i = 0;
	while (i < data->nphilo)
	{
		drop_fork(&data->philo[i]);
		i++;
	}
}
