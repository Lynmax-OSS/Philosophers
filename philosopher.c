/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:56:03 by keteo             #+#    #+#             */
/*   Updated: 2025/06/09 13:56:03 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	join_thread(t_data *data, int i)
{
	pthread_join(data->philo[i].thread, NULL);
}

void	destroy_mutexes(t_data *data, int i)
{
	pthread_mutex_destroy(&data->fork[i].mutex);
	pthread_mutex_destroy(&data->philo[i].meal_mutex);
}

int	main(int ac, char **av)
{
	t_data		data;
	int			i;

	if (parse_args(ac, av, &data))
		return (1);
	if (init(&data))
		return (1);
	start_simulation(&data);
	i = 0;
	while (i < data.nop)
		destroy_mutexes(&data, i++);
	pthread_mutex_destroy(&data.print_mutex);
	free (data.fork);
	free (data.philo);
	return (0);
}
