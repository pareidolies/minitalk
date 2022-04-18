SRCS_SERVER		= server.c \

SRCS_CLIENT		= client.c \
				= client_utils.c \

BONUS			= checker.c \

SRCS_DIR		= srcs/

BONUS_DIR		= srcs_bonus/

SRCS_SERVER_PATH	= $(SRCS_SERVER:%=$(SRCS_DIR)%)

SRCS_CLIENT_PATH	= $(SRCS_CLIENT:%=$(SRCS_DIR)%)

SRCS_B_PATH 		= $(BONUS:%=$(BONUS_DIR)%)

OBJS_SERVER	 	= $(SRCS_SERVER_PATH:%.c=%.o)

OBJS_CLIENT		= $(SRCS_CLIENT_PATH:%.c=%.o)

OBJS_BONUS		= $(SRCS_B_PATH:%.c=%.o)

SERVER			= server

CLIENT		 	= client

NAME_BONUS		= bonus

PATH_LIBFT		= -C libft --no-print-directory

LIBRARY			= ./libft/libft.a

INCS			= includes

RM		 	= rm -f

CC			= cc -Wall -Wextra -Werror

all:			${CLIENT} ${SERVER}

$(SERVER):		${OBJS_SERVER}
			$(MAKE) $(PATH_LIBFT)
			$(CC) -I $(INCS) $(SRCS_SERVER_PATH) $(LIBRARY) -o $(SERVER)

$(CLIENT):		${OBJS_CLIENT}
			$(MAKE) $(PATH_LIBFT)
			$(CC) -I $(INCS) $(SRCS_CLIENT_PATH) $(LIBRARY) -o $(CLIENT)

clean:
			${RM} ${OBJS_SERVER} ${OBJS_CLIENT} ${OBJS_BONUS}
			$(MAKE) clean $(PATH_LIBFT)

fclean:			clean
			${RM} ${SERVER} ${CLIENT} ${NAME_BONUS}
			$(MAKE) fclean $(PATH_LIBFT)

re:			fclean all

bonus:			${OBJS_BONUS}
			$(MAKE) $(PATH_LIBFT)
			$(CC) -I $(INCS) $(SRCS_B_PATH) $(LIBRARY) -o $(NAME_BONUS)

.PHONY:			all clean fclean re bonus
