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

void	ft_assign(t_pos *pos, int x, int y, int size)
{
	pos->x = x;
	pos->y = y;
	pos->size = size;
}

void	ft_search(char **grid, int *line, t_bsq *bsq)
{
	int	diag;
	int	tmp;
	int	i;
	int	j;

	ft_assign(&bsq->pos, 0, 0, 0);
	ft_init(&i, &j, &diag, &tmp);
	while (++i < bsq->len.x)
	{
		j = -1;
		diag = 0;
		while (++j < bsq->len.y)
		{
			tmp = line[j];
			if (grid[i][j] == bsq->params.empty)
				line[j] = ft_if(i, j, line, diag);
			else
				line[j] = 0;
			if (line[j] > bsq->pos.size)
				ft_assign(&bsq->pos, i, j, line[j]);
			diag = tmp;
		}
	}
}

int	ft_get_len(char **grid, t_len *len)
{
	len->x = ft_atoi(grid[0]);
	len->y = ft_strlen(grid[1]);
	if (len->x <= 0 || len->y <= 0)
		return (1);
	return (0);
}

int	ft_bsq(char **grid)
{
	t_bsq		bsq;
	int		*line;

	line = NULL;
	ft_assign(&bsq.pos, 0, 0, 0);
	if (ft_get_len(grid, &bsq.len) != 0)
		return (EXIT_FAILURE);
	ft_get_params(grid[0], &bsq.params);
	grid++;
	line = malloc(sizeof(int) * bsq.len.y);
	if (ft_check(grid, bsq.params, bsq.len) != 0 || !line)
	{
		free(line);
		return (EXIT_FAILURE);
	}
	ft_search(grid, line, &bsq);
	ft_put_bsq(grid, bsq.params.square, bsq.pos);
	ft_print_bsq(grid, bsq.len.y);
	free(line);
	return (EXIT_SUCCESS);
}
