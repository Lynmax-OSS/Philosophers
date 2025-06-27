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

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal = get_time_in_ms();
	while (!philo->data->check_death)
	{
		if (philo->id % 2 == 0)
			usleep(200);
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
