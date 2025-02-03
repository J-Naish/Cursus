/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishi <rnishi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:37:38 by rnishi            #+#    #+#             */
/*   Updated: 2024/05/15 14:25:54 by rnishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memrcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = n;
	if (!dst && !src)
		return (NULL);
	while (i > 0)
	{
		i--;
		((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (len <= 0)
		return (dst);
	if (!dst && !src)
		return (NULL);
	if (dst < src)
		ft_memcpy(dst, src, len);
	else if (dst > src)
		ft_memrcpy(dst, src, len);
	return (dst);
}
