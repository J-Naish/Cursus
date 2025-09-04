/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishi <rnishi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:38:06 by rnishi            #+#    #+#             */
/*   Updated: 2024/05/15 14:26:06 by rnishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strarrlen(char const *s, char c)
{
	int	i;
	int	count;
	int	has_entered_c;

	i = 0;
	count = 0;
	has_entered_c = 1;
	if (s[0] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] == c)
		{
			if (!has_entered_c)
				count += 1;
			has_entered_c = 1;
		}
		else
			has_entered_c = 0;
		i++;
	}
	if (!(s[i - 1] == c))
		count += 1;
	return (count);
}

static int	ft_strsize(char const *s, char c, int i)
{
	int	count;

	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			break ;
		i++;
		count++;
	}
	return (count);
}

static void	ft_skip_c(char const *s, char c, int *current_index)
{
	while (s[*current_index])
	{
		if (s[*current_index] == c)
			*current_index += 1;
		else
			break ;
	}
}

static int	ft_free_all(char **strarr, int strarrlen)
{
	int	i;
	int	j;
	int	has_null_element;

	i = 0;
	has_null_element = 0;
	while (i <= strarrlen)
	{
		if (!strarr[i])
		{
			j = 0;
			while (j <= i)
			{
				free(strarr[j]);
				j++;
			}
			has_null_element = 1;
			free(strarr);
			break ;
		}
		i++;
	}
	return (has_null_element);
}

char	**ft_split(char const *s, char c)
{
	char	**strarr;
	int		strarrlen;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	strarrlen = ft_strarrlen(s, c);
	strarr = (char **)malloc((strarrlen + 1) * sizeof(char *));
	if (!strarr)
		return (NULL);
	i = 0;
	j = 0;
	while (i < strarrlen && s[0] != '\0')
	{
		ft_skip_c(s, c, &j);
		strarr[i] = ft_substr(s, j, ft_strsize(s, c, j));
		if (ft_free_all(strarr, i))
			return (NULL);
		j += ft_strsize(s, c, j);
		i++;
	}
	strarr[i] = (NULL);
	return (strarr);
}
