/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:54:20 by aapryce           #+#    #+#             */
/*   Updated: 2024/04/26 15:23:20 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo, unsigned int sim_start)
{
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	time_to_think;

	if (!sim_start)
		write_current_status(THINKING, philo);
	if (philo->stats->n_philo % 2 == 0)
		return ;
	time_to_eat = philo->stats->time_to_eat;
	time_to_sleep = philo->stats->time_to_sleep;
	if (time_to_sleep > time_to_eat * 2)
		time_to_think = 0;
	else
		time_to_think = time_to_eat * 2 - time_to_sleep;
	ft_usleep(time_to_think * 0.42, philo->stats);
}

void	eat(t_philo *philo)
{
	mutex_centre(&philo->first_fork->fork, LOCK);
	write_current_status(TAKE_FIRST_FORK, philo);
	mutex_centre(&philo->second_fork->fork, LOCK);
	write_current_status(TAKE_SECOND_FORK, philo);
	set_uint(&philo->philo_mtx, &philo->last_meal, get_time(MILISECONDS));
	philo->meals++;
	write_current_status(EATING, philo);
	ft_usleep(philo->stats->time_to_eat, philo->stats);
	if (philo->stats->n_philo_eat > 0
		&& philo->meals == (unsigned int)philo->stats->n_philo_eat)
		set_uint(&philo->philo_mtx, &philo->full, 1);
	mutex_centre(&philo->first_fork->fork, UNLOCK);
	mutex_centre(&philo->second_fork->fork, UNLOCK);
}

void	write_current_status(t_philo_state state, t_philo *philo)
{
	long	time_elapsed;

	time_elapsed = get_time(MILISECONDS) - philo->stats->start_sim;
	if (get_uint(&philo->philo_mtx, &philo->full))
		return ;
	mutex_centre(&philo->stats->write_mtx, LOCK);
	if ((state == TAKE_FIRST_FORK || state == TAKE_SECOND_FORK)
		&& !end_of_sim(philo->stats))
		printf("%ld\t %d has taken a fork\n", time_elapsed, philo->id);
	else if (state == EATING && !end_of_sim(philo->stats))
		printf("%ld \t " GREEN "%d is eating..."
			RESET "\n", time_elapsed, philo->id);
	else if (state == SLEEPING && !end_of_sim(philo->stats))
		printf("%ld \t %d is sleeping...\n", time_elapsed, philo->id);
	else if (state == THINKING && !end_of_sim(philo->stats))
		printf("%ld \t %d is thinking...\n", time_elapsed, philo->id);
	else if (state == DEAD)
		printf("%ld \t " RED "%d is dead" RESET "\n", time_elapsed, philo->id);
	mutex_centre(&philo->stats->write_mtx, UNLOCK);
}
