
/* c libraries */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* plank libraries */

#include "fields.h"


int main () {

	/* initializations */

	unsigned int horizontal = 0, depth = 0, x, product;
	IS is;
	is = new_inputstruct(NULL);

	/* while still recieving input */

	while (get_line(is) == 2) {

		/* get x from the input */

		x = atoi(is->fields[1]);


		/* forward means move the horizontal by x, */
		/* up means the depth goes down, */
		/* else its down, so the depth goes up. */

		if (strcmp(is->fields[0], "forward") == 0) horizontal += x;
		else if (strcmp(is->fields[0], "up") == 0) depth -= x;
		else depth += x;
	}

	/* deallocate the input struct */

	jettison_inputstruct(is);


	/* get the product (puzzle solution) */

	product = horizontal * depth;

	
	/* print puzzle solution */

	printf("Horizontal Reading: %u\nDepth Reading: %u\nProduct: %u\n", 
			horizontal, depth, product);


	return 0;
}
