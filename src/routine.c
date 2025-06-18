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

void	routine(void *arg)
{
	t_philo	philo;

	pthread_mutex_lock(philo.l_fork);
	pthread_mutex_lock(philo.r_fork);
	philo_state(philo.id + 1, get_time_in_ms() - philo.data->start_time, "is eating");
	pthread_mutex_unlock(philo.l_fork);
	pthread_mutex_unlock(philo.r_fork);
	philo_state(philo.id + 1, get_time_in_ms() - philo.data->start_time, "is sleeping");
}
