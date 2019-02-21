/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 05:38:31 by cempassi          #+#    #+#             */
/*   Updated: 2019/02/18 18:46:01 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "libft.h"

static void		signal_catch(int signal)
{
	if (WTERMSIG(signal) == SIGSEGV)
		ft_dprintf(2, "%@s\n", RED, "[SEGV]");
	if (WTERMSIG(signal) == SIGBUS)
		ft_dprintf(2, "%@s\n", RED, "[BUSE]");
	if (WTERMSIG(signal) == SIGABRT)
		ft_dprintf(2, "%@s\n", RED, "[ABRT]");
	if (WTERMSIG(signal) == SIGILL)
		ft_dprintf(2, "%@s\n", RED, "[SILL]");
	if (WTERMSIG(signal) == SIGFPE)
		ft_dprintf(2, "%@s\n", RED, "[FPEX]");
	exit(3);
}

static void		init_signal_catcher(void)
{
	if (signal(SIGBUS, signal_catch) == SIG_ERR)
		ft_dprintf(2,"Error occured catching the SIGBUS.");
	if (signal(SIGSEGV, signal_catch) == SIG_ERR)
		ft_dprintf(2,"Error occured catching the SIGSEGV.");
	if (signal(SIGABRT, signal_catch) == SIG_ERR)
		ft_dprintf(2,"Error occured catching the SIGSEGV.");
	if (signal(SIGILL, signal_catch) == SIG_ERR)
		ft_dprintf(2,"Error occured catching the SIGSEGV.");
	if (signal(SIGFPE, signal_catch) == SIG_ERR)
		ft_dprintf(2,"Error occured catching the SIGSEGV.");
}

static void		parent_manager(void)
{
	int		checker;

	wait(&checker);
	if (WIFEXITED(checker))
	{
		if (WEXITSTATUS(checker) == EXIT_SUCCESS)
			ft_printf("%@s\n", GREEN, "[OK]");
		else if (WEXITSTATUS(checker) == EXIT_FAILURE)
			ft_dprintf(2, "%@s\n", RED, "[KO]");
	}
	else if (WIFSIGNALED(checker))
		ft_dprintf(2, "%@s\n", RED, "Sig not handled");
}

int				load_test(t_stack *head, char *name, int (*f)(void))
{
	t_test	tmp;

	tmp.name = ft_strdup(name);
	tmp.test = f;
	return (ft_stckpush(head, &tmp, sizeof(t_test)));
}

int				run_test(t_stack *tests)
{
	t_test	*to_test;
	pid_t	process;
	int		checker;

	init_signal_catcher();
	while (tests->size)
	{
		to_test = (t_test *)ft_stckpop(tests);
		if ((process = fork()))
			parent_manager();
		else
		{
			ft_printf("> %s: ", to_test->name);
			checker = to_test->test();
			ft_strdel(&to_test->name);
			free(to_test);
			if (checker)
				exit(EXIT_FAILURE);
			else
				exit(EXIT_SUCCESS);
		}
	}
	return (0);
}
