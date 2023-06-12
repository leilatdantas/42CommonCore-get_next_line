/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:27:29 by lebarbos          #+#    #+#             */
/*   Updated: 2023/06/11 18:32:57 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_stash(int fd, char *stash)
{
	char	*buffer;
	int		bytes;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return(NULL);
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read (fd, buffer, BUFFER_SIZE);
		if (!buffer)
			return(NULL);
		buffer[bytes] = '\0';
		stash = ft_strjoin (stash, buffer);
	}
	if (bytes < 0)
	{
		free (stash);
		free (buffer);
		return (NULL);
	}
	free (buffer);
	return (stash);
}

static	void clean_stash(char **stash, char *line)
{
	char	*new_stash;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(line) + 1;
	new_stash = (char *)malloc(sizeof(char) * ft_strlen(*stash) - j + 1);
	while(i < ft_strlen(new_stash))
	{
		new_stash[i] = (*stash)[j];
		i++;
		j++;
	}
	new_stash[j + 1] = '\0';
	*stash = new_stash;
}

static char	*extract_line(char *stash)
{
	size_t	i;
	char	*line;
	char	*new_line;

	i = 0;
	new_line = ft_strchr(stash, '\n');
	line = malloc(sizeof(char) * ft_strlen(stash) - ft_strlen(new_line) + 1);
	while (i <= ft_strlen(line))
	{
		line[i] = stash[i];
		i++;
	}
	free (new_line);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
	line = extract_line(stash);
	clean_stash(&stash, line);
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