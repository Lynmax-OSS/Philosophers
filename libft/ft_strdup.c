/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:19:02 by keteo             #+#    #+#             */
/*   Updated: 2024/11/12 18:06:51 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	s_len;
	char	*ss;
	size_t	i;

	i = 0;
	s_len = ft_strlen(s);
	ss = (char *)malloc(sizeof(char) * (s_len + 1));
	if (ss == NULL)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		ss[i] = s[i];
		i++;
	}
	ss[i] = '\0';
	return (ss);
}
