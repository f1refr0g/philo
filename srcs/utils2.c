/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:54:13 by abeaudet          #+#    #+#             */
/*   Updated: 2023/08/27 17:04:24 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	clear_sim(t_d *data)
{
	int i;

	i = 0;
	if (data->task[i] != NULL)
	{
		while (data->task[i]  != NULL)
		{
			free(data->task[i]);
			i++;
		}
	}
	if (data->philo != NULL)
		free(data->philo);
	if (data != NULL)
		free(data);
}