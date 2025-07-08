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

int	set_full(t_philo *philo)
{
	if (philo->data->meal_limit > 0 && philo->meals_eaten
		== philo->data->meal_limit && philo->full != 1)
	{
		pthread_mutex_lock(&philo->full_mutex);
		philo->full = 1;
		pthread_mutex_unlock(&philo->full_mutex);
		return (0);
	}
	return (1);
}

void	philo_eating(t_philo *philo)
{
	philo_state(philo, "is eating");
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = get_time_in_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
	precise_usleep(philo->data->tte);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->data->check_death)
	{
		if (!set_full(philo))
			return (NULL);
		if (philo->id % 2 == 0)
			precise_usleep(100);
		pick_up_forks(philo);
		philo_eating(philo);
		put_down_forks(philo);
		if (!set_full(philo))
			return (NULL);
		philo_state(philo, "is sleeping");
		precise_usleep(philo->data->tts);
		if (!set_full(philo))
			return (NULL);
		philo_state(philo, "is thinking");
		if (philo->data->nop % 2 != 0 && philo->id % 2 == 1)
			precise_usleep(philo->data->tte / 2);
	}
	return (NULL);
}

// void	*routine(void *arg)
// {
// 	t_philo					*philo;

// 	philo = (t_philo *)arg;
// 	usleep((philo->id % 5) * 200);
// 	pthread_mutex_lock(&philo->meal_mutex);
// 	philo->last_meal = get_time_in_ms();
// 	pthread_mutex_unlock(&philo->meal_mutex);
// 	while (!philo->data->check_death && !philo->data->reach_limit)
// 	{
// 		pick_up_forks(philo);
// 		philo_state(philo, "is eating");
// 		pthread_mutex_lock(&philo->meal_mutex);
// 		philo->last_meal = get_time_in_ms();
// 		philo->meals_eaten++;
// 		pthread_mutex_unlock(&philo->meal_mutex);
// 		precise_usleep(philo->data->tte);
// 		put_down_forks(philo);
// 		philo_state(philo, "is sleeping");
// 		precise_usleep(philo->data->tts);
// 		philo_state(philo, "is thinking");
// 		usleep(500);
// 	}
// 	return (NULL);
// }
