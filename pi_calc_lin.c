#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define OUTPUT_FILE_NAME "points.txt"

// total number of random points
#define TOTAL_POINTS 10000000

int main(int argc, char* argv[]) {

	int total_ponints = 0;
	if (argc != 2){
		total_ponints = TOTAL_POINTS;
	} else{
		total_ponints = atoi(argv[1]);
	}	

	// the number of points inside the circle
    int points_inside_circle = 0;

    // for measuring time 
    double start_time = 0.0;
    double end_time = 0.0;

	start_time = omp_get_wtime();
    
    for (int i = 0; i < total_ponints; i ++) {

        // generating random x and y coordinates in the range [-1, 1]
        double x = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
        double y = ((double)rand() / RAND_MAX) * 2.0 - 1.0;

        // checking whether the point got inside the circle
        if (x * x + y * y <= 1.0) {
            points_inside_circle++;
        }
    }

    end_time = omp_get_wtime();

    // Calculation of the approximate value of the number pi
    double pi_estimate = 4.0 * (double)points_inside_circle / total_ponints;

    printf("=============================================\n");
    printf("||Approximate value of the lin pi: %lf||\n", pi_estimate);
    printf("||time %f                            ||\n", (end_time - start_time) );
    printf("=============================================\n");

    return 0;
}
