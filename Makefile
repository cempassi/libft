# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/17 23:46:04 by cempassi          #+#    #+#              #
#    Updated: 2019/03/01 22:33:28 by cempassi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = Clang
COMPILE = $(CC) -c
DEBUG = $(CC) -g -c

# Reset
NC = \033[0m

# Regular Colors
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m

NAME = libft.a
DBNAME = libftdb.a
CLEANUP = rm -rf
MKDIR = mkdir -p

PATHO = objs/
PATHI = includes/

INCS += libft.h
INCS += ft_printf.h
INCS += conversion.h
INCS += output.h
INCS += memory.h
INCS += list.h
INCS += test.h
INCS += other.h

#--------------------Memory--------------------#
SRCS += ft_bzero.c
SRCS += ft_memalloc.c
SRCS += ft_memmove.c
SRCS += ft_memchr.c
SRCS += ft_memcmp.c
SRCS += ft_memcpy.c
SRCS += ft_memccpy.c
SRCS += ft_memdel.c
SRCS += ft_memset.c

#--------------------Strings---------------------#
SRCS += ft_isalnum.c
SRCS += ft_isalpha.c
SRCS += ft_isascii.c
SRCS += ft_isdigit.c
SRCS += ft_isprint.c
SRCS += ft_strcat.c
SRCS += ft_strchr.c
SRCS += ft_strcmp.c
SRCS += ft_strcpy.c
SRCS += ft_strdup.c
SRCS += ft_strlcat.c
SRCS += ft_strlen.c
SRCS += ft_strncat.c
SRCS += ft_strncmp.c
SRCS += ft_strncpy.c
SRCS += ft_strnstr.c
SRCS += ft_strrchr.c
SRCS += ft_strstr.c
SRCS += ft_strclr.c
SRCS += ft_strdel.c
SRCS += ft_strequ.c
SRCS += ft_striter.c
SRCS += ft_striteri.c
SRCS += ft_strjoin.c
SRCS += ft_strmap.c
SRCS += ft_strmapi.c
SRCS += ft_strnequ.c
SRCS += ft_strnew.c
SRCS += ft_strsub.c
SRCS += ft_strtrim.c
SRCS += ft_tolower.c
SRCS += ft_toupper.c
SRCS += ft_strupper.c
SRCS += ft_strinsert.c
SRCS += ft_strcspn.c
SRCS += ft_strspn.c
SRCS += ft_strrev.c

#--------------------Conversion------------------#
SRCS += ft_atoi.c
SRCS += ft_itoa.c
SRCS += ft_ullitoa.c
SRCS += ft_llitoa.c
SRCS += ft_atoll_base.c
SRCS += ft_atoull_base.c
SRCS += ft_convert_base.c
SRCS += ft_abs.c

#----------------------Tab-----------------------#
SRCS += ft_strsplit.c
SRCS += ft_freetab.c
SRCS += ft_getargstab.c

#--------------------Lists-----------------------#
SRCS += ft_mergesort.c
SRCS += ft_lstadd.c
SRCS += ft_lstcpy.c
SRCS += ft_lstdelone.c
SRCS += ft_lstdelnext.c
SRCS += ft_lstdel.c
SRCS += ft_lstiter.c
SRCS += ft_lstmap.c
SRCS += ft_lstnew.c
SRCS += ft_lstrev.c
SRCS += ft_lstaddback.c
SRCS += ft_lstmerge.c
SRCS += ft_lstfind.c
SRCS += ft_lstlen.c
SRCS += ft_lstfilter.c
SRCS += ft_lstremove_if.c
SRCS += ft_tabtolst.c
SRCS += ft_stckpop.c
SRCS += ft_stckpush.c
SRCS += ft_stckinit.c
SRCS += ft_stckdestroy.c

#--------------------Output----------------------#
SRCS += ft_putchar.c
SRCS += ft_putchar_fd.c
SRCS += ft_putendl.c
SRCS += ft_putendl_fd.c
SRCS += ft_putnbr.c
SRCS += ft_putnbr_fd.c
SRCS += ft_putstr.c
SRCS += ft_putnstr.c
SRCS += ft_putstr_fd.c
SRCS += ft_ringbuffer.c
SRCS += ft_getopt.c
SRCS += ft_getdelim.c
SRCS += ft_getargslst.c

#--------------------ft_printf-------------------#
SRCS += ft_printf.c
SRCS += format.c
SRCS += extract.c
SRCS += type.c
SRCS += widthprec.c
SRCS += output.c
SRCS += digit.c
SRCS += unsigned.c
SRCS += doubles.c
SRCS += other.c

#--------------------test------------------------#
SRCS += test.c

#--------------------directory--------------------#
SRCS += ft_dirlist.c
SRCS += ft_dirdel.c

DSYM += $(NAME).dSYM
DSYM += $(DBNAME).dSYM

OBJS = $(patsubst %.c, $(PATHO)%.o, $(SRCS))
OBJD = $(patsubst %.c, $(PATHO)db%.o, $(SRCS))

WFLAGS += -Wall
WFLAGS += -Werror
WFLAGS += -Wextra
IFLAGS = -I$(PATHI)
CFLAGS = $(WFLAGS)

vpath %.c srcs/conversion
vpath %.c srcs/directory
vpath %.c srcs/ft_printf
vpath %.c srcs/list
vpath %.c srcs/memory
vpath %.c srcs/other
vpath %.c srcs/output
vpath %.c srcs/string
vpath %.c srcs/tab
vpath %.c srcs/test
vpath %.h includes

all : $(PATHO) $(NAME)

debug : $(PATHO) $(DBNAME)

$(NAME): $(OBJS)
	ar rus $@ $^
	printf "$(GREEN)$@ is ready.\n$(NC)"

$(DBNAME): $(OBJD)
	ar rus $@ $^
	printf "$(GREEN)$@ is ready.\n$(NC)"

$(OBJS): $(PATHO)%.o : %.c $(INCS)
	$(COMPILE) $(CFLAGS) $(IFLAGS) $< -o $@
	printf "$(BLUE)Compiling $<\n$(NC)"

$(OBJD): $(PATHO)db%.o : %.c $(INCS)
	$(DEBUG) $(DFLAGS) $(CFLAGS) $(IFLAGS) $< -o $@
	printf "$(BLUE)Compiling $< for debug\n$(NC)"

$(PATHO) :
	$(MKDIR) $(PATHO)

clean:
	$(CLEANUP) $(PATHO)*.o
	printf "$(RED)All *.o files from libft removed\n$(NC)"
	$(CLEANUP) $(DSYM)
	printf "$(RED)All $(DSYM) removed\n$(NC)"

cleandb :
	$(CLEANUP) $(DBNAME)
	printf "$(RED)$(DBNAME) deleted\n$(NC)"

fclean: clean cleandb
	$(CLEANUP) $(NAME)
	$(CLEANUP) $(PATHO)
	printf "$(RED)$(NAME) deleted\n$(NC)"

re : fclean all

.PHONY: all clean fclean debug cleandb
.SILENT:
