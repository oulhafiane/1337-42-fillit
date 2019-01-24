/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 23:03:05 by zoulhafi          #+#    #+#             */
/*   Updated: 2018/10/30 21:55:20 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct		s_direction
{
	int				i;
	int				j;
}					t_direction;

typedef struct		s_tlist
{
	int				(*f)(int**, int, int, int);
	int				t;
	int				alpha;
	int				ci;
	int				cj;
	t_direction		*m;
	struct s_tlist	*next;
}					t_tlist;

enum	e_etrominoes{I1, I2, J1, J2, J3, J4, L1, L2, L3,
	L4, O1, T1, T2, T3, T4, S1, S2, Z1, Z2};

void				check_line1(int count[4], int i, int tetriminoes[19]);
void				check_line2(int count[4], int i, int tetriminoes[19]);
void				check_line3(int count[4], int i, int tetriminoes[19]);
void				remove_block(int **board, int max, int alpha);
void				print_result(int **board, int max);
int					fill_empty(int **b, int m);
int					cnt(int **board, int max, int i, int j);
int					l1j1(int **block, int i);
int					s2z2(int **block, int i);
int					s1z1o1(int **block, int i);
int					t2t4(int **block, int i);
int					l2j4(int **block, int i);
int					j2l4(int **block, int i);
void				free_block(int **block);
int					**fix_block(int **block);
int					check_block(int **block);
int					get_input(char *input, int pcs[27]);
void				push_to_end_tlist(t_tlist *lst);
void				init_counter(t_tlist *lst, int flag);
void				increment_counter(t_tlist *lst, int i, int j, int max);
int					print_tetrimino(int **b, int max, t_tlist *l, int flag);
t_tlist				*create_tlist(int pcs[27]);
int					check_file(char *path);

#endif
