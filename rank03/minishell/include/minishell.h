#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
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
# include "./builtins.h"
# include "./constants.h"
# include "./debug.h"
# include "./executor.h"
# include "./types.h"
# include "./utils.h"

#endif