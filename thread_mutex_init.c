/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_mutex_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:38:48 by aapryce           #+#    #+#             */
/*   Updated: 2024/04/10 13:40:27 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_malloc(size_t bytes)
{
	void	*arr;

	arr = malloc(bytes);
	if (arr == NULL)
	{
		printf("Error: malloc failed\n");
		exit(1);
	}
	return (arr);
}

/*void	mutex_centre(t_mtx *mtx, t_funct funct)
{
	if (funct == LOCK)
		pthread_mutex_lock(mtx);
	else if (funct == UNLOCK)
		pthread_mutex_unlock(mtx);
	else if (funct == INIT)
		pthread_mutex_init(mtx, NULL);
	else if (funct == DESTROY)
		pthread_mutex_destroy(mtx);
	else
	{
		printf("enum error\n");
		exit(1);
	}
}*/
