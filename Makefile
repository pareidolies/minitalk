SRCS_SERVER		= server.c \
			  server_utils.c \

SRCS_CLIENT		= client.c \
			  client_utils.c \

BONUS_SERVER	= server_bonus.c \
				server_utils_bonus.c \

BONUS_CLIENT	= client_bonus.c \
				client_utils_bonus.c \

SRCS_DIR		= srcs/

BONUS_DIR		= bonus/

SRCS_SERVER_PATH	= $(SRCS_SERVER:%=$(SRCS_DIR)%)

SRCS_CLIENT_PATH	= $(SRCS_CLIENT:%=$(SRCS_DIR)%)

BONUS_SERVER_PATH 	= $(BONUS_SERVER:%=$(BONUS_DIR)%)

BONUS_CLIENT_PATH 	= $(BONUS_CLIENT:%=$(BONUS_DIR)%)

OBJS_SERVER	 	= $(SRCS_SERVER_PATH:%.c=%.o)

OBJS_CLIENT		= $(SRCS_CLIENT_PATH:%.c=%.o)

OBJS_SERVER_BONUS	= $(BONUS_SERVER_PATH:%.c=%.o)

OBJS_CLIENT_BONUS	= $(BONUS_CLIENT_PATH:%.c=%.o)

SERVER			= server

CLIENT		 	= client

SERVER_BONUS		= server_bonus

CLIENT_BONUS		= client_bonus

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
			${RM} ${OBJS_SERVER} ${OBJS_CLIENT} ${OBJS_SERVER_BONUS} ${OBJS_CLIENT_BONUS}
			$(MAKE) clean $(PATH_LIBFT)

fclean:			clean
			${RM} ${SERVER} ${CLIENT} ${SERVER_BONUS} ${CLIENT_BONUS}
			$(MAKE) fclean $(PATH_LIBFT)

re:			fclean all

bonus:			${CLIENT_BONUS} ${SERVER_BONUS}

$(SERVER_BONUS):		${OBJS_SERVER_BONUS}
			$(MAKE) $(PATH_LIBFT)
			$(CC) -I $(INCS) $(BONUS_SERVER_PATH) $(LIBRARY) -o $(SERVER_BONUS)

$(CLIENT_BONUS):		${OBJS_CLIENT_BONUS}
			$(MAKE) $(PATH_LIBFT)
			$(CC) -I $(INCS) $(BONUS_CLIENT_PATH) $(LIBRARY) -o $(CLIENT_BONUS)

.PHONY:			all clean fclean re bonus
