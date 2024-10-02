/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaroudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:36:51 by rmaroudi          #+#    #+#             */
/*   Updated: 2024/08/28 20:00:55 by rmaroudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int get_size(char *filename)
{
  int count;
  int fd;
  char c;

  count = 0;
  fd = open(filename, O_RDONLY);
  if (fd == -1)
    return (-1);
  while (read(fd, &c, 1) > 0)
    count++;
  close(fd);
  return (count);
}

char *get_file(char *filename)
{
  int i;
  int fd;
  int size;
  char *str;
  char c;

  i = 0;
  size = get_size(filename);
  fd = open(filename, O_RDONLY);
  str = malloc((size + 1) * sizeof(char));
  while (read(fd, &c, 1) > 0)
  {
    str[i] = c;
    i++;
  }
  str[i] = 0;
  close(fd);
  return (str);
}

char manage_str(char *str, int nbr)
{
  int i;

  i = 0;
  while (str[i])
    i++;
  if (nbr == 3)
    return (str[i - 1]);
  if (nbr == 2)
    return (str[i - 2]);
  if (nbr == 1)
    return (str[i - 3]);
  return (0);
}
