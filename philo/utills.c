/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utills.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:42:06 by aapryce           #+#    #+#             */
/*   Updated: 2024/04/26 15:06:59 by aapryce          ###   ########.fr       */
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

unsigned int	get_time(t_time_unit time_unit)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (time_unit == MILISECONDS)
		return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
	else if (time_unit == MICROSECONDS)
		return ((tv.tv_sec * 1e6) + tv.tv_usec);
	else
		error_msg();
	return (0);
}

void	ft_usleep(unsigned int usec, t_stats *stats)
{
	unsigned int	start;
	unsigned int	time_elapsed;
	unsigned int	time_remaining;

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
