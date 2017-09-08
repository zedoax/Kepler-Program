/* Program that allows users to input variables from kepler's equation
 * to calculate missing variables
 * -------------------------------------------------------------------
 * @author Elijah Bendinsky
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

/* Function: calculate
 * ---------------------------------------
 * Takes all the variables for calculation
 * and calculates the missing one
 */
float calculate(float* distance, float* axis, float* eccentricity, float* anomaly) {
	if(*distance == ((float)0.0)) {
		double x = cos(((double)(*anomaly)));
		return ((float)(((*axis)*(1-((*eccentricity)*(*eccentricity))))/(1+(*eccentricity)*x)));
		
	}
	else if(*axis == ((float)0.0)) {
		double x = cos(((double)(*anomaly)));
		return ((*distance)*(1+((*eccentricity)*x)))/(1-(*eccentricity)*(*eccentricity));
	}
	else if(*eccentricity == ((float)0.0)) {
		// STUB: Need to Calculate Final Equation
	}
	else if(*anomaly == ((float)0.0)) {
		// return arccos(((*distance)/((*axis)*(1-(*eccentricity)*(*eccentricity)))));
		// STUB: Need to calculate final equation and determine how to use arccos in math.h
	}
}

void printterm(distance, axis, eccentricity, anomaly) {
	fprintf(stdout, " Enter x to clear\n \
Enter 'c' to calculate missing values\n \
Enter 'q' to quit\n \
[1] Distance: %f\n \
[2] Semi-Major Axis: %f\n \
[3] Eccentricity: %f\n \
[4] True Anomaly: %f\n \
> ", distance, axis, eccentricity, anomaly);
}

int runterm() {
	char input[128];
	float distance = 0.0;
	float axis = 0.0;
	float eccentricity = 0.0;
	float anomaly = 0.0;
	while(1) {
		printterm(distance, axis, eccentricity, anomaly);
		if(fgets(input, 128, stdin) != NULL) {
			int x = strtol(input, (char**)NULL, 10);
			if(x >= 1 && x <= 4) {
				fprintf(stdout, "Enter the new value: ");
				switch(x) {
					case 1:
						scanf("%f", &distance);
						break;
					case 2:
						scanf("%f", &axis);
						break;
					case 3:
						scanf("%f", &eccentricity);
						break;
					case 4:
						scanf("%f", &anomaly);
						break;
				}
			}
		}
		if(input[0] == 'q') {
			return EXIT_SUCCESS;
		}
		else if(input[0] == 'c') {
			float missed = calculate(&distance, &axis, &eccentricity, &anomaly);
			if(distance==((float)0.0)) {
				fprintf(stdout, "The missing distance is: %f\n", missed);
			}
			else if(axis==((float)0.0)) {
				fprintf(stdout, "The missing semi-major axis is: %f\n", missed);
			}
			else if(eccentricity==((float)0.0)) {
				fprintf(stdout, "The missing eccentricity is: %f\n", missed);
			}
			else if(anomaly==((float)0.0)) {
				fprintf(stdout, "The missing anomaly is: %f\n", missed);
			}
		}	
		else if(input[0] == 'x') {
			distance = 0.0;
			axis = 0.0;
			eccentricity = 0.0;
			anomaly = 0.0;
		}
	}

}

int main(int argc, char* argv[]) {
	runterm();
	return EXIT_FAILURE;
}
