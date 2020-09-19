#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{


	int **tab;
	tab = malloc( 4 * sizeof(int *));

	int i;
	i = -1;
	while ( ++i < 4)
		tab[i] = malloc( 4 * sizeof(int));

	int a = 0, b = 0;

	while (a < 4)
	{
		b = 0;
		while (b < 4)
		{
			piBuffer[a][b] = 0;
			b++;
		}
		a++;
	}

	int c = 0;
	int z = 0, y = 0;
	while (argv[1][c] != '\0')
	{
	}

	int ij = 0;
	int jj = 0;
	while (ij < 4)
	{
		jj = 0;
		while (jj < 4)
		{
			printf("%d", piBuffer[ij][jj]);
			jj++;
		}
		printf("\n");
		ij++;
	}

	return (0);
}
