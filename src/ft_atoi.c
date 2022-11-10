/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:30:23 by minseok2          #+#    #+#             */
/*   Updated: 2022/07/16 13:21:37 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

static int	check_space(const char *input)
{
	if ((*input >= 9 && 13 >= *input) || *input == ' ')
		return (1);
	else
		return (0);
}

static int	check_numeric(const char *input)
{
	if (*input >= '0' && '9' >= *input)
		return (1);
	else
		return (0);
}

static int	check_numeric_len(const char *str)
{
	size_t	length;

	length = 0;
	while (check_numeric(str))
	{
		length++;
		str++;
	}
	return (length);
}

static int	convert_to_integer(const char *str, unsigned long *number, int sign)
{
	while (check_numeric(str))
	{
		*number *= 10;
		if (sign == 1 && *number > LONG_MAX)
			return (-1);
		else if (sign == -1 && *number != 0 && *number - 1 > LONG_MAX)
			return (0);
		*number += (*str - '0');
		if (sign == 1 && *number > LONG_MAX)
			return (-1);
		else if (sign == -1 && *number != 0 && *number - 1 > LONG_MAX)
			return (0);
		str++;
	}
	return (*number * sign);
}

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned long	number;

	sign = 1;
	number = 0;
	while (check_space(str))
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str == '0')
		str++;
	if (check_numeric_len(str) > 19)
	{
		if (sign == 1)
			return (-1);
		return (0);
	}
	return (convert_to_integer(str, &number, sign));
}
