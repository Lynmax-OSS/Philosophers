/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:59:57 by keteo             #+#    #+#             */
/*   Updated: 2025/06/10 12:59:57 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_fork
{
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				id;
	long			last_meal;
	int				meals_eaten;
	int				full;
	t_fork			*l_fork;
	t_fork			*r_fork;
	pthread_t		thread;
	t_data			*data;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	full_mutex;
}	t_philo;

typedef struct s_data
{
	long			start_time;
	int				nop;
	int				ttd;
	int				tte;
	int				tts;
	int				check_death;
	int				meal_limit;
	int				reach_limit;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	limit_mutex;
	t_fork			*fork;
	t_philo			*philo;
}	t_data;

int		init(t_data *data);
int		parse_args(int argc, char **argv, t_data *data);
int		start_simulation(t_data *data);
int		check_full(t_philo *philo);
void	philo_state(t_philo *philo, char *action);
long	get_time_in_ms(void);
void	precise_usleep(long ms);
void	setup_philo(t_data *data);
void	make_thread(t_data *data);
void	philo_state(t_philo *philo, char *action);
void	pick_even_fork(t_philo *philo);
void	pick_odd_fork(t_philo *philo);
void	put_down_forks(t_philo *philo);
void	pick_up_forks(t_philo *philo);
void	*routine(void *arg);
void	*single_philo_routine(void *arg);
void	*monitor(void *arg);

#endif
