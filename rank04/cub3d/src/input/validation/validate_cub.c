#include "../../../include/cub3d.h"

static void	free_exit(char *content, char **lines, char *msg)
{
	free(content);
	free_strarr(lines);
	exit_with_error_msg(msg);
}

void	validate_cub(char *content)
{
	char	**lines;
	char	**map_lines;

	lines = get_lines(content);
	if (!lines)
		exit(EXIT_FAILURE);
	if (!includes_valid_texture_paths(lines))
		free_exit(content, lines, "Invalid texture config\n");
	if (!includes_valid_colors(lines))
		free_exit(content, lines,
			"Invalid color config for floor or ceiling\n");
	if (!includes_valid_map(lines))
		free_exit(content, lines, "No map found\n");
	if (!ends_with_map(lines))
		free_exit(content, lines, "Map has to be the last in the file\n");
	if (!includes_no_extraneous_line(lines))
		free_exit(content, lines, "Must not include extraneous line\n");
	map_lines = extract_map_lines(lines);
	free_strarr(lines);
	if (!map_lines)
		exit(EXIT_FAILURE);
	if (!is_valid_map(map_lines))
		free_exit(content, map_lines, "Invalid map\n");
	free_strarr(map_lines);
}

// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>
// #include <sys/wait.h>
// int main(void)
// {
// 	printf("=== Testing Map Validation ===\n");
// 	int fd;
// 	int pid;
// 	int status;
// 	// Test valid maps
// 	printf("\n--- Testing VALID maps ---\n");
// 	char *valid_maps[] = {
// 		"maps/valid/simple.cub",
// 		"maps/valid/minimal.cub",
// 		"maps/valid/complex.cub",
// 		"maps/valid/irregular.cub",
// 		"maps/valid/player_west.cub",
// 		"maps/valid/with_spaces.cub",
// 		"maps/valid/large_maze.cub",
// 		"maps/valid/empty_lines.cub",
// 		NULL
// 	};
// 	int i = 0;
// 	while (valid_maps[i]) {
// 		printf("Testing %s... ", valid_maps[i]);
// 		pid = fork();
// 		if (pid == 0) {
// 			// Child process
// 			fd = open(valid_maps[i], O_RDONLY);
// 			if (fd == -1) {
// 				printf("SKIP (file not found)\n");
// 				exit(1);
// 			}
// 			validate_cub(fd);
// 			close(fd);
// 			exit(0);  // Should reach here for valid maps
// 		} else {
// 			// Parent process
// 			waitpid(pid, &status, 0);
// 			if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
// 				printf("✅ PASS (Valid map accepted)\n");
// 			} else {
// 				printf("❌ FAIL (Valid map rejected)\n");
// 			}
// 		}
// 		i++;
// 	}
// 	// Test invalid maps
// 	printf("\n--- Testing INVALID maps ---\n");
// 	char *invalid_maps[] = {
// 		"maps/invalid/no_player.cub",
// 		"maps/invalid/multiple_players.cub",
// 		"maps/invalid/three_players.cub",
// 		"maps/invalid/open_north.cub",
// 		"maps/invalid/open_south.cub",
// 		"maps/invalid/open_east.cub",
// 		"maps/invalid/open_west.cub",
// 		"maps/invalid/open_corner.cub",
// 		"maps/invalid/missing_texture.cub",
// 		"maps/invalid/duplicate_texture.cub",
// 		"maps/invalid/invalid_color.cub",
// 		"maps/invalid/missing_color.cub",
// 		"maps/invalid/invalid_char.cub",
// 		"maps/invalid/map_before_config.cub",
// 		"maps/invalid/mixed_order.cub",
// 		"maps/invalid/extraneous_line.cub",
// 		"maps/invalid/empty_file.cub",
// 		"maps/invalid/only_config.cub",
// 		NULL
// 	};
// 	i = 0;
// 	while (invalid_maps[i]) {
// 		printf("Testing %s... ", invalid_maps[i]);
// 		pid = fork();
// 		if (pid == 0) {
// 			// Child process - redirect stderr to suppress error messages
// 			int devnull = open("/dev/null", O_WRONLY);
// 			dup2(devnull, STDERR_FILENO);
// 			close(devnull);
// 			fd = open(invalid_maps[i], O_RDONLY);
// 			if (fd == -1) {
// 				printf("SKIP (file not found)\n");
// 				exit(1);
// 			}
// 			validate_cub(fd);
// 			close(fd);
// 			exit(0);  // Should NOT reach here for invalid maps
// 		} else {
// 			// Parent process
// 			waitpid(pid, &status, 0);
// 			if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
// 				printf("✅ PASS (Invalid map rejected)\n");
// 			} else {
// 				printf("❌ FAIL (Invalid map accepted)\n");
// 			}
// 		}
// 		i++;
// 	}
// 	// Test specific error messages
// 	printf("\n--- Testing ERROR MESSAGES ---\n");
// 	// Test no player error
// 	printf("Testing no_player.cub for error message... ");
// 	fflush(stdout);
// 	pid = fork();
// 	if (pid == 0) {
// 		fd = open("maps/invalid/no_player.cub", O_RDONLY);
// 		validate_cub(fd);
// 		exit(0);
// 	} else {
// 		waitpid(pid, &status, 0);
// 		if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
// 			printf("(Should see 'Invalid map' error above)\n");
// 		}
// 	}
// 	// Test missing texture error
// 	printf("Testing missing_texture.cub for error message... ");
// 	fflush(stdout);
// 	pid = fork();
// 	if (pid == 0) {
// 		fd = open("maps/invalid/missing_texture.cub", O_RDONLY);
// 		validate_cub(fd);
// 		exit(0);
// 	} else {
// 		waitpid(pid, &status, 0);
// 		if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
// 			printf("(Should see 'Invalid texture config' error above)\n");
// 		}
// 	}
// 	// Test invalid color error
// 	printf("Testing invalid_color.cub for error message... ");
// 	fflush(stdout);
// 	pid = fork();
// 	if (pid == 0) {
// 		fd = open("maps/invalid/invalid_color.cub", O_RDONLY);
// 		validate_cub(fd);
// 		exit(0);
// 	} else {
// 		waitpid(pid, &status, 0);
// 		if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
// 			printf("(Should see 'Invalid color config' error above)\n");
// 		}
// 	}
// 	// Test map order error
// 	printf("Testing map_before_config.cub for error message... ");
// 	fflush(stdout);
// 	pid = fork();
// 	if (pid == 0) {
// 		fd = open("maps/invalid/map_before_config.cub", O_RDONLY);
// 		validate_cub(fd);
// 		exit(0);
// 	} else {
// 		waitpid(pid, &status, 0);
// 		if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
// 			printf("(Should see 'Map has to be the last' error above)\n");
// 		}
// 	}
// 	// Test extraneous line error
// 	printf("Testing extraneous_line.cub for error message... ");
// 	fflush(stdout);
// 	pid = fork();
// 	if (pid == 0) {
// 		fd = open("maps/invalid/extraneous_line.cub", O_RDONLY);
// 		validate_cub(fd);
// 		exit(0);
// 	} else {
// 		waitpid(pid, &status, 0);
// 		if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
// 			printf("(Should see 'extraneous line' error above)\n");
// 		}
// 	}
// 	printf("\n=== Map Validation Testing Complete ===\n");
// 	return (0);
// }
