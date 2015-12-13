#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc != 2) {
		fprintf(stderr, "Usage: Day01 <input file>\n");
		return 1;
	}

	FILE *fp = fopen(argv[1], "r");

	char c;
	int f = 0;
	for (int i = 1; (c = fgetc(fp)) != EOF; ++i) {
		switch (c) {
			case '(': {
				++f;
			} break;

			case ')': {
				--f;
			} break;
		}
	}

	fclose(fp);

	fprintf(stdout, "Santa has to go to floor %i.\n", f);

	return 0;
}