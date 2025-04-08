#ifndef DEBUG_H
# define DEBUG_H

# include "./types.h"
# include "./minishell.h"

/**
 * @brief 文字列の配列を出力する関数
 * 
 * @param str_arr 出力したい文字列配列
 */
void	print_str_arr(const t_str_arr str_arr);

/**
 * @brief 真偽値の文字を取得する関数
 * 
 * @param b 真偽値
 * @return "true" | "false"
 */
t_str	bool_to_str(bool b);

/**
 * @brief 真偽値を出力する関数
 * 
 * @param b 真偽値
 */
void	print_bool(bool b);

#endif