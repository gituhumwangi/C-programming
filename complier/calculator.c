#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Global lookahead character
char lookahead;

// Function prototypes
void match(char expected);
int expr();
int term();
int factor();

void error(const char* msg) {
    printf("Error: %s\n", msg);
    exit(1);
}

// Get the next character
void nextChar() {
    lookahead = getchar();
}

// Match the current character
void match(char expected) {
    if (lookahead == expected)
        nextChar();
    else
        error("Unexpected character");
}

// expr -> term { '+' term }
int expr() {
    int value = term();
    while (lookahead == '+') {
        match('+');
        value += term();
    }
    return value;
}

// term -> factor { '*' factor }
int term() {
    int value = factor();
    while (lookahead == '*') {
        match('*');
        value *= factor();
    }
    return value;
}

// factor -> digit
int factor() {
    int value;
    if (isdigit(lookahead)) {
        value = lookahead - '0';  // Convert char to int
        match(lookahead);
    } else {
        error("Expected a digit");
    }
    return value;
}

int main() {
    printf("Enter an expression (digits with + and * operators): ");
    nextChar();  // Initialize lookahead

    int result = expr();

    if (lookahead != '\n') {
        error("Unexpected input after valid expression");
    }

    printf("Result = %d\n", result);

    return 0;
}
