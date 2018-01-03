#include "pp.h"
#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <locale.h>


char map_to_english(wchar_t c)
{
    char result;
    switch (c)
    {
        case L'آ':
            result = 'A';
            break;
        case L'ا':
            result = 'B';
            break;
        case L'ب':
            result = 'C';
            break;
        case L'پ':
            result = 'D';
            break;
        case L'ت':
            result = 'E';
            break;
        case L'ث':
            result = 'F';
            break;
        case L'ج':
            result = 'G';
            break;
        case L'چ':
            result = 'H';
            break;
        case L'ح':
            result = 'I';
            break;
        case L'خ':
            result = 'J';
            break;
        case L'د':
            result = 'K';
            break;
        case L'ذ':
            result = 'L';
            break;
        case L'ر':
            result = 'M';
            break;
        case L'ز':
            result = 'N';
            break;
        case L'ژ':
            result = 'O';
            break;
        case L'س':
            result = 'P';
            break;
        case L'ش':
            result = 'Q';
            break;
        case L'ص':
            result = 'R';
            break;
        case L'ض':
            result = 'S';
            break;
        case L'ط':
            result = 'T';
            break;
        case L'ظ':
            result = 'U';
            break;
        case L'ع':
            result = 'V';
            break;
        case L'غ':
            result = 'W';
            break;
        case L'ف':
            result = 'X';
            break;
        case L'ق':
            result = 'Y';
            break;
        case L'ک':
            result = 'Z';
            break;
        case L'گ':
            result = 'a';
            break;
        case L'ل':
            result = 'b';
            break;
        case L'م':
            result = 'c';
            break;
        case L'ن':
            result = 'd';
            break;
        case L'و':
            result = 'e';
            break;
        case L'ه':
            result = 'f';
            break;
        case L'ی':
            result = 'g';
            break;
        case L'۰':
            result = '0';
            break;
        case L'۱':
            result = '1';
            break;
        case L'۲':
            result = '2';
            break;
        case L'۳':
            result = '3';
            break;
        case L'۴':
            result = '4';
            break;
        case L'۵':
            result = '5';
            break;
        case L'۶':
            result = '6';
            break;
        case L'۷':
            result = '7';
            break;
        case L'۸':
            result = '8';
            break;
        case L'۹':
            result = '9';
            break;
        case L'،':
            result = ',';
            break;
        case L'؛':
            result = ';';
            break;
        default:
            result = c;
    }

    return result;
}

wchar_t map_to_farsi(char c)
{
    wchar_t result;
    switch (c)
    {
        case 'A':
            result = L'آ';
            break;
        case 'B':
            result = L'B';
            break;
        case 'C':
            result = L'C';
            break;
        case L'D':
            result = L'D';
            break;
        case L'E':
            result = L'E';
            break;
        case L'F':
            result = L'F';
            break;
        case L'G':
            result = L'G';
            break;
        case L'H':
            result = L'H';
            break;
        case L'I':
            result = L'I';
            break;
        case L'J':
            result = L'J';
            break;
        case L'K':
            result = L'K';
            break;
        case L'L':
            result = L'L';
            break;
        case L'M':
            result = L'M';
            break;
        case L'N':
            result = L'N';
            break;
        case L'O':
            result = L'O';
            break;
        case L'P':
            result = L'P';
            break;
        case L'Q':
            result = L'Q';
            break;
        case L'R':
            result = L'R';
            break;
        case L'S':
            result = L'S';
            break;
        case L'T':
            result = L'T';
            break;
        case L'U':
            result = L'U';
            break;
        case L'V':
            result = L'V';
            break;
        case L'W':
            result = L'W';
            break;
        case L'X':
            result = L'X';
            break;
        case L'Y':
            result = L'Y';
            break;
        case L'Z':
            result = L'Z';
            break;
        case L'a':
            result = L'a';
            break;
        case L'b':
            result = L'b';
            break;
        case 'c':
            result = L'c';
            break;
        case 'd':
            result = L'd';
            break;
        case 'e':
            result = L'e';
            break;
        case 'f':
            result = L'f';
            break;
        case 'g':
            result = L'g';
            break;
        case '0':
            result = L'0';
            break;
        case '1':
            result = L'1';
            break;
        case L'2':
            result = L'2';
            break;
        case '3':
            result = L'3';
            break;
        case '4':
            result = L'4';
            break;
        case '5':
            result = L'5';
            break;
        case '6':
            result = L'6';
            break;
        case '7':
            result = L'7';
            break;
        case '8':
            result = L'8';
            break;
        case '9':
            result = L'9';
            break;
        case ',':
            result = L',';
            break;
        case ';':
            result = L';';
            break;
        default:
            result = c;
    }

    return result;
}


char *preprocess_line(FileLine *file_line)
{
    char *preprocessed_line = (char *)malloc(wcslen(file_line->line_content) * sizeof(char));
    size_t index = 0;
    char c;
    while(c = map_to_english(file_line->line_content[index]))
        preprocessed_line[index++] = c;
    return preprocessed_line;
}


void build_e2f_bst()
{

}