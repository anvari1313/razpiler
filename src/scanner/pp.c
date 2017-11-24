#include "pp.h"
#include <malloc.h>
#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <locale.h>

CharMapBSTNode *e2f_bst_root;
CharMapBSTNode *f2e_bst_root;

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

//wchar_t map_to_farsi(char c)
//{
//    wchar_t result;
//    switch (c)
//    {
//        case 'A':
//            result = L'آ';
//            break;
//        case L'ا':
//            result = 'B';
//            break;
//        case L'ب':
//            result = 'C';
//            break;
//        case L'پ':
//            result = 'D';
//            break;
//        case L'ت':
//            result = 'E';
//            break;
//        case L'ث':
//            result = 'F';
//            break;
//        case L'ج':
//            result = 'G';
//            break;
//        case L'چ':
//            result = 'H';
//            break;
//        case L'ح':
//            result = 'I';
//            break;
//        case L'خ':
//            result = 'J';
//            break;
//        case L'د':
//            result = 'K';
//            break;
//        case L'ذ':
//            result = 'L';
//            break;
//        case L'ر':
//            result = 'M';
//            break;
//        case L'ز':
//            result = 'N';
//            break;
//        case L'ژ':
//            result = 'O';
//            break;
//        case L'س':
//            result = 'P';
//            break;
//        case L'ش':
//            result = 'Q';
//            break;
//        case L'ص':
//            result = 'R';
//            break;
//        case L'ض':
//            result = 'S';
//            break;
//        case L'ط':
//            result = 'T';
//            break;
//        case L'ظ':
//            result = 'U';
//            break;
//        case L'ع':
//            result = 'V';
//            break;
//        case L'غ':
//            result = 'W';
//            break;
//        case L'ف':
//            result = 'X';
//            break;
//        case L'ق':
//            result = 'Y';
//            break;
//        case L'ک':
//            result = 'Z';
//            break;
//        case L'گ':
//            result = 'a';
//            break;
//        case L'ل':
//            result = 'b';
//            break;
//        case L'م':
//            result = 'c';
//            break;
//        case L'ن':
//            result = 'd';
//            break;
//        case L'و':
//            result = 'e';
//            break;
//        case L'ه':
//            result = 'f';
//            break;
//        case L'ی':
//            result = 'g';
//            break;
//        case L'۰':
//            result = '0';
//            break;
//        case L'۱':
//            result = '1';
//            break;
//        case L'۲':
//            result = '2';
//            break;
//        case L'۳':
//            result = '3';
//            break;
//        case L'۴':
//            result = '4';
//            break;
//        case L'۵':
//            result = '5';
//            break;
//        case L'۶':
//            result = '6';
//            break;
//        case L'۷':
//            result = '7';
//            break;
//        case L'۸':
//            result = '8';
//            break;
//        case L'۹':
//            result = '9';
//            break;
//        case L'،':
//            result = ',';
//            break;
//        case L'؛':
//            result = ';';
//            break;
//        default:
//            result = c;
//    }
//
//    return result;
//}

CharMapBSTNode *alloc_new_node()
{
    CharMapBSTNode *node = (CharMapBSTNode *)malloc(sizeof(CharMapBSTNode));
    node->left_child = NULL;
    node->right_child = NULL;

    return node;
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

// TODO complete this this function
void build_f2e_bst()
{
    f2e_bst_root = NULL;


    FILE *charset_file = fopen(FILE_PATH_F2E_CHARSET, "r");

    if (charset_file == NULL)
    {
        printf("file %s not found.\n", FILE_PATH_F2E_CHARSET);
        exit(-1);
    }

    wchar_t c;
    f2e_bst_root = alloc_new_node();


    f2e_bst_root->f_char = fgetwc(charset_file);    // Read the first farsi character in the file
    f2e_bst_root->e_char = (char)fgetc(charset_file);     // Read the first mapped character


    while ((c = fgetwc(charset_file)) != WEOF)
    {
        CharMapBSTNode *node = alloc_new_node();
        node->f_char = c;
        node->e_char = (char)fgetc(charset_file);

        // To add the new node to the bst
        CharMapBSTNode *current = f2e_bst_root;
        CharMapBSTNode *parent = NULL;
        while (current != NULL)
        {
            if (current->f_char - node->f_char > 0)
            {
                parent = current;
                current = current->left_child;
            }
            else if (current->f_char - node->f_char < 0)
            {
                parent = current;
                current = current->right_child;
            }
            else        // Two farsi characters are the same :|
            {
                wprintf(L"Error!!!!\n");
                exit(-1);
            }
        }

        if (parent->f_char - node->f_char > 0)
        {
            parent->left_child = node;
        }
        else /* if (parent->f_char - node->f_char > 0)*/
        {
            parent->right_child = node;
        }

    }



}

void build_e2f_bst()
{

}