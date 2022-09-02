// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <string.h>
// #include <pthread.h>
// #include <math.h>
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

void *thread_function(void *arg);
double random_double();
char message[] = "Hello World";
int hit_count = 0;
int npoints = 20;

int main(int argc, char* argv[])
{
    srand(time(NULL));
    //gets the number for decimal type ./M
    if(argc > 1)
    {
        npoints = atoi(argv[1]);
    }
 
    int res;
    pthread_t a_thread;
    void *thread_result;
    res = pthread_create(&a_thread, NULL, thread_function, (void *)message);
    if (res != 0)
    {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
   // printf("Waiting for thread to finish...\n");
    res = pthread_join(a_thread, &thread_result);
    if (res != 0)
    {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }
   // printf("Hit count: %d", hit_count);
    exit(EXIT_SUCCESS);
}

void *thread_function(void *arg)
{
    printf("thread_function is running. Argument was %d \n", npoints);
    double x, y;

    /* Check for points inside circle */
    for (int i = 0; i < npoints; i++)
    {
        /* generate random numbers between -1.0 and +1.0 (exclusive) */
        x = random_double() * 2.0 - 1.0;
        y = random_double() * 2.0 - 1.0;
        if (sqrt(x * x + y * y) < 1.0)
            ++hit_count;
    }
    //checking for
     printf("npoints ... %d \n", npoints);
      //printf("hit_count ... %d \n", hit_count);
     double piArea = 4.0*hit_count/ npoints;
     //see how far it is from pi to area
     double check = piArea - M_PI;
     //comments
    printf("Your guess for: %f \n", piArea);
    printf("Difference from pie: %f \n", check);

    pthread_exit(message);
}
/* Generates a double precision random number */
double random_double()
{ 
    
    return rand() / ((double)RAND_MAX + 2);
}