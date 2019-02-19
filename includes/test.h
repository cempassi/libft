/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:27:55 by cempassi          #+#    #+#             */
/*   Updated: 2019/02/19 19:51:14 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H
# define TEST(x) ((t_test *)(to_test->data))->x
# include "libft.h"
# define RED "124"
# define GREEN "76"
# define YELLOW "226"
# define BLUE "39"
# define ISTRUE 0
# define ISFALSE -1

int 	run_test(t_stack *testList);
int		load_test(t_stack *tests, char *name, int (*f)(void));

typedef struct	s_test
{
	char	*name;
	int		(*test)(void);
}				t_test;
#endif
