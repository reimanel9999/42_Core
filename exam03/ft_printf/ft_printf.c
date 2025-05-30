
#include <unistd.h>
#include <stdarg.h>

void	ft_putstr(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		*len += write (1, str++, 1);
}

void	ft_putnbr(long long nbr, int base, int *len)
{
	char *str = "0123456789abcdef";
	if (nbr < 0 && base == 10)
	{
		*len += write (1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= base)
		ft_putnbr(nbr / base, base, len);
	*len += write(1, &str[nbr % base], 1);

}

int	ft_printf(const char *str, ...)
{
	va_list ptr;
	int len;

	len = 0;
	va_start(ptr, str);
	while (*str)
	{
		if (*str != '%')
			len += write(1, str, 1);
		else if ((*str == '%' ) && *(str + 1))
		{
			str++;
			if (*str == 's')
				ft_putstr(va_arg(ptr, char *), &len);
			else if (*str == 'd')
				ft_putnbr((long long)va_arg(ptr, int), 10, &len);
			else if (*str == 'x')
				ft_putnbr((long long)va_arg(ptr, unsigned int), 16, &len);
		}
		str++;
	}
	va_end(ptr);
	return (len);
}
int main()
{
	ft_printf("%s\n", "toto");
	ft_printf("Magic %s is %d", "number", 42);
	ft_printf("\nHexadecimal for %d is %x\n", 42, 42);
}
