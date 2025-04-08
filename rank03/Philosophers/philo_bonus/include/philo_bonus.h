/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 07:41:52 by nash              #+#    #+#             */
/*   Updated: 2025/04/09 01:14:20 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <fcntl.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include "./constants_bonus.h"
# include "./types_bonus.h"

// MARK: parse/
// convert_to_sizet_bonus.c
size_t			convert_to_sizet(const char *s);
// init_bonus.c
t_table			*init_table(int argc, char **argv);
// validate_bonus.c
bool			is_valid_arg(int argc, char **argv);

// MARK: process/
// actions_bonus.c
void			philo_eat(t_philo *philo);
void			philo_sleep(t_philo *philo);
void			philo_think(t_philo *philo);
// destroy_processes_bonus.c
void			destroy_processes(t_table *table, size_t i);
// log_bonus.c
void			log_take_fork(t_philo philo);
void			log_eat(t_philo philo);
void			log_sleep(t_philo philo);
void			log_think(t_philo philo);
// monitor_process_bonus.c
void			create_monitor_process(t_table *table);
// monitor_thread_bonus.c
void			create_monitor_thread(t_philo *philo);
// process_bonus.c
void			create_processes(t_table *table);

// MARK: utils/
// deinit_bonus.c
void			deinit_table(t_table *table);
// time_bonus.c
struct timeval	get_current_time(void);
int				get_elapsed_time(struct timeval start_time);
// unlink_sems_bonus.c
void			unlink_sems(t_meta meta);

#endif
