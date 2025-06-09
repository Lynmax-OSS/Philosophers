/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:40:45 by keteo             #+#    #+#             */
/*   Updated: 2025/05/26 13:34:50 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_frmtchecker(char frmt, va_list *args, int *len, int *i)
{
	if (frmt == 's')
		ft_putstr_count(va_arg(*args, char *), len);
	else if (frmt == 'c')
		ft_putchr_count(va_arg(*args, int), len);
	else if (frmt == 'd' || frmt == 'i')
		ft_putnbr_count(va_arg(*args, int), len);
	else if (frmt == 'x')
		ft_puthex_count(va_arg(*args, unsigned int), len, 'x');
	else if (frmt == 'X')
		ft_puthex_count(va_arg(*args, unsigned int), len, 'X');
	else if (frmt == 'u')
		ft_putunnbr_count(va_arg(*args, unsigned int), len);
	else if (frmt == 'p')
		ft_putptr_count(va_arg(*args, size_t), len);
	else if (frmt == '%')
		ft_putchr_count('%', len);
	else
		(*i)--;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			ft_frmtchecker(format[i], &args, &count, &i);
			i++;
		}
		else
		{
			ft_putchr_count((char)format[i], &count);
			i++;
		}
	}
	va_end(args);
	return (count);
}

// int	main()
// {
// 	printf("s\nDefault: %s\n", "Clearly you don't own an airfryer.");
// 	ft_printf("Custom: %s\n", "Clearly you don't own an airfryer.");

// 	printf("c\nDefault: %c\n",'L');
// 	ft_printf("Custom: %c\n", 'L');

// 	printf("d\nDefault: %d\n", 420);
// 	ft_printf("Custom: %d\n", 420);

// 	printf("i\nDefault: %i\n", 69);
// 	ft_printf("Custom: %i\n", 69);

// 	printf("u\nDefault: %u\n", 42949672);
// 	ft_printf("Custom: %u\n", 42949672);

// 	printf("x\nDefault: %x\n", -10);
// 	ft_printf("Custom: %x\n", -10);

// 	printf("X\nDefault: %X\n", 17);
// 	ft_printf("Custom: %X\n", 17);

// 	printf("p\nDefault: %p\n", -1);
// 	ft_printf("Custom: %p\n", -1);

// 	printf("%%\nDefault: %%\n");
// 	ft_printf("Custom: %%\n");
// 	return (0);
// }