/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:44:44 by lebarbos          #+#    #+#             */
/*   Updated: 2023/08/12 18:13:46 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * The function ft_strchr searches for a specific character in a string and 
 * returns a pointer to the first occurrence of that character.
 * 
 * @param str The parameter "str" is a pointer to a constant character string. 
 * It represents the string in which we want to search for the character "c".
 * 
 * @param c The parameter "c" is the character that we are searching for in the 
 * string "str".
 * 
 * @return The function `ft_strchr` returns a pointer to the first occurrence 
 * of the character `c` in the string `str`. If the character is found, the 
 * function returns a pointer to that character. If the character is not found, 
 * the function returns NULL.
 */

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while ((unsigned char)str[i] != (unsigned char)c && str[i])
		i++;
	if ((unsigned char)c == (unsigned char)str[i])
		return ((char *)(str + i));
	return (NULL);
}

/**
 * The function ft_strlen calculates the length of a string by iterating 
 * through each character until it reaches the null terminator.
 * 
 * @param str The parameter "str" is a pointer to a character array (string).
 * 
 * @return the length of the string `str` as a `size_t` value.
 */
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/**
 * The function `ft_strjoin` concatenates two strings and returns a new string.
 * 
 * @param s1 A pointer to a character array (string) that represents the first 
 * part of the string to be joined.
 * @param s2 s2 is a pointer to a constant character string.
 * 
 * @return a pointer to a newly allocated string that is the result of 
 * concatenating s1 and s2.
 */
char	*ft_strjoin(char *s1, char const *s2)
{
	char	*new_string;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	new_string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_string)
		return (NULL);
	i = -1;
	while (s1[++i])
		new_string[i] = s1[i];
	j = -1;
	while (s2[++j])
		new_string[i + j] = s2[j];
	free(s1);
	new_string[i + j] = '\0';
	return (new_string);
}
