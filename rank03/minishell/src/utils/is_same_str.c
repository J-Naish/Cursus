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
// 	printf("%s\n", bool_to_str(is_same_str("test", "test")));
// 	printf("%s\n", bool_to_str(is_same_str("test1", "test")));
// 	printf("%s\n", bool_to_str(is_same_str("test", "test ")));
// 	printf("%s\n", bool_to_str(is_same_str("", "test")));
// 	printf("%s\n", bool_to_str(is_same_str("tst", "t e s t")));
// 	printf("%s\n", bool_to_str(is_same_str("t e s t", "test")));
// 	printf("%s\n", bool_to_str(is_same_str(NULL, "test")));
// }