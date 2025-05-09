//IEEE-754 Representation
#include <stdio.h>
#include <math.h>

int decToBin(int num, int a[]){

    int d = 0, i = 0;

    while (num != 0){
        d = num % 2;
        a[i] = d;
        num = num / 2;
        i++;
    }
    return i;
}

void decToBinDec(double num, int a[]){

    int d = 0, i = 0;
    for (i = 0; i < 10; i++){
        if ((num - floor(num)) == 0.0){
            break;
        }
        d = (num - floor(num)) * 2;
        a[i] = d;
        num = num * 2;
    }
}

void decToBinDec2(double num, int a[]){

    int d = 0, i = 0;
    for (i = 0; i < 23; i++){
        if ((num - floor(num)) == 0.0){
            break;
        }
        d = (num - floor(num)) * 2;
        a[i] = d;
        num = num * 2;
    }
}

void main(){

    int bin_dec[10] = {0}, length, sign_bit = 0, integer_part = 0, bin_dec_float[10] = {0}, mantissa[50];
    int len1 = 0, count = 0, exponent = 0, j = 0, bias = 127, exp_bin[10] = {0}, len_exp = 0, i = 0;
    int bin_dec2[23] = {0};
    double user_input = 0, decimal_part = 0;
    printf("Enter a decimal number: ");
    scanf("%lf", &user_input);
    printf("The IEEE-754 Floating Point Representation of the number is  \n",user_input);
    if (user_input < 0){
        sign_bit = 1;
    }

    if (fabs(user_input) < 1){


        decToBinDec2(fabs(user_input), bin_dec2);

        for (i = 0; i < 23; i++){
            if (bin_dec2[i] == 1){
                break;
            }
            count++;
        }
        exponent = count + 1;
        bias = bias - exponent;

        len_exp = decToBin(bias, exp_bin);

        printf("%d ", sign_bit);
        printf("%d ", 0);
        for (i = len_exp-1; i >= 0; i--){
            printf("%d", exp_bin[i]);
        }
        printf(" ");
        for (i = exponent; i < 23; i++){
            printf("%d", bin_dec2[i]);
        }
        for (i = 0; i < exponent; i++){
            printf("0");
        }

    }
    else{

        integer_part = floor(fabs(user_input));
        decimal_part = fabs(user_input) - floor(fabs(user_input));

        len1 = decToBin(integer_part, bin_dec);
        decToBinDec(decimal_part, bin_dec_float);

        for (i = len1 - 1; i >= 0; i--){
            if (bin_dec[i] == 1){
                break;
            }
            count++;
        }

        exponent = len1 - count - 1;

        for (i = exponent - 1; i >= 0; i--){
            mantissa[j] = bin_dec[i];
            j++;
        }

        for (i = j; i < j + 10; i++){
            mantissa[i] = bin_dec_float[i-j];
        }

        bias = bias + exponent;
        len_exp = decToBin(bias, exp_bin);

        printf("%d ", sign_bit);

        for (i = len_exp - 1; i >= 0; i--){
            printf("%d", exp_bin[i]);
        }

        printf(" ");

        for (i = 0; i < j + 10; i++){
            printf("%d", mantissa[i]);
        }

        for (i = 0; i < 23 - j - 10; i++){
            printf("0");
        }
    }
}
