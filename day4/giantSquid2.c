
/* c libraries */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* plank libraries */

#include "fields.h"


/* boolean which returns true if the board is winning, and
 * returns false if not */
int winner (int board[5][5]) {

	/* initalizations */

	int i, j;

	
	/* testing all horizontal rows */

	for (i=0; i<5; ++i) {
		for (j=0; j<5; ++j) {
			if (board[i][j] != -1) break;
		}

		if (j==5) return 1;
	}


	/* testing all vertical rows */
	
	for (i=0; i<5; ++i) {
		for (j=0; j<5; ++j) {
			if (board[j][i] != -1) break;
		}

		if (j==5) return 1;
	}


	/* if no row or colomn is marked off, the board has not won yet */

	return 0;
}


/* playing bingo with the given board and draw order,
 * returns the number of turns to win, if givePoints flag
 * is nonzero, then returns the point total of the board */
int bingo (int *draws, int board[5][5], int givePoints) {

	/* initializations */

	int i, j, k;
	int boardcpy[5][5];
	for (i=0; i<5; ++i)
		for (j=0; j<5; ++j)
			boardcpy[i][j] = board[i][j];


	/* while we still haven't won */

	for (i=0; ; ++i) {

		/* mark off board if the current draw is on the board */

		for (j=0; j<5; ++j)
			for (k=0; k<5; ++k)
				if (draws[i] == boardcpy[j][k])
					boardcpy[j][k] = -1;

		
		/* if winning */

		if (winner(boardcpy) == 1) {
			
			/* return the number of turns to win */
			
			if (!givePoints) return i+1;

			
			/* return the point total of the board */

			else {
				int sum = 0;
				for (j=0; j<5; ++j)
					for (k=0; k<5; ++k)
						if (boardcpy[j][k] != -1)
							sum += boardcpy[j][k];

				return draws[i] * sum;
			}
		}
	} 
}


int main () {

	/* initializations */

	char *s, *tok;
	int *drawOrder, worstBoard[5][5], currBoard[5][5], worstTurns = 0, currTurns, points, i, j;
	IS is;
	s = malloc(sizeof(char) * 256);
	drawOrder = malloc(sizeof(int) * 128);
	for (i=0; i<5; ++i)
	       for (j=0; j<5; ++j)
		       worstBoard[i][j] = 0;
	is = new_inputstruct(NULL);


	/* read in the draw order */

	fgets(s, 255, stdin);
 
	tok = strtok(s, ",");
	
	drawOrder[0] = atoi(tok);

	for (i=1; ((tok = strtok(NULL, ",")) != NULL); ++i)
		drawOrder[i] = atoi(tok);


	while (get_line(is) >= 0) {

		/* skips past all non board lines */

		if (is->NF < 5) continue;
		
		
		/* we have a board to read in */
	
		for (i=0; i<5; ++i) {
			
			/* need a new row */

			if (i!=0) get_line(is);


			/* read all numbers in for that row */

			for (j=0; j<5; ++j) currBoard[i][j] = atoi(is->fields[j]);
		}

		
		/* time to play bingo */

		currTurns = bingo(drawOrder, currBoard, 0);


		/* if this is the first round or this is the worst board */

		if (currTurns > worstTurns) {

			/* set worst board and turns to this board and turns */

			worstTurns = currTurns;
			for (i=0; i<5; ++i)
				for (j=0; j<5; ++j)
					worstBoard[i][j] = currBoard[i][j];
		}

	}


	/* get the number point total for the best bingo board */

	points = bingo(drawOrder, worstBoard, 1);	

	
	/* printing puzzle info */

	printf("Draw Order: ");
	for (i=0; i<worstTurns; ++i) printf("%d ", drawOrder[i]);
	printf("\n");
	
	printf("Worst Board:\n");
	for (i=0; i<5; ++i) {
		for (j=0; j<5; ++j)
			printf("%2d ", worstBoard[i][j]);
		printf("\n");
	}

	printf("Highest Number of Turns: %d\nWinning Draw: %d\nSum of Unmarked Numbers: %d\nPoints: %d\n",
		       worstTurns, drawOrder[worstTurns-1], (points / drawOrder[worstTurns-1]), points);

	
	/* deallocations */

	free(s);
	free(drawOrder);
	jettison_inputstruct(is);

	return 0;
}
