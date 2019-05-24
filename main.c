#include <stdio.h>
#include "nn.h"

void	export(int *t, int n)
{
	int i = 3;
	while (i >= 0)
	{
		t[i--] = n & 1;
		n >>= 1;
	}
}

int	main()
{
	perceptron_t *p = perceptron_create(5);
	// taille 5 pour stocker les 4 pixels du motif + le neurone de sortie
	int t[4], sample, expected, valid = 0;
	printf("Detection of sample 1001:\n");
	while (valid < 16) // 16 motifs au total possibles
	{
		sample = 15;
		valid = 0;
		printf("new learning session\n");
		while (sample >= 0)
		{
			expected = (sample == 9) ? 1 : 0;
			export(t, sample);
			printf("sample: %d%d%d%d\n", t[0], t[1], t[2], t[3]);
			if (perceptron_learn(p, t, expected) == expected)
				valid++;
			sample--;
		}
	}
	printf("learning completed!\n");
	perceptron_destroy(p);
	return 0;
}