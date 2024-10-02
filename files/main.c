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

int	check_tab(char **tab, char *str)
{
  int   i;
  int   j;
  int cnt;
  int row;

	i = 1;
  cnt = 0;
  row = atoi(str);
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] != 'o')
        cnt = 1;
			j++;
		}
		i++;
	}
  if (cnt == 0 || (i - 1) != row)
    return (1);
  return (0);
}

int	main(int ac, char **av)
{
	char	**tab;
	char	*str;

  if (ac > 1)
    str = get_file(av[1]);
  else
    str = get_stdin();
	tab = ft_split(str, "\n");
	if (check_tab(tab, tab[0]))
	{
		write(2, "Wrong Input\n", 12);
		return (1);
	}
  handle_matrix(atoi(tab[0]), ft_strlen(tab[1]), tab);
  tab++;
	print_bsq(tab);
}
