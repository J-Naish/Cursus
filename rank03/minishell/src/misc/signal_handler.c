/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:53:24 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:53:24 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/misc.h"

static void	interactive_signal_handler(int signum)
{
	if (signum == SIGINT)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_signal.status = EXIT_SIGNAL_BASE + SIGINT;
	}
}

static void	execution_signal_handler(int signum)
{
	if (signum == SIGINT)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		g_signal.status = EXIT_SIGNAL_BASE + SIGINT;
	}
	else if (signum == SIGQUIT)
	{
		ft_putstr_fd("Quit: 3\n", STDOUT_FILENO);
		g_signal.status = EXIT_SIGNAL_BASE + SIGQUIT;
	}
}

void	setup_signals(void)
{
	struct sigaction	sa;

	sa.sa_handler = interactive_signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);
	signal(SIGQUIT, SIG_IGN);
}

void	setup_execution_signals(void)
{
	struct sigaction	sa;

	sa.sa_handler = execution_signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}
