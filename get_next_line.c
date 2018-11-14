/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:15:07 by mfierlaf          #+#    #+#             */
/*   Updated: 2018/11/14 11:15:22 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	static char	*stock;
	int			i;
	int			k;

	k = 0;
	i = 0;
	if ((stock = malloc(sizeof(char)* BUFF_SIZE)) == NULL)
		return (0);
	while (read(fd,buf,BUFF_SIZE) != 0)
	{
		while (buf[i] != '\n')
			i++;
		if ((tmp = malloc(sizeof(char)* i + 1)) == NULL)
			return (0);
		if (!buf[i])
		{
			if (tmp == NULL)
			{
				tmp = ft_strdup(buf);
				free(buf);
				tmp = ft_strjoin(stock, tmp);
				free(stock);
			}
			else
			{
				tmp = ft_strjoin(tmp, buf);
				free(buf);
				tmp = ft_strjoin(stock, tmp);
				free(stock);
			}
		}
		else
		{
			if (tmp == NULL)
			{
				i = 0;
				while(buf[i] != '\n')
				{
					tmp[i] = buf[i];
					i++;
				}
				tmp = ft_strjoin(stock, tmp);
			}
			else
				tmp = ft_strncat(tmp, buf, i);
			while (buf[i])
			{
				stock[k] = buf[i];
				i++;
				k++;
			}
			stock[k] = '\0';
			i = ft_strlen(tmp);
			tmp[i] = '\0';
			return (tmp);
		}
	}
}
