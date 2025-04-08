#ifndef UTILS_H
# define UTILS_H

# include "./minishell.h"

/**
 * @brief 文字列配列を解放する関数
 * 
 * @param strarr ヒープ領域の文字列配列
 */
void	free_str_arr(t_str_arr_heap strarr);

bool	is_same_str(const char *s1, const char *s2);

#endif