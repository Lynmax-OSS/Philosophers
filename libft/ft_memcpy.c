/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:48:19 by keteo             #+#    #+#             */
/*   Updated: 2024/11/11 16:00:30 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest_str, const void *src_str, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	d = (unsigned char *)dest_str;
	s = (const unsigned char *)src_str;
	if (!dest_str && !src_str && n > 0)
	{
		return (NULL);
	}
	while (n > i)
	{
		d[i] = s[i];
		i++;
	}
	return (dest_str);
}
