Q1. Program to avoid Race Condition using Mutex locks?

#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 

pthread_t tid[2]; 
int a1; 
pthread_mutex_t lock; 
void* trythis(void* arg) { 
pthread_mutex_lock(&lock); 
unsigned long i = 0; 
a1 += 1; 
printf("\n Job %d has started by 3cl1pS3\n", a1); 
for (i = 0; i < (0xFFFFFFFF); i++); 
printf("\n Job %d has finished by 3cl1pS3\n", a1); 
pthread_mutex_unlock(&lock); 
return NULL; 
} 

int main(void) { 
int i = 0; 
int error; 
if (pthread_mutex_init(&lock, NULL) != 0) { 
printf("\n mutex init has failed\n"); 
return 1; 
} 
while (i < 2) { 
error = pthread_create(&(tid[i]),NULL,&trythis, NULL); 
if (error != 0) 
printf("\nThread can't be created :[%s]",strerror(error)); 
i++; 
} 
pthread_join(tid[0], NULL); 
pthread_join(tid[1], NULL); 
pthread_mutex_destroy(&lock); 
return 0; 
}
