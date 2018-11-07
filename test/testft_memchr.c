/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testft_memchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 13:24:15 by cempassi          #+#    #+#             */
/*   Updated: 2018/10/15 14:09:13 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unity.h"

void	testft_memchr0(void)
{
	TEST_ASSERT_NULL(ft_memchr("", 0, 0));
}

void	testft_memchr1(void)
{
	TEST_ASSERT_EQUAL_PTR(memchr("salut", 0, 6), ft_memchr("salut", 0, 6));
}

void	testft_memchr2(void)
{
	TEST_ASSERT_EQUAL_PTR(memchr("Mais", 'i', 5), ft_memchr("Mais", 'i', 5));
}

void	testft_memchr3(void)
{
	TEST_ASSERT_NULL(ft_memchr("abcdef", 'h', 10));
}

void	testft_memchr4(void)
{
	TEST_ASSERT_EQUAL_PTR(memchr("boboboboa", -159, 0), ft_memchr("boboboboa", -159, 0));
}

int		main(void)
{
	UNITY_BEGIN();
	RUN_TEST(testft_memchr0);
	RUN_TEST(testft_memchr1);
	RUN_TEST(testft_memchr2);
	RUN_TEST(testft_memchr3);
	RUN_TEST(testft_memchr4);
	return (UNITY_END());
}
