#include <stdio.h>

int main()
{
    double base, altura;

    puts("Insira um valor pra base do retangulo:");
    scanf("%lf", &base);

    puts("Agora, insira um valor para a altura do retangulo:");
    scanf("%lf", &altura);

    printf("O perimetro do retangulo e sua area respectivamente, com as dimensões inseridas, é de %.2f e %.2f \n", 2*(base+altura), 2*(base*altura));

    return 0;
}