#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <inttypes.h>

void insertion_sort(int *a, int n);

// tekushee vremya "WallTime"
double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int main()//int argc, char * argv[])
{
	
	FILE *f;
	int n;
    //int n = atoi(argv[1]); 
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
    //a[i]= rand()%10;
    printf("%d ", a[i]);  //out scan massiv
}
	
	

    double t = wtime();

	insertion_sort(a,n);
	
	t = wtime() - t; 
	
    printf("%d %.6f \n", n, t);
	
	f = fopen("insertion_sort.txt","a");
	fprintf(f,"%d %.6f\n",n,t);
	fclose(f);  
    free(a);
    return 0;
}


/*сортировка вставкой*/
void insertion_sort(int *a, int n)
{	
	int i, j, key;
	
	int min = a[0];
	int max = a[0];
	
	for(i = 1; i < n; i++){
		if(a[i] < min)
			min = a[i];
		if(a[i] > max)
			max = a[i];
}
	
	/*sort*/
	for ( i=0; i < n; i++) {  
    key = a[i];
	for ( j = i-1; j >= 0 && a[j] > key; j--){
		a[j+1] = a[j];  	
}
	a[j+1] = key;
}

/*output*/
	for(i = 0; i < n; i++){
		printf("%d \n", a[i]);
}
printf("min=%d max=%d \n", min,max);
}


