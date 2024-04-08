/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:49:00 by aapryce           #+#    #+#             */
/*   Updated: 2024/04/08 17:13:54 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_t	*create_thread(t_stats *philo_stats, unsigned int philos)
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
}

int	main(int argc, char **argv)
{
	t_stats	*philo_stats;

	if (argc == 5 || argc == 6)
	{
		input_check(philo_stats, argv);
		philo_stats = init_philo(argc, argv);
	}
}
