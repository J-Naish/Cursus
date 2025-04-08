#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <term.h>
# include <curses.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"


# ifndef EXIT_UNABLE_TO_EXECUTE
#  define EXIT_UNABLE_TO_EXECUTE 126
# endif

# ifndef EXIT_NOT_FOUND
#  define EXIT_NOT_FOUND 127
# endif

# ifndef EXIT_SIGNAL_BASE
#  define EXIT_SIGNAL_BASE 128
# endif

/**
 * @brief ヒープ領域に保存されたfreeすべき文字列型です
 * 
 * char *のエイリアスです
 */
typedef char*	t_str_heap;

/**
 * @brief 文字列型(char *)のエイリアスです
 * 
 * freeする必要はありません
 */
typedef char*	t_str;


// MARK: example/
// example.c
/**
 * @brief 2乗の値に42を加算した値を求める関数  
 * 
 * 2乗の値に42を加算した値を求めますがオーバーフローを考慮しません
 * @param x 何かしらの整数値
 * @return 計算結果
 */
int	example(int x);

#endif