#include <reg51.h>
#include "uart_int.h"

void SumEvenOdd(unsigned int arr[], unsigned int size);

void main() {
    unsigned int arr[10]; 
    unsigned int size, i;

    SerialInit(); 
    
    Printf("Enter the number of elements (max 10): ");
    size = ReadIntPC(); 
    
    if (size > 10) {
        Printf("Size too large, using max size of 10.\n");
        size = 10;
    }
    for (i = 0; i < size; i++) {
        Printf("Enter element ");
        SendInt2PC(i + 1);
        Printf(": ");
        arr[i] = ReadIntPC(); 
    }
    
    SumEvenOdd(arr, size); 
}

void SumEvenOdd(unsigned int arr[], unsigned int size) {
    unsigned int sum_even = 0;
    unsigned int sum_odd = 0;
    unsigned int i;
    
    for (i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            sum_even += arr[i];
        } else {
            sum_odd += arr[i];
        }
    }
    
    
    Printf("Sum of Even Numbers: ");
    SendInt2PC(sum_even);
    serial('\n');
    
    Printf("Sum of Odd Numbers: ");
    SendInt2PC(sum_odd);
		serial('\n');
   
}
