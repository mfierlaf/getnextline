/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:56:19 by mfierlaf          #+#    #+#             */
/*   Updated: 2018/11/15 16:20:57 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char *line;
	int fd ;
	fd = open("get_next_line.c", O_RDONLY);
	line = NULL;
	int ret;
	get_next_line(fd, &line);
	/*while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("line = %s\n", line);
		free(line);
		line = NULL;
	}*/
	return (0);
}
