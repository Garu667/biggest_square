/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:27:49 by tigondra          #+#    #+#             */
/*   Updated: 2025/07/30 20:09:00 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_ret_val(int i)
{
	if (i == 1)
	{
		write(2, "map error\n", 10);
		return (1);
	}
	return (0);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_print_bsq(char **grid, int len)
{
	int	i;

	i = 0;
	while (grid[i])
	{
		write(1, grid[i], len);
		write(1, "\n", 1);
		i++;
	}
}

int	ft_free_grid(char **grid, int opt, int indx)
{
	int	i;

	i = -1;
	if (opt == 0)
		free(grid);
	if (opt == 1)
	{
		while (grid[++i])
			free(grid[i]);
		free(grid);
	}
	if (opt == 2)
	{
		while (++i < indx)
			free(grid[i]);
		free(grid);
	}
	return (0);
}

void	ft_do_bsq(char *file)
{
	char	**grid;
	int		ret;

	ret = 0;
	grid = ft_split(file);
	if (!grid)
		return ;
	ret = ft_bsq(grid);
	if (ret != 0)
		ft_ret_val(1);
	ft_free_grid(grid, 1, 0);
	free(file);
}
