/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testft_memcmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:11:23 by cempassi          #+#    #+#             */
/*   Updated: 2018/10/16 01:16:37 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unity.h"

void	testft_memcmp0(void)
{
	TEST_ASSERT_EQUAL_INT(memcmp("","",10), ft_memcmp("","",10));
}

void	testft_memcmp1(void)
{
	TEST_ASSERT_EQUAL_INT(memcmp("babababababababa","babababababababa",16), ft_memcmp("babababababababa","babababababababa",16));
}

void	testft_memcmp2(void)
{
	TEST_ASSERT_EQUAL_INT(memcmp("\t\v\f\r","\t\v\f\r",5), ft_memcmp("\t\v\f\r","\t\v\f\r",5));
}

void	testft_memcmp3(void)
{
	TEST_ASSERT_EQUAL_INT(memcmp("ababababa","ababababb",10), ft_memcmp("ababababa","ababababb",10));
}

void	testft_memcmp4(void)
{
	int	i = -159;
	TEST_ASSERT_EQUAL_INT(memcmp(&i,&i,1), ft_memcmp(&i,&i,1));
}

void	testft_memcmp5(void)
{
	int i = 127;
	TEST_ASSERT_EQUAL_INT(memcmp(&i,"a",10), ft_memcmp(&i,"a",10));
}

int		main(void)
{
	UNITY_BEGIN();
	RUN_TEST(testft_memcmp0);
	RUN_TEST(testft_memcmp1);
	RUN_TEST(testft_memcmp2);
	RUN_TEST(testft_memcmp3);
	RUN_TEST(testft_memcmp4);
	RUN_TEST(testft_memcmp5);
	return (UNITY_END());
}
