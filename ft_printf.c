/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:44:04 by jeekim            #+#    #+#             */
/*   Updated: 2022/01/26 18:59:10 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "libft.h"

void	ft_putnbr_16_print(long long nbr)
{
	unsigned long	n;//혹시 몰라서 큰 자료형으로 넣었어.
	char			a;
	char			*base;

	base = "0123456789abcdef";
	if (nbr < 0)
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

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd('8', fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else
	{
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

int ft_printf(const char * format, ...)
{
	va_list ap;
	int		i;
	long long l;//- 그냥 42에서도 그렇고 42밖에서도 그렇고 void *로 선언해도 되나?ㅇ
	// 42밖에선 되고 42에서도 써도 되는것같아!

	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == 'c')
			ft_putchar_fd(va_arg(ap, int), 1);
		if (format[i] == 's')
			ft_putstr_fd(va_arg(ap, char *), 1);
		if (format[i] == 'p')
		{
			ft_putstr_fd("0x", 1);
			l = (long long)va_arg(ap, void *);//주소는 이렇게 가져온다 치는데 포인터가 아닌것을 void *로 가져와도 되나? 자료형을 어떻게 해야할지 모르겠어...ㅇ
			// 전현님은 문제 없는 케이스만 가정하고 했던것같대.  void *로 하는게 맞을것같아.....
			ft_putnbr_16_print(l);
		}
		if (format[i] == 'd' || format[i] == 'i')//%d로 표현하려하는데 가변인자에 int보다 큰 수 들어오면 ? ㅇ < 예외처리해줘야하나? ㅇ < 다른 사람꺼 보는데 int 범위 외의 수 안다룬듯.
			ft_putnbr_fd(va_arg(ap, int), 1);


	i++;
	}
	va_end(ap);

	return 0;
}

#include <stdio.h>

int main()
{
	int s = 100;
	printf("%i\n", s);
	ft_printf("%i\n", s);
}
