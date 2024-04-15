/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:44:18 by aapryce           #+#    #+#             */
/*   Updated: 2024/04/15 14:16:01 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef enum e_funct
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}			t_funct;

typedef pthread_mutex_t	t_mtx;
typedef struct s_stats	t_stats;

typedef struct s_fork
{
	t_mtx	*fork;
	int		fork_id;
}	t_fork;

typedef struct s_philo
{
	unsigned int	id;
	unsigned int	meals;
	unsigned int	full; //Flag
	unsigned int	last_meal;
	t_fork			*first_fork;
	t_fork			*second_fork;
	pthread_t		thread_id;
	t_stats			*stats;
}	t_philo;

typedef struct s_stats
{
	unsigned int	n_philo;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	int		n_philo_eat; // Temporary flag if no argument present
	unsigned int	start_sim;
	unsigned int	end_sim; //Flag
	unsigned int	threads_ready_flag; //Flag
	t_mtx			stats_mtx;
	t_fork			*forks;
	t_philo			*philos;
}	t_stats;

/*UTILLS*/
int		ft_overflowcheck(long long res, int sign);
int		ft_atoi(const char *str);
void	error_msg(void);

/*ARG_CHECK*/
void	input_check(char **av);

/*THREAD_MUTEX_INIT*/
void	*ft_malloc(size_t bytes);
void	mutex_centre(t_mtx *mtx, t_funct funct);

/*DATA_INIT*/
t_stats	*assign_stats(char **argv);
void	data_init(t_stats *stats);

/* DINNER */
void	*dinner_sim(void *info);
void	dinner(t_stats *stats);

/* SET_AND_RETURN */
void	set_uint(t_mtx *mtx, unsigned int *dest, unsigned int value);
unsigned int	get_uint(t_mtx *mtx, unsigned int *value);
void	set_int(t_mtx *mtx, int *dest, int value);
unsigned int	get_int(t_mtx *mtx, unsigned *value);
unsigned int	end_sim(t_stats *stats);

/*CORDINATION*/
void	spinlock_threads(t_stats *stats);
#endif
