/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cordination.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:43:43 by aapryce           #+#    #+#             */
/*   Updated: 2024/04/16 11:55:29 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	spinlock_threads(t_stats *stats)
{
	while (!get_uint(&stats->stats_mtx, &stats->threads_ready_flag))       
		;
}