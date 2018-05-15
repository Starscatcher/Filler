/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonuse.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 12:08:59 by aryabenk          #+#    #+#             */
/*   Updated: 2018/05/15 16:41:18 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_BONUSE_H
# define FILLER_BONUSE_H

# include "../libftprintf/libft/libft.h"

typedef struct			s_flag
{
	int		first;
	int		second;
	int		h;
	int		t;
	int		f;
	char	*pp1;
	char	*pp2;
}						t_flag;

void					ft_print_final(t_flag *flag);
void					ft_del_flag(t_flag *flag);
void					ft_read(int fd, char *line, t_flag *flag);
char					*ft_print_fig(int fd, char *line);
t_flag					*ft_create_flag(t_flag *flag);
char					*ft_print_map(int fd, char *line);
void					ft_read_flags(int argc, char **argv, t_flag *flag);
void					ft_print_help(t_flag *flag);

#endif
