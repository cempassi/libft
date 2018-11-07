/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testft_bzero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 17:15:08 by cempassi          #+#    #+#             */
/*   Updated: 2018/10/14 20:59:49 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "unity.h"
#include "libft.h"
#include "limits.h"

void	testft_bzero0(void)
{
	char	test[50] = "abcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxy";
	char	test2[50] = "abcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxy";
	int		num = 50;
	bzero(test, 0);
	ft_bzero(test2, 0);
	TEST_ASSERT_EQUAL_MEMORY(test, test2, num);
}

void	testft_bzero1(void)
{
	char	test[50] = "abcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxy";
	char	test2[50] = "abcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxy";
	int		num = 50;
	bzero(test, num);
	ft_bzero(test2, num);
	TEST_ASSERT_EQUAL_MEMORY(test, test2, num);
}

void	testft_bzero2(void)
{
	char	test[100] = "abcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxy";
	char	test2[100] = "abcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxy";
	int		num = 10;

	bzero(test, num);
	ft_bzero(test2, num);
	TEST_ASSERT_EQUAL_MEMORY(test, test2, num);
}

void	testft_bzero3(void)
{
	char	test[200] = "abcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxy";
	char	test2[200] = "abcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxy";

	bzero(test, 100);
	ft_bzero(test2, 100);
	TEST_ASSERT_EQUAL_MEMORY(test, test2, 100);
}

int		main(void)
{
	UNITY_BEGIN();
	RUN_TEST(testft_bzero0);
	RUN_TEST(testft_bzero1);
	RUN_TEST(testft_bzero2);
	RUN_TEST(testft_bzero3);
	return (UNITY_END());
}
