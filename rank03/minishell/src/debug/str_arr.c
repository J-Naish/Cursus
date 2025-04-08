#include "../../include/debug.h"

static bool	is_escape_char(char c)
{
	if (c == '\a' || c == '\b' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r' || c == '\e')
		return (true);
	else
		return (false);
}

static char	deescape(char c)
{
	if (c == '\a')
		return ('a');
	else if (c == '\b')
		return ('b');
	else if (c == '\t')
		return ('t');
	else if (c == '\n')
		return ('n');
	else if (c == '\v')
		return ('v');
	else if (c == '\f')
		return ('f');
	else if (c == '\r')
		return ('r');
	else if (c == '\e')
		return ('e');
	else
		return (c);
}

static void	print_str(const t_str str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_escape_char(str[i]))
		{
			ft_putchar_fd(str[i], STDOUT_FILENO);
		}
		else
		{
			ft_putstr_fd(YELLOW"\\", STDOUT_FILENO);
			ft_putchar_fd(deescape(str[i]), STDOUT_FILENO);
			ft_putstr_fd(GREEN, STDOUT_FILENO);
		}
		i++;
	}
}

void	print_str_arr(const t_str_arr str_arr)
{
	int	i;

	i = 0;
	if (!str_arr)
	{
		ft_putstr_fd(BOLD"null\n"RESET, STDOUT_FILENO);
		return ;
	}
	ft_putstr_fd("[ ", STDOUT_FILENO);
	while (str_arr[i])
	{
		ft_putstr_fd(GREEN"\'", STDOUT_FILENO);
		print_str(str_arr[i]);
		ft_putstr_fd("\'"RESET, STDOUT_FILENO);
		i++;
		ft_putstr_fd(", ", STDOUT_FILENO);
	}
	ft_putstr_fd(BOLD"null"RESET, STDOUT_FILENO);
	ft_putstr_fd(" ]\n", STDOUT_FILENO);
}

// int main() {
// 	char *test1[] = {
// 		"lorem",
// 		"ipsum",
// 		"dollar",
// 		"sit",
// 		"ammet",
// 		NULL
// 	};
// 	print_str_arr(test1);
// 	char *test2[] = {
// 		"",
// 		"  gdsgs ",
// 		"	",
// 		"ds\nggddsf"
// 	};
// 	print_str_arr(test2);
// 	char *test3[] = {
// 		NULL
// 	};
// 	print_str_arr(test3);
// 	char **test4 = NULL;
// 	print_str_arr(test4);
// }