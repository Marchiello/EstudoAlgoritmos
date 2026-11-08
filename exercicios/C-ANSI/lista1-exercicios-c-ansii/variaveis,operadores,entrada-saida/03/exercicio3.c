#include <stdio.h>

int main()
{
    double temperatura;

    puts("Insira uma temperatura em graus Celsius");
    scanf("%lf", &temperatura);

    printf("%.2f em graus Celsius equivale a %.2f graus Fahrenheit e %.2f graus Kelvin\n", temperatura, (temperatura*1.8)+32, temperatura+273.15);

    return 0;
}