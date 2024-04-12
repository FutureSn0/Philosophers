/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:57:51 by aapryce           #+#    #+#             */
/*   Updated: 2024/04/11 12:53:28 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	overflow_check(int nbr, char **av, int i)
{
	if ((nbr > 0 && av[i][0] == '-') || (nbr < 0 && av[i][0] != '-'))
		error_msg();
}

int	digit_check(const char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	input_check(char **av)
{
	int		i;
	long	nbr;

	i = 1;
	while (av[i])
	{
		if (digit_check(av[i]) == 0)
			error_msg();
		nbr = ft_atoi(av[i]);
		if (nbr <= 0)
			error_msg();
		overflow_check(nbr, av, i);
		i++;
	}
}
