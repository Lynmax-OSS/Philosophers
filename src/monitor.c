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

void	moniter_loop(t_data *data, int i, int *full_count)
{
	long	last_meal;
	long	time_since_meal;

	pthread_mutex_lock(&data->philo[i].meal_mutex);
	last_meal = data->philo[i].last_meal;
	if (data->philo[i].full)
	{
		printf("philo %d is full\n", data->philo->id);
		(*full_count)++;
	}
	pthread_mutex_unlock(&data->philo[i].meal_mutex);
	time_since_meal = get_time_in_ms() - last_meal;
	if (time_since_meal > data->ttd)
	{
		pthread_mutex_lock(&data->print_mutex);
		data->check_death = 1;
		printf("%ld %d died\n",
			get_time_in_ms() - data->start_time,
			data->philo[i].id);
		pthread_mutex_unlock(&data->print_mutex);
	}
}

void	*monitor(void *arg)
{
	t_data	*data;
	int		i;
	int		full_count;

	data = (t_data *)arg;
	i = 0;
	while (!data->check_death)
	{
		full_count = 0;
		moniter_loop(data, i, &full_count);
		i++;
		if (i >= data->nop)
		{
			i = 0;
			if (data->meal_limit > 0 && full_count >= data->nop)
			{
				printf("All philosophers ate enough. Ending simulation.\n");
				data->reach_limit = 1;
				break;
			}
		}
		precise_usleep(1000);
	}
	return (NULL);
}
