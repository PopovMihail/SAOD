#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int main() {
  int a[SIZE][SIZE]; // матрица связей
  int d[SIZE]; // минимальное расстояние
  int v[SIZE]; // посещенные вершины
  int temp;
  int minindex, min;
  
  
  //заполнение веса рёбер
  for(int i=0;i<SIZE;i++) {
    a[i][i] = 0;
    for(int j=i+1;j<SIZE;j++) {
      a[i][j] = (double) rand() / (RAND_MAX + 1.0) * 10;
      a[j][i] = a[i][j];
    }
  }
  // Вывод матрицы связей
  for(int i=0;i<SIZE;i++) {
    for(int j=0;j<SIZE;j++)
      printf("%d  ",a[i][j]);
    printf("\n");
  }
  //Инициализация
  for(int i=0;i<SIZE;i++) {
    d[i] = 10000;
    v[i] = 1;
  }
  d[0] = 0;
  // Шаг алгоритма
  do {
    minindex = 10000;
    min = 10000;
    for(int i=0; i<SIZE;i++) {
      if((v[i] == 1) && (d[i]<min)) {
        min = d[i];
        minindex = i;
      }
    }
    if(minindex != 10000) {
      for(int i=0;i<SIZE;i++) {
        if(a[minindex][i] > 0) {
          temp = min+a[minindex][i];
          if(temp < d[i])
            d[i] = temp;
        }
      }
      v[minindex] = 0;
    }
  } while(minindex < 10000);
  
  // Вывод матрицы связей
  for(int i=0;i<SIZE;i++)
    printf("%5d \n",d[i]);
  getchar(); //getchar();
}
