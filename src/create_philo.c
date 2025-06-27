/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:06:38 by keteo             #+#    #+#             */
/*   Updated: 2025/06/25 17:06:38 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void	create_philo(t_data *data)
{
	int	i;

	i = 0;
	if (data->nop == 1)
		pthread_create(&data->philo[i].thread,
			NULL, single_philo_routine, &data->philo[i]);
	else
	{
		while (i < data->nop)
		{
			pthread_create(&data->philo[i].thread,
				NULL, routine, &data->philo[i]);
			i++;
		}
	}
}
