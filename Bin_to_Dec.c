#include <stdio.h>
#include <math.h>

void main() {
    int dec = 0, temp, bin, dig, i = 0;
    printf("Enter the binary number \n");
    scanf("%d", &bin);
    temp = bin;
    while (temp > 0) {
        dig = temp % 10;
        dec = dec + dig * pow(2, i);
        temp /= 10;
        i++;
    }
    printf("The decimal value for %d is %d \n", bin, dec);
}
