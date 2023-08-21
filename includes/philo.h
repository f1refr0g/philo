/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 07:50:07 by abeaudet          #+#    #+#             */
/*   Updated: 2023/08/21 11:16:05 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

//Data struct to store program parameters.
// nbp = Number of philo.
// ttd = time to die.
// tte = time to eat.
// tts = time to sleep.
// neat = (optional) number of time philo has to eat.
typedef struct s_d{
	int	nbp;
	int	ttd;
	int	tte;
	int	tts;
	int	neat;

}	t_d;

typedef struct s_philo{
	int	nbr;
	int	last_meal;
} t_phlo;

/*Utils.c*/

// Return lenght of string.
int		ft_strlen(char *s);
// End program and return error msg.
void	ft_error(char *msg);
//Used to initiate variable in struct.
void	*ft_memset(void *b, int c, size_t len);
//Set validated args inside struct.
void	data_init(t_d *data, char **av);

/*Parsing.c*/

//Take a string and return it as int.
int	ft_atoi(const char *str);
// Check if arguments are valid format.
void	validate_args(char **av);

/*Delete at end*/
void	print_param(t_d *data);

#endif