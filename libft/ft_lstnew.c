/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:06:29 by keteo             #+#    #+#             */
/*   Updated: 2024/11/21 17:29:18 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*output;

	output = (t_list *)malloc(sizeof(t_list));
	if (!output)
		return (0);
	if (content)
		output -> content = content;
	else
		output -> content = NULL;
	output -> next = NULL;
	return (output);
}
