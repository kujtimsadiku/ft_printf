/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:20:24 by ksadiku           #+#    #+#             */
/*   Updated: 2021/12/02 20:05:07 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(char const *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			words++;
		i++;
	}
	return (words);
}

static char	**ft_free_arr(char **array, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		ft_bzero((void *)array[i], words);
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static char	**ft_str_add(char **fresh, const char *s, char c, int wordcount)
{
	int	holder;
	int	start;
	int	i;

	holder = 0;
	start = 0;
	i = 0;
	while (holder < wordcount)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		fresh[holder] = ft_strsub(s, start, i - start);
		if (!fresh[holder])
			return (ft_free_arr(fresh, wordcount));
		holder++;
	}
	return (fresh);
}

char	**ft_strsplit(char const *s, char c)
{
	int		start;
	int		holder;
	char	**fresh;

	start = 0;
	holder = 0;
	if (!s || !c)
		return (NULL);
	fresh = (char **)malloc(sizeof(char *) * (ft_len(s, c) + 1));
	if (!fresh)
		return (NULL);
	fresh = ft_str_add(fresh, s, c, ft_len(s, c));
	if (!fresh)
		return (NULL);
	fresh[ft_len(s, c)] = 0;
	return (fresh);
}
/*
static int	wordcnt(char *str, char c)
{
	int	word_count;
	int	i;

	word_count = 0;
	i = 0;
	if (str[0] != c)
		word_count++;
	while (str[i])
	{
		if (str[i] != c && str[i - 1] == c)
			word_count++;
		i++;
	}
	return (word_count);
}

static char	**ft_split(char **dest, char *str, char c)
{
	int		i;
	int		word;
	size_t	len;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			len = ft_strlenc(&str[i], c);
			dest[word] = (char *)malloc(sizeof(char) * (len + 1));
			if (!dest[word])
				return (ft_free_array((void **)dest, (size_t)word));
			ft_strncpy(dest[word], &str[i], len);
			dest[word][len] = '\0';
			word++;
			i += len;
		}
	}
	dest[word] = 0;
	return (dest);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**dest;
	char	*str;
	int		word_count;

	str = (char *)s;
	dest = NULL;
	if (s)
	{
		word_count = wordcnt(str, c);
		dest = (char **)malloc(sizeof(char *) * (word_count + 1));
		if (!dest)
			return (NULL);
		ft_split(dest, str, c);
	}
	return (dest);
}*/
