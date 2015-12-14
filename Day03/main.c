#include <stdio.h>

#define	SIZE	128

int main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "Usage: Day01 <input file>\n");
		return 1;
	}

	FILE *fp = fopen(argv[1], "r");
	int grid[SIZE][SIZE] = {};

	int x = (SIZE / 2) - 1, y = (SIZE / 2) - 1;
	grid[x][y]++;

	while (!feof(fp)) {
		switch (fgetc(fp)) {
			case '^': {
				grid[++x][y]++;
			} break;

			case 'v': {
				grid[--x][y]++;
			} break;

			case '<': {
				grid[x][--y]++;
			} break;

			case '>': {
				grid[x][++y]++;
			} break;
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