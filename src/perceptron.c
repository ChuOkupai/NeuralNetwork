#include <stdlib.h>
#include "perceptron.h"

// Initializes a perceptron of size n (n > 0)
perceptron_t*	perceptron_create(int n)
{
	if (n < 2)
		return NULL;
	perceptron_t *p = malloc(sizeof(perceptron_t));
	if (! p)
		return NULL;
	p->weight = malloc(n * sizeof(double));
	if (! p->weight)
	{
		free(p);
		return NULL;
	}
	p->total = n;
	while (n--)
		p->weight[n] = ((double)rand()) / RAND_MAX;
	return p;
}

// Trains a perceptron
int	perceptron_learn(perceptron_t *p, int *input, int desired)
{
	if (! p || ! input)
		return -1;
	int i, z;
	double y = 0;
	for (i = 1; i < p->total; i++)
		y += p->weight[i] * input[i - 1];
	y -= p->weight[0];
	z = (y > 0) ? 1 : 0;
	if (z != desired)
	{
		for (i = 1; i < p->total; i++)
			p->weight[i] += (desired - z) * input[i - 1];
		p->weight[0] -= (desired - z);
	}
	return z;
}

// Frees the memory of a perceptron
void	perceptron_destroy(perceptron_t *p)
{
	if (! p)
		return;
	free(p->weight);
	free(p);
}
