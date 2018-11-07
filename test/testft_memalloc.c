/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testft_memalloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 17:06:04 by cempassi          #+#    #+#             */
/*   Updated: 2018/10/15 21:48:14 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unity.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void	testft_memalloc0(void)
{
	void	*test;

	test = ft_memalloc(0);
	TEST_ASSERT_NULL(test);
	free(test);
}

void	testft_memalloc1(void)
{
	void	*test;

	test = ft_memalloc(1);
	if(test)
		TEST_ASSERT_EACH_EQUAL_INT8(0, test, 1);
	else
		TEST_FAIL_MESSAGE("Allocation Failed");
	free(test);
}

void	testft_memalloc2(void)
{
	void	*test;

	test = ft_memalloc(512);
	if (test)
		TEST_ASSERT_EACH_EQUAL_INT8(0, test, 512);
	else
		TEST_ASSERT_NULL_MESSAGE(test, "ALLOCATION FAILED but ptr at NULL");
	free(test);
}

void	testft_memalloc3(void)
{
	void	*test2;

	test2 = ft_memalloc(42);
	if(test2)
		TEST_ASSERT_EACH_EQUAL_INT8(0, test2, 42);
	else
		TEST_ASSERT_NULL_MESSAGE(test2, "ALLOCATION FAILED, ptr at NULL");
	free(test2);
}

void	testft_memalloc4(void)
{
	void	*test;

	test = ft_memalloc(USHRT_MAX);
	if (test)
		TEST_ASSERT_EACH_EQUAL_INT8(0, test, USHRT_MAX);
	else
		TEST_ASSERT_NULL_MESSAGE(test, "ALLOCATION FAILED, ptr at NULL");
	free(test);
}

int		main(void)
{
	UNITY_BEGIN();
	RUN_TEST(testft_memalloc0);
	RUN_TEST(testft_memalloc1);
	RUN_TEST(testft_memalloc2);
	RUN_TEST(testft_memalloc3);
	RUN_TEST(testft_memalloc4);
	return (UNITY_END());
}
