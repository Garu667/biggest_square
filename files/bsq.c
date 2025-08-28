/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:42:27 by tigondra          #+#    #+#             */
/*   Updated: 2025/07/30 20:04:35 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_get_params(char **tab, t_bsq *bsq)
{
	int		i;

	i = ft_strlen(tab[0]) - 1;
	bsq->params.square = tab[0][i];
	bsq->params.wall = tab[0][i - 1];
	bsq->params.empty = tab[0][i - 2];
	bsq->len.x = ft_atoi(tab[0]);
	bsq->len.y = ft_strlen(tab[1]);
	if (bsq->len.x <= 0 || bsq->len.y <= 0)
		return (1);
	return (0);
}

void	ft_put_bsq(char **tab, char square, t_pos pos)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < pos.size)
	{
		j = 0;
		while (j < pos.size)
		{
			tab[pos.x - j][pos.y - i] = square;
			j++;
		}
		i++;
	}
}

void	ft_print_bsq(char **tab, int len)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		write(1, tab[i], len);
		write(1, "\n", 1);
		i++;
	}
}

int	ft_bsq(char **tab)
{
	t_bsq		bsq;
	int		*line;

	line = NULL;
	if (ft_get_params(tab, &bsq) != 0)
		return (EXIT_FAILURE);
	tab++;
	line = malloc(sizeof(int) * bsq.len.y);
	if (ft_check(tab, bsq.params, bsq.len) != 0 || !line)
	{
		free(line);
		return (EXIT_FAILURE);
	}
	ft_search(tab, line, &bsq);
	ft_put_bsq(tab, bsq.params.square, bsq.pos);
	ft_print_bsq(tab, bsq.len.y);
	free(line);
	return (EXIT_SUCCESS);
}

void	ft_do_bsq(char *file)
{
	char	**tab;
	int		ret;

	ret = 0;
	tab = ft_split(file);
	if (!tab)
		return ;
	ret = ft_bsq(tab);
	if (ret != 0)
		ft_ret_val(1);
	ft_free_tab(tab, 1, 0);
	free(file);
}
