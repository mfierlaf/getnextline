/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:56:19 by mfierlaf          #+#    #+#             */
/*   Updated: 2018/11/22 10:32:32 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char *line;
	int fd ;
	int i;
	int fd3;
	int fd2;
	fd = open("test.txt", O_RDONLY);
	fd2 = open("get_next_line.c", O_RDONLY);
	fd3 = open("text.txt", O_RDONLY);
	line = NULL;
	int ret;
	i = 0;
	ret = 0;
	//get_next_line(fd, &line);
	//printf("%s\n", line);
	while ((ret  = get_next_line(fd, &line)) > 0)
	{

		printf("ID : [%d] %s\n", i,line);
		free(line);
		line = NULL;
		//get_next_line(fd2, &line);
		//printf("ND : [%d] %s\n", i,line);
		//free(line);
		i++;
	//	line = NULL;
	}
	return (0);
}
