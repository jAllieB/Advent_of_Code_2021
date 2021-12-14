
/* c libraries */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main () {

	/* initializations */

	unsigned int x1, y1, x2, y2, i, j, min, max, min2, overlap = 0;
	int **map;
	map = malloc(sizeof(int *) * 1000);
	for (i=0; i<1000; ++i) map[i] = calloc(1000, sizeof(int));
	
	
	/* while still reading in vent lines */

	while(scanf("%u,%u -> %u,%u", &x1, &y1, &x2, &y2) == 4) {

		/* all lines are assumed to be horizontal,verticle or diagonal (slope=one) */

		if (y1 == y2) {


			/* logging the vent on the mapping */

			min = (x1 < x2) ? x1 : x2;
			max = (x1 > x2) ? x1 : x2;
			for (i=min; i<=max; ++i) ++map[i][y1];

		}
		else if (x1 == x2) {

			min = (y1 < y2) ? y1 : y2;
			max = (y1 > y2) ? y1 : y2;
			for (i=min; i<=max; ++i) ++map[x1][i];
		} 
		else {

			/* line is assumed to be diagonal */

			/* initialize i and j */

			i = x1;
			j = y1;

			/* while not at the last point */

			while (i != x2) {
			
				/* incriment the point on our map */

				++map[i][j];
			
			
				/* move up or down according to orientation */

				i = (x1 < x2) ? i+1 : i-1;
				j = (y1 < y2) ? j+1 : j-1;

			}

			/* incriment the map point one last time */

			++map[i][j];
		}
	}


	/* counting up the points with overlapping vents */
	
	for (i=0; i<1000; ++i)
		for (j=0; j<1000; ++j)
			if (map[i][j] > 1)
				++overlap;


	/* printing puzzle solution */

	printf("Number of points with at least 2 vents: %u\n", overlap);


	/* deallocations */
	
	for (i=0; i<1000; ++i) free(map[i]);
	free(map);

	return 0;
}
