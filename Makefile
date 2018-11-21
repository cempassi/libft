CC = Clang
COMPILE = $(CC) -c
OPT =-O2

# Reset
NC=\033[0m

# Regular Colors
BLACK=\033[0;30m
RED=\033[0;31m
GREEN =\033[32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
PURPLE=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m

NAME = libft.a
CLEANUP =rm -rf
MKDIR = mkdir -p

PATHO =objs/
PATHI =includes/

INCS = libft.h

#--------------------Part I--------------------#
SRCS +=ft_atoi.c #DONE
SRCS +=ft_bzero.c #DONE
SRCS +=ft_isalnum.c #DONE
SRCS +=ft_isalpha.c #DONE
SRCS +=ft_isascii.c #DONE
SRCS +=ft_isdigit.c #DONE
SRCS +=ft_isprint.c #DONE
SRCS +=ft_memalloc.c #DONE
SRCS +=ft_memmove.c #DONE
SRCS +=ft_memchr.c #DONE
SRCS +=ft_memcmp.c #DONE
SRCS +=ft_memcpy.c #DONE
SRCS +=ft_memccpy.c #DONE
SRCS +=ft_memdel.c #DONE
SRCS +=ft_memset.c #DONE
SRCS +=ft_strcat.c #DONE
SRCS +=ft_strchr.c #DONE
SRCS +=ft_strcmp.c #DONE
SRCS +=ft_strcpy.c #DONE
SRCS +=ft_strdup.c #DONE
SRCS +=ft_strlcat.c #DONE
SRCS +=ft_strlen.c #DONE
SRCS +=ft_strncat.c #DONE
SRCS +=ft_strncmp.c #DONE
SRCS +=ft_strncpy.c #DONE
SRCS +=ft_strnstr.c #DONE
SRCS +=ft_strrchr.c #DONE
SRCS +=ft_strstr.c #DONE
SRCS +=ft_tolower.c #DONE
SRCS +=ft_toupper.c #DONE

#--------------------Part II-------------------#
SRCS +=ft_itoa.c #DONE
SRCS +=ft_putchar.c #DONE
SRCS +=ft_putchar_fd.c #DONE
SRCS +=ft_putendl.c #DONE
SRCS +=ft_putendl_fd.c #DONE
SRCS +=ft_putnbr.c #DONE
SRCS +=ft_putnbr_fd.c #DONE
SRCS +=ft_putstr.c #DONE
SRCS +=ft_putstr_fd.c #DONE
SRCS +=ft_strclr.c #DONE
SRCS +=ft_strdel.c #DONE
SRCS +=ft_strequ.c #DONE
SRCS +=ft_striter.c #DONE
SRCS +=ft_striteri.c #DONE
SRCS +=ft_strjoin.c #DONE
SRCS +=ft_strmap.c #DONE
SRCS +=ft_strmapi.c #DONE
SRCS +=ft_strnequ.c #DONE
SRCS +=ft_strnew.c #DONE
SRCS +=ft_strsplit.c #DONE
SRCS +=ft_strsub.c #DONE
SRCS +=ft_strtrim.c #DONE

#--------------------Part III------------------#
SRCS +=ft_lstadd.c #DONE
SRCS +=ft_lstdel.c #DONE
SRCS +=ft_lstdelone.c #DONE
SRCS +=ft_lstiter.c #DONE
SRCS +=ft_lstmap.c #DONE
SRCS +=ft_lstnew.c #DONE

#--------------------Part IV-------------------#
SRCS +=ft_convert_base.c #DONE
SRCS +=ft_lstrev.c #DONE
SRCS +=ft_lstaddback.c #DONE
SRCS +=ft_lstmerge.c #DONE
SRCS +=ft_lstfind.c #DONE
SRCS +=ft_strcspn.c #DONE

SRCT =$(patsubst %.c,$(PATHT)test%.c, $(SRCS))
SRCU =$(PATHU)Unity.c

OBJS =$(patsubst %.c, $(PATHO)%.o, $(SRCS))
OBJT +=$(patsubst $(PATHT)%.c, $(PATHO)%.o, $(SRCT))
OBJU +=$(patsubst $(PATHU)%.c, $(PATHO)%.o, $(SRCU))
OBJ =$(OBJS) $(OBJT) $(OBJU)

OUT =$(patsubst $(PATHT)%.c, $(PATHB)%.out, $(SRCT))
RESULTS =$(patsubst $(PATHT)%.c,$(PATHR)%.txt,$(SRCT))

WFLAGS +=-Wall
WFLAGS +=-Werror
WFLAGS +=-Wextra
IFLAGS =-I $(PATHI)
CFLAGS =$(WFLAGS)

.PHONY: all clean fclean
.SILENT:
	
vpath %.c .
vpath %.h includes

all : $(PATHO) $(NAME)

do_test: build_dir $(RESULTS) done

build_dir : $(PATHO) $(PATHB) $(PATHR)

$(NAME): $(OBJS)
	ar rus $@ $^
	@printf "$(GREEN)$@ is ready.\n$(NC)"

$(OBJS): $(PATHO)%.o : %.c $(INCS)
	$(COMPILE) $(OPT) $(CFLAGS) $(IFLAGS) $< -o $@
	@printf "$(BLUE)Compiling $<\n$(NC)"

$(PATHO) :
	$(MKDIR) $(PATHO)

clean:
	@$(CLEANUP) $(PATHO)*.o
	@printf "$(RED)All *.o files removed\n$(NC)"

fclean: clean
	$(CLEANUP) $(NAME)
	$(CLEANUP) $(PATHO)
	@printf "$(RED)$(NAME) deleted\n$(NC)"

re : fclean all
