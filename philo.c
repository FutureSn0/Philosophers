/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:49:00 by aapryce           #+#    #+#             */
/*   Updated: 2024/04/18 16:35:14 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_stats	*philo_stats;
	int		i;

	i = 1;
	if (argc == 5 || argc == 6)
	{
		input_check(argv);
		philo_stats = assign_stats(argv);
		data_init(philo_stats);
		dinner(philo_stats);
		/* completion */
	}
	else
		error_msg();
	return (0);
}
