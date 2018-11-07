/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testft_strlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 13:11:24 by cempassi          #+#    #+#             */
/*   Updated: 2018/10/19 08:17:20 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "libft.h"

void	testft_strlen0(void)
{
	TEST_ASSERT(ft_strlen("") == strlen(""));
}

void	testft_strlen1(void)
{
	TEST_ASSERT(ft_strlen("Yo") == strlen("Yo"));
}

void	testft_strlen2(void)
{
	TEST_ASSERT(ft_strlen("Putain") == strlen("Putain"));
}

void	testft_strlen3(void)
{
	TEST_ASSERT(ft_strlen("Mec") == strlen("Mec"));
}

void	testft_strlen4(void)
{
	TEST_ASSERT(ft_strlen(NULL) == strlen(NULL));
}

int		main(void)
{
	UNITY_BEGIN();
	RUN_TEST(testft_strlen0);
	RUN_TEST(testft_strlen1);
	RUN_TEST(testft_strlen2);
	RUN_TEST(testft_strlen3);
	RUN_TEST(testft_strlen4);
	return (UNITY_END());
}
