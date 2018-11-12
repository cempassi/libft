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
PATHU =unity/
PATHT =test/
PATHB =build/
PATHR =build/results/

IPATH =-I. -I $(PATHU)

INCS = libft.h
INCU +=$(PATHU)unity.h
INCU +=$(PATHU)unity_internals.h

#--------------------Part I--------------------#
SRCS +=ft_atoi.c
SRCS +=ft_bzero.c #DONE
SRCS +=ft_isalnum.c #DONE
SRCS +=ft_isalpha.c #DONE
SRCS +=ft_isascii.c #DONE
SRCS +=ft_isdigit.c #DONE
SRCS +=ft_isprint.c #DONE
SRCS +=ft_memalloc.c #DONE
SRCS +=ft_memmove.c
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
SRCS +=ft_strlcat.c
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
SRCS +=ft_itoa.c
SRCS +=ft_putchar.c
SRCS +=ft_putchar_fd.c
SRCS +=ft_putendl.c
SRCS +=ft_putendl_fd.c
SRCS +=ft_putnbr.c
SRCS +=ft_putnbr_fd.c
SRCS +=ft_putstr.c
SRCS +=ft_putstr_fd.c
SRCS +=ft_strclr.c
SRCS +=ft_strdel.c
SRCS +=ft_strequ.c
SRCS +=ft_striter.c
SRCS +=ft_striteri.c
SRCS +=ft_strjoin.c
SRCS +=ft_strmap.c
SRCS +=ft_strmapi.c
SRCS +=ft_strnequ.c
SRCS +=ft_strnew.c
SRCS +=ft_strsplit.c
SRCS +=ft_strsub.c
SRCS +=ft_strtrim.c

#--------------------Part III------------------#
SRCS +=ft_lstadd.c
SRCS +=ft_lstdel.c
SRCS +=ft_lstdelone.c
SRCS +=ft_lstiter.c
SRCS +=ft_lstmap.c
SRCS +=ft_lstnew.c

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
CFLAGS =$(WFLAGS)

TESTED =-e "s/.*ft/ft_/" -e "s/.txt/: /"
TEST_PASS ="[0-9]\+:PASS"
TEST_IGNORE ="[0-9]\+:IGNORE"
TEST_FAIL ="[0-9]\+:FAIL"
TEST_RES =-o -e $(TEST_PASS) -e $(TEST_IGNORE) -e $(TEST_FAIL)

PASS_COL =''/PASS/s//`printf "$(GREEN)PASS$(NC)"`/g''
IGNORE_COL =''/IGNORE/s//`printf "$(YELLOW)IGNORE$(NC)"`/g''
FAIL_COL =''/FAIL/s//`printf "$(RED)FAIL$(NC)"`/g''
TEST_COL =-e $(PASS_COL) -e $(IGNORE_COL) -e $(FAIL_COL)

.PHONY: all rule test do_test clean fclean t_clean re re_test done
.SILENT:

vpath %.c .
vpath %.c unity
vpath %.c test
vpath %.h unity

all : rule $(PATHO) $(NAME)

do_test: build_dir $(RESULTS) done

build_dir : $(PATHO) $(PATHB) $(PATHR)


test: t_clean do_test
$(RESULTS): $(OUT)
	@$(patsubst $(PATHR)%.txt,-./$(PATHB)%.out, $@) > $@ 2>&1
	@echo "$@" | sed $(TESTED) | tr -d '\n'
	@grep $(TEST_RES) < $@ | sed $(TEST_COL) | tr -s '\n' ' '
	@echo ""

done:
	@echo "\nDONE"

$(OUT): $(NAME) $(OBJT) $(OBJU)
	$(CC) -o $@ $< $(patsubst $(PATHB)%.out,$(PATHO)%.o,$@) $(OBJU)

rule:
	@echo "" >> dummy.c
	@$(COMPILE) $(IPATH) $(CFLAGS) dummy.c
	@$(CLEANUP) dummy.o dummy.c

$(NAME): $(OBJS)
	ar rus $@ $^
	printf "$@ is ready"

$(OBJS): $(PATHO)%.o : %.c $(INCS)
	$(COMPILE) $(OPT) $(CFLAGS) $< -o $@
	#@printf "Compiling $<\n"

$(OBJT): $(PATHO)%.o : $(PATHT)%.c $(INCS) $(INCU)
	$(COMPILE) $(IPATH) $(CFLAGS) $< -o $@

$(OBJU): $(PATHO)%.o : $(PATHU)%.c $(INCU)
	$(COMPILE) $(IPATH) $(CFLAGS) $< -o $@

$(PATHO) :
	$(MKDIR) $(PATHO)

$(PATHB):
	$(MKDIR) $(PATHB)

$(PATHR):
	$(MKDIR) $(PATHR)

clean:
	@$(CLEANUP) $(PATHO)*.o
	@echo "All *.o files removed"

t_clean:
	@$(CLEANUP) $(RESULTS)

fclean: clean
	$(CLEANUP) $(NAME)
	$(CLEANUP) $(PATHO)
	$(CLEANUP) $(PATHB)
	@echo "$(NAME) deleted"

re : fclean all

