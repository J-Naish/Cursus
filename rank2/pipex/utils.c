/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 06:31:30 by nash              #+#    #+#             */
/*   Updated: 2025/02/25 21:52:32 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dup_infile(char *filepath)
{
	int	infilefd;

	infilefd = open(filepath, O_RDONLY);
	if (infilefd < 0)
		error_exit();
	safe_dup2(infilefd, STDIN_FILENO);
	close(infilefd);
}

void	dup_outfile(char *filepath)
{
	int	outfilefd;

	outfilefd = open(filepath, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (outfilefd < 0)
		error_exit();
	safe_dup2(outfilefd, STDOUT_FILENO);
	close(outfilefd);
}

char	**get_cmd_args(char const *cmd)
{
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	if (!cmd_args)
		error_exit();
	return (cmd_args);
}
