/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:24:58 by keteo             #+#    #+#             */
/*   Updated: 2025/06/17 13:24:58 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void	philo_state(t_philo *philo, char *action)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	if (!philo->data->check_death)
	{
		printf("%ld %d %s\n",
			get_time_in_ms() - philo->data->start_time,
			philo->id, action);
	}
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	pick_even_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->r_fork->mutex);
	philo_state(philo, "has taken a fork");
	pthread_mutex_lock(&philo->l_fork->mutex);
	philo_state(philo, "has taken a fork");
}

void	pick_odd_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->r_fork->mutex);
	philo_state(philo, "has taken a fork");
	pthread_mutex_lock(&philo->l_fork->mutex);
	philo_state(philo, "has taken a fork");
}

void	put_down_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->l_fork->mutex);
	pthread_mutex_unlock(&philo->r_fork->mutex);
}

void	pick_up_forks(t_philo *philo)
{
	int	even;

	even = (philo->id % 2 == 0);
	if (even)
		pick_even_fork(philo);
	else
		pick_odd_fork(philo);
}

void	*single_philo_routine(void *arg)
{
	t_philo					*philo;

	philo = (t_philo *)arg;
	philo_state(philo, "has taken a fork");
	precise_usleep(philo->data->ttd);
	philo_state(philo, "died");
	philo->data->check_death = 1;
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal = get_time_in_ms();
	while (!philo->data->check_death)
	{
		pick_up_forks(philo);
		philo_state(philo, "is eating");
		philo->last_meal = get_time_in_ms();
		precise_usleep(philo->data->tte);
		put_down_forks(philo);
		philo_state(philo, "is sleeping");
		precise_usleep(philo->data->tts);
		philo_state(philo, "is thinking");
	}
	return (NULL);
}
