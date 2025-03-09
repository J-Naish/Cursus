/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishi <rnishi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:39:10 by rnishi            #+#    #+#             */
/*   Updated: 2024/05/15 14:26:33 by rnishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_including(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_count_set_beginning(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!ft_is_including(s1[i], set))
			break ;
		i++;
	}
	return (i);
}

static int	ft_count_set_end(char const *s1, char const *set)
{
	int	i;
	int	last;

	i = 0;
	last = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		if (!ft_is_including(s1[last - i], set))
			break ;
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		len;
	int		i;

	len = ft_strlen(s1);
	len -= (ft_count_set_beginning(s1, set) + ft_count_set_end(s1, set));
	i = 0;
	while (s1[i])
	{
		if (!ft_is_including(s1[i], set))
			break ;
		i++;
	}
	result = ft_substr(s1, (unsigned int)i, (size_t)len);
	return (result);
}
