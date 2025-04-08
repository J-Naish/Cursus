#ifndef UTILS_H
# define UTILS_H

# include "./minishell.h"

void	command_not_found(const t_str command);
void	unable_to_execute(const t_str file_path);
void	system_error(void);
void	memory_allocation_failed(void);

/**
 * @brief 文字列配列を解放する関数
 * 
 * @param strarr ヒープ領域の文字列配列
 */
void	free_str_arr(t_str_arr_heap strarr);

/**
 * @brief t_command型のオブジェクトを完全に解放する関数
 * 
 * @param command t_commandオブジェクト
 */
void	free_command(t_command *command);

/**
 * @brief 2つの文字列が完全一致するか検証する関数
 * 
 * @param s1 文字列1
 * @param s2 文字列2
 */
bool	is_same_str(const char *s1, const char *s2);

#endif