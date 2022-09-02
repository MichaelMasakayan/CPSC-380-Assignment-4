#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

using namespace std;
double random_double();
void *thread_function(void *arg);
int npoints;
double hit_count;
char message= 'n';

int main(void)
{
// checking
   int res;
    pthread_t a_thread;
    void *thread_result;
   //  res = pthread_create(&a_thread, NULL, thread_function, (void *)message);
    if (res != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    printf("Waiting for thread to finish...\n");
    res = pthread_join(a_thread, &thread_result);
    if (res != 0) {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }
    printf("Thread joined, it returned %s\n", (char *)thread_result);
    printf("Message is now %c\n", message);
    exit(EXIT_SUCCESS);

return 0;
}
/* Generates a double precision random number */
double random_double() 
{
    return random() / ((double)RAND_MAX + 1);
}
void *thread_function(void *arg) {
    printf("thread_function is running. Argument was %s\n", (char *)arg);
    sleep(3);
    /* Check for points inside circle */
    for (int i = 0; i < npoints; i++) {
        /* generate random numbers between -1.0 and +1.0 (exclusive) */
        double x = random_double() * 2.0 - 1.0;
        double y = random_double() * 2.0 - 1.0;
        if (sqrt(x*x + y*y) < 1.0 )
        ++hit_count;
    } 
    // strcpy(message, "Bye!");
    pthread_exit(NULL);
    return 0;
}

