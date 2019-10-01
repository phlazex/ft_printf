# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/03 16:52:46 by mfahey            #+#    #+#              #
#    Updated: 2019/09/30 18:31:44 by mfahey           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCSLF	= libft/srcs/ft_abs.c\
		libft/srcs/ft_atoll.c\
		libft/srcs/ft_atoull.c\
		libft/srcs/ft_atoi.c\
		libft/srcs/ft_bool.c\
		libft/srcs/ft_bzero.c\
		libft/srcs/ft_fabs.c\
		libft/srcs/ft_floor.c\
		libft/srcs/ft_fpart.c\
		libft/srcs/ft_free_mas.c\
		libft/srcs/ft_ipart.c\
		libft/srcs/ft_isalnum.c\
		libft/srcs/ft_isalpha.c\
		libft/srcs/ft_isascii.c\
		libft/srcs/ft_isdigit.c\
		libft/srcs/ft_islower.c\
		libft/srcs/ft_isprint.c\
		libft/srcs/ft_isspace.c\
		libft/srcs/ft_isupper.c\
		libft/srcs/ft_itoa.c\
		libft/srcs/ft_llitoa_base.c\
		libft/srcs/ft_lstadd.c\
		libft/srcs/ft_lstdel.c\
		libft/srcs/ft_lstdelone.c\
		libft/srcs/ft_lstiter.c\
		libft/srcs/ft_lstmap.c\
		libft/srcs/ft_lstnew.c\
		libft/srcs/ft_max.c\
		libft/srcs/ft_memalloc.c\
		libft/srcs/ft_memccpy.c\
		libft/srcs/ft_memchr.c\
		libft/srcs/ft_memcmp.c\
		libft/srcs/ft_memcpy.c\
		libft/srcs/ft_memdel.c\
		libft/srcs/ft_memmove.c\
		libft/srcs/ft_memset.c\
		libft/srcs/ft_pow.c\
		libft/srcs/ft_min.c\
		libft/srcs/ft_putchar.c\
		libft/srcs/ft_putchar_fd.c\
		libft/srcs/ft_putendl.c\
		libft/srcs/ft_putendl_fd.c\
		libft/srcs/ft_putnbr.c\
		libft/srcs/ft_putnbr_fd.c\
		libft/srcs/ft_putstr.c\
		libft/srcs/ft_putstr_fd.c\
		libft/srcs/ft_rfpart.c\
		libft/srcs/ft_round.c\
		libft/srcs/ft_str2len.c\
		libft/srcs/ft_strcat.c\
		libft/srcs/ft_strchr.c\
		libft/srcs/ft_strclen.c\
		libft/srcs/ft_strclr.c\
		libft/srcs/ft_strcmp.c\
		libft/srcs/ft_strcpy.c\
		libft/srcs/ft_strdel.c\
		libft/srcs/ft_strdup.c\
		libft/srcs/ft_strequ.c\
		libft/srcs/ft_striter.c\
		libft/srcs/ft_striteri.c\
		libft/srcs/ft_strjoin.c\
		libft/srcs/ft_strlcat.c\
		libft/srcs/ft_strlen.c\
		libft/srcs/ft_strmap.c\
		libft/srcs/ft_strmapi.c\
		libft/srcs/ft_strncat.c\
		libft/srcs/ft_strncmp.c\
		libft/srcs/ft_strncpy.c\
		libft/srcs/ft_strnequ.c\
		libft/srcs/ft_strnew.c\
		libft/srcs/ft_strnstr.c\
		libft/srcs/ft_strrchr.c\
		libft/srcs/ft_strsplit.c\
		libft/srcs/ft_strstr.c\
		libft/srcs/ft_strsub.c\
		libft/srcs/ft_strtrim.c\
		libft/srcs/ft_swap.c\
		libft/srcs/ft_tolower.c\
		libft/srcs/ft_toupper.c\
		libft/srcs/ft_ulltoa_base.c\
		libft/srcs/get_next_line.c

SRCSPF	= srcs/ft_printf.c\
		srcs/ft_search.c\
		srcs/ft_flag.c\
		srcs/ft_width.c\
		srcs/ft_precision.c\
		srcs/ft_size.c\
		srcs/ft_type.c\
		srcs/ft_format.c\
		srcs/ft_format_di.c\
		srcs/ft_format_di_frst.c\
		srcs/ft_format_di_scnd.c\
		srcs/ft_format_oux.c\
		srcs/ft_format_o.c\
		srcs/ft_format_o_frst.c\
		srcs/ft_format_u.c\
		srcs/ft_format_x.c\
		srcs/ft_format_x_frst.c\
		srcs/ft_format_fega.c\
		srcs/ft_format_fega_frst.c\
		srcs/ft_atof_printf.c\
		srcs/ft_format_csp.c\
		srcs/ft_format_s.c\
		srcs/ft_format_p.c\
		srcs/ft_format_n.c\
		srcs/ft_insert.c

OBJS	= $(patsubst libft/srcs/%.c,libft/objs/%.o,$(SRCSLF))
OBJS	+= $(patsubst srcs/%.c,objs/%.o,$(SRCSPF))

INCLF	= libft/includes/

INCPF	= includes/

FLAGS	= -Wall -Wextra -Werror

MKLFT	= make -C libft/

all: $(NAME)

libft/objs/%.o: libft/srcs/%.c
	gcc -c $< -o $@ -I $(INCLF)

objs/%.o: srcs/%.c
	gcc -c $< -o $@ -I $(INCPF) -I $(INCLF)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) a.out

re: fclean all
