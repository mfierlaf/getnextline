/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:15:07 by mfierlaf          #+#    #+#             */
/*   Updated: 2018/11/18 21:30:09 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"
#include <limits.h>

char	*endofl(char *buf, char **line, int ret, char *stock)
{
	int k;
	int i;
	char *s;

	i = 0;
	while (buf[i] != '\n' && i < ret)
		i++;
	k = 0;
	buf[i] = '\0';
	s = *line;
	*line = ft_strjoin(*line, buf);
	ft_strdel(&s);
	if ((stock = ft_strnew(BUFF_SIZE)) == NULL)
		return (NULL);
	i++;
	while (i < ret)
	{
		stock[k] = buf[i];
		k++;
		i++;
	}
	stock[k] = '\0';
	return (stock);
}

int	get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			i;
	int 		ret;
	static char *stock;
	char		*s;

	ret = 0;
	i = 0;
	if ((*line = ft_strnew(0)) == NULL)
		return (-1);
	if (stock != NULL)
	{
		while (stock[i] != '\n' && stock[i] != '\0')
			i++;
		if (stock[i] == '\0')
		{
			s = *line;
			*line = ft_strjoin(s, stock);
			ft_strdel(&s);
			ft_strdel(&stock);
		}
		else
		{
			if ((s = ft_strnew(i)) == NULL)
				return (-1);
			ft_strncpy(s, stock, i);
			*line = ft_strdup(s);
			ft_strdel(&s);
			s = stock;
			i++;
			stock = ft_strsub(s, i, (ft_strlen(stock) - (i)));
			ft_strdel(&s);
			return (1);
		}
	}
	while ((ret = (read(fd, buf, BUFF_SIZE))) > 0)
	{
		i = 0;
		buf[ret] = '\0';
		while (buf[i] != '\n' && i < ret)
		{
			i++;
		}
		if (i == ret)
		{
			s = *line;
			*line = ft_strjoin(s, buf);
			ft_strdel(&s);
		}
		else
		{
			if ((stock = endofl(buf, line, ret, stock)) != NULL)
				return (1);
		}
	}
	return (0);
}
