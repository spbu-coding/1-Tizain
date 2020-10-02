#include <stdio.h>
#include <math.h>
#include <string.h>
#include < assert.h >

#define MAX_EXP 6

double middl_rect(double a, double b, int n) {
	double sum = 0, h = (b - a) / n;
  
	for(int i = 0; i < n; i++) {
		sum += sin(a + h * (i + 0.5));
  	}
  
	sum *= h;
	return sum;
}

double simpsons_formula(double a, double b, int n) {
	double sum, sum1 = 0, sum2 = 0, h = (b - a) / n;
  
	for(int i = 1; i < n; i++) {
		sum1 += sin(a + i * h);
  	}
  	sum1 *= 2;

	for(int i = 1; i < n + 1; i++) {
		sum2 += sin(a + i * h - h/2);
  	}
  	sum2 *= 4;

	sum = h/6 * ( sin(a) + sin (b) + sum1 + sum2 );
	return sum;
}

int er_rs (int er) {
    switch (er)
    {
        case(1): printf("a must be between 0 and 3.14\n"); break;
        case(2): printf("b must be between 0 and 3.14\n"); break;
        case(3): printf("a must be less than b\n"); break;
        default: printf("Something going wrong\n"); 
    }
    return 0;
}
int calculate_(double a, double b, char strarr[MAX_EXP][50], int accuracies[], int accnum) {
	
	char str_log[80];
	
	for(int i = 0; i < accnum; i++) {
		int accuracy = accuracies[i];
		double rec = middl_rect(a, b, accuracy);
		double sim = simpsons_formula(a, b, accuracy);

		sprintf(str_log, "%d %.5lf %.5lf", accuracy, rec, sim);
		for(int j = 0; j < sizeof(str_log); j++) 
			strarr[i][j] = str_log[j];
	}

	return 0;
}

int main() {

	int accuracies[MAX_EXP] = {5, 10, 20, 100, 500, 1000};

    double a, b;
	printf("a and b:\n");
    scanf("%lf%lf", &a, &b);

	int c = -1;
	if ((a<0) || (a>3.14)) c = 1;
	if ((b<0) || (b>3.14)) c = 2;
	if (a>=b) c = 3;
	if (c!=-1) {
		er_rs(c);
		c = 0;
	}
	assert(c);

	char strarr [MAX_EXP][50];

	calculate_(a, b, strarr, accuracies, MAX_EXP);

	printf("Results:\n");

	for(int i = 0; i < MAX_EXP; i++) 
		puts(strarr[i]);

    return 0;
}


