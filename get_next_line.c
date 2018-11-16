/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:15:07 by mfierlaf          #+#    #+#             */
/*   Updated: 2018/11/16 14:38:37 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

int	get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			j;
	int			i;
	int			k;
	int 		ret;
	static char	*stock;
	char		*s[2];

	j = 0;
	k = 0;
	ret = 0;
	i = 0;
	if ((tmp = ft_strnew(0)) == NULL)
		return (-1);
	if (stock != NULL)
	{
		while (stock[i] != '\n' && stock[i] != '\0')
			i++;
		if (stock[i] == '\0')
		{
			s[0] = tmp;
			tmp = ft_strjoin(s[0], stock);
			free(s[0]);
			free(stock);
		}
		else
		{
			if ((s[0] = ft_strnew(i)) == NULL)
				return (-1);
			ft_strncpy(s[0], stock, i);
			s[1] = tmp;
			tmp = ft_strjoin(s[1], s[0]);
			free(s[0]);
			free(s[1]);
			if ((*line = ft_strnew(ft_strlen(tmp))) == NULL)
				return (-1);
			*line = ft_strcpy(*line, tmp);
			s[1] = stock;
			stock = ft_strsub(stock, i + 1, (ft_strlen(stock) - (i + 1)));
			free(s[1]);
			return (1);
		}
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		i = 0;
		buf[ret] = '\0';
		while (buf[i] != '\n' && buf[i] != '\0')
		{
			i++;
		}
		if (i == ret)
		{
			s[0] = tmp;
			tmp = ft_strjoin(tmp, buf);
			free(s[0]);
		}
		else
		{
			k = 0;
			buf[i] = '\0';
			s[0] = tmp;
			tmp = ft_strjoin(tmp, buf);
			free(s[0]);
			if ((*line = ft_strnew(ft_strlen(tmp))) == NULL)
				return (-1);
			*line = ft_strcpy(*line, tmp);
			free(tmp);
			if ((stock = ft_strnew(BUFF_SIZE)) == NULL)
			return (-1);
			i++;
			while (i < ret)
			{
				stock[k] = buf[i];
				k++;
				i++;
			}
			stock[k] = '\0';
			return (1);
		}
	}
	if (tmp != NULL)
	{
		if ((*line = ft_strnew(ft_strlen(tmp))) == NULL)
			return (-1);
		*line = ft_strjoin(*line, tmp);
	}
	return (0);
}
