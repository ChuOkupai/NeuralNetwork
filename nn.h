#ifndef _NN_H
# define _NN_H

struct perceptron;
typedef struct perceptron perceptron_t;

perceptron_t*	perceptron_create(int size);

int	perceptron_learn(perceptron_t *p, int *sample, int expected);

void	perceptron_destroy(perceptron_t *p);

#endif