#include <limits.h>
#include <stdio.h>

enum size { MIN, MAX };

int range_char(enum size bound);
int range_int(enum size bound);

/* Displaying the range of variables types using macros of limits*/
int main() {
    printf("Range of char: %d at %d\n", CHAR_MIN, CHAR_MAX);
    printf("Range of unsigned char: %d at %d\n", 0, UCHAR_MAX);
    printf("Range of signed char: %d at %d\n", SCHAR_MIN, SCHAR_MAX);

    printf("Range of int: %d at %d\n", INT_MIN , INT_MAX);
    printf("Range of unsigned int: %u at %u\n", 0, UINT_MAX);

    printf("Range of short: %d at %d\n", SHRT_MIN, SHRT_MAX);
    printf("Range of unsigned short: %u at %u\n", 0, USHRT_MAX);

    printf("Range of long: %ld at %ld\n", LONG_MIN, LONG_MAX);
    printf("Range of unsigned long: %lu at %lu\n", 0LU, ULONG_MAX);

    printf("Range of long long: %lld at %lld\n", LLONG_MIN, LLONG_MAX);
    printf("Range of unsigned long long: %llu at %llu\n", 0LLU, ULLONG_MAX);

    char size_max_char = range_char(MAX);
    char size_min_char = range_char(MIN);
    int size_max_int = range_int(MAX);
    int size_min_int = range_int(MIN);
    printf("%d\n", size_max_char);
    printf("%d\n", size_min_char);
    printf("%d\n", size_max_int);
    printf("%d\n", size_min_int);
    
    return 0;
}

int power2(int a) {
    int power = 1;
    for (; a > 0; a--) {
        power = power * 2;
    }
    return power;
}

/* Calculating max range of char, by adding some quantity power of 2, and reduncing it */
int range_char(enum size bound) {
    char number = 0, later = 0;
    int step = power2(4);
    if (bound == MIN) {
        while (step) {
            later = number;
            number -= step;
            
            if (number >= later) {
                number = later;
                step /= 2;
            }
        }
    }
    else {
        while (step) {
            later = number;
            number += step;
            
            if (number <= later) {
                number = later;
                step /= 2;
            }
        }
    }
    
    return number;
}

int range_int(enum size bound) {
    int number = 0, later = 0;
    int step = power2(15);
    
    if (bound == MIN) {
        while (step) {
            later = number;
            number -= step;
        
            if (number >= later) {
                number = later;
                step /= 2;
            }
        }
    }
    else {
        while (step) {
            later = number;
            number += step;
        
            if (number <= later) {
                number = later;
                step /= 2;
            }
        }
    }
    return number;
}  