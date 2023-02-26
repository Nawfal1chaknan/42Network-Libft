/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchaknan <nchaknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:50:22 by nchaknan          #+#    #+#             */
/*   Updated: 2022/10/25 12:22:43 by nchaknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numberlen(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	insert(char *finstr, int len, long num)
{
	finstr[len] = '\0';
	if (num < 0)
	{
		finstr[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		len--;
		finstr[len] = (num % 10) + 48;
		num = num / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*finstr;
	int		len;
	long	num;

	num = n;
	len = numberlen(num);
	finstr = malloc((numberlen(num) + 1) * sizeof(char));
	if (!finstr)
		return (NULL);
	if (num == 0)
	{
		finstr[0] = '0';
		finstr[1] = '\0';
		return (finstr);
	}
	insert(finstr, len, num);
	return (finstr);
}
