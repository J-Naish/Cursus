#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static int	ft_putll(long long num)
{
	int	count;

	count = 0;
	if (num < 0)
	{
		count += ft_putchar('-');
		num *= -1;
	}
	if (num < 10)
	{
		count += ft_putchar('0' + num);
	}
	else
	{
		count += ft_putll(num / 10);
		count += ft_putll(num % 10);
	}
	return (count);
}

int	ft_putint(int num)
{
	int	count;

	count = 0;
	if (num == INT_MIN)
	{
		count += ft_putll(num);
		return (count);
	}
	if (num < 0)
	{
		count += ft_putchar('-');
		num *= -1;
	}
	if (num < 10)
	{
		count += ft_putchar('0' + num);
	}
	else
	{
		count += ft_putint(num / 10);
		count += ft_putint(num % 10);
	}
	return (count);
}

int	ft_putuint(unsigned int num)
{
	int	count;

	count = 0;
	if (num < 10)
	{
		count += ft_putchar('0' + num);
	}
	else
	{
		count += ft_putuint(num / 10);
		count += ft_putuint(num % 10);
	}
	return (count);
}

int	ft_puthexadecimal(unsigned long long num, int is_upper)
{
	int	count;

	count = 0;
	if (num < 16)
	{
		if (num % 16 < 10)
			count += ft_putchar('0' + num % 16);
		else
		{
			if (is_upper)
				count += ft_putchar('A' + (num % 16) - 10);
			else
				count += ft_putchar('a' + (num % 16) - 10);
		}
	}
	else
	{
		count += ft_puthexadecimal(num / 16, is_upper);
		count += ft_puthexadecimal(num % 16, is_upper);
	}
	return (count);
}

int	ft_puthexadecimal_upper(unsigned int num)
{
	return (ft_puthexadecimal(num, 1));
}

int	ft_puthexadecimal_lower(unsigned int num)
{
	return (ft_puthexadecimal(num, 0));
}

int main()
{
  int num = 75941374;
  printf("\n%d\n", ft_puthexadecimal_lower(num));
  printf("\n%d\n", ft_puthexadecimal_upper(num));
}
