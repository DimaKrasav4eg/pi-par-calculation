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

    // open output file
    FILE *file;
    file = fopen(OUTPUT_FILE_NAME, "w");
    if (file == NULL) {
        printf("file error\n");
        return 1;
    }

    // for measuring time 
    double start_time = 0.0;
    double end_time = 0.0;

    int num_procs = 0;
    #pragma omp parallel reduction (+: points_inside_circle, start_time, end_time)
    {
    	// int thread = omp_get_thread_num();
    	num_procs = omp_get_num_threads();
    	int repeat = 2 * total_ponints/num_procs;
    	double *buffer = (double*)calloc(repeat+1, sizeof(double));
    	unsigned int seed = omp_get_thread_num();

    	// start of time measurement
    	start_time = omp_get_wtime();
	    
	    for (int i = 0; i < repeat; i += 2) {

	        // generating random x and y coordinates in the range [-1, 1]
	        double x = ((double)rand_r(&seed) / RAND_MAX) * 2.0 - 1.0;
	        double y = ((double)rand_r(&seed) / RAND_MAX) * 2.0 - 1.0;

	        buffer[i] = x;
	        buffer[i+1] = y;

	        // checking whether the point got inside the circle
	        if (x * x + y * y <= 1.0) {
	            points_inside_circle++;
	        }
	    }

	    // end of time measurement
	    end_time = omp_get_wtime();

	    // writing points to a file
	    #pragma omp critical
	    {

	    	for (int i = 0; i < repeat; i++) {
        		fprintf(file, "%lf\n", buffer[i]);
    		}
	    }
	}

	fclose(file);

    // Calculation of the approximate value of the number pi
    double pi_estimate = 4.0 * (double)points_inside_circle / total_ponints;


    printf("=============================================\n");
    printf("||Approximate value of the par pi: %lf||\n", pi_estimate);
    printf("||time %f                            ||\n", (end_time - start_time)/num_procs );
    printf("=============================================\n");

    return 0;
}
