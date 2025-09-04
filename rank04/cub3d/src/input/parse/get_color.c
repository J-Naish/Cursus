#include "../../../include/cub3d.h"

static t_color	init_color(void)
{
	t_color	color;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	return (color);
}

t_color	get_color(char *color_string)
{
	t_color	color;
	char	**rgb;

	color = init_color();
	rgb = ft_split(color_string, ',');
	if (!rgb)
		return (color);
	color.r = (uint8_t)ft_atoi(rgb[0]);
	color.g = (uint8_t)ft_atoi(rgb[1]);
	color.b = (uint8_t)ft_atoi(rgb[2]);
	free_strarr(rgb);
	return (color);
}
