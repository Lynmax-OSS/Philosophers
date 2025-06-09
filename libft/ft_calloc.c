/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:40:56 by keteo             #+#    #+#             */
/*   Updated: 2024/11/12 18:07:48 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	t;

	t = nmemb * size;
	ptr = malloc(t);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ft_memset(ptr, 0, t);
	return (ptr);
}
