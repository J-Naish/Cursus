/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishi <rnishi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:38:11 by rnishi            #+#    #+#             */
/*   Updated: 2024/05/15 14:26:07 by rnishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
//   char s[] = "test";
//   int c = '\0';
//   printf("My ver  : %s\n", ft_strchr(s, c));
//   printf("Original: %s\n", strchr(s, c));
//   printf("My ver  : %p\n", ft_strchr(s, c));
//   printf("Original: %p\n", strchr(s, c));
// }