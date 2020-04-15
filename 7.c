Q7. Program to Create two threads, Where one thread prints a welcome message and the other adds two numbers passed by the main process?

#include<stdio.h>
#include<pthread.h>
	
void *welcome(void *arg) {
printf("3cl1pS3 welcomes you to Multithreading!\t\t(Printed by First Thread)\n");
}
	
void *add(void *arg) {
int *num;
num = (int *)arg;
printf("Sum of the Numbers %d and %d is: %d\t(Printed by Second Thread)\n",num[0],num[1],(num[0]+num[1]));
}
	
int main(){
int i;
int num[2]; 
printf("Enter Two Numbers:\n");
for (i=0;i<2;i++){
scanf("%d",&num[i]);
}
pthread_t thrd1; 
pthread_t thrd2; 
pthread_create(&thrd1,NULL,welcome,NULL);
pthread_create(&thrd2,NULL,add,(void *)num); 
pthread_exit(&thrd1); 
pthread_exit(&thrd2); 
return (0);
}
