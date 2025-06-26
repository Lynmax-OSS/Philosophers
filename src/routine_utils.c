/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:07:35 by keteo             #+#    #+#             */
/*   Updated: 2025/06/26 13:08:18 by keteo            ###   ########.fr       */
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
