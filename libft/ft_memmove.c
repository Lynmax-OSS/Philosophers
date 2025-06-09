/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:28:44 by keteo             #+#    #+#             */
/*   Updated: 2024/11/11 15:57:45 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest_str, const void *src_str, size_t numBytes)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest_str;
	s = (const unsigned char *)src_str;
	if (!dest_str && !src_str && numBytes > 0)
	{
		return (NULL);
	}
	if (d > s && d < s + numBytes)
	{
		while (numBytes--)
		{
			d[numBytes] = s[numBytes];
		}
	}
	else
	{
		while (numBytes--)
		{
			*d++ = *s++;
		}
	}
	return (dest_str);
}
