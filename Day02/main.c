#include <stdio.h>

#define	min(a, b)	(((a) < (b)) ? (a) : (b))

int main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "Usage: Day01 <input file>\n");
		return 1;
	}

	FILE *fp = fopen(argv[1], "r");

	long totalArea = 0, totalRibbon;
	while (!feof(fp)) {
		int l, w, h;
		fscanf(fp, "%i%*c%i%*c%i", &l, &w, &h);

		int area = ((2 * l * w) + (2 * w * h) + (2 * h * l));
		area += min(l * w, min(w * h, h * l));
		totalArea += area;

		int ribbon = l * w * h;
		ribbon += min(l + l + w + w, min(w + w + h + h, h + h + l + l));

		totalRibbon += ribbon;
	}

	fprintf(stdout, "%li square feet of wrapping paper is needed in total.\n", totalArea);
	fprintf(stdout, "%li feet of ribbon is needed in total.\n", totalRibbon);

	fclose(fp);

	return 0;
}