/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:44:44 by lebarbos          #+#    #+#             */
/*   Updated: 2023/06/13 09:24:42 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*#include <stdio.h>*/

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != c && str[i])
		i++;
	if (c == str[i])
		return ((char *)(str + i));
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_string;
	size_t	i;
	size_t	j;

	new_string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_string)
		return (NULL);
	i = 0;
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