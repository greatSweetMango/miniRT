# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 16:46:22 by jaehyuki          #+#    #+#              #
#    Updated: 2023/02/01 18:43:14 by gyim             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL = all

NAME		=	minirt
CFLAGS		=	-Wall -Werror -Wextra -MMD -MP -g3 #-fsanitize=address,undefined
CPPFLAGS	=	-I./include -I./libft -I./mlx
LDFLAGS		=	-L./libft -L./mlx
LDLIBS		=	-lft -lmlx
FWS			=	-framework OpenGL -framework AppKit

RM			=	rm -rf

OUTDIR		=	out/

LIBFT		=	./libft/libft.a
MLX			=	./mlx/libmlx.a

##########BONUS##############
MAIN = src/main.c#??

ifdef bonus
	MAIN = main_bonus.c
endif
##############################

SRCS		=	$(MAIN)										\
				src/draw_scene.c							\
				src/error.c									\
				src/key_hooks/mouse_button.c				\
				src/key_hooks/move_obj.c					\
				src/key_hooks/push_keys.c					\
				src/key_hooks/rotate_obj.c					\
				src/key_hooks/update_camera.c				\
				src/key_hooks/update_cylinder.c				\
				src/key_hooks/update_plane.c				\
				src/key_hooks/update_sphere.c				\
				src/functions/ft_ato_rgb.c					\
				src/functions/ft_ato_vec3.c					\
				src/functions/ft_atod.c						\
				src/functions/ft_lst.c						\
				src/functions/ft_rgb_to_i.c					\
				src/functions/ft_split_free.c				\
				src/nomalization/nomalize_camera_utils.c	\
				src/nomalization/nomalize_camera.c			\
				src/operators/vec3_cross_product.c			\
				src/operators/vec3_div.c					\
				src/operators/vec3_inner_product.c			\
				src/operators/vec3_minus.c					\
				src/operators/vec3_multi.c					\
				src/operators/vec3_plus.c					\
				src/operators/vec3_set.c					\
				src/operators/vec3_unit.c					\
				src/parse_scene/parse_arg.c					\
				src/parse_scene/set_scene_util.c			\
				src/parse_scene/set_scene.c					\
				src/rt_engine/ray.c							\
				src/rt_engine/rt_engine.c
				
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
