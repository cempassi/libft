/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testft_memset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 00:00:10 by cempassi          #+#    #+#             */
/*   Updated: 2018/10/15 00:56:48 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unity.h"
#include "unity.h"
#include "libft.h"


void	testft_memset0(void)
{
	char	test[2]; 
	char	test2[2];

	memset(test, 0, 2);
	ft_memset(test2, 0, 2);
	TEST_ASSERT_EQUAL_MEMORY(test, test2, 2);
}

void	testft_memset1(void)
{
	char	test[2]; 

	TEST_ASSERT_EQUAL_PTR(test, ft_memset(test, 'A', 2));
}

void	testft_memset2(void)
{
	char	test[200] = "abcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxy";
	char	test2[200] = "abcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxy";

	memset(test, 'a', 200);
	ft_memset(test2, 'a', 200);
	TEST_ASSERT_EQUAL_MEMORY(test, test2, 200);
}

void	testft_memset3(void)
{
	char	test[200] = "abcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxy";
	char	test2[200] = "abcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxy";

	memset(test, -159, 200);
	ft_memset(test2, -159, 200);
	TEST_ASSERT_EQUAL_MEMORY(test, test2, 200);
}

void	testft_memset4(void)
{
	char	test[4096];
	char	test2[4096];

	memset(test, 'a', 4046);
	ft_memset(test2, 'a', 4096);
	TEST_ASSERT_EQUAL_MEMORY(test, test2, 4096);
}

void	testft_memset5(void)
{
	char	test[4096];

	TEST_ASSERT_EQUAL_PTR(test, ft_memset(test, 'a', 4096));
}

void	testft_memset6(void)
{
	char	test[4096];

	TEST_ASSERT_EQUAL_MEMORY(test, ft_memset(test, 'a', 0), 4046);
}

int		main(void)
{
	UNITY_BEGIN();
	RUN_TEST(testft_memset0);
	RUN_TEST(testft_memset1);
	RUN_TEST(testft_memset2);
	RUN_TEST(testft_memset3);
	RUN_TEST(testft_memset4);
	RUN_TEST(testft_memset5);
	RUN_TEST(testft_memset6);
	return (UNITY_END());
}
