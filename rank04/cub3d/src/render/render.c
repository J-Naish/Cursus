#include "../../include/cub3d.h"

static void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	get_texture_color(t_texture *texture, int x, int y)
{
	char	*pixel;

	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return (0);
	pixel = texture->addr + (y * texture->line_length
			+ x * (texture->bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
}

static int	get_wall_texture_index(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->step_x > 0)
			return (2);
		else
			return (3);
	}
	else
	{
		if (ray->step_y > 0)
			return (1);
		else
			return (0);
	}
}

static void	calculate_texture_coordinates(t_ray *ray, t_player *player,
		t_texture *texture)
{
	if (ray->side == 0)
		ray->wall_x = player->position.y + ray->perp_wall_dist * ray->dir.y;
	else
		ray->wall_x = player->position.x + ray->perp_wall_dist * ray->dir.x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)texture->width);
	if (ray->side == 0 && ray->dir.x > 0)
		ray->tex_x = texture->width - ray->tex_x - 1;
	if (ray->side == 1 && ray->dir.y < 0)
		ray->tex_x = texture->width - ray->tex_x - 1;
}

void	draw_vertical_line(t_game *game, int x, t_ray *ray)
{
	int			y;
	int			color;
	int			tex_index;
	t_texture	*texture;
	double		step;
	double		tex_pos;

	tex_index = get_wall_texture_index(ray);
	texture = &game->textures[tex_index];
	calculate_texture_coordinates(ray, &game->player, texture);
	step = 1.0 * texture->height / ray->line_height;
	tex_pos = (ray->draw_start - WINDOW_HEIGHT / 2
			+ ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		ray->tex_y = (int)tex_pos & (texture->height - 1);
		tex_pos += step;
		color = get_texture_color(texture, ray->tex_x, ray->tex_y);
		my_mlx_pixel_put(&game->img, x, y, color);
		y++;
	}
}

void	draw_floor_and_ceiling(t_game *game, int x)
{
	int	y;
	int	floor_color;
	int	ceiling_color;

	floor_color = (game->level->floor.r << 16)
		| (game->level->floor.g << 8) | game->level->floor.b;
	ceiling_color = (game->level->ceiling.r << 16)
		| (game->level->ceiling.g << 8) | game->level->ceiling.b;
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		if (y < WINDOW_HEIGHT / 2)
			my_mlx_pixel_put(&game->img, x, y, ceiling_color);
		else
			my_mlx_pixel_put(&game->img, x, y, floor_color);
		y++;
	}
}
