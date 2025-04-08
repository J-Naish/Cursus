#ifndef UTILS_H
# define UTILS_H

# include "./minishell.h"

/**
 * @brief 文字列配列を解放する関数
 * 
 * @param strarr ヒープ領域の文字列配列
 */
void	free_strarr(t_strarr_heap strarr);

#endif