/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:49:00 by aapryce           #+#    #+#             */
/*   Updated: 2024/04/10 14:00:16 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_stats(t_stats *philo_stats)
{
	printf("Number of philosophers: %d\n", philo_stats->n_philo);
	printf("Time to die: %d\n", philo_stats->time_to_die);
	printf("Time to eat: %d\n", philo_stats->time_to_eat);
	printf("Time to sleep: %d\n", philo_stats->time_to_sleep);
	printf("Number of times each philosopher must eat: %d\n", philo_stats->n_philo_eat);
}

int	main(int argc, char **argv)
{
	t_stats	*philo_stats;
	int		i;

	i = 1;
	if (argc == 5 || argc == 6)
	{
		input_check(argv);
		philo_stats = assign_stats(argv);
		print_stats(philo_stats);
		while (i < argc)
		{
			printf("%s\n", argv[i]);
			i++;
		}
		/*philo_stats = init_philo(argc, argv);
		dinner_start(philo_stats);
		completion */
	}
	else
		error_msg();
	return (0);
}
