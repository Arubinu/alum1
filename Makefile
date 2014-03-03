# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apergens <apergens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/09/25 08:56:14 by apergens          #+#    #+#              #
#    Updated: 2014/03/03 09:49:51 by apergens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= alum1
LNAME	= ft ft_gnl
LEVELS	= echo "../"; i+=1;
LEVELS	:= $(shell i=1; while [[ $$i -le $(MAKELEVEL) ]]; do $(LEVELS) done)

DIR		= $(patsubst %,lib%,$(LNAME))
HDR		= $(foreach var, $(DIR), $(var)/$(var).a)

FILES	= ft_alum1 ft_print_alum ft_print_notice ft_print_title \
		ft_check_entry ft_reset_alum ft_all_alum ft_print_prompt \
		ft_print_easter_eggs ft_calc_alum ft_return_mode ft_print_mode \
		ft_end_alum
SRC		= $(addsuffix .c, $(FILES))
OBJ		= $(patsubst %.c,objs/%.o,$(SRC))

FTFLAGS	= $(patsubst %,-L%,$(DIR)) $(patsubst %,-l%,$(LNAME))
CFLAGS	= -Wall -Wextra -Werror -pedantic -I./$(LEVELS)includes

COLOR0	= \033[0m
COLOR1	= \033[32m
COLOR2	= \033[1;34m
COLOR3	= \033[1;31m
COLOR4	= \033[1;34m
COLOR5	= \033[1;30m
COLOR6	= \033[33m
COLOR7	= \033[1;34;5m

PUCE0	= \033[1;31m ¤
PUCE1	= $(COLOR5) ¤
PUCE2	= $(COLOR5) -> $(COLOR6)
F_INFOS = \
	echo "$(PUCE2)binaire     : $(COLOR0)$(NAME)"; \
	echo "$(PUCE2)compilateur : $(COLOR0)$(CC)"; \
	echo "$(PUCE2)extra-flags : $(COLOR0)$(CFLAGS)"; \
	echo "$(PUCE2)librairies  : $(COLOR0)$(LNAME)";

MAKE	+= CC="$(CC)"
ifdef DEBUG
    CFLAGS	+= -g3
    MAKE	+= DEBUG=1
else
    CFLAGS	+= -O3
endif

all: $(NAME)

$(NAME): $(HDR) $(OBJ)
	@if [ "$($_INFOS)" != "OK" ]; then $(call F_INFOS) $(eval $_INFOS :=OK) fi;
	@echo "$(PUCE1)$(COLOR1) Compilation du binaire : $(COLOR0)$(NAME)"
	@$(CC) $(CFLAGS) $(FTFLAGS) -o $(NAME) $(OBJ)

objs/%.o: srcs/$(notdir %.c)
	@if [ "$($_INFOS)" != "OK" ]; then $(call F_INFOS) $(eval $_INFOS :=OK) fi;
	@mkdir -p objs
	@$(CC) -c $(CFLAGS) -o "$@" "$<"

$(DIR) %.a:
	@if [ "$($_INFOS)" != "OK" ]; then $(call F_INFOS) $(eval $_INFOS :=OK) fi;
	@$(eval $@_VAR :=$(notdir $(basename $@))) \
	if [[ -e "$($@_VAR)" && -f "$($@_VAR)/Makefile" ]]; then \
		echo "$(PUCE1)$(COLOR2) Compilation de la librairie : \c"; \
		echo "$(COLOR0)$(shell echo "$($@_VAR)" | cut -c 4-)"; \
		$(MAKE) -C $($@_VAR) > /dev/null; \
	else \
		echo "$(PUCE0)$(COLOR4) Librairie introuvable : $(COLOR0)\c"; \
		echo "$(shell echo "$($@_VAR)" | cut -c 4-)"; \
	fi;

libclean:
	@if [ "$($_INFOS)" != "OK" ]; then $(call F_INFOS) $(eval $_INFOS :=OK) fi;
	@$(foreach var, $(HDR), $(eval $@_VAR :=$(notdir $(basename $(var)))) \
		if [[ -e "$($@_VAR)" && -f "$($@_VAR)/Makefile" ]]; then \
			echo "$(PUCE1)$(COLOR7) Suppression de la librairie : \c"; \
			echo "$(COLOR0)$(shell echo "$($@_VAR)" | cut -c 4-)"; \
			$(MAKE) -C $($@_VAR) clean > /dev/null; \
		else \
			echo "$(PUCE0)$(COLOR7) Librairie introuvable : $(COLOR0)\c"; \
			echo "$(shell echo "$($@_VAR)" | cut -c 4-)"; \
		fi;)

libfclean: libclean
	@if [ "$($_INFOS)" != "OK" ]; then $(call F_INFOS) $(eval $_INFOS :=OK) fi;
	@$(foreach var,$(DIR),$(MAKE) -C $(var) fclean > /dev/null;)

binclean:
	@if [ "$($_INFOS)" != "OK" ]; then $(call F_INFOS) $(eval $_INFOS :=OK) fi;
	@$(RM) $(OBJ)
	@$(RM) -r objs

binfclean: binclean
	@test -f "$(NAME)" \
		&& echo "$(PUCE1)$(COLOR3) Suppression du binaire : $(COLOR0)$(NAME)" \
		&& $(RM) $(NAME) || echo "\c";

clean: libclean binclean

fclean: libfclean binfclean

binre: binfclean $(NAME)

re: fclean all

.PHONY: all libclean binclean clean libfclean binfclean fclean binre re $(DIR)
