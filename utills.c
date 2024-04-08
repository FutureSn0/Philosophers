/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utills.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:42:06 by aapryce           #+#    #+#             */
/*   Updated: 2024/04/08 17:01:28 by aapryce          ###   ########.fr       */
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
