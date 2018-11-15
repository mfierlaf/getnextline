/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:15:07 by mfierlaf          #+#    #+#             */
/*   Updated: 2018/11/15 16:46:45 by mfierlaf         ###   ########.fr       */
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
	char		*s;

	j = 0;
	k = 0;
	ret = 0;
	i = 0;
	if ((tmp = ft_strnew(0)) == NULL)
		return (-1);
	if ((*line = ft_strnew(0)) == NULL)
		return (-1);
	if (stock != NULL)
	{
		//printf("stock %s\n", stock);
		while (stock[i] != '\n' && stock[i] != '\0')
			i++;
	//	printf("%d\n", 9);
		if (stock[i] == '\0')
		{
	//		printf("%s\n", stock);
			tmp = ft_strjoin(tmp, stock);
			free(stock);
	//		printf("%d\n", 10);
		}
		else
		{
			//printf("%d\n", 7);
			if ((s = ft_strnew(i)) == NULL)
				return (-1);
			ft_strncpy(s, stock, i);
	//		printf("%d\n", 2);
			tmp = ft_strjoin(tmp, s);
			free(s);
			*line = ft_strjoin(*line, tmp);
			stock = ft_strsub(stock, i + 1, (ft_strlen(stock) - (i + 1)));
			return (1);
		}
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
	//	printf("%d\n", 11);
		i = 0;
		buf[ret] = '\0';
		while (buf[i] != '\n' && buf[i] != '\0')
		{
		//	printf("SALUT\n");
			i++;
		}
		printf("ret; %d I; %d\n", ret, i);
		if (!buf[i])
		{
			printf("test\n");
			tmp = ft_strjoin(tmp, buf);			
			printf("C'est moi %s\n", tmp);
		}
		else
		{
			printf("Salut\n");
			k = 0;
			if ((s = ft_strnew(0)) == NULL)
				return (-1);
			buf[i] = '\0';
			printf("lol\n");
			tmp = ft_strjoin(tmp, buf);
			printf("tmp = %s\n", tmp);
			*line = ft_strjoin(*line, tmp);
			free(tmp);
			printf("%d\n", 1); 
			if ((stock = ft_strnew(BUFF_SIZE)) == NULL)
			return (-1);
			i++;
		//	printf("%d\n", 3);
			while (i < ret)
			{
		//		printf("%s\n", "boucle");
				stock[k] = buf[i];
				k++;
				i++;
			}
			stock[k] = '\0';
			printf("stock = %s\n", stock);
			return (1);
		}
	}
	return (0);
}