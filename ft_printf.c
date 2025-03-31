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

#include "printf.h"

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
#include "printf.h"

int main() 
{
    int entero = 123;
    float flotante = 3.14159;
    double doble = 3.14159265358979;
    char caracter = 'A';
    char cadena[] = "Hola, Mundo!";
    unsigned int numero_sin_signo = 4294967295;

    // Imprimir un número entero en formato decimal
    ft_printf("Número entero (%%d): %d\n", entero);

    // Imprimir un número entero en formato octal
    ft_printf("Número entero en octal (%%o): %o\n", entero);

    // Imprimir un número entero en formato hexadecimal (minúsculas)
    ft_printf("Número entero en hexadecimal (%%x): %x\n", entero);

    // Imprimir un número entero en formato hexadecimal (mayúsculas)
    ft_printf("Número entero en hexadecimal (%%X): %X\n", entero);

    // Imprimir un número de punto flotante
    ft_printf("Número flotante (%%f): %f\n", flotante);

    // Imprimir un número de punto flotante con precisión de 2 decimales
    ft_printf("Número flotante con precisión (%%.2f): %.2f\n", flotante);

    // Imprimir un número de doble precisión (double)
    ft_printf("Número doble (%%lf): %lf\n", doble);

    // Imprimir un carácter
    ft_printf("Carácter (%%c): %c\n", caracter);

    // Imprimir una cadena de texto
    ft_printf("Cadena (%%s): %s\n", cadena);

    // Imprimir un número sin signo
    ft_printf("Número sin signo (%%u): %u\n", numero_sin_signo);

    // Imprimir un número de punto flotante con ancho de campo
    ft_printf("Número flotante con ancho de campo (%%10.2f): %10.2f\n", flotante);

    // Imprimir un número entero con ancho de campo
    ft_printf("Número entero con ancho de campo (%%10d): %10d\n", entero);

    // Imprimir un número entero con ancho de campo y relleno con ceros
    ft_printf("Número entero con relleno de ceros (%%010d): %010d\n", entero);

    // Imprimir un número en hexadecimal con ancho de campo
    ft_printf("Número en hexadecimal con ancho (%%#10x): %#10x\n", entero);

    // Imprimir dirección de memoria (puntero)
    int *puntero = &entero;
    ft_printf("Dirección de memoria del entero (%%p): %p\n", (void *)puntero);

    // Imprimir un porcentaje
    ft_printf("Porcentaje (%%): %%\n");

    return 0;
}