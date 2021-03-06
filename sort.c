#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <inttypes.h>

// tekushee vremya "WallTime"
double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int main(int argc, char * argv[])
{
	
	FILE *file;
		
	int n;
    //int n = atoi(argv[1]); 
    uint32_t *a;
    printf("input size ");
    scanf("%f ", &n);
    a = malloc(sizeof(uint32_t) * n);
    
	if (a == NULL) {
    fprintf(stderr, "No enough memory \n");
    exit(EXIT_FAILURE);
}
    int i;
    for(i = 0; i < n; i++) { 
    //a[i] = (double) rand() / (RAND_MAX + 1.0) * 100001;
    a[i]= rand()%10;
    printf("%d ", a[i]);  //out scan massiv
}
	
	file = fopen(fname,"w");

    double t = wtime();
	//counting_sort(a, n);
    //t = wtime() - t; 
    //printf("%d %.6f\n", n, t);
    
   // t = wtime();
   // insertion_sort(a,n);
    //t = wtime() - t; 
    //printf("%d %.6f \n", n, t);
	
	heap_sort(a,n);
    t = wtime() - t; 
    printf("%d %.6f \n", n, t);
    file = fopen("lab.dat","w");
    fprintf(file,"%f %%d %.6f \n", n, t);
    free(a);
    return 0;
}



/*пиромидальная сортировка*/

void siftDown(int *a, int root, int bottom) {
  int done, maxChild, temp;
  done = 0;
  while ((root*2 <= bottom) && (!done)) {
    if (root*2 == bottom)
      maxChild = root * 2;
    else if (a[root * 2] > a[root * 2 + 1])
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;
    if (a[root] < a[maxChild]) {
      temp = a[root];
      a[root] = a[maxChild];
      a[maxChild] = temp;
      root = maxChild;
    }  else
      done = 1;
  }
}
void heap_sort(int *a, int n) {
  int i, temp;
  for (i = (n / 2)-1; i >= 0; i--)
    siftDown(a, i, n);
  for (i = n-1; i >= 1; i--) {
    temp = a[0];
    a[0] = a[i];
    a[i] = temp;
    siftDown(a, 0, i-1);
  }
  /*output*/
	for(i = 0; i < n; i++){
		printf("%d \n", a[i]);
}
printf("min=%d max=%d \n", a[0],a[n-1]);
}

