/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivas-q <arivas-q@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:32:22 by arivas-q          #+#    #+#             */
/*   Updated: 2025/03/14 11:22:44 by arivas-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_format(char spec, va_list args, int *count)
{
	char			c;
	char			*str;
	unsigned long	ptr;

	if (spec == 'c')
	{
		c = va_arg(args, int);
		write(1, &c, 1);
		(*count)++;
	}
	else if (spec == 's')
	{
		str = va_arg(args, char *);
		ft_putstr_cnt(str, count);
	}
	else if (spec == 'p')
	{
		ptr = (unsigned long)va_arg(args, void *);
		write(1, "0x", 2);
		*count += 2;
		ft_puthex_cnt(ptr, count, "0123456789abcdef");
	}
	else
		return (put_format2(spec, args, count));
	return (*count);
}

int	put_format2(char spec, va_list args, int *count)
{
	unsigned int	u;
	int				n;

	if (spec == 'd' || spec == 'i')
	{
		n = va_arg(args, int);
		ft_putlong_cnt(n, count);
	}
	else if (spec == 'u')
	{
		u = va_arg(args, unsigned int);
		ft_putuint_cnt(u, count);
	}
	else if (spec == 'x' || spec == 'X')
	{
		u = va_arg(args, unsigned int);
		if (spec == 'x')
			ft_puthex_cnt(u, count, "0123456789abcdef");
		else
			ft_puthex_cnt(u, count, "0123456789ABCDEF");
	}
	else if (spec == '%')
		print_percentaje(count);
	return (*count);
}

void	print_percentaje(int *count)
{
	write(1, "%", 1);
	(*count)++;
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			put_format(*format, args, &count);
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

int	main()
{
	ft_printf("Impresión de un solo carácter: %c\n", 'A');
	ft_printf("Impresión de un string: %s\n", "Soy una string");
	ft_printf("Impresión de un texto o número a formato hexadecimal: %p es un texto y %p es un número\n", "me encanta cantar", 1998);
	ft_printf("Impresión de un número decimal con signo: %d\n", -314159);
	ft_printf("Impresión de un número entero: %i\n", -964);
	ft_printf("Impresión de un número decimal sin signo: %u\n", 314159);
	ft_printf("Impresión de un número hexadecimal en minúsculas: %x y otro en mayúsculas: %X\n", 1998, 1998);
	ft_printf("Impresión de el símbolo del porcentaje: %%");
}
