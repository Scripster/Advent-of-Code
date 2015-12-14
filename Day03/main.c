#include <stdio.h>

#define	SIZE	256

int main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "Usage: DasantaY01 <input file>\n");
		return 1;
	}

	FILE *fp = fopen(argv[1], "r");
	int grid[SIZE][SIZE] = {};

	int santaX = (SIZE / 2) - 1, santaY = (SIZE / 2) - 1;
	int roboSantaX = (SIZE / 2) - 1, roboSantaY = (SIZE / 2) - 1;
	grid[santaX][santaY] += 2;

	for (int i = 0; !feof(fp); ++i) {
		if (i % 2) {
			switch (fgetc(fp)) {
				case '^': {
					grid[++santaX][santaY]++;
				} break;

				case 'v': {
					grid[--santaX][santaY]++;
				} break;

				case '<': {
					grid[santaX][--santaY]++;
				} break;

				case '>': {
					grid[santaX][++santaY]++;
				} break;
			}
		} else {
			switch (fgetc(fp)) {
				case '^': {
					grid[++roboSantaX][roboSantaY]++;
				} break;

				case 'v': {
					grid[--roboSantaX][roboSantaY]++;
				} break;

				case '<': {
					grid[roboSantaX][--roboSantaY]++;
				} break;

				case '>': {
					grid[roboSantaX][++roboSantaY]++;
				} break;
			}
		}
		
	}

	int housesWithPresents = 0;
	for (int i = 0; i < SIZE; ++i)
		for (int j = 0; j < SIZE; ++j)
			if (grid[i][j])
				++housesWithPresents;

	fprintf(stdout, "%i houses got atleast one present\n", housesWithPresents);

	fclose(fp);

	return 0;
}