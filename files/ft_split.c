/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaroudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:13:52 by rmaroudi          #+#    #+#             */
/*   Updated: 2024/08/27 16:05:55 by rmaroudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	char_is_sep(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if ((char_is_sep(str[i + 1], charset) == 1
				|| str[i + 1] == 0) && (char_is_sep(str[i], charset) == 0))
			words++;
		i++;
	}
	return (words);
}

void	ft_strcpy(char *dest, char *src, char *charset)
{
	int	i;

	i = 0;
	while (char_is_sep(src[i], charset) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

void	alloc_split(char **split, char *str, char *charset)
{
	int	i;
	int	j;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (char_is_sep(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (char_is_sep(str[i + j], charset) == 0)
				j++;
			split[words] = malloc((j + 1) * sizeof(char));
			ft_strcpy(split[words], (str + i), charset);
			i += j;
			words++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		words;

	words = count_word(str, charset);
	split = malloc((words + 1) * sizeof(char **));
	alloc_split(split, str, charset);
	split[words] = 0;
	return (split);
}
