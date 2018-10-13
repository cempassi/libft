CC = Clang
COMPILE = $(CC) -c

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
CLEANUP = rm -rf
MKDIR = mkdir -p

PATHO =objs/
PATHU =unity/
PATHT =test/
PATHB =build/
PATHR =build/results/
PATHI =./

IPATH =-I. -I$(PATHU)

INCS = $(PATHI)libft.h
INCU +=$(PATHU)unity.h
INCU +=$(PATHU)unity_internals.h

SRCS +=ft_strlen.c
SRCS +=ft_strcmp.c
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

TESTED =-e 's/.*\(ft*.\)/\1/' -e 's/.txt/ :/'
TEST_PASS ='s/.*\([0-9]:PASS\).*/\1/p'
TEST_IGNORE ="s/.*\([0-9]:IGNORE\).*/\1/p"
TEST_FAIL ="s/.*\([0-9]:FAIL\).*/\1/p"
TEST_RES =-n -e $(TEST_PASS) -e $(TEST_IGNORE) -e $(TEST_FAIL)

PASS_COL =''/PASS/s//`printf "$(GREEN)PASS$(NC)"`/g''
IGNORE_COL =''/IGNORE/s//`printf "$(YELLOW)IGNORE$(NC)"`/g''
FAIL_COL =''/FAIL/s//`printf "$(RED)FAIL$(NC)"`/g''
TEST_COL =-e $(PASS_COL) -e $(IGNORE_COL) -e $(FAIL_COL)

.PHONY: all test do_test clean fclean t_clean re re_test

vpath %.c .
vpath %.c unity
vpath %.c test
vpath %.h unity

all : $(PATHO) $(NAME)

test: build_dir do_test

build_dir : $(PATHO) $(PATHB) $(PATHR)

do_test : $(RESULTS)

$(RESULTS): $(OUT)
	@$(patsubst $(PATHR)%.txt,./$(PATHB)%.out, $@) > $@ 2>&1
	@echo "$@" | sed $(TESTED)
	@sed $(TEST_RES) < $@ | sed $(TEST_COL) | tr -s '\n' ' '
	@echo "\nDONE"

$(OUT): $(OBJS) $(OBJT) $(OBJU)
	@$(CC) -o $@ $(patsubst $(PATHB)test%.out,$(PATHO)%.o,$@) $(patsubst $(PATHB)%.out,$(PATHO)%.o,$@) $(OBJU)

$(NAME): $(OBJS)
	@ar rus $@ $^

$(OBJS): $(PATHO)%.o : %.c $(INCS)
	@$(COMPILE) $(CFLAGS) $< -o $@

$(OBJT): $(PATHO)%.o : $(PATHT)%.c $(INCS) $(INCU)
	@$(COMPILE) $(IPATH) $(CFLAGS) $< -o $@

$(OBJU): $(PATHO)%.o : $(PATHU)%.c $(INCU)
	@$(COMPILE) $(IPATH) $(CFLAGS) $< -o $@

$(PATHO):
	@$(MKDIR) $(PATHO)

$(PATHB):
	@$(MKDIR) $(PATHB)

$(PATHR):
	@$(MKDIR) $(PATHR)

clean:
	@$(CLEANUP) $(PATHO)*.o
	@echo "All *.o files removed"

t_clean:
	@$(CLEANUP) $(RESULTS)

fclean : clean
	$(CLEANUP) $(NAME)
	$(CLEANUP) $(PATHO)
	$(CLEANUP) $(PATHB)
	@echo "$(NAME) deleted"

re : fclean all

re_test: t_clean test
