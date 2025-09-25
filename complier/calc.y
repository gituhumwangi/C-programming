%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
int yyerror(char *s);
%}

%token NUMBER

%left '+' '-'

%%
lines:
      lines expr '\n'   { printf("= %d\n", $2); }
    | /* empty */
    ;

expr:
      expr '+' expr     { $$ = $1 + $3; }
    | expr '-' expr     { $$ = $1 - $3; }
    | NUMBER            { $$ = $1; }
    ;
%%

int main() {
    printf("Enter expressions (e.g., 10 + 20 - 5). Press Ctrl+D (or Ctrl+Z) to exit.\n");
    yyparse();
    return 0;
}

int yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 0;
}
