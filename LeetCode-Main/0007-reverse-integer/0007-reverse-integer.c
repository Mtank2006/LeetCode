#include <stdio.h>
#include <limits.h>
int reverse(long x){
    int temp=0;
    long rev =0;
    while (x!=0) {
        temp = x %10;
        x /= 10;
        rev = 10*rev+temp;
        if (rev > INT_MAX || rev < INT_MIN) {
            return 0;
        }
    }
    return rev;
}
int main () {
    long x;
    scanf ("%ld",&x);
    printf ("%d",reverse(x));
}