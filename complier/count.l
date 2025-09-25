%{
#include "y.tab.h"
%}

%%
a   { return A; }
b   { return B; }
\n  { /* ignore newline */ }
.   { /* ignore other chars */ }
%%

int yywrap() {
    return 1;
}
