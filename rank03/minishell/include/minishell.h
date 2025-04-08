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
# include "./constants.h"
# include "./types.h"


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