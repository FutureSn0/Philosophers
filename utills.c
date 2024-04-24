/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utills.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:42:06 by aapryce           #+#    #+#             */
/*   Updated: 2024/04/24 13:50:38 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_overflowcheck(long long res, int sign)
{
	if (res < 0)
	{
		if (sign == 1)
			return (-1);
		return (0);
	}
	return ((int) sign * res);
}

int	ft_atoi(const char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*(str + 1) == '-' || *(str + 1) == '+')
			return (0);
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (ft_overflowcheck(res, sign));
}

void	error_msg(void)
{
	printf("Error: invalid input\n");
	exit(1);
}

long	get_time(t_time_unit time_unit)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (time_unit == SECONDS)
		return (tv.tv_sec + (tv.tv_usec / 1e6));
	else if (time_unit == MILISECONDS)
		return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
	else if (time_unit == MICROSECONDS)
		return ((tv.tv_sec * 1e6) + tv.tv_usec);
	else
		error_msg();
	return (0);
}

/* Custom usleep cosistenly checks if sleep time has passed and if
the simulation has ended breaking loop if true. This makes it more percise,
but more CPU intense than reglar usleep */

void	ft_usleep(long usec, t_stats *stats)
{
	long	start;
	long	time_elapsed;
	long	time_remaining;

	start = get_time(MICROSECONDS);
	while (get_time(MICROSECONDS) - start < usec)
	{
		if (end_of_sim(stats))
			break ;
		time_elapsed = get_time(MICROSECONDS) - start;
		time_remaining = usec - time_elapsed;
		if (time_remaining > 1e3)
			usleep(time_remaining / 2);
		else
			while (get_time(MICROSECONDS) - start < usec)
				;
	}
}
