#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
	/* Read from stdin */
	unsigned long w;
	scanf("%lu", &w);
	unsigned long x1,y1 = 0; // Since coords start at 1 instead of 0, y1 will be zero if we are given a number instead of coordinate
	scanf("%lu %lu", &x1, &y1);

	unsigned long i = 0;
	unsigned long area = w*w;
	unsigned long x = w/2, y = w/2; // Zero indexed
	typedef enum {UP, RIGHT, DOWN, LEFT} direction;
	direction dir = RIGHT;

	// Initial check
	if (x1 == x+1 && y1 == y+1){ // Given the exact center
		printf("1\n");
		return 0;
	}
	else if (x1 == 1 && y1 == 0){
		printf("(%lu, %lu)\n", x+1, y+1);
		return 0;
	}

	/*
	Alternate method: instead of saving the whole board, keep track of the number of turns and moves.
	*/
	unsigned long moves = 0;
	unsigned long moveLength = 1;
	unsigned long turnCount = 0;
	for (i = 2; i <= area; i++){
		// Move
		switch (dir){
			case UP:
				y--;
				break;
			case RIGHT:
				x++;
				break;
			case DOWN:
				y++;
				break;
			case LEFT:
				x--;
				break;
		}
		moves++;

		// Check
		if (y1 != 0){ // Given coordinates
			if (x+1 == x1 && y+1 == y1){
				printf("%lu\n", i);
				return 0;
			}
		}
		else if (i == x1 && y1 == 0){
			printf("(%lu, %lu)\n", x+1, y+1);
			return 0;
		}

		// Change direction
		if (moves % moveLength == 0){
			switch (dir){
				case UP:
					dir = LEFT;
					break;
				case RIGHT:
					dir = UP;
					break;
				case DOWN:
					dir = RIGHT;
					break;
				case LEFT:
					dir = DOWN;
					break;
			}
			turnCount++;
		}
		if (turnCount >= 2){
			moveLength++;
			turnCount = 0;
		}
	}

	return 1;
}