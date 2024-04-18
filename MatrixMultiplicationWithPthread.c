/**
 * Matrix (N*N) multiplication with multiple threads.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
double time_taken;
int size, num_threads;
int **matrix1, **matrix2, **matrix3;

int ** allocate_matrix( int size )
{
  /* Allocate 'size' * 'size' doubles contiguously. */
  int * vals = (int *) malloc( size * size * sizeof(int) );

  /* Allocate array of double* with size 'size' */
  int ** ptrs = (int **) malloc( size * sizeof(int*) );

  int i;
  for (i = 0; i < size; ++i) {
    ptrs[ i ] = &vals[ i * size ];
  }

  return ptrs;
}

void init_matrix( int **matrix, int size )
{
  int i, j;

  for (i = 0; i < size; ++i) {
    for (j = 0; j < size; ++j) {
      matrix[ i ][ j ] = rand() %100 + 1;
    }
  }
}

void print_matrix( int **matrix, int size )
{
  int i, j;

  for (i = 0; i < size; ++i) {
    for (j = 0; j < size-1; ++j) {
      printf( "%d, ", matrix[ i ][ j ] );
    }
    printf( "%d", matrix[ i ][ j ] );
    putchar( '\n' );
  }
}

/**
 * Thread routine.
 * Each thread works on a portion of the 'matrix1'.
 * The start and end of the portion depend on the 'arg' which
 * is the ID assigned to threads sequentially. 
 */
void * worker( void *arg )
{
  clock_t t;
  t = clock();
  int i, j, k, tid, portion_size, row_start, row_end;
  int sum;
  
  tid = *(int *)(arg); // get the thread ID assigned sequentially.
  portion_size = size / num_threads;
  row_start = tid * portion_size;
  row_end = (tid+1) * portion_size;

  for (i = row_start; i < row_end; ++i) { // hold row index of 'matrix1'
    for (j = 0; j < size; ++j) { // hold column index of 'matrix2'
      sum = 0; // hold value of a cell
      /* one pass to sum the multiplications of corresponding cells
	 in the row vector and column vector. */
      for (k = 0; k < size; ++k) { 
	sum += matrix1[ i ][ k ] * matrix2[ k ][ j ];
      }
      matrix3[ i ][ j ] = sum;
    }
  }
  t = clock() - t;
  time_taken = (((double)t)/CLOCKS_PER_SEC)*1000;
  pthread_exit(0);
}

int main( int argc, char *argv[] )
{
  int i;
  
  
  pthread_t * threads;

  size = atoi( argv[1] );
  num_threads = atoi( argv[2] );


  threads = (pthread_t *) malloc( num_threads * sizeof(pthread_t) );

  matrix1 = allocate_matrix( size );
  matrix2 = allocate_matrix( size );
  matrix3 = allocate_matrix( size );
  
  init_matrix( matrix1, size );
  init_matrix( matrix2, size );

  if ( size <= 16 ) {
    printf( "Matrix 1:\n" );
    print_matrix( matrix1, size );
    printf( "Matrix 2:\n" );
    print_matrix( matrix2, size );
  }

  
  for ( i = 0; i < num_threads; ++i ) {
    int *tid;
    tid = (int *) malloc( sizeof(int) );
    *tid = i;
    pthread_create( &threads[i], NULL, worker, (void *)tid );
  }
  
  for ( i = 0; i < num_threads; ++i ) {
    pthread_join( threads[i], NULL );
  }
 
 
  if ( size <= 16 ) {
    printf( "Matrix 3:\n" );
    print_matrix( matrix3, size );
  }

  printf( "Number of threads: %d\tExecution time:%.3lf ms\n",
          num_threads, time_taken);

  return 0;
}