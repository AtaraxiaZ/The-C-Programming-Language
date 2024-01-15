#include <stdio.h>

int fahr2cel(int fahr){
    return (5.0/9.0) * (fahr-32.0);
}

int main()
{
	float fahr, celsius;
	float lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;
	
	fahr = lower;
	printf("%s %s\n", "fahr", "celsius");
	while (fahr <= upper) {
        celsius = fahr2cel(fahr);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}
