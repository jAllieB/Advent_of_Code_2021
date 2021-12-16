
/* c libraries */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


/* compar function for qsort */

int compar(void *v1, void *v2) {
	return (*(int *)v1) - (*(int *)v2);
}


int main () {

	/* initializations */

	char *s, *tok;
	int *crabs, i, j, eleMax, minFuel = 99999999, curFuel, maxVal;

	s = malloc(sizeof(char) * 10000);
	crabs = malloc(sizeof(int) * 2048);

	
	/* parsing and storing crab starting positions */

	fgets(s, 10000, stdin);

	tok = strtok(s, ",");

	crabs[0] = atoi(tok);

	for (i=1; (tok = strtok(NULL, ",")) != NULL; ++i)
		crabs[i] = atoi(tok);

	
	/* storing the number of crabs */

	eleMax = i;


	/* sorting the crab positions from smallest to largest */

	qsort(crabs, eleMax, sizeof(int), (void *)compar);

	
	/* get the largest crab position */

	maxVal = crabs[eleMax-1];


	/* go through ever possible alignment */

	for (i=0; i<=maxVal; ++i) {

		/* reset the current fuel usage */

		curFuel = 0;
		
		
		/* add up all the individual subs' fuel usage, using the well known summation */
		/* sum (from 1 to i) of i equals (i * (i+1))/2 */

		for (j=0; j<eleMax; ++j)	
			curFuel += (abs(crabs[j] - i) * (abs(crabs[j] - i) + 1))/2;


		/* if this is the lowest fuel usage found so far, store it in minFuel */

		if (curFuel < minFuel) minFuel = curFuel;
	}

	/* print the puzzle solution */

	printf("Minimum Fuel Cost: %d\n", minFuel);


	/* deallocations */

	free(s);
	free(crabs);

	return 0;
}
