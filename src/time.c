/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:10:03 by keteo             #+#    #+#             */
/*   Updated: 2025/06/10 13:10:03 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

long	get_time_in_ms(void)
{
	struct	timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	precise_usleep(long ms)
{
	long	start;

	start = get_time_in_ms();
	while ((get_time_in_ms() - start) < ms)
		usleep(500);
}

// int main(void)
// {
// 	long	time = get_time();
// 	printf("%li\n", time);
// }