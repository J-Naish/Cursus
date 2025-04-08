#include "../../include/utils.h"

void	free_str_arr(t_str_arr_heap strarr)
{
	int	i;

	if (!strarr)
		return ;
	i = 0;
	while (strarr[i])
	{
		free(strarr[i]);
		i++;
	}
	free(strarr);
}
