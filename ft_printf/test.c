#include <stdio.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		count += ft_putchar(*s);
		s++;
	}
	return (count);
}

static int	ft_puthexadecimal(unsigned long long num)
{
	int	count;

	count = 0;
	if (num < 16)
	{
		if (num % 16 < 10)
			count += ft_putchar('0' + num % 16);
		else
			count += ft_putchar('a' + (num % 16) - 10);
	}
	else
	{
		count += ft_puthexadecimal(num / 16);
		count += ft_puthexadecimal(num % 16);
	}
	return (count);
}

int	ft_putaddr(void *ptr)
{
	unsigned long long	addr;
	int					count;

	addr = (unsigned long long)ptr;
	count = 0;
	count += ft_putstr("0x");
	count += ft_puthexadecimal(addr);
	return (count);
}

int main()
{
  int x = 2;
  ft_putaddr(NULL);
  printf("\n%p\n", NULL);
}
