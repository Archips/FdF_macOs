.PHONY : all re clean fclean

SRCS = srcs/check.c \
	   srcs/color.c \
	   srcs/draw.c \
	   srcs/free.c \
	   srcs/get_next_line.c \
	   srcs/get_next_line_utils.c \
	   srcs/init.c \
	   srcs/keys.c \
	   srcs/main.c \
	   srcs/nbr_utils.c \
	   srcs/parse.c \
	   srcs/projection.c \
	   srcs/utils.c \

SRCS_BONUS = srcs_bonus/color_bonus.c \
			 srcs_bonus/init_bonus.c \
			 srcs_bonus/keys_bonus.c \
			 srcs_bonus/keys_utils_bonus.c \
			 srcs/check.c \
			 srcs/draw.c \
			 srcs/free.c \
			 srcs/get_next_line.c \
			 srcs/get_next_line_utils.c \
			 srcs/nbr_utils.c \
			 srcs/parse.c \
			 srcs/projection.c \
			 srcs/utils.c \
			 srcs_bonus/main_bonus.c \

CC = gcc
NAME = fdf
CFLAGS = -Wall -Wextra -Werror -c
FRAMEWORKS = -framework OpenGl -framework Appkit
RM = rm -f
INCLUDES = includes
OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	@make -C libft
	${CC} ${OBJS} -lmlx -lft -L libft -L /usr/local/lib ${FRAMEWORKS} -o ${NAME}

bonus : ${OBJS_BONUS}
	@make -C libft
	${CC} ${OBJS_BONUS} -lmlx -lft -L libft -L /usr/local/lib ${FRAMEWORKS} -o ${NAME}

clean : 
	@make clean -C libft
	${RM} ${OBJS}
	${RM} ${OBJS_BONUS}

fclean : clean
	@make fclean -C libft
	${RM} ${NAME}

re : fclean all
