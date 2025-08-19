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

char	*ft_get_params(char *str)
{
	char	*params;
	int		i;	
	int		j;

	j = 0;
	i = ft_strlen(str) - 1;
	params = malloc(sizeof(char) * 4);
	if (!params)
		return (NULL);
	while (i > 0)
	{
		if (j < 3)
		{
			params[j] = str[i];
			j++;
		}
		i--;
	}
	params[j] = 0;
	return (params);
}

void	ft_put_bsq(char **grid, char *params, int *pos, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			grid[pos[0] - j][pos[1] - i] = params[0];
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

int	*ft_assign(int *pos, int line, int i, int j)
{
	pos[0] = i;
	pos[1] = j;
	pos[2] = line;
	return (pos);
}

int	ft_if(int i, int j, int *line, int prev)
{
	if (i == 0 || j == 0)
		return (1);
	else
		return (ft_min(line[j], line[j - 1], prev) + 1);
}
