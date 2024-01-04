# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/02 09:55:12 by sbelomet          #+#    #+#              #
#    Updated: 2024/01/04 12:19:45 by sbelomet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -fsanitize=address -g3

#Variables

NAME		=	philo
HEADERS		=	-I includes
SRC_DIR		=	srcs/
OBJ_DIR		=	objs/
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

# Colors

RED 		=	\033[1;91m
YELLOW		=	\033[1;93m
GREEN		=	\033[1;92m
BLUE		=	\033[1;94m
PURPLE		=	\033[1;95m
DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
MAGENTA		=	\033[0;95m
CYAN		=	\033[1;96m
WHITE		=	\033[0;97m
RAINBOW		=	$(RED)-$(YELLOW)-$(GREEN)-$(CYAN)-$(BLUE)-$(PURPLE)-

#Sources

FILES		=	main error_handling utils1 philos_phunctions
SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

#Commands

all:			$(OBJ_DIR) $(NAME)

$(NAME):		$(OBJ)
					@echo "$(RAINBOW)$(RAINBOW)$(RAINBOW)$(DEF_COLOR)"
					$(CC) $(CFLAGS) $(OBJ) $(HEADERS) -pthread -o $(NAME)
					@echo ""
					@echo "$(GREEN)$(NAME) est compilé !$(DEF_COLOR)🥶🥶🥶"
					@echo "$(RAINBOW)$(RAINBOW)$(RAINBOW)$(DEF_COLOR)"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c	
					@echo "$(YELLOW)$< est dans le four...$(DEF_COLOR)🥵🥵🥵"
					@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

$(OBJ_DIR):
					@mkdir -p $(OBJ_DIR)

clean:
					@rm -rf $(OBJ_DIR)
					@echo "$(RAINBOW)$(RAINBOW)$(RAINBOW)$(DEF_COLOR)"
					@echo "$(BLUE)à la poubelle les .o$(DEF_COLOR)🤓🤓🤓"

fclean:			clean
					@rm -rf $(NAME)
					@echo "$(CYAN)à la poubelle l'exec$(DEF_COLOR)🤤🤤🤤"

re:				fclean all

.PHONY:			all clean fclean re