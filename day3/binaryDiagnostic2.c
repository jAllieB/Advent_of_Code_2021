
/* c libraries */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* plank libraries */

#include "jval.h"
#include "dllist.h"


int main () {

	/* initializations */

	char c, buf[14], *oxystr, *co2str;
	unsigned int i, zeroes, ones;

	Dllist oxygenRating, co2Rating, tmp, tmp2;
	oxygenRating = new_dllist();
	co2Rating = new_dllist();


	/* while still reading input (twelve chars + \n) */

	while (fgets(buf, 14, stdin) != NULL) {

		/* add input to both lists */

		dll_append(oxygenRating, new_jval_s(strdup(buf)));
		dll_append(co2Rating, new_jval_s(strdup(buf)));
	}

	
	/* for every bit position */

	for (i=0; i<12; ++i) {

		/* add up the number of ones and zeroes in that bit position */

		dll_traverse (tmp, oxygenRating) {
			if (tmp->val.s[i] == '1') ++ones;
			else ++zeroes;
		}

		
		/* set c to the most common number (with equality choosing one) */

		c = (ones >= zeroes) ? '1' : '0';


		/* prune list of all inputs without the most common bit in the given position */

		dll_traverse (tmp, oxygenRating) {
			if (tmp->val.s[i] != c) {
				tmp2 = dll_prev(tmp);
				free(tmp->val.s);
				dll_delete_node(tmp);
				tmp = tmp2;
			}
		}


		/* if we only have one element left, break out of our loop */

		if (dll_first(oxygenRating)->flink == dll_nil(oxygenRating)) break;
		

		/* reset for next iteration */

		ones = 0;
		zeroes = 0;
	}


	/* same procedure but for our co2Ratings */

	for (i=0; i<12; ++i) {

		dll_traverse (tmp, co2Rating) {
			if (tmp->val.s[i] == '1') ++ones;
			else ++zeroes;
		}

		
		/* now selecting for least common bit (with equality choosing zero) */

		c = (ones < zeroes) ? '1' : '0';

		dll_traverse (tmp, co2Rating) {
			if (tmp->val.s[i] != c) {
				tmp2 = dll_prev(tmp);
				free(tmp->val.s);
				dll_delete_node(tmp);
				tmp = tmp2;
			}
		}

		if (dll_first(co2Rating)->flink == dll_nil(co2Rating)) break;
		
		ones = 0;
		zeroes = 0;
	}

	oxystr = dll_first(oxygenRating)->val.s;
	co2str = dll_first(co2Rating)->val.s;


	/* convert the only two remaining strings into their corresponding integers */

	unsigned int generator = 0, scrubber = 0;

	for (i=0; i<12; ++i) {
		if (oxystr[i] == '1') generator |= 1 << (11 - i);
		if (co2str[i] == '1') scrubber |= 1 << (11 - i);
	}

	
	/* display the puzzle solution */

	printf("Oxygen Generator Rating: %u\nCO2 Scrubber Rating: %u\nLife Support Rating: %u\n", 
			generator, scrubber, (generator*scrubber));



	free(oxystr);
	free(co2str);

	free_dllist(oxygenRating);
	free_dllist(co2Rating);

	return 0;
}
