/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:03:06 by abeaudet          #+#    #+#             */
/*   Updated: 2023/08/21 09:26:42 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//CHeck if args are digit only.
int	string_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

//Take a string and return it as an int.
int	ft_atoi(const char *str)
{
	int	entier;
	int	signe;

	entier = 0;
	signe = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			signe = -1;
	while (*str >= '0' && *str <= '9')
	{
		entier = entier * 10;
		entier = entier + ((*(str++)) - '0');
	}
	return (entier * signe);
}

//long int atoi to verify validity with ft_limit.
long int	ft_atoil(const char *str)
{
	long int	entier;
	long int	signe;

	entier = 0;
	signe = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			signe = -1;
	while (*str >= '0' && *str <= '9')
	{
		entier = entier * 10;
		entier = entier + ((*(str++)) - '0');
	}
	return (entier * signe);
}

//Check if the number is inside min/max INT value.
int	ft_limit(long int nbr)
{
	if (nbr < INT_MIN || nbr > INT_MAX)
		return (0);
	return (1);
}

void	validate_args(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!string_digit(av[i]))
			ft_error("Argument invalid, must contain digit only.\n");
		if (!ft_limit(ft_atoil(av[i])))
			ft_error("Argument are outside of min/max INT value.\n");
		i++;
	}
	if (ft_atoi(av[1]) < 1 || ft_atoi(av[1]) > 200)
		ft_error("Number of philo invalid.\n");
	if (ft_atoi(av[2]) < 60)
		ft_error("Time to die can't be under 60ms.\n");
	if (ft_atoi(av[3]) < 60)
		ft_error("Time to eat can't be under 60 ms.\n");
	if (ft_atoi(av[4]) < 60)
		ft_error("Time to sleep can't be under 60ms.\n");
	if (av[5])
		if (ft_atoi(av[5]) < 1)
			ft_error("Number of time philo must eat can't be less than 1.\n");
}
