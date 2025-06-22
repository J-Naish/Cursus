/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:53:48 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:53:48 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

bool	is_special_char(char c)
{
	return (c == '|' || c == '&' || c == '>' || c == '<');
}

bool	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

// int main() {
// 	print_bool((is_special_char('|')));
// 	print_bool((is_special_char('&')));
// 	print_bool((is_special_char('>')));
// 	print_bool((is_special_char('<')));
// 	print_bool((is_special_char('a')));
// 	print_bool((is_special_char('0')));
// }
// int main() {
// 	print_bool(is_space(' '));
// 	print_bool(is_space('	'));
// 	print_bool(is_space('a'));
// 	print_bool(is_space('\t'));
// 	print_bool(is_space('\v'));
// 	print_bool(is_space('\n'));
// }