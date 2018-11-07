/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:15:07 by mfierlaf          #+#    #+#             */
/*   Updated: 2018/11/07 16:53:41 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	static char	*stock;
	int			i;
	int			j;

	i = 0;
	while (read(fd,buf,BUFF_SIZE) != 0)
	{
		while (buf[i] != '\n')
			i++;
		if (!buf[i])
		{
			if (tmp == NULL)
			{
				tmp = ft_strdup(buf);
				free(buf);
			}
			else
			{
				tmp = ft_strjoin(tmp, buf);
				free(buf);
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
			}
			else
				tmp = ft_strncat(tmp, buf, i);
			i = ft_strlen(tmp);
			tmp[i] = '\0';
			return (tmp);
		}
	}
}


char *ft_strndup(const char *src, char c)
{
	int		i;
	char	*cpy;
	int		size;

	i = 0;
	size = ft_strlen(src);
	if ((cpy = malloc(sizeof(char) * (size))) == NULL)
		return ((void*)0);
	while (i < size && src[i] != c)
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
