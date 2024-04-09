/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:44:18 by aapryce           #+#    #+#             */
/*   Updated: 2024/04/09 13:05:47 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
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

typedef struct s_fork
{
	t_mtx	*fork;
	int		fork_id;
}	t_fork;

typedef struct s_philo
{
	unsigned int	id;
	unsigned int	meals;
	unsigned int	full;
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
	unsigned int	n_philo_eat;
	unsigned int	start_sim;
	unsigned int	end_sim;
	t_fork			*forks;
	t_philo			*philos;
}	t_stats;

int		ft_overflowcheck(long long res, int sign);
int		ft_atoi(const char *str);
void	error_msg(void);

void	input_check(t_stats *stats, char **av);

void	*ft_malloc(size_t bytes);
void	mutex_centre(t_mtx *mtx, t_funct funct);

t_stats	*assign_stats(int argc, char **argv);
void	data_init(t_stats *stats);

#endif
