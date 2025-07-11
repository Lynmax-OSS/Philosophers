/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:33:11 by keteo             #+#    #+#             */
/*   Updated: 2025/07/11 16:01:45 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int	set_full(t_philo *philo)
{
	if (philo->data->meal_limit > 0 && philo->meals_eaten
		>= philo->data->meal_limit && philo->full != 1)
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

void	waiting(t_philo *philo)
{
	int	flag;

	flag = 0;
	while (!flag)
	{
		pthread_mutex_lock(&philo->data->start);
		flag = philo->data->start_flag;
		pthread_mutex_unlock(&philo->data->start);
		precise_usleep(100);
	}
}

int	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death_mutex);
	if (philo->data->check_death)
	{
		pthread_mutex_unlock(&philo->data->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->death_mutex);
	return (0);
}

void	set_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = get_time_in_ms();
	pthread_mutex_unlock(&philo->meal_mutex);
}
