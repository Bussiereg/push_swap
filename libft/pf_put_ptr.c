/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:46:08 by gbussier          #+#    #+#             */
/*   Updated: 2023/01/16 11:36:31 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"

/* int main(void)
{
	int	a = 5;
	int b;
	int c;

    b = ft_put_ptr(&a);
	c = printf("\n%p", &a);
	printf("\n%d\n%d", b, c);
} */

int	pf_put_xlong(unsigned long nb, char *base)
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
		count = count + pf_put_xlong(nb / 16, base);
		count = count + pf_put_xlong(nb % 16, base);
	}
	return (count);
}

int	pf_put_ptr(void *ptr, char *base)
{
	int				count;
	unsigned long	result;

	result = (unsigned long)ptr;
	if ((void *)result == NULL)
		return (pf_put_str("(nil)"));
	count = pf_put_str("0x") + pf_put_xlong(result, base);
	return (count);
}
