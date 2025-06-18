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


typedef struct s_data
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

typedef struct s_philo
{
	int			id;
	long		last_meal;
	int			meals_eaten;
	t_fork		*l_fork;
	t_fork		*r_fork;
	pthread_t	thread;
	t_data		*data;
}	t_philo;

int		init(t_data *data, int ac, char **av);
void	philo_state(t_philo *philo, char *action);
long	get_time_in_ms(void);
void	precise_usleep(long ms);

#endif
