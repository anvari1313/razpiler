#include "pp.h"
#include <wchar.h>

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
        case L'ن':
            result = 'c';
            break;
        case L'و':
            result = 'd';
            break;
        case L'ه':
            result = 'e';
            break;
        case L'ی':
            result = 'f';
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
            result = ' ';
    }

    return result;
}
