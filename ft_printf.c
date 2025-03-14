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

#include <libft.h>
#include <stdarg.h>
#include <stddef.h>

put_format (va_list *args, const char c, size_t *size)
{
	if (c == )
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	size_t	i;
	
	va_start(args, format);
	while (format)
	{
		if (format[i] = '%')
		{
			i++;
			put_format(&args, format, &size);
		}
		else
		{
			ft_putchar_fd(format[i])
			size++;
		}
		i++;
	}
}