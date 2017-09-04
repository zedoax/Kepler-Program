/* Program that allows users to input variables from kepler's equation
 * to calculate missing variables
 * -------------------------------------------------------------------
 * @author Elijah Bendinsky
 */

#include <stdio.h>
#include <stdlib.h>

/* Function: calculate
 * ---------------------------------------
 * Takes all the variables for calculation
 * and calculates the missing one
 */
float calculate(float* distance, float* axis, float* eccentricity, float* anomaly) {

}

int main(int argc, char* argv[]) {
	char input[128];
	float distance = 0.0;
	float axis = 0.0;
	float eccentricity = 0.0;
	float anomaly = 0.0;
	while(1) {
		fprintf(stdout, "Enter 'q' to quit\n \
[1] Distance: %f\n \
[2] Semi-Major Axis: %f\n \
[3] Eccentricity: %f\n \
[4] True Anomaly: %f\n \
> ", distance, axis, eccentricity, anomaly);
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
			
		}	
				
	}
	return EXIT_FAILURE;
}
