%{
#include "calc.tab.h"  // Make sure this is inside %{ %} before %%
#include <stdlib.h>
%}

%%

[0-9]+      { yylval = atoi(yytext); return NUMBER; }
[+\n-]      { return yytext[0]; }
[ \t]       { /* skip whitespace */ }
.           { printf("Unknown character: %s\n", yytext); }

%%

int yywrap() { return 1; }
