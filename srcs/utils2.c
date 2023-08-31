/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:54:13 by abeaudet          #+#    #+#             */
/*   Updated: 2023/08/31 10:13:55 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	clear_sim(t_d *data)
{
	// int i;

	// i = 0;
	// if (data->task[i] != NULL)
	// {
	// 	while (i < data->nphilo)
	// 	{
	// 		if (data->task[i] != NULL)
	// 		{
	// 			free(data->task[i]);
	// 			printf("free task : %d\n", i);
	// 		}
	// 		i++;
	// 	}
	// }
	free(data->task);
	if (data->philo != NULL)
		free(data->philo);
	// if (data != NULL)
	// 	free(data);
}