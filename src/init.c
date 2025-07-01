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

static int	validate_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				write(2, "Error: arguments not integers\n", 31);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	parse_args(int argc, char **argv, t_data *data)
{
	if (argc < 5 || argc > 6)
	{
		write(2, "Error: Not enough arguments\n", 29);
		return (1);
	}
	if (validate_args(argc, argv))
		return (1);
	data->nop = int_atoi(argv[1]);
	data->ttd = int_atoi(argv[2]);
	data->tte = int_atoi(argv[3]);
	data->tts = int_atoi(argv[4]);
	data->meal_limit = -1;
	if (argc == 6)
		data->meal_limit = int_atoi(argv[5]);
	if (data->nop <= 0 || data->ttd <= 0 || data->tte <= 0 || data->tts <= 0
		|| (argc == 6 && data->meal_limit <= 0))
	{
		write(2, "Error: arguments must be positive integers\n", 44);
		return (1);
	}
	return (0);
}

int	init(t_data *data)
{
	int	i;

	i = 0;
	data->check_death = 0;
	data->reach_limit = 0;
	pthread_mutex_init(&data->print_mutex, NULL);
	data->fork = malloc(sizeof(t_fork) * data->nop);
	data->philo = malloc(sizeof(t_philo) * data->nop);
	if (!data->fork || !data->philo)
		return (1);
	while (i < data->nop)
	{
		pthread_mutex_init(&data->fork[i].mutex, NULL);
		i++;
	}
	i = 0;
	setup_philo(&data);
	return (0);
}

int	start_simulation(t_data *data)
{
	int			i;
	pthread_t	monitor_thread;

	data->start_time = get_time_in_ms();
	i = 0;
	if (data->nop == 1)
	{
		pthread_create(&data->philo[0].thread, NULL,
			single_philo_routine, &data->philo[0]);
		pthread_join(data->philo[0].thread, NULL);
		return (0);
	}
	make_thread(&data);
	pthread_create(&monitor_thread, NULL, monitor, data);
	pthread_join(monitor_thread, NULL);
	i = 0;
	while (i < data->nop)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
	return (0);
}
