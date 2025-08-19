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

int	*ft_assign_pos(void)
{
	int	*pos;

	pos = malloc(sizeof(int) * 3);
	pos[0] = 0;
	pos[1] = 0;
	pos[2] = 0;
	return (pos);
}

int	*ft_search(char **grid, char *params, int *line, int *len)
{
	int	prev;
	int	*pos;
	int	tmp;
	int	i;
	int	j;

	ft_init(&i, &j, &prev, &tmp);
	pos = ft_assign_pos();
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
			if (line[j] > pos[2])
				pos = ft_assign(pos, line[j], i, j);
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
	char	*params;
	int		*line;
	int		*pos;
	int		*len;

	pos = NULL;
	line = NULL;
	len = ft_get_len(grid);
	if (!len)
		return (EXIT_FAILURE);
	params = ft_get_params(grid[0]);
	grid++;
	grid[len[1]] = NULL;
	if (!params || ft_check(grid, params, len))
		return (ft_free_params(len, pos, line, params));
	line = malloc(sizeof(int) * len[0]);
	if (!line)
		return (EXIT_FAILURE);
	pos = ft_search(grid, params, line, len);
	ft_put_bsq(grid, params, pos, pos[2]);
	ft_print_bsq(grid, len[0]);
	return (ft_free_params(len, pos, line, params));
}
