/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 07:50:07 by abeaudet          #+#    #+#             */
/*   Updated: 2023/08/27 13:40:30 by abeaudet         ###   ########.fr       */
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

struct s_philo;
//Data struct to store program parameters.
// nbp = Number of philo.
// ttd = time to die.
// tte = time to eat.
// tts = time to sleep.
// neat = (optional) number of time philo has to eat.
typedef struct s_d{
	int					nphilo;
	int					tte;
	int					ttd;
	int					tts;
	int					neat;
	int					dead;
	struct s_philo		*philo;
	pthread_t			*task;
	pthread_mutex_t		*forks;
	pthread_mutex_t		lock;
	pthread_mutex_t		msg;
}	t_d;

//id = Philo number around the table
//mc = meal count
//lm = time of last meal
typedef struct s_philo{
	int					id;
	int					mcount;
	int					status;
	int					sleep;
	int					lmeal;
	int					ttd;
	int					dead;
	struct s_d			*data;
	pthread_t			task;
	pthread_mutex_t		lfork;
	pthread_mutex_t		rfork;
	pthread_mutex_t		lock;
}	t_philo;

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
int		ft_atoi(const char *str);
// Check if arguments are valid format.
void	validate_args(char **av);

/*Delete at end*/
void	print_param(t_d *data);

#endif