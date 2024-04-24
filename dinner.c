/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 09:59:19 by aapryce           #+#    #+#             */
/*   Updated: 2024/04/24 14:56:51 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*one_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	spinlock_threads(philo->stats);
	set_uint(&philo->philo_mtx, &philo->last_meal, get_time(MILISECONDS));
	thread_counter(&philo->stats->stats_mtx, &philo->stats->total_threads);
	write_current_status(TAKE_FIRST_FORK, philo);
	while (!end_of_sim(philo->stats))
		usleep(200);
	return (NULL);
}

void	*monitor_sim(void *info)
{
	t_stats	*stats;
	unsigned int i;

	stats = (t_stats *)info;
	while (!running_threads(&stats->stats_mtx, &stats->total_threads, stats->n_philo))
		;
	while (!end_of_sim(stats))
	{
		i = 0;
		while (i < stats->n_philo && !end_of_sim(stats))
		{
			if (philo_died(stats->philos + i))
			{
				set_uint(&stats->stats_mtx, &stats->end_sim, 1);
				write_current_status(DEAD, stats->philos + i);
			}
			i++;
		}
	}
	return (NULL);
}

void	*dinner_sim(void *info)
{
	t_philo	*philo;

	philo = (t_philo *)info;
	spinlock_threads(philo->stats);
	set_uint(&philo->philo_mtx, &philo->last_meal, get_time(MILISECONDS));
	thread_counter(&philo->stats->stats_mtx, &philo->stats->total_threads);
	philo_desync(philo);
	while (!end_of_sim(philo->stats))
	{
		if (get_uint(&philo->philo_mtx, &philo->full))
			break ;
		eat(philo);
		write_current_status(SLEEPING, philo);
		ft_usleep(philo->stats->time_to_sleep, philo->stats);
		thinking(philo, 0);
	}
	return (NULL);
}

void	dinner(t_stats *stats)
{
	unsigned int	i;

	i = 0;
	if (stats->n_philo_eat == 0)
		return ;
	else if (stats->n_philo == 1)
		thread_centre(&stats->philos[0].thread_id, one_philo, &stats->philos[0], CREATE);
	else
		while (i < stats->n_philo)
		{
			thread_centre(&stats->philos[i].thread_id, dinner_sim,
				&stats->philos[i], CREATE);
			i++;
		}
	thread_centre(&stats->monitor, monitor_sim, stats, CREATE);
	stats->start_sim = get_time(MILISECONDS);
	set_uint(&stats->stats_mtx, &stats->threads_ready_flag, 1);
	i = 0;
	while (i < stats->n_philo)
	{
		thread_centre(&stats->philos[i].thread_id, NULL, NULL, JOIN);
		i++;
	}
	set_uint(&stats->stats_mtx, &stats->end_sim, 1);
	thread_centre(&stats->monitor, NULL, NULL, JOIN);
}
