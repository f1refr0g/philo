/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 07:50:07 by abeaudet          #+#    #+#             */
/*   Updated: 2023/08/31 20:49:03 by abeaudet         ###   ########.fr       */
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

//Philo status
# define SLEEPING	0
# define FORK		1
# define EATING		2
# define THINKING	3
# define DEAD		4

typedef struct s_philo	t_philo;
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
	t_philo				*philo;
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

//Action
void	pick_fork(t_philo *philo);
void	drop_fork(t_philo *philo);
void	announcer(int state, t_philo *philo);

//Take a string and return it as int.
int		ft_atoi(const char *str);
// Check if arguments are valid format.
void	validate_args(char **av);

/*Delete at end*/
void	print_param(t_d *data);
void	clear_sim(t_d *data);

#endif