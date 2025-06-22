/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:54:03 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:54:04 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

t_str_arr_heap	init_str_arr(void)
{
	t_str_arr_heap	str_arr;

	str_arr = (t_str_arr_heap)malloc(sizeof(t_str_heap));
	if (!str_arr)
		return (NULL);
	*str_arr = NULL;
	return (str_arr);
}

t_str_arr_heap	append_str(t_str_arr_heap str_arr, t_str str)
{
	int				i;
	t_str_arr_heap	new;

	i = 0;
	while (str_arr[i])
		i++;
	new = (t_str_arr_heap)malloc(sizeof(t_str_heap) * (i + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (str_arr[i])
	{
		new[i] = ft_strdup(str_arr[i]);
		i++;
	}
	new[i] = ft_strdup(str);
	new[i + 1] = NULL;
	free_str_arr(str_arr);
	return (new);
}

t_str_arr_heap	dup_str_arr(t_str_arr original)
{
	int				size;
	int				i;
	t_str_arr_heap	copy;

	size = 0;
	while (original[size])
		size++;
	copy = (t_str_arr_heap)malloc(sizeof(t_str *) * (size + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (original[i])
	{
		copy[i] = ft_strdup(original[i]);
		if (!copy[i])
		{
			free_str_arr(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static int	total_len(t_str_arr str_arr, t_str connector)
{
	int	i;
	int	length;
	int	connector_len;

	length = 0;
	if (connector)
		connector_len = (int)ft_strlen(connector);
	else
		connector_len = 0;
	i = 0;
	while (str_arr[i])
	{
		length += (int)ft_strlen(str_arr[i]);
		i++;
		if (str_arr[i])
			length += connector_len;
	}
	return (length);
}

t_str_heap	join_str_arr(t_str_arr str_arr, t_str connector)
{
	int			i;
	int			j;
	int			k;
	int			pos;
	t_str_heap	s;

	s = (t_str_heap)malloc(sizeof(char) * (total_len(str_arr, connector) + 1));
	if (!s)
		return (NULL);
	i = 0;
	pos = 0;
	while (str_arr[i])
	{
		j = 0;
		while (str_arr[i][j])
			s[pos++] = str_arr[i][j++];
		i++;
		k = 0;
		while (str_arr[i] && connector && connector[k])
			s[pos++] = connector[k++];
	}
	s[pos] = '\0';
	return (s);
}

// int main() {
// 	char **test;
// 	test = init_str_arr();
// 	print_str_arr(test);
// 	test = append_str(test, "test");
// 	print_str_arr(test);
// 	test = append_str(test, "hello world");
// 	print_str_arr(test);
// 	free_str_arr(test);
// }
// int main() {
// 	char *test[] = {
// 		"hello",
// 		" ",
// 		"world",
// 		"!",
// 		NULL
// 	};
// 	char *joined = join_str_arr(test, NULL);
// 	ft_putendl_fd(joined, STDOUT_FILENO);
// 	free(joined);
// 	joined = join_str_arr(test, " ");
// 	ft_putendl_fd(joined, STDOUT_FILENO);
// 	free(joined);
// }