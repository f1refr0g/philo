/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:26:25 by abeaudet          #+#    #+#             */
/*   Updated: 2023/09/28 16:38:21 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_dead(t_d *data)
{
	int i;

	i = 0;
	while (i <= data->nphilo)
	{
		if (get_time() - data->philo[i].lmeal >= data->ttd)
		{
			data->dead = 1;
			break ;
		}
		else if (i == data->nphilo)
			i = 0;
		i++;
	}
}
