#include "../rpc.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    reportable_t parent;

    char *input;
    unsigned long int output;

} my_struct_t;


void *parse_parameters(void *data)
{
    char *buf = (char *)(data);

    my_struct_t *d = (my_struct_t *)(malloc(sizeof(my_struct_t)));
    
    // taking the input as it is
    d->input = buf;

    return (void *)d;
}


void *do_work(void *data)
{
    my_struct_t *d = (my_struct_t *)(data);
    
    // primes for the hashing function to work with
    const unsigned int PRIME1 = 37;
	const unsigned int PRIME2 = 1048583;

    // the variable that will hold the result
	unsigned long int h = 0;    
    
    // the hash operation itself
    int i = 0;
	while (i<strlen(d->input)) {
		h = h * PRIME1 ^ (*d->input++ - ' ');
        i++;
	}
	h %= PRIME2;

    // saved at the output
    d->output = h;

    return data;
}



reportable_t *report(void *data)
{
    my_struct_t *d = (my_struct_t *)(data);

    d->parent.data = (char *)(malloc(255 * sizeof(char)));

    snprintf(d->parent.data, 255, "Input: \'%s\'    Output: \'%ld\'\n",d->input,d->output);
    d->parent.len = strlen(d->parent.data);

    return (reportable_t *)(data);
}

void clean_up(void *params, void *result, reportable_t *report)
{
    if (report && report->data)
    {
        free(report->data);
    }

    if (params)
    {
        free(params);
    }
}
