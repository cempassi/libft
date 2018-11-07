/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testft_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 21:04:25 by cempassi          #+#    #+#             */
/*   Updated: 2018/10/14 21:35:46 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unity.h"
#include <stdlib.h>

void	testft_atoi0(void)
{
	TEST_ASSERT_EQUAL_INT(atoi("0"), ft_atoi("0"));
}

void	testft_atoi1(void)
{
	TEST_ASSERT_EQUAL_INT(atoi("2147483647"), ft_atoi("2147483647"));
}

void	testft_atoi2(void)
{
	TEST_ASSERT_EQUAL_INT(atoi("-2147483648"), ft_atoi("-2147483648"));
}

void	testft_atoi3(void)
{
	TEST_ASSERT_EQUAL_INT(atoi("a42"), ft_atoi("a42"));
}

void	testft_atoi4(void)
{
	TEST_ASSERT_EQUAL_INT(atoi("42a"), ft_atoi("42a"));
}

void	testft_atoi5(void)
{
	TEST_ASSERT_EQUAL_INT(atoi("+-42"), ft_atoi("+-42"));
}

void	testft_atoi6(void)
{
	TEST_ASSERT_EQUAL_INT(atoi("-+42"), ft_atoi("-+42"));
}

void	testft_atoi7(void)
{
	TEST_ASSERT_EQUAL_INT(atoi("             +42"), ft_atoi("             +42"));
}

void	testft_atoi8(void)
{
	TEST_ASSERT_EQUAL_INT(atoi("             -42"), ft_atoi("             -42"));
}

void	testft_atoi9(void)
{
	TEST_ASSERT_EQUAL_INT(atoi("\t\n\v\f\r +42"), ft_atoi("\t\n\v\f\r +42"));
}

void	testft_atoi10(void)
{
	TEST_ASSERT_EQUAL_INT(atoi("\t\n\v\f\r -42"), ft_atoi("\t\n\v\f\r -42"));
}

void	testft_atoi11(void)
{
	TEST_ASSERT_EQUAL_INT(atoi("00000000000000000000000000000000000000000042"), ft_atoi("00000000000000000000000000000000000000000042"));
}

void	testft_atoi12(void)
{
	TEST_ASSERT_EQUAL_INT(atoi("000000000000000000000000000001000000042"), ft_atoi("000000000000000000000000000001000000042"));
}

int		main(void)
{
	UNITY_BEGIN();
	RUN_TEST(testft_atoi0);
	RUN_TEST(testft_atoi1);
	RUN_TEST(testft_atoi2);
	RUN_TEST(testft_atoi3);
	RUN_TEST(testft_atoi4);
	RUN_TEST(testft_atoi5);
	RUN_TEST(testft_atoi6);
	RUN_TEST(testft_atoi7);
	RUN_TEST(testft_atoi8);
	RUN_TEST(testft_atoi9);
	RUN_TEST(testft_atoi10);
	RUN_TEST(testft_atoi11);
	RUN_TEST(testft_atoi12);
	return (UNITY_END());
}
