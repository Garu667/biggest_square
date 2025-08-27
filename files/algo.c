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

void	ft_get_params(char *str, t_params *params)
{
	int		i;

	i = ft_strlen(str) - 1;
	params->square = str[i];
	params->wall = str[i - 1];
	params->empty = str[i - 2];
}

void	ft_put_bsq(char **grid, char square, t_pos pos)
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
			grid[pos.x - j][pos.y - i] = square;
			j++;
		}
		i++;
	}
}

void	ft_init(int *a, int *b, int *c, int *d)
{
	*a = -1;
	*b = -1;
	*c = 0;
	*d = 0;
}

int	ft_if(int i, int j, int *line, int prev)
{
	if (i == 0 || j == 0)
		return (1);
	else
		return (ft_min(line[j], line[j - 1], prev) + 1);
}
