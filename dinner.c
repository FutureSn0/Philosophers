/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 09:59:19 by aapryce           #+#    #+#             */
/*   Updated: 2024/04/15 14:15:58 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void    *dinner_sim(void *info)
{
        t_philo *philo;

        philo = (t_philo *)info;
        spinlock_threads(philo->stats);
}

void    dinner(t_stats *stats)
{
        int     i;
        
        i = 0;
		if (stats->n_philo_eat == 0)
			return ;
		else if (stats->n_philo == 1)
			/*ad_hoc*/
		else
                while (i < stats->n_philo)
				{
					thread_centre(&stats->philos[i].thread_id, dinner_sim, &stats->philos[i], CREATE); 
				}
		set_uint(&stats->stats_mtx, &stats->threads_ready_flag, 1);
}
