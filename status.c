/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:54:20 by aapryce           #+#    #+#             */
/*   Updated: 2024/04/16 15:15:41 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_current_status(t_philo_state state, t_philo *philo)
{
	long	time_elapsed;

        time_elapsed = get_time(MILISECONDS) - philo->stats->start_sim;
		if (philo->full)
			return ;
		mutex_centre(&philo->stats->write_mtx, LOCK);
		if (state == TAKE_FIRST_FORK || state == TAKE_SECOND_FORK
		&& !end_of_sim(philo->stats))
			printf("%ld\t %d has taken a fork\n", time_elapsed, philo->id);
		if (state == EATING && !end_of_sim(philo->stats))
			printf("%ld \t %d is eating\n", time_elapsed, philo->id);

}