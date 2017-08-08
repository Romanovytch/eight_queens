#include <stdio.h>
#include <unistd.h>

#define COLS 8
#define ROWS 8

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	can_be_placed(int echq[COLS][ROWS], int posx, int posy)
{
	int x;
	int y;

	x = posx;
	y = posy;
	while (x != 0)
	{
		x = x - 1;
		if (echq[x][posy] == 1)
			return (0);
	}
	x = posx;
	while (x != 7)
	{
		x = x + 1;
		if (echq[x][posy] == 1)
			return (0);
	}	
	y = posy;
	while (y != 0)
	{
		y = y - 1;
		if (echq[posx][y] == 1)
			return (0);
	}
	y = posy;
	while (x != 7)
	{
		y = y + 1;
		if (echq[posx][y] == 1)
			return (0);
}
	x = posx;
	y = posy;
	while (x != 7 && y != 7)
	{
		y = y + 1;
		x = x + 1;	
		if (echq[x][y] == 1)
			return (0);
	}
	x = posx;
	y = posy;
	while (x != 7 && y != 0)
	{
		y = y - 1;
		x = x + 1;	
		if (echq[x][y] == 1)
			return (0);
	}
	x = posx;
	y = posy;
	while (x != 0 && y != 0)
	{
		y = y - 1;
		x = x - 1;	
		if (echq[x][y] == 1)
			return (0);
	}
	x = posx;
	y = posy;
	while (x != 0 && y != 7)
	{
		y = y + 1;
		x = x - 1;	
		if (echq[x][y] == 1)
			return (0);
	}
//	printf("Posx: %d, Posy : %d\n", posx, posy);
	return (1);
}

int	recursive_eight_queens(int echq[COLS][ROWS], int posx, int nb)
{
	int posy;

	posy = 0;
	while (posy < 8)
	{
		if (can_be_placed(echq, posx, posy) == 1)
		{
			echq[posx][posy] = 1;
			if (posx == 0)
				ft_putchar('d');
			ft_putchar(posx + '0');
			ft_putchar(posy + '0');
			nb = recursive_eight_queens(echq, posx + 1, nb);
			ft_putchar(' ');
			if (posx == 7)
			{ 
				ft_putchar('\n');
				nb = nb + 1;
			}
			echq[posx][posy] = 0;
		}
	posy = posy + 1;
	}
	return (nb);
}

int	ft_eight_queens_puzzle()
{
	int echq[COLS][ROWS];
	int nb;
	int i;
	int j;

	i = 0;
	nb = 0;
	while (i < 8)
	{
	j = 0;
		while (j < 8)
			echq[i][j++] = 0;
	i = i + 1;
	}
	nb = recursive_eight_queens(echq, 0, 0);
	return (nb);
}


int	main()
{
	int nb;
	nb = 0;

	nb = ft_eight_queens_puzzle();
	printf("Solutions of eight queens puzzle : %d\n", nb);
}



