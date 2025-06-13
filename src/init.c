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

int	int_atoi(char *s)
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

int	init(t_data *data, int ac, char **av)
{
	if (ac != 5)
	{
		write(2, "./philo: <philo> <die> <eat> <sleep>\n", 38);
		return (1);
	}
	data->philo = int_atoi(av[1]);
	data->ttd = int_atoi(av[2]);
	data->tte = int_atoi(av[3]);
	data->tts = int_atoi(av[4]);
	return (0);
}