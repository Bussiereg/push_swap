/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:41:49 by gbussier          #+#    #+#             */
/*   Updated: 2023/01/11 15:15:13 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"
/*
int	main(void)
{
	int	nb;
	int	a;

	nb = -2147483648;
	a = ft_put_nbr(nb);
	printf("\n%d", a);
	return (0);
}
*/

int	pf_put_nbr(int nb)
{
	char	x;
	int		count;

	count = 0;
	if (nb == -2147483648)
		count = pf_put_str("-2147483648");
	else if (nb < 0)
	{
		count = pf_put_char('-');
		count = count + pf_put_nbr(-nb);
	}
	else if (nb >= 0 && nb <= 9)
	{
		x = nb + '0';
		count = pf_put_char(x);
	}
	else if (nb > 9)
	{
		count = count + pf_put_nbr(nb / 10);
		count = count + pf_put_nbr(nb % 10);
	}
	return (count);
}
