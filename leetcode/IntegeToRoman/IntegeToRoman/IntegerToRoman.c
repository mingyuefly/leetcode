//
//  IntegerToRoman.c
//  IntegeToRoman
//
//  Created by Gguomingyue on 2019/6/12.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "IntegerToRoman.h"
#include <string.h>
#include <stdlib.h>

/*
 //answered by myself
char * intToRoman(int num){
    if (num < 1 || num > 3999) {
        return "";
    }
    int digit = 0;
    int thousand = 0, hundred = 0, ten = 0, last = 0;
    char *d1 = "I", *d5 = "V", *d10 = "X", *d50 = "L", *d100 = "C", *d500 = "D", *d1000 = "M";
    int temp = num % 10;
    int temp1 = num;
    while (temp1 > 0) {
        if (digit == 0) {
            last = temp;
        } else if (digit == 1) {
            ten = temp;
        } else if (digit == 2) {
            hundred = temp;
        } else {
            thousand = temp;
        }
        digit++;
        temp1 /= 10;
        temp = temp1 % 10;
    }
    printf("%d %d %d %d\n", thousand, hundred, ten, last);
    char * tempOutput = (char *)malloc(sizeof(char) * 20);
    if (thousand != 0) {
        for (int i = 0; i < thousand; i++) {
            strcat(tempOutput, d1000);
        }
    }
    if (hundred != 0) {
        if (hundred >= 5) {
            if (hundred == 9) {
                strcat(tempOutput, d100);
                strcat(tempOutput, d1000);
            } else {
                strcat(tempOutput, d500);
                for (int i = 0; i < (hundred - 5); i++) {
                    strcat(tempOutput, d100);
                }
            }
        } else {
            if (hundred == 4) {
                strcat(tempOutput, d100);
                strcat(tempOutput, d500);
            } else {
                for (int i = 0; i < hundred; i++) {
                    strcat(tempOutput, d100);
                }
            }
        }
    }
    if (ten > 0) {
        if (ten >= 5) {
            if (ten == 9) {
                strcat(tempOutput, d10);
                strcat(tempOutput, d100);
            } else {
                strcat(tempOutput, d50);
                for (int i = 0; i < (ten - 5); i++) {
                    strcat(tempOutput, d10);
                }
            }
        } else {
            if (ten == 4) {
                strcat(tempOutput, d10);
                strcat(tempOutput, d50);
            } else {
                for (int i = 0; i < ten; i++) {
                    strcat(tempOutput, d10);
                }
            }
        }
    }
    if (last > 0) {
        if (last >= 5) {
            if (last == 9) {
                strcat(tempOutput, d1);
                strcat(tempOutput, d10);
            } else {
                strcat(tempOutput, d5);
                for (int i = 0; i < (last - 5); i++) {
                    strcat(tempOutput, d1);
                }
            }
        } else {
            if (last == 4) {
                strcat(tempOutput, d1);
                strcat(tempOutput, d5);
            } else {
                for (int i = 0; i < last; i++) {
                    strcat(tempOutput, d1);
                }
            }
        }
    }
    return tempOutput;
}
*/


// answer from others
int RomanDigit(char* roman,int digit,char a,char b,char c){
    switch(digit){
        case 1:roman[0]=a;return 1;
        case 2:roman[0]=a;roman[1]=a;return 2;
        case 3:roman[0]=a;roman[1]=a;roman[2]=a;return 3;
        case 4:roman[0]=a;roman[1]=b;return 2;
        case 5:roman[0]=b;return 1;
        case 6:roman[0]=b;roman[1]=a;return 2;
        case 7:roman[0]=b;roman[1]=a;roman[2]=a;return 3;
        case 8:roman[0]=b;roman[1]=a;roman[2]=a;roman[3]=a;return 4;
        case 9:roman[0]=a;roman[1]=c;return 2;
    }
    return 0;
}

char* intToRoman(int num) {
    //char digit[9][5]={I,II,III,IV,V,VI,VII,VIII,IX};
    //char tensdig[9][5]={X,XX,XXX,XL,L,LX,LXX,LXXX,XC};
    //char hunsdig[9][5]={C,CC,CCC,CD,D,DC,DCC,DCCC,CM};
    //char thodig[3][3]={M,MM,MMM};
    char* roman = (char*)malloc(sizeof(char) * 16);
    int index = 0;
    if(num / 1000 != 0){
        index += RomanDigit(roman+index,num/1000,'M','#','#');
        num %= 1000;
    }
    if(num / 100 != 0){
        index += RomanDigit(roman + index,num / 100,'C','D','M');
        num %= 100;
    }
    if(num / 10 != 0){
        index += RomanDigit(roman + index,num / 10,'X','L','C');
        num %= 10;
    }
    if(num != 0){
        index += RomanDigit(roman + index,num,'I','V','X');
    }
    roman[index]=0;
    return roman;
}


