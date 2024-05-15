/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishi <rnishi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:39:15 by rnishi            #+#    #+#             */
/*   Updated: 2024/05/15 14:26:35 by rnishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	s_len;
	unsigned int	buffer_size;
	char			*substr;
	size_t			i;

	s_len = (unsigned int)ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if ((unsigned int)len > s_len - start)
		buffer_size = s_len - start;
	else
		buffer_size = len;
	substr = (char *)malloc((buffer_size + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// int main()
// {
//   char s[] = "Hello,World";
//   unsigned int start = 12;
//   size_t len = 10;
//   printf("%s\n", ft_substr(s, start, len));
// }