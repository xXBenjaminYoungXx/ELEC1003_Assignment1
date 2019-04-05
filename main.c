/*
User: Benjamin Young
Student ID: c3330653
Email: BenjaminYoung7198@gmail.com
NOTE: The code has been editted on codeblocks and committed on github
-UPPERCASE should be only input, (ADV: turn all cases into uppercase if lower case detected.)
-
Method List:

TODO: Go over lecture notes on file transfere, and ASCII, otherwise use stdio to i/o
note if stdio is used loss of marks will occur
TODO: Use common comments and pseudo to structure program
TODO: Use functions to run respective menu options, and functions within those
to execute code required to encript/decript information.
TODO: Talk with peers to exchange ideas with how to approach problem
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
    int a, b, c;
    FILE *Output;
    FILE *Input;
    Output = fopen("Output", "w");
    Input = fopen("Input", "r");
    fscanf(Input, "%d %d %d", &a ,&b, &c);
    fprintf(Output, "%d %d %d", a ,b ,c);
    fclose(Output);
    fclose(Input);
    return 0;
}


