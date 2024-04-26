/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:52:48 by aapryce           #+#    #+#             */
/*   Updated: 2024/04/26 16:13:19 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup(t_stats *stats)
{
	t_philo			*philo;
	unsigned int	i;

	i = 0;
	while (i < stats->n_philo)
	{
		philo = stats->philos + i;
		mutex_centre(&philo->philo_mtx, DESTROY);
		i++;
	}
	mutex_centre(&stats->stats_mtx, DESTROY);
	mutex_centre(&stats->write_mtx, DESTROY);
	free(stats->forks);
	free(stats->philos);
	free(stats);
}
