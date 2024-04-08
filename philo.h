/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:44:18 by aapryce           #+#    #+#             */
/*   Updated: 2024/04/08 17:13:28 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

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
	t_fork			*left_fork;
	t_fork			*right_fork;
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

t_stats	*init_philo(int argc, char **argv);
void	input_check(t_stats *stats, char **av);

#endif
