/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:44:44 by lebarbos          #+#    #+#             */
/*   Updated: 2023/06/11 18:24:38 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*#include <stdio.h>*/

char	*ft_strchr(char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	if (*str == '\0' && c == '\0')
		return (str);
	else
		return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_string;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1)
		return (s2);
	if (!s2)
		return(s1);
	new_string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_string)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		new_string[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
	{
		new_string[i + j] = s2[j];
		j++;
	}
	new_string[i + j] = '\0';
	return (new_string);
}

/* Tests
int main(void)
{
	char *str = "pudim";
	char *new_str = ft_strchr(str, 18);
	printf("%s", new_str);
}

int main(void)
{
	char	*s1 = "";
	char	*s2 = "vida";
	printf("Nova String: %s", ft_strjoin(s1, s2));
}
*/