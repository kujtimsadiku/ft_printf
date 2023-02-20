/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:20:24 by ksadiku           #+#    #+#             */
/*   Updated: 2022/05/19 15:40:18 by ksadiku          ###   ########.fr       */
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
	char	**fresh;

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
