/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:49:46 by keteo             #+#    #+#             */
/*   Updated: 2025/07/01 15:10:51 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void	setup_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nop)
	{
		data->philo[i].id = i + 1;
		data->philo[i].meals_eaten = 0;
		data->philo[i].l_fork = &data->fork[i];
		data->philo[i].r_fork = &data->fork[(i + 1) % data->nop];
		data->philo[i].data = data;
		data->philo[i].full = 0;
		pthread_mutex_init(&data->philo[i].meal_mutex, NULL);
		pthread_mutex_init(&data->philo[i].full_mutex, NULL);
		i++;
	}
}

void	make_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nop)
	{
		pthread_create(&data->philo[i].thread, NULL,
			routine, &data->philo[i]);
		i++;
	}
}
