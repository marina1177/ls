/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:44:45 by wzei              #+#    #+#             */
/*   Updated: 2019/10/23 14:11:08 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_SORT_H
# define FT_LS_SORT_H

# include "ft_ls_m.h"

typedef unsigned char	t_1b;
typedef unsigned short	t_2b;
typedef unsigned int	t_4b;
typedef unsigned long	t_8b;

/*
**# define timercmp(a, b, CMP) \
**	(((a)->tv_sec == (b)->tv_sec) ? \
**	((a)->tv_nsec CMP (b)->tv_nsec) : \
**	((a)->tv_sec CMP (b)->tv_sec))
*/

typedef struct		s_test
{
	struct stat				ft_stat;
	char					*name;
}					t_test;

typedef struct		s_maxlen
{
	short	maxtype;
	t_8b	maxl_mode;
	t_8b	maxl_nlink;
	t_8b	maxl_uname;
	t_8b	maxl_gname;
	t_8b	maxl_size;
	t_8b	maxl_time;
	t_8b	maxl_filename;
}					t_maxlen;

typedef struct		s_lstat
{
	char	name[PATH_MAX + 1];
	size_t	namelen;
}					t_lstat;

/*
** ls_sort_args.c
*/
void				ls_sort_args();
void				ls_sort_args_file(t_mlist *files);

/*
** ls_sort.c
*/

void				quicksort(t_vector *v, int low, int high,
								int (*f)(void *, void *));

/*
** ft_lstsort.c
*/

void				merge_sort(t_list **head_ref, int (*f)(void *, void *));
t_list				*sorted_merge(t_list *a, t_list *b,
									int (*f)(void *, void *));
void				front_back_split(t_list *source,
					t_list **front_ref, t_list **back_ref);

/*
** ls_cmp.c
*/

int					ls_isdir(void *a, void *b);
int					ls_cmp_lex(void *a, void *b);
int					ls_cmp_atime(void *a, void *b);
int					ls_cmp_mtime(void *a, void *b);
int					ls_cmp_size(void *a, void *b);

#endif
