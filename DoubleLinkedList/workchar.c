#include<stdio.h>
#include<stdlib.h>


void showInfor( char * str )
{
    printf("string : %s \n", str );
    printf("size if %s : %ld \n"  , str , sizeof(str) ) ;
    printf("under this line to show all elementles of %s :" , str );
    //for( int i = 0 ; i <=)
}

char* add(char* root, char* add) {
    // Calculate the lengths of both strings manually.
    int len1 = 0, len2 = 0;
    while (root[len1] != '\0') len1++;
    while (add[len2] != '\0') len2++;

    // Allocate memory for the concatenated string (+1 for the null terminator).
    char* result = malloc(len1 + len2 + 1);
    if (!result) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    // Copy characters from root into result.
    for (int i = 0; i < len1; i++) {
        result[i] = root[i];
    }

    // Append characters from add into result.
    for (int i = 0; i < len2; i++) {
        result[len1 + i] = add[i];
    }

    // Null-terminate the result.
    result[len1 + len2] = '\0';

    return result;
}


int main()
{
    char* str = "ntuanh" ;
    char* str_root = " user name " ;
    char * res = add(str , str_root);

    char str_2[] = "hotel ";

    printf("%s\n" , str_2 );
    printf("%s\n" , res );
    printf("Hello Woorld \n") ;

    return 0 ;
}