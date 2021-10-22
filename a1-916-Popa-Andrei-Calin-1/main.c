#include <stdio.h>
#include <math.h>

int menu() {
    /*
     Prints menu in console and reads input.
     return: character
     */
    char cmd;
    printf("\n\nMENU\n"
           "a. Print the Pascal triangle of dimension n of all combinations C(m,k) of m objects taken by k, k = 0, 1, ..., m, for line m, where m = 1, 2, ..., n.\n"
           "b. Given a vector of numbers, find the longest contiguous subsequence of prime numbers.\n"
           "c. Compute the approximated value of square root of a positive real number. The precision is provided by the user.\n"
           "x. Exit program.\n");

    scanf(" %c", &cmd);

    return cmd;
}

int prime(int n) {
    /*
     param: integer
     return: 1 if the number is prime
             0 if the number is not prime
     */
    int flag = 1;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            flag = 0;
            break;
        }
    }
    if (n <= 1)
        flag = 0;

    if (flag == 1) return 1;
    else return 0;
}

void funct_a() {
    /*
     Prints the Pascal triangle of dimension n of all combinations C(m,k)
     */
    int n, i, space, k = 0, count = 0, count1 = 0;

    printf(" Give n: ");
    scanf("%d", &n);
    printf("\n");

    for (i = 1; i <= n; ++i) {
        for (space = 1; space <= n - i; ++space) {
            printf("  ");
            ++count;
        }
        while (k != 2 * i - 1) {
            if (count <= n - 1) {
                printf("%d ", i + k);
                ++count;
            } else {
                ++count1;
                printf("%d ", (i + k - 2 * count1));
            }
            ++k;
        }
        count1 = count = k = 0;
        printf("\n");
    }
}

void funct_b() {
    /*
     Given a vector of numbers, prints the longest contiguous subsequence of prime numbers.
     */
    int n, v[100];

    printf(" Give vector's length: ");
    scanf("%d", &n);
    printf("Give vector: ");
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);

    int len = 0, maxlen = 0, end = 0;
    for (int i = 0; i < n; i++) {
        if (prime(v[i]) == 0) {
            if (len > maxlen) {
                maxlen = len;
                end = i;
            }
            len = 0;
        } else len++;
    }
    if (len > maxlen) {
        maxlen = len;
        end = n;
    }

//    printf("%d %d \n", maxlen, end);
    for (int i = end - maxlen; i < end; i++) printf("%d ", v[i]);
}

void funct_c() {
    int n, p;

    printf(" Give number: ");
    scanf("%d", &n);
    printf("Give precision: ");
    scanf("%d", &p);

    float rez = sqrt(n);

    int inti = rez;
    int deci = (rez - inti) * pow(10, p);

    printf("%d.%d", inti, deci);

//     printf("%d.%.0f", (int)sqrt(n), (sqrt(n) - (int)sqrt(n)) * pow(10, p));
}


int main() {

    while (1) {
        char cmd = menu();
        if (cmd == 'a') funct_a();
        else if (cmd == 'b') funct_b();
        else if (cmd == 'c') funct_c();
        else if (cmd == 'x') return 0;
        else printf("Invalid input!\n");
    }
}
