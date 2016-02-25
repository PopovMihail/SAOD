#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <inttypes.h>
void counting_sort(int *a, int n);
// tekushee vremya "WallTime"
double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int main()
{
	FILE *f;
	int n;
    uint32_t *a;
    printf("input size ");
    scanf("%d",&n);
    n = n * 1000;
    a = malloc(sizeof(uint32_t) * n);
    
	if (a == NULL) {
    	fprintf(stderr, "No enough memory \n");
    	exit(EXIT_FAILURE);
	}
    int i;
    for(i = 0; i < n; i++) { 
    	a[i] = (double) rand() / (RAND_MAX + 1.0) * 100001;
    	printf("%d ", a[i]);  //out scan massiv
	}
	
	double t = wtime();
	counting_sort(a,n);
	t = wtime() - t; 
    printf("%d %.6f \n", n, t);
	f = fopen("counting_sort.txt","a");
	fprintf(f,"%d %.6f\n",n,t);
	fclose(f);  
    free(a);
    return 0;
}

/*сортировка подсчётом*/
void counting_sort(int *a, int n){	

	int i, j, idx = 0;
	int min = a[0];
	int max = a[0];
	
	for(i = 1; i < n; i++){
		if(a[i] < min)
			min = a[i];
		if(a[i] > max)
			max = a[i];
	}
	printf("min=%d max=%d \n", min,max);
	int k = max - min + 1;
	int b[k]; 
	for(i = 0; i < k; i++) 
		b[i] = 0;

	for(i = 0; i < n; i++) 
		b[a[i] - min]++;
	for(i = min; i <= max; i++) 
		for(j = 0; j < b[i - min]; j++) 
			a[idx++] = i;

	for(i = 0; i < n; i++){
		printf("%d \n", a[i]);
	}
}


