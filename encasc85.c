#include <stdio.h>
#include <math.h>
//#include <ctype.h>

#define CALC_OFFSET 85
#define STEP 33
#define SPACE 50


void changeByte(unsigned int *aprosim, int *byte) {
    *byte = (int) *aprosim % CALC_OFFSET;
    *byte += STEP;
    *aprosim /= CALC_OFFSET;
}

void checkForNewLine(int *newl) {
    if (*newl == SPACE) {
        printf("\n");
        *newl = 0;
    }
}

void printByteAndCheck(const int *byte, int *newl) {
    printf("%c", *byte);
    (*newl)++;
    checkForNewLine(newl);
}

unsigned int calculateUnsingedInteger(
        const int *input_1, const int *input_2,
        const int *input_3, const int *input_4
) {
    int ch1, ch2, ch3, ch4;

    ch1 = *input_1 * (int) pow(256, 3);
    ch2 = *input_2 * (int) pow(256, 2);
    ch3 = *input_3 * 256;
    ch4 = *input_4;

    return ch1 + ch2 + ch3 + ch4;
}

//int getCharAndOmitWhitespace() {
//    int character;
//    while (isspace(character = getchar()));
//    return character;
//}

int main(void) {

    unsigned int aprosim = 0;
    int input_1, input_2, input_3, input_4;
    int byte1 = 0, byte2 = 0, byte3 = 0, byte4 = 0, byte5 = 0;
//    char t1,t2,t3,t4;
//    char c1,c2,c3,c4,c5;
    int newl = 0;                      // newl holds 50 characters until a new line

    printf("<~\n");

    while (1) {
        input_1 = getchar();
        input_2 = getchar();
        input_3 = getchar();
        input_4 = getchar();

//    Debugging
//        t1 = (char) input_1;
//        t2 = (char) input_2;
//        t3 = (char) input_3;
//        t4 = (char) input_4;
//  Breakpoint here

        if (input_1 == '\0' && input_2 == '\0' && input_3 == '\0' && input_4 == '\0') {
            putchar('z');
            newl++;
        }

        if (input_1 == EOF) {
            break;
        }

        if (input_2 == EOF) {        // if one character remains at the end of input

            input_2 = '\0';
            input_3 = '\0';      // input is completed with 3 bytes
            input_4 = '\0';

            aprosim = calculateUnsingedInteger(
                    &input_1,
                    &input_2,
                    &input_3,
                    &input_4);

            changeByte(&aprosim, &byte5);
            changeByte(&aprosim, &byte4);
            changeByte(&aprosim, &byte3);
            changeByte(&aprosim, &byte2);
            changeByte(&aprosim, &byte1);

            checkForNewLine(&newl);

            printByteAndCheck(&byte1, &newl);
            printByteAndCheck(&byte2, &newl);
            break;
        }

        if (input_3 == EOF) {    // if two characters remain at the end of input

            input_3 = '\0';
            input_4 = '\0';      // input is completed with 2 bytes

            aprosim = calculateUnsingedInteger(
                    &input_1, &input_2, &input_3, &input_4
                    );

            changeByte(&aprosim, &byte5);
            changeByte(&aprosim, &byte4);
            changeByte(&aprosim, &byte3);
            changeByte(&aprosim, &byte2);
            changeByte(&aprosim, &byte1);

            checkForNewLine(&newl);

            printByteAndCheck(&byte1, &newl);
            printByteAndCheck(&byte2, &newl);
            printByteAndCheck(&byte3, &newl);
            break;
        }

        if (input_4 == EOF) {      // if three characters remain at the end of input

            input_4 = '\0';      // input is completed with 1 byte

            aprosim = calculateUnsingedInteger(
                    &input_1,
                    &input_2,
                    &input_3,
                    &input_4);

            changeByte(&aprosim, &byte5);
            changeByte(&aprosim, &byte4);
            changeByte(&aprosim, &byte3);
            changeByte(&aprosim, &byte2);
            changeByte(&aprosim, &byte1);

            checkForNewLine(&newl);

            printByteAndCheck(&byte1, &newl);
            printByteAndCheck(&byte2, &newl);
            printByteAndCheck(&byte3, &newl);
            printByteAndCheck(&byte4, &newl);
            break;
        }

        aprosim = calculateUnsingedInteger(
                &input_1,
                &input_2,
                &input_3,
                &input_4);

        changeByte(&aprosim, &byte5);
        changeByte(&aprosim, &byte4);
        changeByte(&aprosim, &byte3);
        changeByte(&aprosim, &byte2);
        changeByte(&aprosim, &byte1);

//        Debugging
//        c1 = (char) byte1;
//        c2 = (char) byte2;
//        c3 = (char) byte3;
//        c4 = (char) byte4;
//        c5 = (char) byte5;

        checkForNewLine(&newl);

        if (byte5 == '!' && byte4 == '!' && byte3 == '!' && byte2 == '!' && byte1 == '!')
            continue;

        printByteAndCheck(&byte1, &newl);
        printByteAndCheck(&byte2, &newl);
        printByteAndCheck(&byte3, &newl);
        printByteAndCheck(&byte4, &newl);
        printByteAndCheck(&byte5, &newl);
    }

    printf("\n~>\n");
    return 0;
}

