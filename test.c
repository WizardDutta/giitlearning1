// C program to demonstrate
// example of time() function.

#include <stdio.h>
#include <time.h>

int main()
{
	time_t seconds;

	time(&seconds);
	printf("Seconds since January 1, 1970 = %ld\n", seconds);

    time_t second;
     
    second = time(NULL);
    printf("Seconds since January 1, 1970 = %ld\n", second);
    
    struct tm *local;
    local = localtime(&seconds);
    printf("%s ",asctime(local));

	return 0;
}
