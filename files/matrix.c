/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaroudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:18:26 by rmaroudi          #+#    #+#             */
/*   Updated: 2024/08/28 13:01:33 by rmaroudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	**allocate_matrix(int row, int col)
{
	int	i;
	int	**matrix;

	i = 0;
	matrix = malloc(row * sizeof(int *));
	if (matrix == NULL)
		return (NULL);
	while (i < row)
	{
		matrix[i] = malloc(col * sizeof(int));
		i++;
	}
	return (matrix);
}

void	fill_matrix(int **matrix, char **tab)
{
	int	i;
	int	j;

	i = 1;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			matrix[i - 1][j] = 1;
			if (tab[i][j] == manage_str(tab[0], 2))
				matrix[i - 1][j] = 0;
			j++;
		}
		i++;
	}
}

int	**handle_matrix(int row, int col, char **tab)
{
	int	**matrix;

	matrix = allocate_matrix(row, col);
	fill_matrix(matrix, tab);
	matrix = find_square(matrix, row, col);
	search_square(matrix, tab, row, col);
	//free_mat(matrix);
	return (matrix);
}

void	print_bsq(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			ft_putchar(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
