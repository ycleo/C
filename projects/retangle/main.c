#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    double width = atof(argv[1]);
    double height = atof(argv[2]);
    // sscanf(argv[1], "%lf", &width);
    // sscanf(argv[2], "%lf", &height);

    double perimeter = 0.0, area = 0.0;
    perimeter = (width + height) * 2;
    area = width * height;

    printf("%f %f %.3f %.3f\n", width, height, perimeter, area);
    return 0;
}