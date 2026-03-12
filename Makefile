# All notes are now in the Makefile template
NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -I.

SRCS =	./sources_libft/ft_isalpha.c \
		./sources_libft/ft_isdigit.c \
		./sources_libft/ft_isalnum.c \
		./sources_libft/ft_isascii.c \
		./sources_libft/ft_itoa.c \
		./sources_libft/ft_isprint.c \
		./sources_libft/ft_strlen.c \
		./sources_libft/ft_memset.c \
		./sources_libft/ft_bzero.c \
		./sources_libft/ft_memcpy.c \
		./sources_libft/ft_memmove.c \
		./sources_libft/ft_strlcpy.c \
		./sources_libft/ft_strlcat.c \
		./sources_libft/ft_toupper.c \
		./sources_libft/ft_tolower.c \
		./sources_libft/ft_strchr.c \
		./sources_libft/ft_strrchr.c \
		./sources_libft/ft_strncmp.c \
		./sources_libft/ft_strcmp.c \
		./sources_libft/ft_memchr.c \
		./sources_libft/ft_memcmp.c \
		./sources_libft/ft_strnstr.c \
		./sources_libft/ft_atoi.c \
		./sources_libft/ft_calloc.c \
		./sources_libft/ft_strdup.c \
		./sources_libft/ft_substr.c \
		./sources_libft/ft_strjoin.c \
		./sources_libft/ft_strtrim.c \
		./sources_libft/ft_split.c \
		./sources_libft/ft_strmapi.c \
		./sources_libft/ft_striteri.c \
		./sources_libft/ft_putchar_fd.c \
		./sources_libft/ft_putstr_fd.c \
		./sources_libft/ft_putendl_fd.c \
		./sources_libft/ft_putnbr_fd.c \
		./sources_ft_printf/ft_printf.c \
		./sources_ft_printf/ft_printf_common_specifiers.c \
		./sources_ft_printf/ft_printf_hexa_specifiers.c

OBJS = $(SRCS:.c=.o)

BONUS_SRCS =	./sources_libft/ft_lstnew.c \
				./sources_libft/ft_lstadd_front.c \
				./sources_libft/ft_lstsize.c \
				./sources_libft/ft_lstlast.c \
				./sources_libft/ft_lstadd_back.c \
				./sources_libft/ft_lstdelone.c \
				./sources_libft/ft_lstclear.c \
				./sources_libft/ft_lstiter.c \
				./sources_libft/ft_lstmap.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# If I'm on my own machine (campus or home), update the 98 & 99 Folders - UPDATE ALL MAKEFILES w/ home data (whoamI at home is not schappuy)
UPDATE_PERSO := $(shell whoami)
CURRENT_DIR = $(shell basename $$PWD)

ifeq ($(UPDATE_PERSO), schappuy)
ifeq ($(CURRENT_DIR), 01_Libft)
		EXTRA := install
	endif
endif

ifeq ($(UPDATE_PERSO), prunelle)
ifeq ($(CURRENT_DIR), 01_Libft)
		EXTRA := install
	endif
endif

all: $(NAME) bonus $(EXTRA)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

install:
	cp libft.h ../98_include
	cp libft.a ../99_lib

.PHONY: all clean fclean re bonus
