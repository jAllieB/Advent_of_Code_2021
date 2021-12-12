
/* c libraries */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* plank libraries */

#include "fields.h"

int main () {

	/* initializations */

	unsigned int aim = 0, horizontal = 0, depth = 0, x, product;
	IS is;
	is = new_inputstruct(NULL);


	/* while still recieving input (all inputs have two fields) */

	while (get_line(is) == 2) {

		/* read in the x */

		x = atoi(is->fields[1]);


		/* if forward then move x in the horizontal direction */
		/* and increase depth by aim times x, */
		/* if up then decrease aim by x */
		/* else, its down so increase aim by x */

		if (strcmp(is->fields[0], "forward") == 0) {
			horizontal += x;
			depth += aim * x;
		}
		else if (strcmp(is->fields[0], "up") == 0) aim -= x;
		else aim += x;
	}

	
	/* deallocate input struct */

	jettison_inputstruct(is);


	/* get product (puzzle solution) */

	product = horizontal * depth;


	/* print puzzle solution */

	printf("Horizontal Reading: %u\nDepth Reading: %u\nProduct: %u\n", 
			horizontal, depth, product);


	return 0;
}
