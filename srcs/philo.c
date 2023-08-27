/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:45:31 by abeaudet          #+#    #+#             */
/*   Updated: 2023/08/27 17:03:11 by abeaudet         ###   ########.fr       */
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
		usleep((philo->data->tte / 2) * 1000);
		pthread_mutex_lock(&philo->data->lock);
		if (time < philo->data->nphilo)
		{
			printf("Philo id %d\n", philo->id);
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
	int	i;

	i = 0;
	philo = malloc(sizeof (t_philo) * data->nphilo);
	while (i < data->nphilo)
	{
		philo[i].id = i + 1;
		philo[i].data = data;
		i++;
	}
	data->philo = philo;
}

void	thread_init(t_d *data)
{
	int i;

	data->task = malloc((sizeof (pthread_t) * (data->nphilo)));
	i = 0;
	while (i < data->nphilo)
	{
		data->task[i] = malloc(sizeof(pthread_t));
		pthread_create(&data->task[i], NULL, &routine, &data->philo[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_d	data;
	int		i;

	if (!(ac == 5 || ac == 6))
		ft_error("Wrong number of arguments.\n");
	validate_args(av);
	ft_memset(&data, 0, sizeof(t_d));
	data_init(&data, av);
	printf("1%d\n", data.nphilo);
	philo_init(&data);
	printf("2%d\n", data.nphilo);
	pthread_mutex_init(&data.lock, NULL);
	printf("3%d\n", data.nphilo);
	thread_init(&data);
	printf("4%d\n", data.nphilo);
	i = 0;
	printf("outloop%d\n", data.nphilo);
	while (i < data.nphilo)
	{
		pthread_join(data.task[i], NULL);
		i++;
	}
	clear_sim(&data);
	pthread_mutex_destroy(&data.lock);
	return (0);
}