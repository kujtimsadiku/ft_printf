/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:20:09 by ksadiku           #+#    #+#             */
/*   Updated: 2021/11/30 15:14:41 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *str, const char *find, size_t flen)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (ft_strstr(&str[i], find) == &str[i])
		{
			count++;
		}
		i += flen - 1;
	}
	return (count);
}

static char	*ft_newstr(char *newstr, char *str, char *find, char *replace)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		if (ft_strstr(str, find) == str)
		{
			ft_strcpy(&newstr[i], replace);
			i += ft_strlen(replace);
			str += ft_strlen(find);
		}
		else
			newstr[i++] = *str++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_replace_word(char *str, char *find, char *replace)
{
	char	*newstr;
	size_t	i;
	size_t	count;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	count = ft_count_words(str, find, ft_strlen(find));
	if (replace > find)
		newstr = (char *)malloc
			(i + count * (ft_strlen(replace) - ft_strlen(find)) + 1);
	else
		newstr = (char *)malloc
			(i - count * (ft_strlen(find) - ft_strlen(replace)) + 1);
	if (!newstr)
		return (NULL);
	newstr = ft_newstr(newstr, str, find, replace);
	return (newstr);
}
