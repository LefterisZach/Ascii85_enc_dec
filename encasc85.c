#include <stdio.h>
#include <math.h>

#define CALC_OFFSET 85
#define STEP 33
#define SPACE 50

void changeByte(unsigned int* aprosim, int* byte) {
    *byte = (int) *aprosim % CALC_OFFSET;
    *byte += STEP;
    *aprosim /= CALC_OFFSET;
}

void checkForNewLine(int *newl) {
    if ((*newl) == SPACE) {
        printf("\n");
        (*newl) = 0;
    }
}

void printByteAndCheck(const int *byte, int *newl) {
    printf("%c", *byte);
    (*newl)++;
    checkForNewLine(newl);
}

int main(void) {

    unsigned int aprosim = 0;
    int byte1 = 0, byte2 = 0, byte3 = 0, byte4 = 0, byte5 = 0;
    int b1, b2, b3, b4;
    int ch1, ch2, ch3, ch4;
    static int newl = 0;                      // newl holds 50 characters until a new line

    printf("<~\n");

    while (1) {
        b1 = getchar();
        if (b1 == EOF)
            break;
        b2 = getchar();
        b3 = getchar();
        b4 = getchar();

        if (b1 == '\0' && b2 == '\0' && b3 == '\0' && b4 == '\0') {
            putchar('z');
            newl++;
        }

        checkForNewLine(&newl);

        if (b2 == EOF) {        // if one character remains at the end of input

            b2 = '\0';
            b3 = '\0';      // input is completed with 3 bytes
            b4 = '\0';

            ch1 = b1 * pow(256, 3);
            ch2 = b2 * pow(256, 2);
            ch3 = b3 * 256;
            ch4 = b4;

            aprosim = ch1 + ch2 + ch3 + ch4;

            changeByte(&aprosim, &byte1);
            changeByte(&aprosim, &byte2);
            changeByte(&aprosim, &byte3);
            changeByte(&aprosim, &byte4);
            changeByte(&aprosim, &byte5);

            printByteAndCheck(&byte5, &newl);
            printByteAndCheck(&byte4, &newl);
            break;
        }

        if (b3 == EOF) {    // if two characters remain at the end of input

            b3 = '\0';
            b4 = '\0';      // input is completed with 2 bytes

            ch1 = b1 * pow(256, 3);
            ch2 = b2 * pow(256, 2);
            ch3 = b3 * 256;
            ch4 = b4;

            aprosim = ch1 + ch2 + ch3 + ch4;

            changeByte(&aprosim, &byte1);
            changeByte(&aprosim, &byte2);
            changeByte(&aprosim, &byte3);
            changeByte(&aprosim, &byte4);
            changeByte(&aprosim, &byte5);

            printByteAndCheck(&byte5, &newl);
            printByteAndCheck(&byte4, &newl);
            printByteAndCheck(&byte3, &newl);
            break;
        }

        if (b4 == EOF) {      // if three characters remain at the end of input

            b4 = '\0';      // input is completed with 1 byte

            ch1 = b1 * pow(256, 3);
            ch2 = b2 * pow(256, 2);
            ch3 = b3 * 256;
            ch4 = b4;

            aprosim = ch1 + ch2 + ch3 + ch4;

            changeByte(&aprosim, &byte1);
            changeByte(&aprosim, &byte2);
            changeByte(&aprosim, &byte3);
            changeByte(&aprosim, &byte4);
            changeByte(&aprosim, &byte5);

            printByteAndCheck(&byte5, &newl);
            printByteAndCheck(&byte4, &newl);
            printByteAndCheck(&byte3, &newl);
            printByteAndCheck(&byte2, &newl);
            break;
        }


        ch1 = b1 * pow(256, 3);
        ch2 = b2 * pow(256, 2);
        ch3 = b3 * 256;
        ch4 = b4;

        aprosim = ch1 + ch2 + ch3 + ch4;

        changeByte(&aprosim, &byte1);
        changeByte(&aprosim, &byte2);
        changeByte(&aprosim, &byte3);
        changeByte(&aprosim, &byte4);
        changeByte(&aprosim, &byte5);

        checkForNewLine(&newl);

        if (byte5 == '!' && byte4 == '!' && byte3 == '!' && byte2 == '!' && byte1 == '!')
            continue;

        printByteAndCheck(&byte5, &newl);
        printByteAndCheck(&byte4, &newl);
        printByteAndCheck(&byte3, &newl);
        printByteAndCheck(&byte2, &newl);
        printByteAndCheck(&byte1, &newl);
    }

    printf("\n~>\n");
    return 0;
}

