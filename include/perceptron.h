#ifndef _PERCEPTRON_H
# define _PERCEPTRON_H

typedef struct perceptron
{
	double *weight;
	int total;
}	perceptron_t;

// Initializes a perceptron of size n (n > 0)
perceptron_t*	perceptron_create(int n);

// Trains a perceptron
int	perceptron_learn(perceptron_t *p, int *input, int desired);

// Frees the memory of a perceptron
void	perceptron_destroy(perceptron_t *p);

#endif