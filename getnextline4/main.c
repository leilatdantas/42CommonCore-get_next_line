/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:38:27 by lebarbos          #+#    #+#             */
/*   Updated: 2023/06/13 11:56:55 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	int fd;
	char	*str;
	fd = open("test.txt", O_RDONLY);
	str = (char *)-1;
    
	while(str != NULL)
	{
        str = get_next_line(fd);
		printf("%s", str);
		free(str);
	}
	close(fd);
	return(0);
}