/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:49:00 by aapryce           #+#    #+#             */
/*   Updated: 2024/04/09 13:00:28 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_stats	*philo_stats;

	if (argc == 5 || argc == 6)
	{
		input_check(philo_stats, argv);
		philo_stats = init_philo(argc, argv);
		// dinner_start(philo_stats); //
		// clean / leak check / completion //
	}
	else
		error_msg();
}
