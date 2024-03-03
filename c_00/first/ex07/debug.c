#include <unistd.h>
#include <stdio.h>
void	write_dig(short d)
{
	if (d < 0)
	{
		d = d * -1;
	}
	d = d + 48;
	write(1, &d, 1);
}

void	ft_putnbr(int nb)
{
	int		max_base;
	short	dig_to_write;

	max_base = 1000000000;
	if (nb < 0)
	{
		write(1, "-", 1);
		// nb = nb * -1;
	}
	while (nb / 10 != 0)
	{
		dig_to_write = nb / max_base;
		nb = nb % max_base;
		max_base = max_base / 10;
		if (dig_to_write != 0)
		{
			write_dig(dig_to_write);
		}
	}
	write_dig(nb);
}

int main(){
	printf("2147483647\n");
	ft_putnbr(+2147483647);
	printf("\n");
	printf("-2147483648\n");
	ft_putnbr(-2147483648);
	printf("\n");
	printf("-1\n");
	ft_putnbr(-1);
	printf("\n");
	printf("0\n");
	ft_putnbr(0);
	printf("\n");
	printf("1\n");
	ft_putnbr(1);
	printf("\n");
	printf("1\n");
	ft_putnbr(+1);
	printf("\n");
}