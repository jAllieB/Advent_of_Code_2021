
/* c libraries */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


/* comparison function for qsort */

int compar(void *v1, void *v2) {
	return (*(int *)v1) - (*(int *)v2);
}


int main () {

	/* initializations */

	char *s, *tok;
	int *crabs, i, j, eleMax, minFuel = 99999999, curFuel, maxVal;

	s = malloc(sizeof(char) * 10000);
	crabs = malloc(sizeof(int) * 2048);

	
	/* parsing and storing the crab positions */

	fgets(s, 10000, stdin);

	tok = strtok(s, ",");

	crabs[0] = atoi(tok);

	for (i=1; (tok = strtok(NULL, ",")) != NULL; ++i)
		crabs[i] = atoi(tok);

	
	/* getting the number of crabs */

	eleMax = i;

	
	/* sorting the crabs' position from smallest to largest */

	qsort(crabs, eleMax, sizeof(int), (void *)compar);

	
	/* getting the largest crab sub position */

	maxVal = crabs[eleMax-1];


	/* go through every possible alignment */

	for (i=0; i<=maxVal; ++i) {
	
		/* reset current fuel usage indicator */

		curFuel = 0;


		/* add up the fuel used by each crab sub */

		for (j=0; j<eleMax; ++j)	
			curFuel += abs(crabs[j] - i);

		
		/* if this is the lowest value found so far, store it */

		if (curFuel < minFuel) minFuel = curFuel;
	}
	
	/* print puzzle solution */

	printf("Minimum Fuel Cost: %d\n", minFuel);


	/* deallocations */

	free(s);
	free(crabs);

	return 0;
}
