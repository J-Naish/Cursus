/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_shell.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:53:22 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:53:22 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/misc.h"

void	initialize_shell(void)
{
	struct termios	term;
	struct termios	orig_term;

	tcgetattr(STDIN_FILENO, &orig_term);
	term = orig_term;
	term.c_lflag |= ICANON;
	term.c_lflag |= ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
