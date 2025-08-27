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

t_pos	ft_search(char **grid, char *params, int *line, int *len)
{
	t_pos	pos;
	int	prev;
	int	tmp;
	int	i;
	int	j;

	ft_assign(&pos, 0, 0, 0);
	ft_init(&i, &j, &prev, &tmp);
	while (++i < len[1])
	{
		j = -1;
		prev = 0;
		while (++j < len[0])
		{
			tmp = line[j];
			if (grid[i][j] == params[2])
				line[j] = ft_if(i, j, line, prev);
			else
				line[j] = 0;
			if (line[j] > pos.size)
				ft_assign(&pos, i, j, line[j]);
			prev = tmp;
		}
	}
	return (pos);
}

int	*ft_get_len(char **grid)
{
	int	*len;
	int	i;

	i = 0;
	len = malloc(sizeof(int) * 2);
	if (!len)
		return (NULL);
	len[1] = ft_atoi(grid[0]);
	while (grid[i])
		i++;
	if (len[1] <= 0 || (i - 1) != len[1])
	{
		free(len);
		return (NULL);
	}
	len[0] = ft_strlen(grid[1]);
	if (len[0] <= 0)
	{
		free(len);
		return (NULL);
	}
	return (len);
}

int	ft_bsq(char **grid)
{
	t_pos	pos;
	char	*params;
	int		*line;
	int		*len;

	line = NULL;
	ft_assign(&pos, 0, 0, 0);
	len = ft_get_len(grid);
	if (!len)
		return (EXIT_FAILURE);
	params = ft_get_params(grid[0]);
	grid++;
	grid[len[1]] = NULL;
	if (!params || ft_check(grid, params, len))
		return (ft_free_params(len, line, params));
	line = malloc(sizeof(int) * len[0]);
	if (!line)
		return (EXIT_FAILURE);
	pos = ft_search(grid, params, line, len);
	ft_put_bsq(grid, params, pos);
	ft_print_bsq(grid, len[0]);
	return (ft_free_params(len, line, params));
}
