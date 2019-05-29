#include <stdio.h>
#include "nn.h"

void	export(int *t, int n)
{
	int i = 2;
	while (i >= 0)
	{
		t[i--] = n & 1;
		n >>= 1;
	}
}

int	main()
{
	perceptron_t *p = perceptron_create(4);
	// 2 constantes (booléen) + un opérateur (ou / et) + le neurone de sortie
	int session = 0, t[3], sample, max, expected, valid = 0;
	printf("Detection of boolean expression:\n");
	max = 8; // 7 motifs au total possibles
	while (valid < max)
	{
		sample = 0;
		valid = 0;
		printf("Learning session %d:\n", ++session);
		while (sample < max)
		{
			export(t, sample);
			printf("sample: %d ", t[0]);
			printf((t[1] == 0) ? "or" : "and");
			printf(" %d\n", t[2]);
			expected = (t[1] == 0) ? (t[0] | t[2]) : (t[0] & t[2]);
			if (perceptron_learn(p, t, expected) == expected)
				valid++;
			sample++;
		}
	}
	printf("learning completed!\n");
	perceptron_destroy(p);
	return 0;
}