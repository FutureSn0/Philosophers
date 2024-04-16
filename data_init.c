/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:57:42 by aapryce           #+#    #+#             */
/*   Updated: 2024/04/16 15:00:48 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_stats	*assign_stats(char **args)
{
	t_stats	*philo_stats;

	philo_stats = ft_malloc(sizeof(t_stats));
	if (!philo_stats)
		return (NULL);
	philo_stats->n_philo = ft_atoi(args[1]);
	philo_stats->time_to_die = ft_atoi(args[2]) * 1e3;
	philo_stats->time_to_eat = ft_atoi(args[3]) * 1e3;
	philo_stats->time_to_sleep = ft_atoi(args[4]) * 1e3;
	if (philo_stats->time_to_die < 6e4 || philo_stats->time_to_eat < 6e4
		|| philo_stats->time_to_sleep < 6e4)
	{
		free(philo_stats);
		error_msg();
	}
	if (args[5])
		philo_stats->n_philo_eat = ft_atoi(args[5]);
	else
		philo_stats->n_philo_eat = -1;
	return (philo_stats);
}

void	assign_forks(t_philo *philo, t_fork *forks, int position)
{
	int		nbr_philo;

	nbr_philo = philo->stats->n_philo;
	philo->first_fork = &forks[(position + 1) % nbr_philo];
	philo->second_fork = &forks[position];
	if (philo->id % 2)
	{
		philo->first_fork = &forks[position];
		philo->second_fork = &forks[(position + 1) % nbr_philo];
	}
}

void	philo_init(t_stats *stats)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < stats->n_philo)
	{
		philo = &stats->philos + i;
		philo->id = i + 1;
		philo->full = 0;
		philo->meals = 0;
		philo->stats = stats;
		assign_forks(philo, stats->forks, i);
	}
}

void	data_init(t_stats *stats)
{
	int	i;

	i = 0;
	stats->end_sim = 0;
	stats->threads_ready_flag = 0;
	stats->philos = ft_malloc(sizeof(t_philo) * stats->n_philo);
	mutex_centre(&stats->stats_mtx, INIT);
	mutex_centre(&stats->write_mtx, INIT);
	stats->forks = ft_malloc(sizeof(t_fork) * stats->n_philo);
	while (i < stats->n_philo)
	{
		mutex_centre(&stats->forks[i].fork, INIT);
		stats->forks[i].fork_id = i;
	}
	philo_init(stats);
}

/*pthread_t	*create_thread(t_stats *philo_stats, unsigned int philos)
{
	pthread_t	*philo_thread;
	int			i;

	i = 0;
	philo_thread = (pthread_t *)malloc(sizeof(pthread_t) * philos);
	if (!philo_thread)
		return (NULL);
	while (i < philos)
	{
		if (pthread_create(&philo_thread[i++], NULL, xx, philo_stats) != 0)
		{
			free(philo_thread);
			return (NULL);
		}
	}
	return (philo_thread);
}*/
