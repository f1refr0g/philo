/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:45:31 by abeaudet          #+#    #+#             */
/*   Updated: 2023/08/21 10:39:32 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_d	data;

	if (!(ac == 5 || ac == 6))
		ft_error("Wrong number of arguments.\n");
	validate_args(av);
	ft_memset(&data, 0, sizeof(t_d));
	data_init(&data, av);
	print_param(&data);
	return (0);
}
