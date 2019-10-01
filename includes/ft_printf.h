/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 16:42:27 by mfahey            #+#    #+#             */
/*   Updated: 2019/09/30 20:26:09 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"
# define N 100000
# define ELF 15
# define MLF 64
# define BFS 80
# define P 16383
# define Z 0.

typedef struct				s_flag
{
	int						sharp;
	int						zero;
	int						minus;
	int						space;
	int						plus;
}							t_flag;

typedef enum				e_size
{
	ws,
	hh,
	h,
	l,
	ll,
	j,
	z,
	t,
	L,
}							t_size;

typedef enum				e_type
{
	wt,
	d,
	D,
	i,
	o,
	O,
	u,
	U,
	x,
	X,
	f,
	F,
	e,
	E,
	g,
	G,
	a,
	A,
	c,
	s,
	p,
	n,
}							t_type;

typedef union				u_value
{
	int						di;
	signed char				hhdi;
	short int				hdi;
	long int				ldi;
	long long int			lldi;
	unsigned int			oux;
	unsigned char			hhoux;
	unsigned short int		houx;
	unsigned long int		loux;
	unsigned long long int	lloux;
	size_t					z;
	long double				lf;
	int						c;
	int						*n;
	signed char				*hhn;
	short int				*hn;
	long int				*ln;
	long long int			*lln;
	size_t					*zn;
}							t_value;

typedef union				u_ldbl
{
	long double				lf;
	struct
	{
		unsigned long long	mnt : MLF;
		unsigned int		exp : ELF;
		unsigned int		sgn : 1;
	}						s_lfprt;
}							t_ldbl;

typedef struct				s_printf
{
	va_list					ap;
	const char				*fmt;
	size_t					i;
	char					str[N];
	char					*ss;
	size_t					j;
	size_t					k;
	t_value					*value;
	t_ldbl					*ldbl;
	int						bf[BFS];
	char					*srpf;
	char					*slpf;
	long double				rpf;
	long double				lpf;
	long double				exp;
	int						pn;
	int						z;
	size_t					length;
	char					*aflag;
	t_flag					*flag;
	int						width;
	int						precision;
	int						prec;
	char					*asize;
	t_size					size;
	char					*atype;
	t_type					type;
	int						percent;
}							t_printf;

int							ft_printf(const char *format, ...);
void						ft_search(t_printf *ft);
void						ft_search_deafault(t_printf *ft);
void						ft_isflag(t_printf *ft);
int							ft_isflag_frst(t_printf *ft, int c);
void						ft_iswidth(t_printf *ft);
void						ft_isprecision(t_printf *ft);
void						ft_issize(t_printf *ft);
int							ft_issize_frst(t_printf *ft, int c);
void						ft_istype(t_printf *ft);
int							ft_istype_frst(t_printf *ft, int c);
void						ft_format(t_printf *ft);
void						ft_format_di(t_printf *ft);
void						ft_format_di_thrd(t_printf *ft);
void						ft_format_di_svnth(t_printf *ft);
void						ft_format_di_ghth(t_printf *ft);
void						ft_format_di_nnth(t_printf *ft);
void						ft_format_oux(t_printf *ft);
void						ft_format_o_frst(t_printf *ft);
void						ft_format_o_frth(t_printf *ft);
void						ft_format_o_ffth(t_printf *ft);
void						ft_format_o_sxth(t_printf *ft);
void						ft_format_u_frst(t_printf *ft);
void						ft_format_x_frst(t_printf *ft);
void						ft_format_x_frth(t_printf *ft);
void						ft_format_fega(t_printf *ft);
void						ft_format_fega_frst(t_printf *ft);
void						ft_format_fega_frth(t_printf *ft);
void						ft_atof_printf(t_printf *ft);
void						ft_format_csp(t_printf *ft);
void						ft_format_c(t_printf *ft);
void						ft_format_s(t_printf *ft);
void						ft_format_s_frst(t_printf *ft);
void						ft_format_p_frst(t_printf *ft);
void						ft_format_n(t_printf *ft);
void						ft_insert_chr(t_printf *ft,
		size_t i, size_t length, int chr);
void						ft_insert_di(t_printf *ft);
void						ft_insert_sharp(t_printf *ft);
void						ft_insert_f(t_printf *ft);

#endif
