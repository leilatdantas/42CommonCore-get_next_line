/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:13:03 by lebarbos          #+#    #+#             */
/*   Updated: 2023/06/12 16:33:47 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_stash(int fd, char *stash)
{
	char		*buffer;
	int			bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while(!ft_strchr(stash, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(stash);
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		if (!buffer)
			return (NULL);
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

static char	*extract_line(char *stash)
{
	char	*line;
	char	*next_line;
	size_t	size_line;
	size_t	i;

	i = 0;
	next_line = ft_strchr(stash, '\n');
	size_line = ft_strlen(stash) - ft_strlen(next_line) + 2;
	line = malloc(sizeof(char) * size_line);
	if(!line)
		return (NULL);
	while (i < size_line - 1)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	free(next_line);
	return(line);
}

static char	*clean_stash(char *stash)
{
	char	*new_stash;
	char	*next_line;
	size_t	i;
	size_t	j;
	
	next_line = ft_strchr(stash, '\n');
	if (!next_line)
	{
		free(stash);
		return (NULL);
	}
	new_stash = malloc(sizeof(char) * ft_strlen(next_line));
	j = ft_strlen(stash) - ft_strlen(next_line) + 1;
	i = 0;
	while (i < j)
	{
		new_stash[i] = stash[j + i];
		i++;
	}
	new_stash[i] = '\0';
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = read_and_stash(fd, stash);
	if(!stash)
		return (NULL);
	line = extract_line(stash);
	stash = clean_stash(stash);
	return (line);
}

// int main(void)
// {
// 	int fd;
// 	char	*str;
	
// 	fd = open("test.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	printf("Line: %s", str);
// }