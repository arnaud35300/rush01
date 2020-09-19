#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int **tab;
	tab = malloc(4 * sizeof(int *));

	int i;
	i = -1;
	while (++i < 4)
		tab[i] = malloc(4 * sizeof(int));

	int a = 0, b = 0;
	while (a < 4)
	{
		b = 0;
		while (b < 4)
		{
			tab[a][b] = 0;
			b++;
		}
		a++;
	}

	int ij = 0;
	int jj = 0;
	while (ij < 4)
	{
		jj = 0;
		while (jj < 4)
		{
			printf("%d", tab[ij][jj]);
			jj++;
		}
		printf("\n");
		ij++;
	}
	return (0);
}
