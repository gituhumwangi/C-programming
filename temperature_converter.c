#include <stdio.h>
/*This program converts fahrenheit to celsius. From 0 celsius to 300*/

int main(){
    float celsius, fahrenheit;
    int lower, upper, step;

    lower=0;
    upper=300;
    step=20;

    fahrenheit = lower;
    printf("%10s %10s\n", "Fahrenheit", "Celsius");

    printf("-----------------------\n");

    while(fahrenheit <= upper){
        celsius = (5.0 / 9.0) * (fahrenheit - 32.0);
        printf("%10.1f %10.1f\n", fahrenheit, celsius);
        fahrenheit = fahrenheit + step;
    }
}

/*Convert celsius to fahrenheit. From 0 degrees celsius to 300 degrees celsius*/

#include <stdio.h>

int main(){
    float celsius, fahrenheit;
    float lower, upper, step;

    lower = 0 ;
    upper = 300;
    step = 20;
    celsius = lower;
     
    printf("10%s 10%s\n", "Celsius", "Fahrenheit");
    printf("_______________________\n");

    while(celsius <= upper){
        fahrenheit = (9.0/5.0) * (celsius - 32.0);
        printf("%10.1f %10.1f\n", celsius, fahrenheit);
        celsius = celsius +step;
    }

}