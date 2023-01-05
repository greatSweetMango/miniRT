# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 16:46:22 by jaehyuki          #+#    #+#              #
#    Updated: 2023/01/05 17:40:28 by jaehyuki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL = all

NAME		=	minirt
CFLAGS		=	-Wall -Werror -Wextra -MMD -MP -g
CPPFLAGS	=	-I./include -I./libft -I./mlx
LDFLAGS		=	-L./libft -L./mlx
LDLIBS		=	-lft -lmlx
FWS			=	-framework OpenGL -framework AppKit

RM			=	rm -rf

OUTDIR		=	out/

LIBFT		=	./libft/libft.a
MLX			=	./mlx/libmlx.a

##########BONUS##############
MAIN = src/test.c #??

ifdef bonus
	MAIN = main_bonus.c
endif
##############################

SRCS		=	$(MAIN)					\
				src/error.c				\
				src/get_rgb.C			\
				src/parse_arg.c			\
				src/set_scene.c			\
				src/functions/ft_atod.c

OBJS		=	$(addprefix $(OUTDIR),$(SRCS:%.c=%.o))
DEPS		=	$(addprefix $(OUTDIR),$(SRCS:%.c=%.d))
-include $(DEPS)

$(OUTDIR)%.o : %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

bonus : 
	$(MAKE) bonus=1 

all		:
	$(MAKE) -C $(dir $(LIBFT))
	$(MAKE) -C $(dir $(MLX))
	$(MAKE) $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS) $(FWS)

$(OBJS) : $(LIBFT) $(MLX)

$(LIBFT) : 
	@$(MAKE) -C $(dir $(LIBFT))

$(MLX)	:
	@$(MAKE) -C $(dir $(MLX))

clean	:
	@$(RM) $(OUTDIR)
	@$(MAKE) -C $(dir $(LIBFT)) clean
	@$(MAKE) -C $(dir $(MLX)) clean

fclean	: clean
	@$(RM) $(NAME) $(LIBFT) $(MLX)

re		: fclean
	$(MAKE) all

.PHONY	: all clean fclean re $(dir $(LIBFT)) $(dir $(MLX)) bonus
