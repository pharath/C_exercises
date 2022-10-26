// clock() vs time():
// "The clock function determines the processor time used." C11dr §7.26.2.1 2.
// "The time function determines the current calendar time. The encoding of the value is unspecified" C11dr §7.26.2.4 2.
// 
// https://en.wikipedia.org/wiki/CPU_time
//
// CPU time:
// - "amount of time for which a central processing unit (CPU) was used for processing 
// instructions of a computer program or operating system"
// - "used to quantify the overall empirical efficiency of two functionally identical algorithms" (e.g. merge sort vs bubble sort)
//
// wall time, elapsed real time:
// - "elapsed time, which includes for example, waiting for input/output (I/O) operations"
// - "Elapsed real time includes I/O time, any multitasking delays, and all other types of waits incurred by the program"
// - "depending on 
//   - real world variables such as the CPU's temperature, as well as 
//   - other operating system variables, such as the process's priority."

#include <time.h>
#include <stdio.h>

int main () {
   clock_t start_t, end_t;
   double total_t;
   int i;

   start_t = clock();   // Note: clock() does not measure waiting time for I/O operations (e.g. when using getc(stdin))
   printf("Starting of the program, start_t = %ld\n", start_t);
    
   printf("Going to scan a big loop, start_t = %ld\n", start_t);
   for(i=0; i< 10000000; i++) {
   }
   
   end_t = clock();
   printf("End of the big loop, end_t = %ld\n", end_t);
   
   total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
   printf("Total time taken by CPU: %f sec\n", total_t  );
   printf("Exiting of the program...\n");

   return(0);
}