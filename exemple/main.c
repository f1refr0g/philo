# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define NB	200

typedef struct s_main
{
	int				size;
	int				i;
	pthread_mutex_t	lock;
}	t_main;

typedef struct s_ph
{
	int		id;
	t_main	*data;
}	t_ph;

void	*task(void *in)
{
	t_ph	*ph;
	int		loop = 1;
	int		time = 0;

	ph = (t_ph *)in;
	if (ph->id % 2 == 0)
		usleep(500);
	while (loop)
	{
		usleep(500);
		pthread_mutex_lock(&ph->data->lock);
		if (ph->data->i < NB * 100)
		{
			printf("id %d eat %d\n", ph->id, ph->data->i);
			ph->data->i += 1;
			time++;
		}
		else
			loop = 0;
		pthread_mutex_unlock(&ph->data->lock);
	}
	printf("id %d time call = %d\n", ph->id, time);
	return (in);
}

int	main(void)
{
	t_main	info;
	info.i = 0;
	int		i = 0;
	pthread_t	t[NB];
	t_ph		ph[NB];

	pthread_mutex_init(&info.lock, NULL);
	while (i < NB)
	{
		ph[i].id = i + 1;
		ph[i].data = &info;
		i++;
	}
	i = 0;
	while (i < NB)
	{
		pthread_create(&t[i], NULL, &task, &ph[i]);
		i++;
	}
	i = 0;
	while (i < NB)
	{
		pthread_join(t[i] , NULL);
		i++;
	}
	pthread_mutex_destroy(&info.lock);
	return (0);
}