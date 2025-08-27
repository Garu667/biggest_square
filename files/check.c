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

int	ft_check_char(t_params params)
{
	if (params.empty >= '0' && params.empty <= '9')
		return (EXIT_FAILURE);
	if ((params.empty < 32 || params.empty > 126))
		return (EXIT_FAILURE);
	if ((params.wall < 32 || params.wall > 126))
		return (EXIT_FAILURE);
	if ((params.square < 32 || params.square > 126))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_check_tab(char **grid, t_params params, t_len len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j] && j < len.y)
		{
			if ((grid[i][j] != params.empty) && (grid[i][j] != params.wall))
				return (EXIT_FAILURE);
			j++;
		}
		if (j != len.y)
			return (EXIT_FAILURE);
		i++;
	}
	if (i != len.x)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_check(char **grid, t_params params, t_len len)
{
	if (ft_check_char(params) != 0)
		return (EXIT_FAILURE);
	if (ft_check_tab(grid, params, len) != 0)
		return (EXIT_FAILURE);
	return (0);
}
