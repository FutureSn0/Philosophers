/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:44:18 by aapryce           #+#    #+#             */
/*   Updated: 2024/04/24 14:54:33 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef enum e_philo_state
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DEAD,
}	t_philo_state;

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

typedef enum e_time_unit
{
	SECONDS,
	MILISECONDS,
	MICROSECONDS,
}	t_time_unit;

typedef pthread_mutex_t	t_mtx;
typedef struct s_stats	t_stats;

typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;
}	t_fork;

typedef struct s_philo
{
	unsigned int	id; //ID of philo
	unsigned int	meals; // Amount of meals eaten
	unsigned int	full; //Flag
	unsigned int	last_meal; // tile elapsed since last meal
	t_fork			*first_fork;
	t_fork			*second_fork;
	pthread_t		thread_id;
	t_mtx			philo_mtx;
	t_stats			*stats;
}	t_philo;

typedef struct s_stats
{
	unsigned int	n_philo;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	int				n_philo_eat;
	unsigned int	start_sim;
	unsigned int	end_sim; //Flag
	unsigned int	threads_ready_flag; //Flag
	unsigned int	total_threads;
	pthread_t	monitor;
	t_mtx			stats_mtx; // Mutex for set and get
	t_mtx			write_mtx; // Mutex to write thread info 
	t_fork			*forks;
	t_philo			*philos;
}	t_stats;

/*UTILLS*/
int		ft_overflowcheck(long long res, int sign);
int		ft_atoi(const char *str);
void	error_msg(void);
long	get_time(t_time_unit time_unit);
void	ft_usleep(long usec, t_stats *stats);

/*ARG_CHECK*/
void	input_check(char **av);

/*THREAD_MUTEX_INIT*/
void	*ft_malloc(size_t bytes);
void	mutex_centre(t_mtx *mtx, t_funct funct);
void	thread_centre(pthread_t *thread, void *(*start_routine) (void *),
			void *arg, t_funct funct);

/*DATA_INIT*/
t_stats	*assign_stats(char **argv);
void	data_init(t_stats *stats);

/* DINNER */
void	*dinner_sim(void *info);
void	dinner(t_stats *stats);
void	*monitor_sim(void *info);
void	*one_philo(void *arg);

/* SET_AND_RETURN */
void	set_uint(t_mtx *mtx, unsigned int *dest, unsigned int value);
unsigned int	get_uint(t_mtx *mtx, unsigned int *value);
unsigned int	end_of_sim(t_stats *stats);

/*CORDINATION*/
void	spinlock_threads(t_stats *stats);
void	thread_counter(t_mtx *mtx, unsigned int *value);
unsigned int	running_threads(t_mtx *mtx, unsigned int *threads, unsigned int n_philo);
unsigned int	philo_died(t_philo *philo);
void	philo_desync(t_philo *philo);

/*STATUS*/
void	thinking(t_philo *philo, unsigned int sim_start);
void	eat(t_philo *philo);
void	write_current_status(t_philo_state state, t_philo *philo);

/*CLEANUP*/
void	cleanup(t_stats *stats);
#endif
