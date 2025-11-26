// Program for CRC Algorithm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int crc(char *ip, char *op, char *poly, int mode)
{
    int i, j, k;
    strcpy(op, ip);

    if (mode) {
        for (i = 0; i < strlen(poly) - 1; i++)
            strcat(op, "0");
    }

    for (j = 0; j <= strlen(op) - strlen(poly); j++) {
        if (op[j] == '1') {
            for (k = 0; k < strlen(poly); k++) {
                if ((op[j + k] == '0' && poly[k] == '0') || (op[j + k] == '1' && poly[k] == '1'))
                    op[j + k] = '0';
                else
                    op[j + k] = '1';
            }
        }
    }

    // Error check
    for (j = 0; j < strlen(op); j++)
        if (op[j] == '1')
            return 1;   // error detected

    return 0;  // no error
}

int main()
{
    int i, n, flag;
    char ip[50], op[100], recv[100];
    char poly[] = "10001000000100001";  // CRC-16 polynomial (17 bits)

    flag = 0;
    strcpy(ip, "");
    strcpy(op, "");

    printf("\n ----- CRC-16 ----- \n");
    printf("Enter the input message in binary: ");
    scanf("%s", ip);

    n = strlen(ip);

    // Validate input
    for (i = 0; i < n; i++) {
        if (ip[i] != '0' && ip[i] != '1') {
            flag = 1;
            break;
        }
    }

    if (flag) {
        printf("Invalid input message. Binary only (0/1).\n");
        exit(0);
    }

    crc(ip, op, poly, 1);

    printf("The transmitted message is: %s%s\n", ip, op + strlen(ip));

    printf("\nEnter the received message in binary: ");
    scanf("%s", recv);

    if (!crc(recv, op, poly, 0))
        printf("No error in data\n");
    else
        printf("Error in data transmission has occurred\n");

    return 0;
}
