/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:06:49 by tigondra          #+#    #+#             */
/*   Updated: 2025/07/30 19:36:39 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_check_char(char *params)
{
	int	i;

	i = 0;
	if (params[2] >= '0' && params[2] <= '9')
		return (EXIT_FAILURE);
	while (params[i])
	{
		if ((params[i] < 32 || params[i] > 126))
			return (EXIT_FAILURE);
		i++;
	}
	if (i > 3)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_check_tab(char **grid, char *params, int *len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j] && j < len[0])
		{
			if ((grid[i][j] != params[1]) && (grid[i][j] != params[2]))
				return (EXIT_FAILURE);
			j++;
		}
		if (j != len[0])
			return (EXIT_FAILURE);
		i++;
	}
	if (i != len[1])
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_check(char **grid, char *params, int *len)
{
	if (ft_check_char(params) != 0)
		return (EXIT_FAILURE);
	if (ft_check_tab(grid, params, len) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
