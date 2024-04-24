/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cordination.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:43:43 by aapryce           #+#    #+#             */
/*   Updated: 2024/04/24 15:02:28 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	spinlock_threads(t_stats *stats)
{
	while (!get_uint(&stats->stats_mtx, &stats->threads_ready_flag))
		;
}

void	thread_counter(t_mtx *mtx, unsigned int *value)
{
	mutex_centre(mtx ,LOCK);
	(*value)++;
	mutex_centre(mtx ,UNLOCK);
}

unsigned int	running_threads(t_mtx *mtx, unsigned int *threads, unsigned int n_philo)
{
	unsigned int	ready;

	ready = 0;
	mutex_centre(mtx, LOCK);
	if (*threads == n_philo)
		ready = 1;
	mutex_centre(mtx, UNLOCK);
	return (ready);
}

unsigned int	philo_died(t_philo *philo)
{
	long		elapsed;
	unsigned int	time_to_die;

	if (get_uint(&philo->philo_mtx, &philo->full))
		return (0);
	elapsed = get_time(MILISECONDS) - get_uint(&philo->philo_mtx, &philo->last_meal);
	time_to_die = philo->stats->time_to_die / 1e3;
	if (elapsed > time_to_die)
		return (1);
	return (0);
}

void	philo_desync(t_philo *philo)
{
	if (philo->stats->n_philo % 2 == 0)
	{
		if (philo->id % 2 == 0)
			ft_usleep(3e4, philo->stats);
	}
	else
	{
		if (philo->id % 2)
			thinking(philo, 1);
	}
}
