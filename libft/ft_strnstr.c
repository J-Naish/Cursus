/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishi <rnishi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:39:00 by rnishi            #+#    #+#             */
/*   Updated: 2024/05/15 14:26:29 by rnishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!haystack && len == 0)
		return (NULL);
	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && haystack[i + j] && i + j < len)
		{
			if (needle[j] != haystack[i + j])
				break ;
			j++;
		}
		if (!needle[j])
			return ((char *)&(haystack[i]));
		i++;
	}
	return (NULL);
}

// /bin/sh: line 1: 92724 Segmentation fault: 11  ./a.out 2>> error.log
// [MISSING]
// /* 115 */ ASSERT_EQ_PTR(ft_strnstr(NULL, "1", 0), strnstr(NULL, "1", 0));