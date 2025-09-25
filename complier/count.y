%{
#include <stdio.h>

// Counter for number of 'a's
int count = 0;


int yylex(void);
int yyerror(char *s);
%}

%token A B

%%
S : A S  { count++; } 
  | B    
  ;
%%

int main() {
    printf("Enter the string (e.g., aaab): ");
    yyparse();
    printf("Number of a's: %d\n", count);
    return 0;
}

// Error handling function
int yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 0;
}
