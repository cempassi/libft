/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testft_strlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 13:11:24 by cempassi          #+#    #+#             */
/*   Updated: 2018/10/13 16:05:54 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "libft.h"

void	test_ft_strlen0(void)
{
	TEST_ASSERT(ft_strlen("") == strlen(""));
}

void	test_ft_strlen1(void)
{
	TEST_ASSERT(ft_strlen("Yo") == strlen("Yo"));
}

void	test_ft_strlen2(void)
{
	TEST_ASSERT(ft_strlen("Putain") == strlen("Putain"));
}

void	test_ft_strlen3(void)
{
	TEST_ASSERT(ft_strlen("Mec") == strlen("Mec"));
}

int		main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_strlen0);
	RUN_TEST(test_ft_strlen1);
	RUN_TEST(test_ft_strlen2);
	RUN_TEST(test_ft_strlen3);
	return (UNITY_END());
}
