#include <stdio.h>
#define SPACE 50

int main(void) {

    unsigned int aprosim = 0;
    int byte1 = 0,byte2 = 0,byte3 = 0,byte4 = 0,byte5 = 0;
    int b1=0,b2=0,b3=0,b4=0,ch1=0,ch2=0,ch3=0,ch4=0,newl = 0;

    printf("<~\n");

    while(1){
        b1 = getchar();     if(b1 == EOF)break;
        b2 = getchar();
        b3 = getchar();
        b4 = getchar();

        if(b1 == '\0' && b2 == '\0' && b3 == '\0' && b4 == '\0'){
            putchar('z');
            newl++;               // newl holds 50 characters for new line
        }
        if(newl == SPACE ){
            printf("\n");
            newl = 0;
        }

        if(b2==EOF){        // if one character remains at the end of input

            b2 = '\0';
            b3 = '\0';      // input is completed with 4-1 bytes
            b4 = '\0';

            ch1 = b1*256*256*256;
            ch2 = b2*256*256;
            ch3 = b3*256;
            ch4 = b4;

            aprosim = ch1+ch2+ch3+ch4;


            byte1 = aprosim%85;
            byte1 = byte1 + 33;
            aprosim = aprosim/85;

            byte2 = aprosim%85;
            byte2 = byte2 + 33;
            aprosim = aprosim/85;

            byte3 = aprosim%85;
            byte3 = byte3 + 33;
            aprosim = aprosim/85;

            byte4 = aprosim%85;
            byte4 = byte4 + 33;
            aprosim = aprosim/85;

            byte5 = aprosim%85;
            byte5 = byte5 + 33;
            aprosim = aprosim/85;

            putchar(byte5);
            putchar(byte4);
            break;
        }

        if(b3==EOF){    // if two characters remain at the end of input

            b3 = '\0';
            b4 = '\0';      // input is completed with 4-2 bytes

            ch1 = b1*256*256*256;
            ch2 = b2*256*256;
            ch3 = b3*256;
            ch4 = b4;

            aprosim = ch1+ch2+ch3+ch4;


            byte1 = aprosim%85;
            byte1 = byte1 + 33;
            aprosim = aprosim/85;

            byte2 = aprosim%85;
            byte2 = byte2 + 33;
            aprosim = aprosim/85;

            byte3 = aprosim%85;
            byte3 = byte3 + 33;
            aprosim = aprosim/85;

            byte4 = aprosim%85;
            byte4 = byte4 + 33;
            aprosim = aprosim/85;

            byte5 = aprosim%85;
            byte5 = byte5 + 33;
            aprosim = aprosim/85;

            putchar(byte5);
            putchar(byte4);
            putchar(byte3);
            break;
        }

        if(b4==EOF){      // if three characters remain at the end of input

            b4 = '\0';      // input is completed with 4-2 bytes

            ch1 = b1*256*256*256;
            ch2 = b2*256*256;
            ch3 = b3*256;
            ch4 = b4;

            aprosim = ch1+ch2+ch3+ch4;


            byte1 = aprosim%85;
            byte1 = byte1 + 33;
            aprosim = aprosim/85;

            byte2 = aprosim%85;
            byte2 = byte2 + 33;
            aprosim = aprosim/85;

            byte3 = aprosim%85;
            byte3 = byte3 + 33;
            aprosim = aprosim/85;

            byte4 = aprosim%85;
            byte4 = byte4 + 33;
            aprosim = aprosim/85;

            byte5 = aprosim%85;
            byte5 = byte5 + 33;
            aprosim = aprosim/85;

            putchar(byte5);
            putchar(byte4);
            putchar(byte3);
            putchar(byte2);
            break;
        }


        ch1 = b1*256*256*256;
        ch2 = b2*256*256;
        ch3 = b3*256;
        ch4 = b4;

        aprosim = ch1+ch2+ch3+ch4;


        byte1 = aprosim%85;
        byte1 = byte1 + 33;
        aprosim = aprosim/85;

        byte2 = aprosim%85;
        byte2 = byte2 + 33;
        aprosim = aprosim/85;

        byte3 = aprosim%85;
        byte3 = byte3 + 33;
        aprosim = aprosim/85;

        byte4 = aprosim%85;
        byte4 = byte4 + 33;
        aprosim = aprosim/85;

        byte5 = aprosim%85;
        byte5 = byte5 + 33;
        aprosim = aprosim/85;

        if(newl == SPACE){
            printf("\n");
            newl = 0;
        }

        if(byte5 == '!' && byte4 == '!' && byte3 == '!'&& byte2 == '!' && byte1 == '!')
            continue;

        putchar(byte5); newl++;
        if(newl == SPACE){
            printf("\n");
            newl = 0;
        }
        putchar(byte4); newl++;
        if(newl == SPACE){
            printf("\n");
            newl = 0;
        }

        putchar(byte3); newl++;
        if(newl == SPACE){
            printf("\n");
            newl = 0;
        }

        putchar(byte2); newl++;
        if(newl == SPACE){
            printf("\n");
            newl = 0;
        }

        putchar(byte1); newl++;
        if(newl == SPACE){
            printf("\n");
            newl = 0;
        }
    }

    printf("\n~>\n");
    return 0;
}

