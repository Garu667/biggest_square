/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramaroud <ramaroud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:36:02 by ramaroud          #+#    #+#             */
/*   Updated: 2025/07/30 16:51:52 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_assign(t_pos *pos, int x, int y, int size)
{
	pos->x = x;
	pos->y = y;
	pos->size = size;
}

int	ft_min(int count, ...)
{
	va_list	args;
	int	min;
	int	val;
	int	i;

	i = 0;
	min = 2147483647;
	va_start(args, count);
	while (i < count)
	{
		val = va_arg(args, int);
		if (val < min)
			min = val;
		i++;
	}
	va_end(args);
	return (min);
}

static inline int	ft_if(int i, int j, int *line, int prev)
{
	if (i == 0 || j == 0)
		return (1);
	else
		return (ft_min(3, line[j], line[j - 1], prev) + 1);
}

void	ft_search(char **tab, int *line, t_bsq *bsq)
{
	int	diag;
	int	tmp;
	int	i;
	int	j;

	i = -1;
	ft_assign(&bsq->pos, 0, 0, 0);
	while (++i < bsq->len.x)
	{
		j = -1;
		diag = 0;
		while (++j < bsq->len.y)
		{
			tmp = line[j];
			if (tab[i][j] == bsq->params.empty)
				line[j] = ft_if(i, j, line, diag);
			else
				line[j] = 0;
			if (line[j] > bsq->pos.size)
				ft_assign(&bsq->pos, i, j, line[j]);
			diag = tmp;
		}
	}
}
