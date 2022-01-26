/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 10:38:05 by jeekim            #+#    #+#             */
/*   Updated: 2022/01/25 16:22:35 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_16_print(int nbr)
{
	unsigned int	n;
	char			a;
	char			*base;

	base = "0123456789abcdef";
	if (nbr < 0)//음수 처리
	{
		write(1, "-", 1);
		n = nbr * (-1);
	}
	else
		n = nbr;
	if (n >= 16)
		ft_putnbr_16_print(n / 16);
	a = base[n % 16];
	write(1, &a, 1);
}

#include <stdio.h>
int main()
{
	ft_putnbr_16_print(-100);
	ft_putnbr_16_print(333);
}
