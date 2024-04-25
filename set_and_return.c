/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_and_return.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:13:30 by aapryce           #+#    #+#             */
/*   Updated: 2024/04/25 14:07:40 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_uint(t_mtx *mtx, unsigned int *dest, unsigned int value)
{
	mutex_centre(mtx, LOCK);
	*dest = value;
	mutex_centre(mtx, UNLOCK);
}

unsigned int	get_uint(t_mtx *mtx, unsigned int *value)
{
	unsigned int	res;

	mutex_centre(mtx, LOCK);
	res = *value;
	mutex_centre(mtx, UNLOCK);
	return (res);
}

unsigned int	end_of_sim(t_stats *stats)
{
	return (get_uint(&stats->stats_mtx, &stats->end_sim));
}
