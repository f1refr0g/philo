/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 08:11:32 by abeaudet          #+#    #+#             */
/*   Updated: 2023/08/21 10:38:33 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(0);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)b;
	while (i < len)
	{
		*ptr = (unsigned char)c;
		i++;
		ptr++;
	}
	return (b);
}

void	data_init(t_d *data, char **av)
{
	data->nbp = ft_atoi(av[1]);
	data->ttd = ft_atoi(av[2]);
	data->tte = ft_atoi(av[3]);
	data->tts = ft_atoi(av[4]);
	if (av[5])
		data->neat = ft_atoi(av[5]);
	else
		data->neat = 0;
}

void	print_param(t_d *data)
{
	printf("%d\n", data->nbp);
	printf("%d\n", data->ttd);
	printf("%d\n", data->tte);
	printf("%d\n", data->tts);
	printf("%d\n", data->neat);
}