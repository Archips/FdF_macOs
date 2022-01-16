.PHONY : all re clean fclean

SRCS = check.c \
	   color.c \
	   draw.c \
	   free.c \
	   get_next_line.c \
	   get_next_line_utils.c \
	   init.c \
	   keys.c \
	   keys_utils.c \
	   main.c \
	   nbr_utils.c \
	   parse.c \
	   projection.c \
	   utils.c \

CC = gcc
NAME = fdf
CFLAGS = -Wall -Wextra -Werror -c
FRAMEWORKS = -framework OpenGl -framework Appkit
RM = rm -f
OBJS = ${SRCS:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	@make -C libft
	${CC} ${OBJS} -lmlx -lft -L libft -L /usr/local/lib ${FRAMEWORKS} -o ${NAME}

${OBJS} : ${SRCS}
	${CC} ${CFLAGS} ${SRCS}

clean : 
	@make clean -C libft
	${RM} ${OBJS}

fclean : clean
	@make fclean -C libft
	${RM} ${NAME}

re : fclean all
