#include <stdio.h>
int main () {

    double A[5]= {1,2,3,4,5};

    for (size_t i = 0; i < 5; ++i) {
        if(i) {
            printf("element %zu is %g, \tits square is %g\n",
            i,
            A[i],
            A[i] * A[i]);
        }
    }

    return 0;
}
