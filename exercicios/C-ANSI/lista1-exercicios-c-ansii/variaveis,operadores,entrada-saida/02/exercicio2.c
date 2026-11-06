#include <stdio.h>

int main()
{
    double base, altura;

    puts("Insira um valor pra base do retangulo:");
    scanf("%lf", &base);

    puts("Agora, insira um valor para a altura do retangulo:");
    scanf("%lf", &altura);

    printf("O perimetro do retangulo com as dimensões inseridas é de %.2f\n", 2*(base+altura));

    return 0;
}