/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:15:07 by mfierlaf          #+#    #+#             */
/*   Updated: 2018/11/14 17:11:22 by mfierlaf         ###   ########.fr       */
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
	static char	*stock;
	char		*s;
	j = 0;
	k = 0;
	i = 0;
	if ((tmp = ft_strnew(0)) == NULL)
		return (-1);
	if (stock != NULL)
	{
		while (stock[i] != '\n' && stock[i] != '\0')
			i++;
		if (stock[i] == '\0')
		{
			tmp = ft_strjoin(tmp, stock);
			free(stock);
		}
		else
		{
			s = ft_strnew(i);
			s = ft_strncpy(s, stock, i);
			tmp = ft_strjoin(tmp, s);
			free(s);
			*line = tmp;
			stock = ft_strsub(stock, i + 1, (ft_strlen(stock) - (i + 1)));
			return (1);
		}
	}
	while (read(fd,buf,BUFF_SIZE) != 0)
	{
		i = 0;
		while (buf[i] != '\n' && buf[i] != '\0')
			i++;		
		if (buf[i] == '\0')
		{
			tmp = ft_strjoin(tmp, buf);
		}
		else
		{
			k = 0;
			j = ft_strlen(tmp);
			while (k < i)
			{
				tmp[j + k] = buf[k];
				k++;
			}
			tmp[j + k] = '\0';
			ft_strcpy(*line, tmp);
			ft_strclr(tmp);
			k = 0;
			if((stock = malloc(sizeof(char) * (ft_strlen(buf) - i + 1))) == NULL)
				return (-1);
			while (buf[i])
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
