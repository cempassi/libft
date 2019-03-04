/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:27:55 by cempassi          #+#    #+#             */
/*   Updated: 2019/03/04 18:16:56 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
# include "libft.h"
# define RED "124"
# define GREEN "76"
# define YELLOW "226"
# define BLUE "39"
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
