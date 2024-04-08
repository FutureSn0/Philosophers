/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:57:42 by aapryce           #+#    #+#             */
/*   Updated: 2024/04/08 17:06:51 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_stats	*init_philo(int argc, char **args)
{
	t_stats	*philo_stats;

	philo_stats = malloc(sizeof(t_stats));
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
		philo_stats->n_philo_eat = 1;
	return (philo_stats);
}
