// decimal to binary
#include <stdio.h>

void main() {
    int dec, temp, bin[16], i = 0, j;
    printf("Enter the decimal number \n");
    scanf("%d", &dec);
    temp = dec;
    while (dec > 0) {
        bin[i] = dec % 2;
        dec = dec / 2;
        i++;
    }
    printf("The binary conversion of %d is ", temp);
    for (j = i - 1; j >= 0; j--) {
        printf("%d", bin[j]);
    }
    printf("\n");
}

