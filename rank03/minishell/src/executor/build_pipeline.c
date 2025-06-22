/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_pipeline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:52:51 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:52:54 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor.h"

static void	set_operator(t_pipeline *pipeline, t_token *token)
{
	if (is_same_str(token->value, "||"))
		pipeline->operator = CHAIN_OR;
	else if (is_same_str(token->value, "&&"))
		pipeline->operator = CHAIN_AND;
}

static void	add_command_to_pipeline(t_pipeline *pipeline,
		t_token **tokens, int start, int end)
{
	pipeline->commands = append_command(pipeline->commands,
			create_command(tokens, start, end));
}

static t_pipeline	**handle_chain_operator(t_pipeline **pipelines,
		int pl_idx, t_token *token)
{
	set_operator(pipelines[pl_idx], token);
	return (append_pipeline(pipelines, init_pipeline()));
}

t_pipeline	**build_pipeline(t_token **tokens)
{
	int			i;
	int			pl_idx;
	int			start;
	t_pipeline	**pipelines;

	i = 0;
	pl_idx = 0;
	start = 0;
	pipelines = init_pipeline_arr();
	while (tokens[i])
	{
		if (is_pipe(tokens[i]) || is_chain(tokens[i]))
		{
			add_command_to_pipeline(pipelines[pl_idx], tokens, start, i);
			start = i + 1;
			if (is_chain(tokens[i]))
			{
				pipelines = handle_chain_operator(pipelines, pl_idx, tokens[i]);
				pl_idx++;
			}
		}
		i++;
	}
	add_command_to_pipeline(pipelines[pl_idx], tokens, start, i);
	return (pipelines);
}

// int main() {
// 	t_token **tokens;
// 	t_pipeline **pipelines;
// 	// test 1
// 	tokens = tokenize("echo hello world");
// 	pipelines = build_pipeline(tokens);
// 	print_pipelines(pipelines);
// 	free_tokens(tokens);
// 	free_pipelines(pipelines);
// 	// test 2
// 	tokens = tokenize("ls -la | grep .txt");
//     pipelines = build_pipeline(tokens);
//     print_pipelines(pipelines);
//     free_tokens(tokens);
//     free_pipelines(pipelines);
// 	// test 3
// 	tokens = tokenize("mkdir test && cd test");
//     pipelines = build_pipeline(tokens);
//     print_pipelines(pipelines);
//     free_tokens(tokens);
//     free_pipelines(pipelines);
// 	// test 4
// 	tokens = tokenize("cat nonexistent.txt || echo 'File not found'");
//     pipelines = build_pipeline(tokens);
//     print_pipelines(pipelines);
//     free_tokens(tokens);
//     free_pipelines(pipelines);
// 	// test 5
// 	tokens = tokenize("cat /etc/passwd | grep root | wc -l");
//     pipelines = build_pipeline(tokens);
//     print_pipelines(pipelines);
//     free_tokens(tokens);
//     free_pipelines(pipelines);
// 	// test 6
// 	tokens = tokenize("cat < input.txt | sort | uniq > output.txt");
//     pipelines = build_pipeline(tokens);
//     print_pipelines(pipelines);
//     free_tokens(tokens);
//     free_pipelines(pipelines);
// 	// test 7
// 	tokens = tokenize("ls -la && echo 'success' || echo 'failure'");
//     pipelines = build_pipeline(tokens);
//     print_pipelines(pipelines);
//     free_tokens(tokens);
//     free_pipelines(pipelines);
// 	// test 8
// 	tokens = tokenize("cat << EOF | grep hello");
//     pipelines = build_pipeline(tokens);
//     print_pipelines(pipelines);
//     free_tokens(tokens);
//     free_pipelines(pipelines);
// }