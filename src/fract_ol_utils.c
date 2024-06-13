/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <adbourji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:57:23 by adbourji          #+#    #+#             */
/*   Updated: 2024/06/13 02:51:40 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (*s)
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

double	ft_atod(char *s)
{
	long	interger;
	double	fractional;
	double	pow;
	int		sign;

	interger = 0;
	fractional = 0;
	pow = 0.1;
	sign = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		++s;
	if (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -1;
	while (*s != '.' && *s)
		interger = interger * 10 + (*s++ - '0');
	if (*s == '.')
		++s;
	while (*s)
	{
		fractional += (*s - '0') * pow;
		pow *= 0.1;
		s++;
	}
	return (sign * (interger + fractional));
}
