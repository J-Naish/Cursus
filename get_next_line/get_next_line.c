/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 03:30:54 by nash              #+#    #+#             */
/*   Updated: 2025/01/10 21:03:17 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char *get_next_line(int fd)
{
  char* buffer;
  size_t bytes;
  int bytes_read;

  buffer = malloc(BUFFER_SIZE);
  bytes = sizeof(buffer);
  bytes_read = read(fd, buffer, bytes);
  if (bytes_read == -1)
  {
    return NULL;
  }
  return buffer;
}