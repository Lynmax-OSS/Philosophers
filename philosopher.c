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
}

int	main(int ac, char **av)
{
	t_data		data;
	pthread_t	moniter_thread;
	int			i;

	if (init(&data, ac, av))
		return(1);
	data.start_time = get_time_in_ms();
	create_philo(&data);
	pthread_create(&moniter_thread, NULL, moniter, &data);
	pthread_join(moniter_thread, NULL);
	i = 0;
	while (i < data.nop)
		join_thread(&data, i++);
	i = 0;
	while (i < data.nop)
		destroy_mutexes(&data, i++);
	pthread_mutex_destroy(&data.print_mutex);
	free (data.fork);
	free (data.philo);
	return (0);
}
