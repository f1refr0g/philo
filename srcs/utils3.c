/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:09:39 by abeaudet          #+#    #+#             */
/*   Updated: 2023/10/30 11:32:26 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	set_philo(t_philo *philo ,t_d *data, int i)
{
	philo->id = i + 1;
	philo->data = data;
	philo->finished = 0;
	philo->mcount = 0;
	philo->lmeal = data->start;
	philo->ttd = data->ttd;
	philo->tts = data->tts;
	philo->tte = data->tte;
	philo->neat = data->neat;
	philo->start = data->start;
	philo->nphilo = data->nphilo;
}