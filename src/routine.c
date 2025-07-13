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
	set_ready(philo);
	while (!check_death(philo))
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
