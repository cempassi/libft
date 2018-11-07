/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testft_memdel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:36:54 by cempassi          #+#    #+#             */
/*   Updated: 2018/10/15 17:02:15 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unity.h"
#include <stdlib.h>

void	testft_memdel0(void)
{
	void	*i;
	i = NULL;
	ft_memdel(&i);
	TEST_ASSERT_NULL(i);
}

void	testft_memdel1(void)
{
	void	*i;
	if(!(i = malloc(sizeof(char))))
		TEST_IGNORE();
	ft_memdel(&i);
	TEST_ASSERT_NULL(i);
	free(i);
}

void	testft_memdel2(void)
{
	void	*i;
	if(!(i = malloc(sizeof(char) * 1024)))
		TEST_IGNORE();
	ft_memdel(&i);
	TEST_ASSERT_NULL(i);
	free(i);
}

int		main(void)
{
	UNITY_BEGIN();
	RUN_TEST(testft_memdel0);
	RUN_TEST(testft_memdel1);
	RUN_TEST(testft_memdel2);
	return (UNITY_END());
}
