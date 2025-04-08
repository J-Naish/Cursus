#include "../../include/utils.h"

bool	is_same_str(const char *s1, const char *s2)
{
	size_t	s1_len;

	if (!s1 || !s2)
		return (false);
	s1_len = ft_strlen(s1);
	if (s1_len != ft_strlen(s2))
		return (false);
	if (ft_strncmp(s1, s2, s1_len) == 0)
		return (true);
	else
		return (false);
}

// int main() {
// 	print_bool((is_same_str("test", "test")));
// 	print_bool((is_same_str("test1", "test")));
// 	print_bool((is_same_str("test", "test ")));
// 	print_bool((is_same_str("", "test")));
// 	print_bool((is_same_str("tst", "t e s t")));
// 	print_bool((is_same_str("t e s t", "test")));
// 	print_bool((is_same_str(NULL, "test")));
// }