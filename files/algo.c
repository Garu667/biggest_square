/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaroudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:21:21 by rmaroudi          #+#    #+#             */
/*   Updated: 2024/08/28 19:59:52 by rmaroudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void ft_putchar(char c)
{
  write(1, &c, 1);
}

char	*get_stdin(void)
{
  char *str;
  char *new_str;
  ssize_t bytes_read;
  size_t size;
  size_t i;

  i = 0;
  size = 0;
  str = malloc(1024);
  if (!str) return (NULL);
  while ((bytes_read = read(0, str + size, 1024)) > 0)
  {
    size += bytes_read;
    if (size % 1024 == 0) // Verif si la mem est full
    {
      new_str = malloc(size + 1024); // Alloue + de mem
      if (!new_str)
      {
        free(str);
        exit(1);
      }
      i = 0;
      while (i < size)
      {
        new_str[i] = str[i];
        i++;
      }
      free(str);
      str = new_str;
    }
  }
  str[size] = '\0';
  return (str);
}

int **find_square(int **tab, int row, int col)
{
  int i;
  int min_value;
  int j;

  i = row - 2;
  while (i >= 0)// Parcours du tableau à partir du coin en bas à droite
  {
    j = col - 2;
    while (j >= 0)
    {
      if (tab[i][j] != 0) // Si on est pas sur un mur, cherche la taille du carré possible
      {
        min_value = tab[i][j + 1];
        if (tab[i + 1][j] < min_value)
          min_value = tab[i + 1][j];
        if (tab[i + 1][j + 1] < min_value)
          min_value = tab[i + 1][j + 1];
        tab[i][j] = min_value + 1; // Si on peut agrandir le carré, incrémente la valeur
      }
      j--;
    }
    i--;
  }
  return (tab);
}

void	put_square(char **tab, int x, int y, int int_max)
{
	int	i;
	int	j;

	i = 0;
	while (i != int_max)
	{
		j = 0;
		while (j != int_max)
		{
			tab[x + (i + 1)][y + j] = manage_str(tab[0], 3);
			j++;
		}
		i++;
	}
}

void	search_square(int **matrix, char **tab, int row, int col)
{
  int pos[2] = {0, 0};
  int int_max; 
  int j;
  int i;

  i = 0;
  j = 0;
  int_max = 0;
  while (i < row)
  {
    j = 0;
    while (j < col)
    {
      if (matrix[i][j] > int_max)
      {
        int_max = matrix[i][j];
        pos[0] = i;
        pos[1] = j;
      }
      j++;
    }
    i++;
  }
	put_square(tab, pos[0], pos[1], int_max);
}
