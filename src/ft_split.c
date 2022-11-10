/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:33:59 by minseok2          #+#    #+#             */
/*   Updated: 2022/07/15 12:33:13 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	**allocate_splited_str(char const *s, char c)
{
	char	**splited_str;
	size_t	word_count;

	word_count = 0;
	if (s == NULL)
		return (NULL);
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if (*s != c)
		{
			word_count++;
			while (*s && *s != c)
				s++;
		}
		while (*s && *s == c)
			s++;
	}
	splited_str = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (splited_str == NULL)
		return (NULL);
	return (splited_str);
}

static char	*cut_each_str(char const *s, char c)
{
	char	*str;
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	**free_all(char **splited_str, int i)
{
	while (--i > 0)
		free(splited_str[i]);
	free(splited_str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**splited_str;
	size_t	i;

	i = 0;
	splited_str = allocate_splited_str(s, c);
	if (splited_str == NULL)
		return (NULL);
	while (*s && *s == c)
		s++;
	while (*s)
	{
		splited_str[i] = cut_each_str(s, c);
		if (splited_str == NULL)
			return (free_all(splited_str, i));
		while (*s != c && *s)
			s++;
		while (*s && *s == c)
			s++;
		i++;
	}
	splited_str[i] = NULL;
	return (splited_str);
}
