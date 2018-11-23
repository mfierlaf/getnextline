/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:58:27 by mfierlaf          #+#    #+#             */
/*   Updated: 2018/10/19 16:12:21 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s, const char *s2)
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
	while (hay[i] != '\0')
	{
		j = 0;
		while (hay[i + j] == needle[j] && hay[i + j] != '\0')
		{
			j++;
		}
		if (needle[j] == '\0')
			return (hay + i);
		i++;
	}
	return ((void*)0);
}
