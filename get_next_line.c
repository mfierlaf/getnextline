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

int	get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			i;
	int			k;
	int 		ret;
	static char	*stock;
	char		*s[2];

	k = 0;
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
			s[0] = *line;
			*line = ft_strjoin(s[0], stock);
			ft_strdel(&s[0]);
			ft_strdel(&stock);
		}
		else
		{
			if ((s[0] = ft_strnew(i)) == NULL)
				return (-1);
			ft_strncpy(s[0], stock, i);
			*line = ft_strdup(s[0]);
			ft_strdel(&s[0]);
			s[0] = stock;
			i++;
			stock = ft_strsub(s[0], i, (ft_strlen(stock) - (i)));
			ft_strdel(&s[0]);
			return (1);
		}
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		i = 0;
		buf[ret] = '\0';
		while (buf[i] != '\n' && i < ret)
		{
			i++;
		}
		if (i == ret)
		{
			*line = ft_strjoin(*line, buf);
		}
		else
		{
			buf[i] = '\0';
			s[0] = *line;
			*line = ft_strjoin(*line, buf);
			ft_strdel(&s[0]);
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
	return (0);
}
