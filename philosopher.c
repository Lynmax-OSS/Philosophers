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

int	main(int ac, char **av)
{
	t_philo philosopher;

	if (ac != 5)
		write(2, "./philo: <philo> <die> <eat> <think>\n", 38);
	
}
