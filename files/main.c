/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaroudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:36:51 by rmaroudi          #+#    #+#             */
/*   Updated: 2024/08/28 20:00:47 by rmaroudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_tab(char **tab, int row, int col)
{
	int	i;
	int	j;
	int	cnt;

	i = 1;
	cnt = 0;
	if (col == -1)
		return (1);
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] != manage_str(tab[0], 2))
				cnt = 1;
			j++;
		}
		if (j != col)
			return (1);
		i++;
	}
	if (cnt == 0 || (i - 1) != row)
		return (1);
	return (0);
}

int	ret_error(int nb)
{
	if (nb == 1)
	{
		write(2, "map error\n", 10);
		return (2);
	}
	return (-1);
}

int	main(int ac, char **av)
{
	char	**tab;
	char	*str;
	int		i;

	i = 1;
	str = NULL;
	if (ac > 1)
		str = get_file(av[i]);
	else
		str = get_stdin();
	if (!str)
		return (ret_error(1));
	tab = ft_split(str, "\n");
	if (check_tab(tab, ft_atoi(tab[0]), ft_strlen(tab[1])))
		return (ret_error(1));
	handle_matrix(ft_atoi(tab[0]), ft_strlen(tab[1]), tab);
	tab++;
	print_bsq(tab);
}
