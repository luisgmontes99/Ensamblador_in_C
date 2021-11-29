#include <iostream>
#include <conio.h>

int gcd( int $a, int $b )
{
    int $result;
    __asm__ __volatile__(
        "movl %1, %%eax;"
        "movl %2, %%ebx;"
        "CONTD: cmpl $0, %%ebx;"
        "je DONE;"
        "xorl %%edx, %%edx;"
        "idivl %%ebx;"
        "movl %%ebx, %%eax;"
        "movl %%edx, %%ebx;"
        "jmp CONTD;"
        "DONE: movl %%eax, %0;" : "=g" ( $result ) : "g" ( $a ), "g" ( $b )
    );
    return $result ;
}

int suma( int $a, int $b )
{
    int $result;
    __asm__ __volatile__ (
            "movl %1, %%eax;"
            "movl %2, %%ebx;"
            "addl %%ebx, %%eax;"
            "movl %%eax,%0;" : "=g" ( $result ) : "g" ( $a ), "g" ( $b )
    );
    return $result ;
}

int suma3( int $a, int $b, int $c )
{
    int $result;
    __asm__ _volatile_(
            "movl %1, %%eax;"
            "movl %2, %%ebx;"
            "movl %3, %%ecx;"
            "addl %%ebx, %%eax;"
            "addl %%ecx, %%eax;"
            "movl %%eax,%0;" : "=g" ( $result ) : "g" ( $a ), "g" ( $b ),  "g" ( $c )
    );
    return $result ;
}



int main(int argc, char** argv) {
    int a,b,c,d;
    a = 4;
    b = 6;
    c = gcd(a,b);
    printf("a=%d \t b=%d \t gcd=%d \n\r",a,b,c);
    c = suma(a,b);
    printf("a=%d \t b=%d \t suma=%d \n\r",a,b,c);
    d=suma3(a,b, c );
    printf("suma=%d \n\r",d);

	return 0;
}
