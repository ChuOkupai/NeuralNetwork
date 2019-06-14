#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "perceptron.h"

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
	srand(time(NULL));
	perceptron_t *p = perceptron_create(5);
	// taille 5 pour stocker les 4 pixels du motif + le neurone de sortie
	int session = 0, t[4], sample, expected, valid = 0, i;
	printf("Detection of sample 1001:\n");
	while (valid < 16) // 16 motifs au total possibles
	{
		session++;
		sample = 0;
		valid = 0;
		printf("Learning session %d:\n", session);
		while (sample < 16)
		{
			expected = (sample == 9) ? 1 : 0;
			export(t, sample);
			printf("sample: %d%d%d%d\n", t[0], t[1], t[2], t[3]);
			if (perceptron_learn(p, t, expected) == expected)
				valid++;
			else // wrong answer!
			{
				printf("new weights set: ");
				for (i = 1; i < p->total; i++)
					printf("%f ", p->weight[i]);
				printf("%f\n", p->weight[0]);
			}
			sample++;
		}
	}
	printf("learning completed!\n");
	perceptron_destroy(p);
	return 0;
}