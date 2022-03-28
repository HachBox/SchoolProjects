#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>

#include <string.h>

//global variables
int read_count = 0;
char str[] = "All work and no play makes Jack a dull boy.";
sem_t rw_sem; //used by both readers and writers
sem_t cs_sem; //used for protecting critical sections of readers

//writer function
void* writer(void* thread_id_writer){
	//loop while str isn't empty
	while(str[0] != '\0') {
		printf("writer %ld is writing ...\n",(long)thread_id_writer);
		sem_wait(&rw_sem); //locks sem
		int i = strlen(str)-1; 
		str[i] = '\0';
		//writing (chopping off last char)
		sem_post(&rw_sem); //unlocks sem
		sleep(1); //sleep for 1 second
	}
	//sem_post(&rw_sem); //unlocks sem
	//note: you need to use rw_sem semaphore when writing in the loop
	printf("writer %ld is exiting ...\n",(long)thread_id_writer);
	pthread_exit(0);
}

//reader function
void* reader(void* thread_id_reader) {
	//loop while str isn't empty
	//sem_wait(&rw_sem); //locks sem

	while(str[0] != '\0') {
		sem_wait(&cs_sem); //locks sem cs
		read_count++;
		printf("read_count increments to: %d\n",read_count);

		if(read_count == 1)
			sem_wait(&rw_sem); //locks sem cs

		sem_post(&cs_sem); //unlocks sem cs
		printf("reader %ld is reading ... content : %s\n",(long)thread_id_reader ,str);
		sem_wait(&cs_sem); //locks sem cs

		read_count--;
		printf("read_count decrements to: %d\n",read_count);

		if(read_count == 0)
			sem_post(&rw_sem); //unlocks sem rw

		sem_post(&cs_sem);
		sleep(2); //sleep for 1 second
	}
	//sem_post(&rw_sem); //unlocks sem
	//note: you need to use cs_sem semaphore when reading in the loop
	printf("reader %ld is exiting ...\n",(long)thread_id_reader);
	pthread_exit(0);
}

int main(int argc, char *argv[]) {

	if (argc != 3)
	{
		fprintf(stderr,"Submit only two integers (i.e.) '8 2'\n");
		return -1;
	}

	int r_threads = atoi(argv[1]);
	int w_threads = atoi(argv[2]);

	if (r_threads < 0)
	{
		fprintf(stderr,"%d must be>= 0\n",r_threads);
		return -1;
	}

	if (w_threads < 0)
	{
		fprintf(stderr,"%d must be>= 0\n",w_threads);
		return -1;
	}

	/*these two lines are added for initializing both to 1*/
	if (sem_init(&rw_sem, 0, 1) == -1) {
		perror("sem_init");
		exit(EXIT_FAILURE);
	}

	if (sem_init(&cs_sem, 0, 1) == -1) {
		perror("sem_init");
		exit(EXIT_FAILURE);
	}
	pthread_t* thread_ids_writer = (pthread_t*)malloc(w_threads*sizeof(pthread_t));
	pthread_t* thread_ids_reader = (pthread_t*)malloc(r_threads*sizeof(pthread_t));

	printf("*** Reader-Writer Problem Simulation *** \n"
			"Number of reader threads: %d\n"
			"Number of writer threads: %d\n",r_threads, w_threads);

	for(long i = 0; i < w_threads; i++) {
		int w = pthread_create(&thread_ids_writer[i], NULL, &writer, (void*)i);
		if (w != 0) {
			printf("%d \n",w);
			perror("pthread_create");	
			exit(EXIT_FAILURE);
		}
	}

	for(long j = 0; j < r_threads; j++) {
		long r = pthread_create(&thread_ids_reader[j], NULL, &reader, (void*)j);
		if (r != 0) {
			//printf("big oof right here");
			perror("pthread_create");	
			exit(EXIT_FAILURE);
		}
	}

	for(long j = 0; j < r_threads; j++) {
		pthread_join(thread_ids_reader[j], NULL); 
	}

	//printf("There are still %ld writers waiting on the semaphore...\n",((long)w_threads)-1);

	for(long i = 0; i < w_threads; i++) {
		pthread_join(thread_ids_writer[i], NULL);
	}
	printf("All threads are done.\n"
			"Resources cleaned up.\n");

	sem_destroy(&rw_sem);
	sem_destroy(&cs_sem);
}
