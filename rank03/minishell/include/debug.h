#ifndef DEBUG_H
# define DEBUG_H

# include "./minishell.h"

/**
 * @brief 文字列の配列を出力する関数
 * 
 * @param strarr 出力したい文字列配列
 */
void	print_str_array(const t_strarr strarr);
/**
 * @brief 真偽値の文字を取得する関数
 * 
 * @param b 真偽値
 * @return "true" | "false"
 */
t_str	bool_to_str(bool b);

#endif