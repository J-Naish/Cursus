/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 03:30:54 by nash              #+#    #+#             */
/*   Updated: 2025/01/11 23:04:16 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
  char* buffer;
  char* start;
  char* temp;
  size_t count;

  buffer = malloc(BUFFER_SIZE);
  if (!buffer)
    return NULL;
  start = buffer;
  temp = get_next_char__malloc(fd);
  count = 0;
  while (temp && count < BUFFER_SIZE && *temp != '\n')
  {
    *buffer = *temp;
    free(temp);
    buffer++;
    count++;
    temp = get_next_char__malloc(fd);
  }

  *buffer = '\0';
  return start;
}

int main()
{
  int fd = open("test.txt", O_RDONLY);
  if (fd < 0)
  {
    perror("open");
    return 1;
  }

  char* first_line = get_next_line(fd);
  if (first_line)
  {
    printf("%s\n", first_line);
  }
  char* second_line = get_next_line(fd);
  if (second_line)
  {
    printf("%s\n", second_line);
  }
  close(fd);
  return 0;
}
