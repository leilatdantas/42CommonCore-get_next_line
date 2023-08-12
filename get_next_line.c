/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:13:03 by lebarbos          #+#    #+#             */
/*   Updated: 2023/08/12 18:19:01 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * The function reads data from a file descriptor and appends it to a stash 
 * until a newline character is found or the end of the file is reached.
 * 
 * @param fd The parameter "fd" in the function "read_and_stash" represents the 
 * file descriptor of thefile that is being read from.
 * 
 * @param stash The `stash` parameter is a character pointer that represents a 
 * string where we want to store the data read from the file descriptor `fd`.
 * 
 * @return the updated value of the "stash" variable.
 */
static char	*read_and_stash(int fd, char *stash)
{
	char		*buffer;
	int			bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			free(stash);
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

/**
 * The function "extract_line" takes a string as input and returns a new string 
 * containing the characters up to the first newline character, including the 
 * newline character if it exists.
 * 
 * @param stash The `stash` parameter is a pointer to a string that contains 
 * multiple lines of text.
 * 
 * @return a pointer to a string that represents a line  extracted from the 
 * input string "stash".
 */
static char	*extract_line(char *stash)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
		line = malloc(sizeof(char) * (i + 1));
	else
		line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = -1;
	while (stash[++i] != '\0' && stash[i] != '\n')
		line[j++] = stash[i];
	if (stash[i] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

/**
 * The function "clean_stash" removes the first line from a string and returns 
 * the modified string.
 * 
 * @param stash The parameter "stash" is a pointer to a string that needs to be
 * cleaned.
 * 
 * @return a pointer to a new string that is a cleaned version of the input 
 * string "stash".
 */
static char	*clean_stash(char *stash)
{
	size_t	i;
	size_t	j;
	char	*new_stash;

	i = 0;
	j = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	new_stash = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	i++;
	while (stash[i] != '\0')
	{
		new_stash[j] = stash[i];
		j++;
		i++;
	}
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

/**
 * The function "get_next_line" reads a line from a file descriptor and returns 
 * it as a string.
 * 
 * @param fd The parameter "fd" stands for file descriptor. It is an integer 
 * value that represents an open file in the operating system. In this context, 
 * it is used to specify the file from which the function should read the next 
 * line.
 * 
 * @return a string, which represents the next line read from the file 
 * descriptor specified by `fd`.
 */
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = clean_stash(stash);
	return (line);
}

/*int	main(void)
{
	int		fd;
	char	*str;

	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	//printf("%s", str);
	close(fd);
	return (0);
}*/
