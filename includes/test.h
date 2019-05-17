/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:27:55 by cempassi          #+#    #+#             */
/*   Updated: 2019/05/17 13:04:49 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
# include "libft.h"
# define TEST_RED "124"
# define TEST_GREEN "76"
# define TEST_YELLOW "226"
# define TEST_BLUE "39"
# define ISTRUE 0
# define ISFALSE -1

typedef struct	s_test
{
	char	*name;
	int		(*test)(void);
}				t_test;

int				run_test(t_stack *tests);
int				load_test(t_stack *tests, char *name, int (*f)(void));
#endif
