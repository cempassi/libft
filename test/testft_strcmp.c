/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testft_strcmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 17:38:18 by cempassi          #+#    #+#             */
/*   Updated: 2018/10/13 14:35:42 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "libft.h"

void	test_ft_strcmp0(void)
{
	TEST_ASSERT(ft_strcmp("", "") == strcmp("", ""));
}

void	test_ft_strcmp1(void)
{
	TEST_ASSERT(ft_strcmp("Mamamia", "Mamamamia") == strcmp("Mamamia", "Mamamamia"));
}

void	test_ft_strcmp2(void)
{
	TEST_ASSERT(ft_strcmp("bababbbabbabba", "bababbbabbabbaba") == strcmp("bababbbabbabba", "bababbbabbabbaba"));
}

void	test_ft_strcmp3(void)
{
	TEST_ASSERT(ft_strcmp("\n\n\n\n\t\f\v\rlol", "\n\n\n\n\t\f\v\rlol") == strcmp("\n\n\n\n\t\f\v\rlol","\n\n\n\n\t\f\v\rlol"));
}

void	test_ft_strcmp4(void)
{
	TEST_ASSERT(ft_strcmp("\n\n\n\n\t\f\v\rlol\0", "\n\n\n\n\t\f\v\rlol") == strcmp("\n\n\n\n\t\f\v\rlol\0", "\n\n\n\n\t\f\v\rlol"));
}

void	test_ft_strcmp5(void)
{
	TEST_ASSERT(ft_strcmp("\0\n","\0\n") == strcmp("\0\n","\0\n"));
}

int		main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_strcmp0);
	RUN_TEST(test_ft_strcmp1);
	RUN_TEST(test_ft_strcmp2);
	RUN_TEST(test_ft_strcmp3);
	RUN_TEST(test_ft_strcmp4);
	RUN_TEST(test_ft_strcmp5);
	return (UNITY_END());
}
