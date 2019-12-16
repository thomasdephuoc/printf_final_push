
NAME		= libftprintf.a
LIBFT		= libft.a
DIR_LIBFT	= ./libft_printf/
CFLAGS		= -Wall -Werror -Wextra -I. -c
FILES		= ft_buffer.c \
				ft_car_convert.c \
				ft_convert.c \
				ft_not_dash.c \
				ft_not_dash_compl.c \
				ft_hexa_convert.c \
				ft_int_convert.c \
				ft_percent.c \
				ft_point_convert.c \
				ft_precision.c \
				ft_printf.c \
				ft_uns_int_convert.c \
				ft_utils.c \
				parse_format_specs.c \
				ft_fromlibft.c \
				ft_dash.c \
				ft_zero.c \

OBJ			= $(FILES:.c=.o)

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			cc $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): 		$(OBJ) ft_printf.h
				make -C $(DIR_LIBFT)
				cp $(DIR_LIBFT)$(LIBFT) ./$(NAME)
				ar rcs $(NAME) $(OBJ)
				/bin/rm -f $(LIBFT)
				ranlib $(NAME)

all:		$(NAME)

clean:
			rm -f $(OBJ)
			make clean -C $(DIR_LIBFT)

fclean:		clean
			rm -f $(NAME)
			make fclean -C $(DIR_LIBFT)

re:			fclean all

bonus:		$(NAME)

.PHONY:		clean fclean all re
