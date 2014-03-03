# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apergens <apergens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/09/25 08:56:14 by apergens          #+#    #+#              #
#    Updated: 2014/03/03 04:03:40 by apergens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBNAME	= ft
NAME	= lib$(LIBNAME).a

LEVELS	= echo "../"; i+=1;
LEVELS	:= $(shell i=1; while [[ $$i -le $(MAKELEVEL) ]]; do $(LEVELS) done)

FILES	= ft_atoi ft_bzero ft_isalnum ft_isalpha ft_isascii ft_isdigit \
		ft_isgraph ft_islower ft_isprint ft_ispunct ft_isupper ft_isxdigit \
		ft_itoa ft_memalloc ft_memccpy ft_memchr ft_memcmp ft_memcpy \
		ft_memdel ft_memmove ft_memset ft_putchar ft_putchar_fd ft_putendl \
		ft_putendl_fd ft_putnbr ft_putnbr_fd ft_putstr ft_putstr_fd ft_strcat \
		ft_strchr ft_strclr ft_strcmp ft_strcpy ft_strdel ft_strdup ft_strequ \
		ft_striter ft_striteri ft_strjoin ft_strlcat ft_strlen ft_strmap \
		ft_strmapi ft_strncat ft_strncmp ft_strncpy ft_strnequ ft_strnew \
		ft_strnstr ft_strrchr ft_strsplit ft_strstr ft_strsub ft_strtrim \
		ft_tolower ft_toupper ft_lstnew ft_lstdelone ft_lstdel ft_lstadd \
		ft_lstiter ft_lstmap ft_ilen ft_strclen ft_strfjoin ft_strfsub \
		ft_free_return ft_strcchr ft_strftrim ft_strfsplit ft_lstcmp ft_ftoa \
		ft_xtoa ft_strins ft_argtrim ft_putlst ft_free_strtab ft_lstaddend \
		ft_lstlen ft_lsttoa ft_strreplace ft_ctoa ft_tablen ft_strcdup \
		ft_puttabstr ft_putchar_loop ft_strfdup ft_strcnew
SRC		= $(addsuffix .c, $(FILES))
OBJ		= $(patsubst %.c,objs/%.o,$(SRC))

FTFLAGS	= $(patsubst %,-L%,$(DIR)) $(patsubst %,-l%,$(LNAME))
CFLAGS	= -Wall -Wextra -Werror -pedantic -I./$(LEVELS)includes

COLOR0	= \033[0m
COLOR1	= \033[32m
COLOR2	= \033[1;34m
COLOR3	= \033[31m
COLOR4	= \033[1;34m
COLOR5	= \033[1;30m
COLOR6	= \033[33m

PUCE1	= $(COLOR5) ¤
PUCE2	= $(COLOR5) -> $(COLOR6)
F_INFOS = \
	echo "$(PUCE2)binaire     : $(COLOR0)$(NAME)"; \
	echo "$(PUCE2)compilateur : $(COLOR0)$(CC)"; \
	echo "$(PUCE2)extra-flags : $(COLOR0)$(CFLAGS)";

ifdef DEBUG
    CFLAGS	+= -g
else
    CFLAGS	+= -O3
endif

all: $(NAME)

$(NAME): $(OBJ)
	@if [ "$($_INFOS)" != "OK" ]; then $(call F_INFOS) $(eval $_INFOS :=OK) fi;
	@echo "$(PUCE1)$(COLOR1) Compilation de la librairie !$(COLOR0)"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

objs/%.o: srcs/$(notdir %.c)
	@if [ "$($_INFOS)" != "OK" ]; then $(call F_INFOS) $(eval $_INFOS :=OK) fi;
	@mkdir -p objs
	@$(CC) -c $(CFLAGS) -o "$@" "$<"

clean:
	@if [ "$($_INFOS)" != "OK" ]; then $(call F_INFOS) $(eval $_INFOS :=OK) fi;
	@$(RM) $(OBJ)
	@$(RM) -r objs

fclean: clean
	@test -f "$(NAME)" \
		&& echo "$(PUCE1)$(COLOR3) Suppression de la librairie !$(COLOR0)" \
		&& $(RM) $(NAME) || echo "\c";

re: fclean all

.PHONY: all clean fclean re
