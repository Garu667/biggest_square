/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaroudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:37:22 by rmaroudi          #+#    #+#             */
/*   Updated: 2024/08/28 13:05:00 by rmaroudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
/* ft_split.c */
int	char_is_sep(char c, char *charset);

int	count_word(char *str, char *charset);

void ft_strcpy(char *dest, char *src, char *charset);

void alloc_split(char **split, char *str, char *charset);

char **ft_split(char *str, char *charset);
/* matrix.c */
int ft_strlen(char *str);

int **allocate_matrix(int row, int col);

void fill_matrix(int **matrix, char **tab);

int **handle_matrix(int row, int col, char **tab);

void print_bsq(char **tab);
/* algo.c */
void ft_putchar(char c);

char *get_stdin(void);

int **find_square(int **tab, int row, int col);

void put_square(char **tab, int x, int y, int int_max);

void search_square(int **matrix, char **tab, int row, int col);
/* file.c */
int get_size(char *filename);

char *get_file(char *filename);

char manage_str(char *str, int nbr);
/* main.c */
int	check_tab(char **tab, char *str);
//int main(int ac, char **av);
