#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 117
#define MIN 33


void decodeApprosim(
        const int *byte1, const int *byte2, const int *byte3,
        const int *byte4, const int *byte5, unsigned int *aprosim
) {
    *aprosim = (*byte1 * (int) pow(85, 4) + (*byte2 * (int) pow(85, 3)) +
                (*byte3 * (int) pow(85, 2)) + (*byte4 * 85) + (*byte5));
}

void decodeBytes(
        int *byte1, int *byte2,
        int *byte3, int *byte4,
        unsigned int *aprosim
) {

    *byte1 = *aprosim / (int) pow(256, 3);
    *aprosim = *aprosim % (int) pow(256, 3);
    *byte2 = *aprosim / (int) pow(256, 2);
    *aprosim = *aprosim % (int) pow(256, 2);
    *byte3 = *aprosim / 256;
    *aprosim = *aprosim % 256;
    *byte4 = *aprosim;

}

int getCharAndOmitWhitespace() {
    int character;
    while (isspace(character = getchar()));
    return character;
}

void printBytes(int ch1, int ch2, int ch3, int ch4) {
    putchar(ch1);
    putchar(ch2);
    putchar(ch3);
    putchar(ch4);
}

int main(void) {

    unsigned int aprosim = 0;
    int f1 = 0, f2 = 0;
    int byte1 = 0, byte2 = 0, byte3 = 0, byte4 = 0, byte5 = 0;
    int ch1 = 0, ch2 = 0, ch3 = 0, ch4 = 0;


    while ((f1 = getchar()) != '<') {
        if (f1 == ' ' || f1 == '\t' || f1 == '\n')   //ignoring whitespace
            continue;
        else if (isalpha(f2) || isdigit(f2)) {      // function isalpha checks if the passed character is alphabetic
            printf("Unnecessary input\n");        // function isdigit checks if the passed character is a decimal digit character
            exit(0);                              //function exit terminates the calling process immediately
        } else {
            printf("Bad start\n");
            exit(0);
        }
    }

    if ((f2 = getchar()) != '~') {
        printf("Bad start\n");
        exit(0);
    }

    while (1) {

        byte1 = getCharAndOmitWhitespace();

        if (byte1 == 'z') {
            byte1 = '!';
            byte2 = '!';
            byte3 = '!';
            byte4 = '!';
            byte5 = '!';

            byte1 -= 33;
            byte2 -= 33;
            byte3 -= 33;
            byte4 -= 33;
            byte5 -= 33;

            decodeApprosim(&byte1, &byte2, &byte3, &byte4, &byte5, &aprosim);

            decodeBytes(&ch1, &ch2, &ch3, &ch4, &aprosim);

            printBytes(ch1, ch2, ch3, ch4);
            continue;
        }

        byte2 = getCharAndOmitWhitespace();
        byte3 = getCharAndOmitWhitespace();
        byte4 = getCharAndOmitWhitespace();
        byte5 = getCharAndOmitWhitespace();

        if (byte1 == EOF || byte2 == EOF || byte3 == EOF || byte4 == EOF || byte5 == EOF) {
            printf("\tBad end\n");                              // case of not ending with '~'
            exit(0);
        }
        if ((byte1 > MAX && byte1 != '~') || byte1 < MIN) {
            printf("\tBad input character\n");
            exit(0);
        }
        if ((byte2 > MAX && byte2 != '~') || byte2 < MIN) {
            printf("\tBad input character\n");
            exit(0);
        }
        if ((byte3 > MAX && byte3 != '~') || byte3 < MIN) {
            printf("\tBad input character\n");
            exit(0);
        }
        if ((byte4 > MAX && byte4 != '~') || byte4 < MIN) {
            printf("\tBad input character\n");
            exit(0);
        }

        if ((byte5 > MAX && byte5 != '~') || byte5 < MIN) {
            printf("\tBad input character\n");
            exit(0);
        }

        if (byte3 == '~') {       // if two characters remain at the end of input

            byte3 = 'u';
            byte4 = 'u';      // input is completed with 5-2 bytes
            byte5 = 'u';

            byte1 -= 33;
            byte2 -= 33;
            byte3 -= 33;
            byte4 -= 33;
            byte5 -= 33;

            decodeApprosim(&byte1, &byte2, &byte3, &byte4, &byte5, &aprosim);

            decodeBytes(&ch1, &ch2, &ch3, &ch4, &aprosim);

            putchar(ch1);
            break;
        }


        if (byte4 == '~') {   // if three characters remain at the end of input

            byte4 = 'u';
            byte5 = 'u';    // input is completed with 5-3 bytes

            byte1 -= 33;
            byte2 -= 33;
            byte3 -= 33;
            byte4 -= 33;
            byte5 -= 33;

            decodeApprosim(&byte1, &byte2, &byte3, &byte4, &byte5, &aprosim);

            decodeBytes(&ch1, &ch2, &ch3, &ch4, &aprosim);

            putchar(ch1);
            putchar(ch2);
            break;
        }


        if (byte5 == '~') {       // if four characters remain at the end of input

            byte5 = 'u';      // input is completed with 5-4 bytes

            byte1 -= 33;
            byte2 -= 33;
            byte3 -= 33;
            byte4 -= 33;
            byte5 -= 33;

            decodeApprosim(&byte1, &byte2, &byte3, &byte4, &byte5, &aprosim);

            decodeBytes(&ch1, &ch2, &ch3, &ch4, &aprosim);

            putchar(ch1);
            putchar(ch2);
            putchar(ch3);
            break;
        }

        byte1 -= 33;
        byte2 -= 33;
        byte3 -= 33;
        byte4 -= 33;
        byte5 -= 33;

        decodeApprosim(&byte1, &byte2, &byte3, &byte4, &byte5, &aprosim);

        decodeBytes(&ch1, &ch2, &ch3, &ch4, &aprosim);

        printBytes(ch1, ch2, ch3, ch4);

    }


    if ((f1 = getchar()) != '>' && f1 != '\n') {      // case of not ending with '>'
        printf("\tBad end\n");
        exit(0);
    }

    f2 = getchar();
    if (f2 == EOF)
        return 0;

    else if (isalpha(f2) || isdigit(f2)) {      // case of ending with unnecessary input
        printf("\tUnnecessary input\n");
        exit(0);
    } else
        do {
            f2 = getCharAndOmitWhitespace();
        } while (f2 != EOF);

    return 0;
}

