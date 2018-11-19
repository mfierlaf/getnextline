/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:15:07 by mfierlaf          #+#    #+#             */
/*   Updated: 2018/11/19 09:36:54 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"
#include <limits.h>

char *ft_stock(char **line, char *stock)
{
	int i;
	char *s;

	i = 0;
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
			return (NULL);
		ft_strncpy(s, stock, i);
		*line = ft_strdup(s);
		ft_strdel(&s);
		s = stock;
		i++;
		stock = ft_strsub(s, i, (ft_strlen(stock) - (i)));
		ft_strdel(&s);
		return (stock);
	}
	return(NULL);
}

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

char *boucle(char **line, char *buf, char *stock, int fd)
{
	char *s;
	int i;
	int ret;

	i = 0;
	ret = 0;

	while ((ret = (read(fd, buf, BUFF_SIZE))) > 0)
	{
		i = 0;
		buf[ret] = '\0';
		while (buf[i] != '\n' && i < ret)
			i++;
		if (i == ret)
		{
			s = *line;
			*line = ft_strjoin(s, buf);
			ft_strdel(&s);
			if (ret < BUFF_SIZE)
				return (*line);
		}
		else
			if ((stock = endofl(buf, line, ret, stock)) != NULL)
				return (stock);
	}
	return (NULL);
}


int	get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char *stock;

	if ((*line = ft_strnew(0)) == NULL)
		return (-1);
	if (stock != NULL)
		if ((stock = ft_stock(line, stock)) != NULL)
			return (1);
	if ((stock = boucle(line, buf, stock, fd)) != NULL)
		return (1);
	ft_strdel(&stock);
	return (0);
}
