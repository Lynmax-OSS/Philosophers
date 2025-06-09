/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:50:16 by keteo             #+#    #+#             */
/*   Updated: 2024/11/18 19:25:09 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_number_size(int number)
{
	unsigned int	length;

	length = 0;
	if (number == 0)
		return (1);
	if (number < 0)
		length += 1;
	while (number != 0)
	{
		number /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				length;
	long			numbers;

	numbers = n;
	length = ft_number_size(n);
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	if (numbers < 0)
		numbers *= -1;
	str[length--] = '\0';
	while (numbers > 0)
	{
		str[length--] = (numbers % 10) + '0';
		numbers = numbers / 10;
	}
	if (n < 0)
		str[length] = '-';
	if (n == 0)
		str[length] = '0';
	return (str);
}
