/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:15:07 by mfierlaf          #+#    #+#             */
/*   Updated: 2018/11/22 10:29:39 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		join(char **src, char *add)
{
	char *tmp;

	tmp = *src;
	if ((*src = ft_strjoin(tmp, add)) == NULL)
		return (-1);
	ft_strdel(&tmp);
	return (1);
}

char	*ft_stock(char **line, char *stock)
{
	int		i;
	char	*s;

	i = 0;
	while (stock[i] != '\n' && stock[i] != '\0')
		i++;
	if (stock[i] == '\0')
	{
		if (join(*&line, stock) == -1)
			return (NULL);
		ft_strdel(&stock);
	}
	else
	{
		if ((s = ft_strnew(i)) == NULL)
			return (ERROR);
		ft_strncpy(s, stock, i++);
		join(*&line, s);
		ft_strdel(&s);
		s = stock;
		stock = ft_strsub(s, i, (ft_strlen(stock) - (i)));
		ft_strdel(&s);
		return (stock);
	}
	return (NULL);
}

char	*endofl(char *buf, char **line, int ret, char *stock)
{
	int		k;
	int		i;

	i = 0;
	while (buf[i] != '\n' && i < ret)
		i++;
	k = 0;
	buf[i] = '\0';
	join(*&line, buf);
	if ((stock = ft_strnew(BUFF_SIZE)) == NULL)
		return (ERROR);
	i++;
	while (i < ret)
	{
		stock[k++] = buf[i++];
	}
	stock[k] = '\0';
	return (stock);
}

char	*boucle(char **line, char *buf, char *stock, int fd)
{
	int		i;
	int		ret;

	while ((ret = (read(fd, buf, BUFF_SIZE))) > 0)
	{
		i = 0;
		buf[ret] = '\0';
		while (buf[i] != '\n' && i < ret)
			i++;
		if (i == ret)
		{
			join(*&line, buf);
		}
		else
		{
			if ((stock = endofl(buf, line, ret, &stock[fd])) == ERROR)
				return (ERROR);
			else if (stock != NULL)
				return (stock);
		}
	}
	if (ret == -1)
		return (ERROR);
	return (NULL);
}

int		get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char *stock[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX || read(fd, buf, 0) == -1)
		return (-1);
	if ((*line = ft_strnew(0)) == NULL)
		return (-1);
	if (stock[fd] != NULL)
	{
		if ((stock[fd] = ft_stock(line, stock[fd])) == ERROR)
			return (-1);
		else if (stock[fd] != NULL)
			return (1);
	}
	if ((stock[fd] = boucle(line, buf, stock[fd], fd)) == ERROR)
		return (-1);
	else if (stock[fd] != NULL)
		return (1);
	if (*line[0] == '\0')
		return (0);
	return (1);
}
