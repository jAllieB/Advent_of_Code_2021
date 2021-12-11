
/* Usage: ./sonarSweep < input.txt */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main () {

	/* initializations */

	unsigned int prevDepth = UINT_MAX, curDepth = 0, incDepth = 0;

	/* while still reading from stdin */

	while (!feof(stdin)) {

		scanf("%u", &curDepth);

		
		/* if depth increased since last measurement, log depth increase */

		if (curDepth > prevDepth) ++incDepth;


		/* update previous depth */

		prevDepth = curDepth;
	}


	/* print puzzle solution and exit */

	printf("%u measurements are larger than the previous measurements.\n", incDepth);

	return 0;
}
