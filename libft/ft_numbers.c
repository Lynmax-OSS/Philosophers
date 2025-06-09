/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:34:34 by keteo             #+#    #+#             */
/*   Updated: 2025/05/26 13:34:44 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_count(int nb, int *count)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*count) += 11;
		return ;
	}
	if (nb < 0)
	{
		ft_putchr_count('-', count);
		ft_putnbr_count(nb * -1, count);
	}
	else
	{
		if (nb > 9)
			ft_putnbr_count(nb / 10, count);
		ft_putchr_count(nb % 10 + '0', count);
	}
}

void	ft_putunnbr_count(unsigned int nb, int *count)
{
	if (nb > 9)
		ft_putunnbr_count(nb / 10, count);
	ft_putchr_count(nb % 10 + '0', count);
}

void	ft_putptr_count(size_t ptr, int *count)
{
	char	str[25];
	int		i;
	char	*base_char;

	base_char = "0123456789abcdef";
	i = 0;
	if (ptr == 0)
	{
		ft_putstr_count("(nil)", count);
		return ;
	}
	ft_putstr_count("0x", count);
	while (ptr != 0)
	{
		str[i] = base_char[ptr % 16];
		ptr = ptr / 16;
		i++;
	}
	while (i--)
		ft_putchr_count(str[i], count);
}

void	ft_puthex_count(unsigned int hex, int *count, char x_or_x)
{
	char	str[25];
	int		i;
	char	*base_char;

	if (x_or_x == 'X')
		base_char = "0123456789ABCDEF";
	else
		base_char = "0123456789abcdef";
	i = 0;
	if (hex == 0)
	{
		ft_putchr_count('0', count);
		return ;
	}
	while (hex != 0)
	{
		str[i] = base_char[hex % 16];
		hex = hex / 16;
		i++;
	}
	while (i--)
		ft_putchr_count(str[i], count);
}
