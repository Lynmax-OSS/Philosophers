/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:39:45 by keteo             #+#    #+#             */
/*   Updated: 2025/05/26 13:35:04 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchr_count(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putstr_count(char *args, int *count)
{
	int	i;

	i = 0;
	if (!args)
	{
		write(1, "(null)", 6);
		(*count) += 6;
		return ;
	}
	while (args[i] != '\0')
	{
		ft_putchr_count(args[i], count);
		i++;
	}
}
