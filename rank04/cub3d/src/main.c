#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_level		*level;
	t_game		*game;
	int			fd;
	char		*content;

	validate_arg(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_with_error_msg("Failed to open the file\n");
	content = read_file(fd);
	close(fd);
	validate_cub(content);
	level = get_level(content);
	free(content);
	if (!level)
		return (EXIT_FAILURE);
	game = init_game(level);
	if (!game)
		return (EXIT_FAILURE);
	start_game(game);
	return (EXIT_SUCCESS);
}
