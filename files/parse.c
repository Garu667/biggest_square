/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:10:45 by tigondra          #+#    #+#             */
/*   Updated: 2025/07/30 19:44:30 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strlen_word(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int	ft_count_word(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '\n' && str[i + 1] == '\n')
			count++;
		i++;
	}
	return (count);
}

int	ft_free_tab(char **tab, int opt, int indx)
{
	int	i;

	i = -1;
	if (opt == 0)
		free(tab);
	if (opt == 1)
	{
		while (tab[++i])
			free(tab[i]);
		free(tab);
	}
	if (opt == 2)
	{
		while (++i < indx)
			free(tab[i]);
		free(tab);
	}
	return (0);
}

char	**ft_parse_tab(char **tab, char *str, int line, int i)
{
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (i < line)
	{
		tab[i] = malloc(sizeof(char) * (ft_strlen_word(&str[c]) + 1));
		if (!tab[i])
		{
			ft_free_tab(tab, 2, i);
			return (NULL);
		}
		j = 0;
		while (str[c] != '\n')
		{
			tab[i][j] = str[c];
			c++;
			j++;
		}
		tab[i][j] = 0;
		c++;
		i++;
	}
	return (tab);
}

char	**ft_split(char *str)
{
	char	**tab;
	int		i;
	int		line;

	i = 0;
	line = ft_count_word(str);
	tab = malloc(sizeof(char *) * (line + 1));
	if (!tab)
	{
		ft_free_tab(tab, 0, 0);
		return (NULL);
	}
	tab = ft_parse_tab(tab, str, line, i);
	tab[line] = NULL;
	return (tab);
}
