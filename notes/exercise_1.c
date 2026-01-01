#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define THREAD_COUNT 10

void* print_thread_name(void * thread_id)
{
	pthread_t t_id = *((pthread_t*) thread_id);

	for (int i = 0; i < 5; i++)
	{
		printf("Hello World (Thread #%d)\n", (int)t_id);
	}

	return NULL;
}


int main()
{
	pthread_t my_threads[THREAD_COUNT];
	int thread_ids[THREAD_COUNT];
	
	for (int i = 0; i < THREAD_COUNT; i++) {
		thread_ids [i] = 1000 +i;
	}

	for (int i = 0; i < THREAD_COUNT; i++){
		pthread_create(&my_threads[i], NULL, &print_thread_name, &thread_ids[i]);
	}
	
	for(int i = 0; i < THREAD_COUNT; i++) {
		void* status;
		pthread_join(my_threads[i], &status);
	}
	return 0;
}
				
