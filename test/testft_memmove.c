/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testft_memmove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 11:51:37 by cempassi          #+#    #+#             */
/*   Updated: 2018/10/15 11:55:50 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unity.h"

void	testft_memmove0(void)
{
	char	dst[100];
	char	dst2[100];
	char	src[] = "Salut";
	TEST_ASSERT_EQUAL_MEMORY(memmove(dst,src,0), ft_memmove(dst2, src, 0), 6);
}

void	testft_memmove1(void)
{
	char	dst[100];
	char	dst2[100];
	char	src[] = "Salut";
	TEST_ASSERT_EQUAL_MEMORY(memmove(dst,src,6), ft_memmove(dst2, src, 6), 6);
}

void	testft_memmove2(void)
{
	char	dst[100] = "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
	char	dst2[100] = "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
	char	src[] = "Salut";
	TEST_ASSERT_EQUAL_MEMORY (memmove(dst,src,100), ft_memmove(dst2, src, 100), 100);
}

void	testft_memmove3(void)
{
	char	dst[100];
	char	dst2[100];
	char	src[100] = "Salut";
	TEST_ASSERT_EQUAL_MEMORY (memmove(dst,src,100), ft_memmove(dst2, src, 100), 100);
}

void	testft_memmove4(void)
{
	char	dst[100] = "Salut mon pote";
	char	dst2[100] = "Salut mon pote";
	TEST_ASSERT_EQUAL_MEMORY (memmove(dst,&dst[4],15), ft_memmove(dst2, &dst[4], 15), 15);
}

void	testft_memmove5(void)
{
	char	dst[100] = "Salut mon pote11111222222222223333333333444444444455555555556666666666777777777788888888889999999999";
	char	dst2[100] = "Salut mon pote11111222222222223333333333444444444455555555556666666666777777777788888888889999999999";
	TEST_ASSERT_EQUAL_MEMORY (memmove(&dst[5],dst,95), ft_memmove(&dst2[5], dst2, 95), 100);
}

void	testft_memmove6(void)
{
	char	dst[100];
	char	dst2[100];
	char	src[] = "Salut";
	TEST_ASSERT_EQUAL_MEMORY (memmove(dst,src + 20, 100), ft_memmove(dst2, src + 20, 100), 100);
}

void	testft_memmove7(void)
{
	char	dst[100];
	char	dst2[100];
	char	src[] = "Salut";
	TEST_ASSERT_EQUAL_PTR (dst, ft_memmove(dst2, src, 100));
}

int		main(void)
{
	UNITY_BEGIN();
	RUN_TEST(testft_memmove0);
	RUN_TEST(testft_memmove1);
	RUN_TEST(testft_memmove2);
	RUN_TEST(testft_memmove3);
	RUN_TEST(testft_memmove4);
	RUN_TEST(testft_memmove5);
	RUN_TEST(testft_memmove6);
	RUN_TEST(testft_memmove7);
	return (UNITY_END());
}
