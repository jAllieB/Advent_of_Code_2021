
/* c libraries */

#include <stdio.h>
#include <stdlib.h>


int main () {

	/* initializations */

	char buf[14];
	unsigned int i, zeroes[12], ones[12];
	for (i=0; i<12; ++i) {
		zeroes[i] = 0;
		ones[i] = 0;
	}
	

	/* while still reading input (twelve chars + \n) */

	while (fgets(buf, 14, stdin) != NULL) {
	
		/* if bit is one, add to ones, otherwise add to zeroes */

		for (i=0; i<12; ++i) {
			if (buf[i] == '1') ++ones[i];
			else ++zeroes[i];
		}	
	}


	/* initializations */

	unsigned int gammaRate = 0, epsilonRate = 0, powerConsumption;


	/* bit shifting to make the two rates */

	for (i=0; i<12; ++i) {
		if (ones[i] > zeroes[i]) gammaRate |= (1 << (11 - i));
		else epsilonRate |= (1 << (11 - i));
	}


	/* deriving the power consumption out of the two rates */

	powerConsumption = gammaRate * epsilonRate;


	/* display the puzzle solution */

	printf("Gamma Rate: %u\nEpsilon Rate: %u\nPower Consumption: %u\n", 
			gammaRate, epsilonRate, powerConsumption);


	return 0;
}
