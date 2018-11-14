/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:56:19 by mfierlaf          #+#    #+#             */
/*   Updated: 2018/11/14 16:42:07 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char *line;
	int fd ;
	int res;
	fd = open("text.txt", O_RDONLY);
	res = get_next_line(fd, &line);
	printf("%d\n", res);
	printf("%s\n", line);
    res = get_next_line(fd, &line);
    printf("%d\n", res);
    printf("%s\n", line);
    res = get_next_line(fd, &line);
    printf("%d\n", res);
    printf("%s\n", line);
    res = get_next_line(fd, &line);
    printf("%d\n", res);
    printf("%s\n", line);
    res = get_next_line(fd, &line);
    printf("%d\n", res);
    printf("%s\n", line);
    res = get_next_line(fd, &line);
    printf("%d\n", res);
    printf("%s\n", line);
    res = get_next_line(fd, &line);
    printf("%d\n", res);
    printf("%s\n", line);
    res = get_next_line(fd, &line);
    printf("%d\n", res);
    printf("%s\n", line);
	return (0);
}
