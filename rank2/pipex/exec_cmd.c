/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 03:56:49 by nash              #+#    #+#             */
/*   Updated: 2025/02/19 06:48:32 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *join_path(const char *dir, const char *cmd)
{
    size_t len_dir = strlen(dir);
    size_t len_cmd = strlen(cmd);
    char *full_path = malloc(len_dir + 1 + len_cmd + 1); // dir + '/' + cmd + '\0'
    if (!full_path)
        return (NULL);
    strcpy(full_path, dir);
    full_path[len_dir] = '/';
    strcpy(full_path + len_dir + 1, cmd);
    return full_path;
}

char *find_command_path(const char *cmd, char **envp)
{
    char *path_env = NULL;
    char *token;
    char *saveptr;
    char *full_path;

    for (int i = 0; envp[i] != NULL; i++)
    {
        if (strncmp(envp[i], "PATH=", 5) == 0)
        {
            path_env = envp[i] + 5;
            break;
        }
    }
    if (!path_env)
        return (NULL);
    char *paths = strdup(path_env);
    if (!paths)
        return (NULL);

    token = strtok_r(paths, ":", &saveptr);
    while (token != NULL)
    {
        full_path = join_path(token, cmd);
        if (!full_path)
        {
            free(paths);
            return (NULL);
        }
        if (access(full_path, X_OK) == 0)
        {
            free(paths);
            return (full_path);
        }
        free(full_path);
        token = strtok_r(NULL, ":", &saveptr);
    }
    free(paths);
    return (NULL); // command not found in PATH
}

void	exec_cmd(char *cmd, char **envp)
{
    char **args;
    char *cmd_path = NULL;

    if (strchr(cmd, '/') == NULL)
    {
        args = get_cmd_args(cmd);
        if (!args)
            error_exit();
        cmd_path = find_command_path(args[0], envp);
        if (!cmd_path)
        {
            error_exit();
        }
    }
    else
    {
        cmd_path = strdup(cmd);
        if (!cmd_path)
            error_exit();
        args = get_cmd_args(cmd);
        if (!args)
        {
            free(cmd_path);
            error_exit();
        }
    }

    if (execve(cmd_path, args, envp) == -1)
    {
        free(cmd_path);
        error_exit();
    }
}
