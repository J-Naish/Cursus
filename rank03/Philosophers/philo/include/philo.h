/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 07:40:59 by nash              #+#    #+#             */
/*   Updated: 2025/04/09 01:09:14 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <stdint.h>
# include <unistd.h>
# include <time.h>
# include <sys/time.h>
# include <sys/types.h>
# include <pthread.h>
# include "./constants.h"
# include "./types.h"

// MARK: parse
// convert_to_sizet.c
size_t			convert_to_sizet(const char *s);
// init.c
t_table			*init_table(int argc, char **argv);
// validate.c
bool			is_valid_arg(int argc, char **argv);

// MARK: thread
// actions.c
void			philo_eat(t_philo *philo);
void			philo_sleep(t_philo *philo);
void			philo_think(t_philo *philo);
// helpers.c
bool			should_simulation_stop(t_monitor *monitor);
void			split_sleep(size_t duration, t_monitor *monitor);
// log.c
void			log_take_fork(t_philo *philo);
void			log_eat(t_philo *philo);
void			log_sleep(t_philo *philo);
void			log_think(t_philo *philo);
void			log_die(t_philo *philo);
// monitor.c
bool			is_one_of_philos_starving(t_table *table);
bool			have_all_philos_eaten_enough(t_table *table);
// thread.c
void			create_threads(t_table *table);

// MARK: utils
// deinit.c
void			deinit_table(t_table *table);
// time.c
struct timeval	get_current_time(void);
int				get_elapsed_time(struct timeval start_time);

#endif
