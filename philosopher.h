#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>

typedef struct	s_fork
{
	pthread_mutex_t mutex;
}	t_fork;


typedef struct	s_data
{
	long			start_time;
	int				nop;
	int				ttd;
	int				tte;
	int				tts;
	int				check_death;
	pthread_mutex_t	print_mutex;
	t_fork			*fork;
	t_philo			*philo;
}	t_data;

typedef struct	s_philo
{
	int			id;
	long		last_meal;
	int			meals_eaten;
	t_fork		*L_fork;
	t_fork		*R_fork;
	pthread_t	thread;
	t_data		*data;
}	t_philo;
#endif
