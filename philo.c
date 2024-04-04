/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:49:00 by aapryce           #+#    #+#             */
/*   Updated: 2024/04/04 16:11:29 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_t	*create_thread(t_stats *philo_stats, unsigned int philos)
{
	pthread_t	*philo_thread;
	int	i;

	i = 0;

	philo_thread = (pthread_t *)malloc(sizeof(pthread_t) * philos);
	if (!philo_thread)
		return (NULL);
	while (i < philos)
	{
		if (pthread_create(&philo_thread[i++], NULL, xx, philo_stats) != 0);
		{
			free(philo_thread);
			return (NULL);
		}
	}
	return (philo_thread);
}

t_stats	*init_philo(int argc, char **args)
{
	t_stats	*philo_stats;

	philo_stats = malloc(sizeof(t_stats));
	philo_stats->n_philo = ft_atoi(args[1]);
	philo_stats->time_to_die = ft_atoi(args[2]);
	philo_stats->time_to_eat = ft_atoi(args[3]);
	philo_stats->time_to_sleep = ft_atoi(args[4]);
	if (args[5])
		philo_stats->n_philo_eat = ft_atoi(args[5]);
	return (philo_stats);
}

int	main(int argc, char **argv)
{
	t_stats	*philo_stats;

	if (argc == 5 || argc == 6)
	{
		philo_stats = init_philo(argc, argv);
	}
}
