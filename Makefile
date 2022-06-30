# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 05:01:42 by aheddak           #+#    #+#              #
#    Updated: 2022/06/30 05:04:55 by aheddak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

BONUS		=	so_long

UTILS		=	elements_check.c ft_split.c ft_strdup.c ft_strlen.c ft_substr.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c inits.c input_.c move_plyr.c parsing.c rendering.c so_long.c

UTILS_BONUS	= elements_check.c ft_split.c ft_strdup.c ft_strlen.c ft_substr.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c inits.c input_.c move_plyr.c parsing.c rendering.c so_long.c

FLAGS		=	-Wall -Wextra -Werror

OBJCT		=	${UTILS:.c=.o}

OBJCTB		=	${UTILS_BONUS:.c=.o}

RM			=	rm -f

CC			=	gcc

MLX			= -lmlx -framework OpenGL -framework AppKit

all		:	$(NAME)

$(NAME)	:	$(OBJCT)	
	$(CC) $(FLAGS) $(MLX) $(UTILS) -o $(NAME)

bonus : $(BONUS)

$(BONUS) : $(OBJCTB)
	$(CC) $(FLAGS) $(MLX) $(UTILS_BONUS) -o $(BONUS)

clean :
	${RM} $(OBJCT) $(OBJCTB)

fclean : clean
	${RM} ${NAME} ${BONUS}

re : fclean all