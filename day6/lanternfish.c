
/* c libraries */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* plank libraries */

#include "jval.h"
#include "jrb.h"


int main (int argc, char *argv[]) {

	/* initializations */

	unsigned int generations, i, j;
        long toBeAdded = 0, popCount = 0;
	char *s, *tok;
	JRB pop, tmp;

	
	/* command line parsing, takes generations=80 as default (solution to part one) */

	if (argc==1) generations = 80;
	else if (argc==2) generations = atoi(argv[1]);
	else {
		fprintf(stderr, "Usage: ./lanternfish1 [# of generations=80]\n");
		exit(1);
	}

	
	/* data structure initializations */

	s = malloc(sizeof(char) * 1024);
	pop = make_jrb();


	/* read in all fish gestation times and seperate into tokens */

	fgets(s, 1024, stdin);
	tok = strtok(s, ",");


	/* each node corresponds to the number of fish (val) */
	/* with a given amount of gestation time (key) */

	for (i=0; i<9; ++i) jrb_insert_int(pop, i, new_jval_l(0));
	
	/* while we still have input to read in, add fish to it's gestation time node */

	do {
		tmp = jrb_find_int(pop, atol(tok));
		if (tmp != NULL) ++(tmp->val.l);
	
	} while ((tok = strtok(NULL, ",\n")) != NULL);


	for (i=0; i<generations; ++i) {

		/* get the number of new fish to be added */
		/* equal to the number of fish with a gestation time of zero */

		toBeAdded = jrb_first(pop)->val.l;

		/* decriment all fish gestation times, */
		/* add new fish to top of gestation time, */
		/* add fish who just gave birth to 6 days list */
		
		jrb_traverse (tmp, pop) {
			if (tmp->key.i == 8) tmp->val.l = toBeAdded;
			else tmp->val.l = jrb_next(tmp)->val.l;

			if (tmp->key.i == 6) tmp->val.l += toBeAdded;
		}	
		
	}

	/* add up all the fish populations */

	jrb_traverse(tmp, pop) popCount += tmp->val.l;


	/* print puzzle solution */

	printf("Lanternfish population after %d days: %ld\n", i, popCount);


	/* deallocations */

	free(s);
	jrb_free_tree(pop);


	return 0;
}
