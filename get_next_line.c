/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:15:07 by mfierlaf          #+#    #+#             */
/*   Updated: 2018/11/18 15:57:31 by mfierlaf         ###   ########.fr       */
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
			free(s[0]);
			free(stock);
		}
		else
		{
			if ((s[0] = ft_strnew(i)) == NULL)
				return (-1);
			ft_strncpy(s[0], stock, i);
			s[1] = *line;
			*line = ft_strjoin(s[1], s[0]);
			free(s[0]);
			free(s[1]);
			s[1] = stock;
			stock = ft_strsub(stock, i + 1, (ft_strlen(stock) - (i + 1)));
			free(s[1]);
			return (1);
		}
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		printf ("ret = %d\n", ret);
		i = 0;
		buf[ret] = '\0';
		printf("buf = %s\n", buf);
		while (buf[i] != '\n' && i < ret)
		{
			i++;
		}
		printf("i = %d\n", i);
		if (i == ret)
		{
			printf("test");
			s[1] = *line;
			printf("s1 = %s\n", s[1]);
			*line = ft_strjoin(s[1], buf);
			printf("boucle = %s\n", *line);
			free(s[1]);
		}
		else
		{
			printf("alors\n");
			buf[i] = '\0';
			printf("check 0 = %s\n", buf);
			s[0] = *line;
			printf("s0 = %s\n", s[0]);
			*line = ft_strjoin(s[0], buf);
			printf("line 2 = %s\n", *line);
			free(s[0]);
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
		//	printf("stock = %s\n", stock);
			return (1);
		}
	}
	return (0);
}
