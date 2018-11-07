/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testft_memcpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 10:36:38 by cempassi          #+#    #+#             */
/*   Updated: 2018/10/16 15:51:01 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "libft.h"

void	testft_memcpy0(void)
{
	char	dst[100];
	char	dst2[100];
	char	src[] = "Salut";
	TEST_ASSERT_EQUAL_MEMORY(memcpy(dst,src,0), ft_memcpy(dst2, src, 0), 6);
}

void	testft_memcpy1(void)
{
	char	dst[100];
	char	dst2[100];
	char	src[] = "Salut";
	TEST_ASSERT_EQUAL_MEMORY(memcpy(dst,src,6), ft_memcpy(dst2, src, 6), 6);
}

void	testft_memcpy2(void)
{
	char	dst1[100] ="1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
	char	dst2[100] ="1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111" ;
	char	src[100] = "Salut";
	TEST_ASSERT_EQUAL_MEMORY(memcpy(dst1,src,100),ft_memcpy(dst2, src, 100), 100);
}

void	testft_memcpy3(void)
{
	char	dst[100];
	char	dst2[100];
	char	src[100] = "Salut";
	TEST_ASSERT_EQUAL_MEMORY(memcpy(dst,src,100), ft_memcpy(dst2, src, 100), 100);
}

void	testft_memcpy4(void)
{
	char	dst[100] = "Salut mon pote";
	char	dst2[100] = "Salut mon pote";
	TEST_ASSERT_EQUAL_MEMORY(memcpy(dst,&dst[4],15), ft_memcpy(dst2, &dst2[4], 15), 15);
}

void	testft_memcpy5(void)
{
	char	dst[100];
	char	dst2[100];
	char	src[100] = "Sa\0lut";
	TEST_ASSERT_EQUAL_MEMORY(memcpy(dst,src, 7), ft_memcpy(dst2, src, 7), 7);
}

void	testft_memcpy6(void)
{
	char	dst[100];
	char	src[] = "Salut";
	TEST_ASSERT_EQUAL_PTR(dst, ft_memcpy(dst, src, 100));
}

int		main(void)
{
	UNITY_BEGIN();
	RUN_TEST(testft_memcpy0);
	RUN_TEST(testft_memcpy1);
	RUN_TEST(testft_memcpy2);
	RUN_TEST(testft_memcpy3);
	RUN_TEST(testft_memcpy4);
	RUN_TEST(testft_memcpy5);
	RUN_TEST(testft_memcpy6);
	return (UNITY_END());
}
