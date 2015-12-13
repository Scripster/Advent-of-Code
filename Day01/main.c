#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc != 2) {
		fprintf(stderr, "Usage: Day01 <input file>\n");
		return 1;
	}

	FILE *fp = fopen(argv[1], "r");

	char c;
	int f = 0, enteredBasement = 0;
	for (int i = 1; (c = fgetc(fp)) != EOF; ++i) {
		switch (c) {
			case '(': {
				++f;
			} break;

			case ')': {
				--f;
			} break;
		}

		if (!enteredBasement && f == -1) {
			fprintf(stdout, "%i is the position of the first character that forces Santa to enter the basement.\n", i);
			enteredBasement = 1;
		}
	}

	fclose(fp);

	fprintf(stdout, "Santa has to go to floor %i.\n", f);

	return 0;
}