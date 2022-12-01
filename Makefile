# @author   athirion (archips)
####################################### BEG_5 ####

NAME        := fdf

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#
# LIBS        libraries to be used
# LIBS_TARGET libraries to be built
#
# INCS        header file locations
#
# SRC_DIR     source directory
# SRCS        source files
#
# BUILD_DIR   build directory
# OBJS        object files
# DEPS        dependency files
#
# CC          compiler
# CFLAGS      compiler flags
# CPPFLAGS    preprocessor flags
# LDFLAGS     linker flags
# LDLIBS      libraries name

############## MACOS ##############
ifeq ($(shell uname -s), Darwin)
	LIBS        := ft mlx m
	LIBS_TARGET := \
				   lib/libft/libft.a \
				   lib/minilibx-darwin/libmlx.a
	INCS      := /opt/X11/include
	CFLAGS    := -D OSTYPE=darwin
	LDLIBS    := -framework OpenGL -framework AppKit
endif

############## LINUX ##############
ifeq ($(shell uname -s), Linux)
	LIBS        := ft mlx m X11 Xext
	LIBS_TARGET := \
				   lib/libft/libft.a \
				   lib/minilibx-linux/libmlx.a
	CFLAGS    := -D OSTYPE=linux
endif

INCS        := $(INCS) include $(dir $(LIBS_TARGET))
INCS        := $(INCS) $(addsuffix include,$(dir $(LIBS_TARGET)))

SRC_DIR     	:= srcs
SRC_DIR_BONUS	:= srcs_bonus
SRCS = check.c \
	   color.c \
	   draw.c \
	   free.c \
	   get_next_line.c \
	   get_next_line_utils.c \
	   init.c \
	   keys.c \
	   main.c \
	   nbr_utils.c \
	   parse.c \
	   projection.c \
	   utils.c

SRCS_BONUS = color_bonus.c \
			 keys_color_bonus.c \
			 init_bonus.c \
			 keys_bonus.c \
			 keys_utils_bonus.c \
			 utils_bonus.c \
			 check.c \
			 draw.c \
			 free.c \
			 get_next_line.c \
			 get_next_line_utils.c \
			 nbr_utils.c \
			 parse.c \
			 projection.c \
			 main_bonus.c

SRCS        := $(SRCS:%=$(SRC_DIR)/%)
SRCS_BONUS	:= $(SRCS_BONUS:%=$(SRC_DIR_BONUS)/%)

BUILD_DIR   := .build
BUILD_DIR_B	:= .build_bonus
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJS_B      := $(SRCS_BONUS:$(SRC_DIR_BONUS)/%.c=$(BUILD_DIR_B)/%.o)
DEPS        := $(OBJS:.o=.d)
DEPS_BONUS  := $(OBJS_B:.o=.d)

CC          := clang
CFLAGS      := $(CFLAGS)   -Wall -Wextra -Werror
CPPFLAGS    := $(CPPFLAGS) $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS     := $(LDFLAGS)  $(addprefix -L,$(dir $(LIBS_TARGET)))
LDLIBS      := $(LDLIBS)   $(addprefix -l,$(LIBS))

#------------------------------------------------#
#   UTENSILS                                     #
#------------------------------------------------#
# RM        force remove
# MAKE      quietly make
# DIR_DUP   duplicate directory tree
# ERR_MUTE  filter errors
# VALGRIND  valgrind command

RM          := rm -f
MAKE        := $(MAKE) --jobs --silent --no-print-directory
DIR_DUP     = mkdir -p $(@D)
VALGRIND    := valgrind -q  --dsymutil=yes --leak-check=yes --show-leak-kinds=all --track-fds=yes
ERR_MUTE	:= 2>/dev/null

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#
# all       default goal
# $(NAME)   link .o -> archive
# $(LIBS)   build libraries
# %.o       compilation .c -> .o
# clean     remove .o
# fclean    remove .o + binary
# re        remake default goal
# update    update the repo to its most recent version

all: $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	$(info CREATED $@)

bonus: $(OBJS_B) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(OBJS_B) $(LDLIBS) -o $(NAME)
	$(info CREATED $@)

$(LIBS_TARGET):
	$(MAKE) -C $(@D) $(ERR_MUTE)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

$(BUILD_DIR_B)/%.o: $(SRC_DIR_BONUS)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

-include $(DEPS)

clean:
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f clean; done
	$(RM) $(OBJS) $(DEPS) $(OBJS_B) $(DEPS_BONUS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

update:
	git stash
	git pull
	git submodule update --init
	git stash pop

#----------------------------#
#   DIFFERENT CFLAGS BUILD   #
#----------------------------#
# asan      address sanitizer
# ansi      ansi c89 compliance
# every     all warnings

asan: CFLAGS    += -O0 -g3 -fsanitize=address,undefined,integer -fno-optimize-sibling-calls
asan: LDFLAGS   += -g3 -fsanitize=address,undefined,integer
asan: all

ansi: CFLAGS    += -W -pedantic -std=c89
ansi: all

every: CFLAGS   += -Weverything
every: all

#----------------------------#
#   TESTS                    #
#----------------------------#
# runv          run with valgrind
# run           vanilla run
# malloc_test   gh/ft_mallocator TODO broken

run-%: $(NAME)
	-./$(NAME) $*

vrun-%: CFLAGS  += -g3
vrun-%: $(NAME)
	-$(VALGRIND) ./$(NAME) $*

malloc_test: $(OBJS)
	clang -Wall -Wextra -Werror -g -fsanitize=undefined -rdynamic -o $@ $(OBJS) \
		-Ltest/ft_mallocator -lmallocator

#------------------------------------------------#
#   SPEC                                         #
#------------------------------------------------#

.PHONY: clean fclean re malloc_test
.SILENT:

####################################### END_5 ####
