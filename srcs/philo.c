/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:45:31 by abeaudet          #+#    #+#             */
/*   Updated: 2023/09/05 11:09:11 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *input)
{
	t_philo	*philo;
	int		loop;
	int		time;

	loop = 1;
	time = 0;
	philo = (t_philo *) input;
	if (philo->id % 2 == 0)
		usleep((philo->data->tte / 2) * 1000);
	while (loop)
	{
		pthread_mutex_lock(&philo->data->lock);
		if (is_finished(philo) != 1)
		{
			pick_fork(philo);
			usleep((philo->data->tte) * 1000);
			philo->mcount++;
			drop_fork(philo);
			time++;
		}
		else
			loop = 0;
		pthread_mutex_unlock(&philo->data->lock);
	}
	return (input);
}

void	philo_init(t_d *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = malloc(sizeof (t_philo) * data->nphilo);
	if (philo == NULL)
		ft_error("Maloc error");
	while (i < data->nphilo)
	{
		pthread_mutex_init(&philo[i].rfork, NULL);
		philo[i].id = i + 1;
		philo[i].data = data;
		philo[i].finished = 0;
		philo[i].mcount = 0;
		i++;
	}
	philo[0].lfork = philo[i].rfork;
	i = 1;
	while (i < data->nphilo)
	{
		philo[i].lfork = philo[i - 1].rfork;
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
	thread_init(&data);
	i = 0;
	while (i < data.nphilo)
	{
		pthread_join(data.task[i], NULL);
		i++;
	}
	pthread_mutex_destroy(&data.msg);
	clear_sim(&data);
	return (0);
}
