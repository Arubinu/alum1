/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 20:52:33 by apergens          #+#    #+#             */
/*   Updated: 2014/03/03 09:49:40 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM1_H
# define ALUM1_H

# include "libft.h"
# include "libft_gnl.h"

# define TERM_WIDTH		82
# define TITLE_DECAL	8

typedef struct	s_rows
{
	int		nbr;
	char	*alum;
}				t_rows;

int		ft_all_alum(int cols, int rows, int del, int get);
int		ft_calc_alum(char *entry, int get);
int		ft_check_entry(char *entry);
int		ft_end_alum(char **entry, char *bin, int error);
void	ft_print_alum(int c, int max);
void	ft_print_easter_eggs(int decal, int width, int c, int error);
void	ft_print_mode(int decal, int width, char *str, int mode);
int		ft_print_notice(int decal, int width, int error, char *bin);
void	ft_print_prompt(char **entry, int error);
int		ft_print_title(void);
int		ft_reset_alum(char **nbr, int choice, int error);
int		ft_return_mode(char *mode);

#endif
