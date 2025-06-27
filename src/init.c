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

int	validate_args(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
			{
				write(2, "Error: invalid argument\n", 25);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	int_atoi(char *s)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		result *= 10;
		result = result + (s[i] - '0');
		i++;
	}
	if (result > INT_MAX)
		return (-1);
	return ((int)result);
}

static void	set_philo(t_data *data, int i)
{
	pthread_mutex_init(&data->fork[i].mutex, NULL);
	pthread_mutex_init(&data->philo[i].meal_mutex, NULL);
	data->philo[i].id = i + 1;
	data->philo[i].l_fork = &data->fork[i];
	data->philo[i].r_fork = &data->fork[(i + 1) % data->nop];
	data->philo[i].data = data;
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
	return (1);
}

int	init(t_data *data, int ac, char **av)
{
	if (ac != 5)
	{
		write(2, "./philo: <philo> <die> <eat> <sleep>\n", 38);
		return (0);
	}
	if (validate_args(av))
		return (1);
	data->nop = int_atoi(av[1]);
	data->ttd = int_atoi(av[2]);
	data->tte = int_atoi(av[3]);
	data->tts = int_atoi(av[4]);
	data->check_death = 0;
	if (data->nop <= 0 || data->ttd <= 0 || data->tte <= 0 || data->tts <= 0)
	{
		write(2, "Error: arguments must be positive integers\n", 44);
		return (1);
	}
	if (!setup(data))
		return (1);
	return (0);
}
