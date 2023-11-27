/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 07:50:07 by abeaudet          #+#    #+#             */
/*   Updated: 2023/11/27 05:07:01 by abeaudet         ###   ########.fr       */
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
	int					finished;
	int					pfini;
	u_int64_t			start;
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
	uint64_t			lmeal;
	int					ttd;
	int					tts;
	int					tte;
	int					neat;
	int					nphilo;
	u_int64_t			start;
	int					dead;
	int					finished;
	struct s_d			*data;
	pthread_t			task;
	pthread_mutex_t		*lfork;
	pthread_mutex_t		rfork;
}	t_philo;

/*Utils.c*/

//Return time of the day in MS
u_int64_t	get_time(void);
// Return lenght of string.
int			ft_strlen(char *s);
// End program and return error msg.
void		ft_error(char *msg);
//Used to initiate variable in struct.
void		*ft_memset(void *b, int c, size_t len);
//Set validated args inside struct.
void		data_init(t_d *data, char **av);

/* action.c*/

//Lock mutex associated to fork
void		pick_fork(t_philo *philo);
//Unlock mutex associated to fork
void		drop_fork(t_philo *philo);
//Output timestamp and action of philo
void		announcer(int state, t_philo *philo);
//Check if philo are alive
int			check_dead(t_philo *philo);

//Take a string and return it as int.
int			ft_atoi(const char *str);
// Check if arguments are valid format.
void		validate_args(char **av);

//Verify if philo has eaten total meal required (optional parameter)
int			is_finished(t_philo *philo);

/*Delete at end*/

//Print the parameter of the program
void		print_param(t_d *data);
//Clear data to end program
void		clear_sim(t_d *data);
//More precise usleep function
int			ft_usleep(useconds_t time);

//death.c
int			ft_dead(t_philo *philo);
// int			ft_dead(t_d *data);
void		ft_close(t_d *data);
int			ft_checkdead(t_philo *philo);
void		ft_death(t_d *data);
//utils3.c
void		set_philo(t_philo *philo, t_d *data, int i);

#endif