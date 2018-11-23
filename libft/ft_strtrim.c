/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 13:43:16 by mfierlaf          #+#    #+#             */
/*   Updated: 2018/10/23 16:51:59 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*cpy;
	int		i;
	int		j;
	int		k;

	if (s == NULL)
		return (NULL);
	k = 0;
	i = 0;
	j = 0;
	while (s[j] != '\0')
		j++;
	while ((s[i] == '\t' || s[i] == '\n' || s[i] == ' ') && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (ft_strnew(0));
	while (s[j] == '\t' || s[j] == '\n' || s[j] == ' ' || s[j] == '\0')
		j--;
	if ((cpy = (char*)malloc(sizeof(char) * (j - i + 2))) == NULL)
		return ((void*)0);
	while (i <= j)
		cpy[k++] = s[i++];
	cpy[k++] = '\0';
	return (cpy);
}
