/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 17:14:29 by mfierlaf          #+#    #+#             */
/*   Updated: 2018/10/23 16:50:00 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *s2, size_t len)
{
	char	*hay;
	char	*needle;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	hay = (char*)s;
	needle = (char*)s2;
	if (ft_strlen(needle) == 0)
		return (hay);
	while (i < len)
	{
		j = 0;
		while (hay[i + j] == needle[j] && hay[i + j] != '\0' && (i + j) < len)
			j++;
		if (needle[j] == '\0')
			return (hay + i);
		i++;
	}
	return ((void*)0);
}
