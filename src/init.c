/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:00:28 by keteo             #+#    #+#             */
/*   Updated: 2025/06/10 17:00:28 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"
#include <stdlib.h>

static int	int_atoi(char *s)
{
	int	i;
	long result;

	i = 0;
	result = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		result *= 10;
		result = result + (s[i] - '0');
		i++;
	}
	if (result > INT_MAX)
		return(-1);
	return ((int)result);
}

static int	set_philo(t_data *data, int i)
{

}

static int	setup(t_data *data)
{
	int	i;

	i = 0;
	data->fork = malloc(sizeof(t_fork) * data->nop);
	data->philo = malloc(sizeof(t_philo) * data->nop);
	if (!data->fork || !data->philo)
		return (0);
	pthread_mutex_init(&data->print_mutex, NULL);
	while (i < data->nop)
	{
		set_philo(data, i);
		i++;
	}
	return(1);
}

int	init(t_data *data, int ac, char **av)
{
	if (ac != 5)
	{
		write(2, "./philo: <philo> <die> <eat> <sleep>\n", 38);
		return (0);
	}
	data->nop = int_atoi(av[1]);
	data->ttd = int_atoi(av[2]);
	data->tte = int_atoi(av[3]);
	data->tts = int_atoi(av[4]);
	data->check_death = 0;
	if (!setup(data))
		return (0);
	return (1);
}
