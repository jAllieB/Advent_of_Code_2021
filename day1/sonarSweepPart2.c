
/* C libraries */

#include <stdio.h>
#include <stdlib.h>

int main () {

	/* initializations */

	unsigned int curDepth, incDepth = 0, window1 = 0, window2 = 0, window3 = 0;


	/* log the first three depth readings */

	scanf("%u", &curDepth);
	window1 += curDepth;

	scanf("%u", &curDepth);
	window1 += curDepth;
	window2 += curDepth;

	scanf("%u", &curDepth);
	window1 += curDepth;
	window2 += curDepth;
	window3 += curDepth;


	/* while there are still depth readings to log */

	while (1) {
	
		/* log current reading, break if no readings left */

		scanf("%u", &curDepth);
		if (feof(stdin)) break;

		
		/* add the (third and final) depth to window2 */

		window2 += curDepth;
		window3 += curDepth;

		
		/* if window2 is bigger than window1, the sliding window has increased */

		if (window2 > window1) ++incDepth;


		/* slide the window by moving window2->window1, window3->window2 */
		/* and resetting window3 to the current depth for next window */

		window1 = window2;
		window2 = window3;
		window3 = curDepth;
	}

	
	/* we are out of depths to read in, but still need to test the last two depths */

	if (window2 > window1) ++incDepth;

	
	/* output the puzzle solution */

	printf("The sum of measurements in this sliding window increased %d times.\n", incDepth);


	return 0;
}
