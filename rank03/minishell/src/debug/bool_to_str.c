#include "../../include/debug.h"

t_str	bool_to_str(bool b)
{
	if (b)
		return (YELLOW"true"RESET);
	else
		return (YELLOW"false"RESET);
}

// int main() {
// 	printf("true is %s\n", bool_to_str(true));
// 	printf("false is %s\n", bool_to_str(false));
// }