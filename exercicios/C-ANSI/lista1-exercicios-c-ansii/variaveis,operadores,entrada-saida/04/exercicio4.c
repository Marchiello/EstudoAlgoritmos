#include <stdio.h>

int main()
{
    int valor1, valor2;

    puts("Insira dois valores separados por um espaço para verificar seus respectivos calculos:");
    scanf("%d %d", &valor1, &valor2);

    printf("%d + %d = %d\n", valor1, valor2, valor1+valor2);
    printf("%d - %d = %d\n", valor1, valor2, valor1-valor2);
    printf("%d x %d = %d\n", valor1, valor2, valor1*valor2);
    printf("%d / %d = %d\n", valor1, valor2, valor1/valor2);
    printf("Resto da divisão = %d\n", valor1%valor2);

    return 0;
}