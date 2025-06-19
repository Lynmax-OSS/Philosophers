/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moniter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 02:07:26 by keteo             #+#    #+#             */
/*   Updated: 2025/06/19 02:07:26 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void	moniter_loop(t_data *data, int i)
{
	long	time_since_meal;

	time_since_meal = get_time_in_ms() - data->philo[i].last_meal;
	if (time_since_meal > data->ttd)
	{
		pthread_mutex_lock(&data->print_mutex)
		data->check_death = 1;
		printf("%ld %d died\n",
			get_time_in_ms() - data->start_time,
			data->philo[i].id);
		pthread_mutex_unlock(&data->print_mutex);
	}
}

void	moniter(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	i = 0;
	while (!data->check_death)
	{
		moniter_loop(data, i);
		i++;
		if (i >= data->nop)
			i = 0;
		usleep(1000);
	}
	return (NULL);
}
