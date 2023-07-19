/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:37:23 by gbussier          #+#    #+#             */
/*   Updated: 2023/01/16 10:44:24 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"
/*
int main(void)
{
	int	a;
	ft_put_x(16, "0123456789abcdef");
}
*/

int	pf_put_x(unsigned int nb, char *base)
{
	char	x;
	int		count;

	count = 0;
	if (nb < 16)
	{
		x = base[nb];
		count = pf_put_char(x);
	}
	else if (nb >= 16)
	{
		count = count + pf_put_x(nb / 16, base);
		count = count + pf_put_x(nb % 16, base);
	}
	return (count);
}
