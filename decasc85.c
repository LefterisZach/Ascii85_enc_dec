#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 117
#define MIN 33


int main(void) {

    unsigned int aprosim = 0;
    int f1 = 0,f2 = 0,byte1 = 0,byte2 = 0,byte3 = 0,byte4 = 0,byte5 = 0,ch1=0,ch2=0,ch3=0,ch4=0;


    while((f1 = getchar()) != '<'){
        if(f1 == ' ' || f1 == '\t' || f1 == '\n')   //ignoring whitespace
            continue;
        else if(isalpha(f2) || isdigit(f2)){      // function isalpha checks if the passed character is alphabetic
            printf("Unnecessary input\n");        // function isdigit checks if the passed character is a decimal digit character
            exit(0);                              //function exit terminates the calling process immediately
        }

        else
        {       printf("Bad start\n");
            exit(0);
        }
    }


    if((f2 = getchar()) != '~'){
        printf("Bad start\n");
        exit(0);
    }


    while(1){


        byte1 = getchar();
        if(byte1==' '|| byte1 == '\t' || byte1 == '\n')continue;    //ignoring whitespace

        if(byte1 == 'z'){
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

            aprosim = (byte1*85*85*85*85) + (byte2*85*85*85) + (byte3*85*85) + (byte4*85) + byte5;

            ch1 = aprosim/(256*256*256);
            aprosim = aprosim%(256*256*256);
            ch2 = aprosim/(256*256);
            aprosim = aprosim%(256*256);
            ch3 = aprosim/256;
            aprosim = aprosim%256;
            ch4 = aprosim;


            putchar(ch1);
            putchar(ch2);
            putchar(ch3);
            putchar(ch4);
            continue;
        }

        byte2 = getchar();
        if(byte2 == ' ' || byte2 == '\t' || byte2 == '\n'){
            do{
                byte2 = getchar();
            }while(byte2 == ' ' || byte2 == '\t' || byte2 == '\n');
        }


        byte3 = getchar();
        if(byte3 == ' ' || byte3 == '\t' || byte3 == '\n'){
            do{
                byte3 = getchar();
            }while(byte3 == ' ' || byte3 == '\t' || byte3 == '\n');
        }


        byte4 = getchar();
        if(byte4 == ' ' || byte4 == '\t' || byte4 == '\n'){
            do{
                byte4 = getchar();
            }while(byte4 == ' ' || byte4 == '\t' || byte4 == '\n');
        }


        byte5 = getchar();
        if(byte5 == ' ' || byte5 == '\t' || byte5 == '\n'){
            do{
                byte5 = getchar();
            }while(byte5 == ' ' || byte5 == '\t' || byte5 == '\n');
        }




        if(byte1==EOF||byte2==EOF||byte3==EOF||byte4==EOF||byte5==EOF){
            printf("\tBad end\n");                              // case of not ending with '~'
            exit(0);
        }
        if((byte1 > MAX && byte1 != '~') || byte1 < MIN){
            printf("\tBad input character\n");
            exit(0);
        }
        if((byte2 > MAX && byte2 != '~') || byte2 < MIN){
            printf("\tBad input character\n");
            exit(0);
        }
        if((byte3 > MAX && byte3 != '~') || byte3 < MIN){
            printf("\tBad input character\n");
            exit(0);
        }
        if((byte4 > MAX && byte4 != '~') || byte4 < MIN ){
            printf("\tBad input character\n");
            exit(0);
        }

        if((byte5 > MAX && byte5 != '~') || byte5 < MIN){
            printf("\tBad input character\n");
            exit(0);
        }


        if(byte3 == '~'){       // if two characters remain at the end of input

            byte3 = 'u';
            byte4 = 'u';      // input is completed with 5-2 bytes
            byte5 = 'u';

            byte1 -= 33;
            byte2 -= 33;
            byte3 -= 33;
            byte4 -= 33;
            byte5 -= 33;

            aprosim = (byte1*85*85*85*85) + (byte2*85*85*85) + (byte3*85*85) + (byte4*85) + byte5;

            ch1 = aprosim/(256*256*256);
            aprosim = aprosim%(256*256*256);
            ch2 = aprosim/(256*256);
            aprosim = aprosim%(256*256);
            ch3 = aprosim/256;
            aprosim = aprosim%256;
            ch4 = aprosim;

            putchar(ch1);
            break;
        }


        if(byte4 == '~'){   // if three characters remain at the end of input

            byte4 = 'u';
            byte5 = 'u';    // input is completed with 5-3 bytes

            byte1 -= 33;
            byte2 -= 33;
            byte3 -= 33;
            byte4 -= 33;
            byte5 -= 33;

            aprosim = (byte1*85*85*85*85) + (byte2*85*85*85) + (byte3*85*85) + (byte4*85) + byte5;

            ch1 = aprosim/(256*256*256);
            aprosim = aprosim%(256*256*256);
            ch2 = aprosim/(256*256);
            aprosim = aprosim%(256*256);
            ch3 = aprosim/256;
            aprosim = aprosim%256;
            ch4 = aprosim;

            putchar(ch1);
            putchar(ch2);
            break;
        }


        if(byte5 == '~'){       // if four characters remain at the end of input

            byte5 = 'u';      // input is completed with 5-4 bytes

            byte1 -= 33;
            byte2 -= 33;
            byte3 -= 33;
            byte4 -= 33;
            byte5 -= 33;

            aprosim = (byte1*85*85*85*85) + (byte2*85*85*85) + (byte3*85*85) + (byte4*85) + byte5;

            ch1 = aprosim/(256*256*256);
            aprosim = aprosim%(256*256*256);
            ch2 = aprosim/(256*256);
            aprosim = aprosim%(256*256);
            ch3 = aprosim/256;
            aprosim = aprosim%256;
            ch4 = aprosim;

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

        aprosim = (byte1*85*85*85*85) + (byte2*85*85*85) + (byte3*85*85) + (byte4*85) + byte5;

        ch1 = aprosim/(256*256*256);
        aprosim = aprosim%(256*256*256);
        ch2 = aprosim/(256*256);
        aprosim = aprosim%(256*256);
        ch3 = aprosim/256;
        aprosim = aprosim%256;
        ch4 = aprosim;


        putchar(ch1);
        putchar(ch2);
        putchar(ch3);
        putchar(ch4);


    }




    if((f1 = getchar()) != '>' && f1 != '\n'){      // case of not ending with '>'
        printf("\tBad end\n");
        exit(0);
    }

    f2 = getchar();
    if(f2==EOF)return 0;

    else if(isalpha(f2) || isdigit(f2)){      // case of ending with unnecessary input
        printf("\tUnnecessary input\n");
        exit(0);
    }
    else do{
            f2 = getchar();
            if(f2 == ' ' || f2 == '\t' || f2 == '\n')     //ignoring whitespace
                continue;
        }while(f2!=EOF);


    return 0;
}

