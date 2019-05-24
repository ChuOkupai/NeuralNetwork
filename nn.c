#include <stdlib.h>
#include <stdio.h>
#include "nn.h"

struct perceptron
{
	int *w;
	int size;
};

perceptron_t*	perceptron_create(int size)
{
	if (size < 2)
		return NULL;
	perceptron_t *p = malloc(sizeof(perceptron_t));
	if (! p)
		return p;
	p->w = calloc(size, sizeof(int));
	if (! p->w)
	{
		free(p);
		return NULL;
	}
	p->size = size;
	return p;
}

int	perceptron_learn(perceptron_t *p, int *sample, int expected)
{
	if (! p || ! sample)
		return 0;
	int i, z;
	float y = 0;
	for (i = 1; i < p->size; i++)
		y += p->w[i] * sample[i - 1];
	y -= p->w[0];
	z = (y > 0) ? 1 : 0;
	if (z != expected)
	{
		for (i = 1; i < p->size; i++)
			p->w[i] += (expected - z) * sample[i - 1];
		p->w[0] -= (expected - z);
		printf("new weights: ");
		for (i = 1; i < p->size; i++)
			printf("%d ", p->w[i]);
		printf("%d\n", p->w[0]);
	}
	return z;
}

void	perceptron_destroy(perceptron_t *p)
{
	if (! p)
		return;
	free(p->w);
	free(p);
}
