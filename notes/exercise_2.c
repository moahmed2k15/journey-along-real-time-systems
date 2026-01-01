#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void* get_sqrt_till_x(void *arg)
{
    int max = *((int *) arg);
    double* results = (double*) malloc(max * sizeof(double));

    for (int i = 0; i < max; i++) {
        results[i] = sqrt((double) i);
    }

    return results;
}

int main(int argc, char** argv)
{
    if(argc < 2) {
        fprintf(stderr, "usage exe2 <val>");
        return 1;
    }

    int max = atoi(argv[1]);

    pthread_t thread_id;
    void* returned;

    pthread_create(&thread_id, NULL, &get_sqrt_till_x, &max); 
    
    printf("Waiting for thread to complete it's operation\n");

    pthread_join(thread_id, &returned);

    double* results = (double*) returned;

    for(int i = 0; i < max; i++) {
        printf("Sqrt of %d is %lf\n", i, results[i]);
    }
    return 0;
}





