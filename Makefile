GREEN:=\x1b[32m
NC:=\033[0m

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
			 srcs_bonus/keys_color_bonus.c \
			 srcs_bonus/init_bonus.c \
			 srcs_bonus/keys_bonus.c \
			 srcs_bonus/keys_utils_bonus.c \
			 srcs_bonus/utils_bonus.c \
			 srcs/check.c \
			 srcs/draw.c \
			 srcs/free.c \
			 srcs/get_next_line.c \
			 srcs/get_next_line_utils.c \
			 srcs/nbr_utils.c \
			 srcs/parse.c \
			 srcs/projection.c \
			 srcs_bonus/main_bonus.c \

CC = gcc
NAME = fdf
CFLAGS = -Wall -Wextra -Werror
FRAMEWORKS = -framework OpenGl -framework Appkit
RM = rm -f
OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	@echo "${GREEN}Compiling the libft..${NC}"
	@make -C libft
	@echo "${GREEN}Compliling the fdf mandatory part..${NC}"
	${CC} ${CFLAGS} ${OBJS} -lmlx -lft -L libft -L /usr/local/lib ${FRAMEWORKS} -o ${NAME}
	@echo "${GREEN}----->Fdf is ready to be used - USAGE: ./fdf [path/to/map]<-----${NC}"
	
bonus : ${OBJS_BONUS}
	@echo "${GREEN}Compiling the libft..${NC}"
	@make -C libft
	@echo "${GREEN}Compliling the fdf bonus part..${NC}"
	${CC} ${CFLAGS} ${OBJS_BONUS} -lmlx -lft -L libft -L /usr/local/lib ${FRAMEWORKS} -o ${NAME}
	@echo "${GREEN}----->Fdf is ready to be used - USAGE: ./fdf [path/to/map]<-----${NC}"

clean : 
	@echo "${GREEN}Removing libft's objects..${NC}"
	@make clean -C libft
	@echo "${GREEN}Removing fdf's mandatories objects..${NC}"
	${RM} ${OBJS}
	@echo "${GREEN}Removing fdf's bonus objects..${NC}"
	${RM} ${OBJS_BONUS}

fclean : clean
	@echo "${GREEN}Removing libft archive..${NC}"
	@make fclean -C libft
	@echo "${GREEN}Removing fdf..${NC}"
	${RM} ${NAME}
	@echo "${GREEN}Cleaning done!${NC}"

re : fclean all
