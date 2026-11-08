**Enunciado:** Leia dois inteiros e mostre soma, diferença, produto, quociente inteiro e resto da divisão.

* Código:

````c

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

````

1º: Importo a biblioteca Padrão de Entrada e Saída.

2º: Crio a função `main()` como `int` pra seguir o padrão de retornar o valor `0` quando todo o código é executado sem erros.

3º: Declaro as variáveis `valor1` e `valor2` numa mesma linha pois ambas são do tipo `int`.

4º: Uso a função `puts()`(*put string*) pra informar o que o usuário deve fazer.

5º: Chamo a função `scanf()` para que o usuário insira os valores solicitados pelo programa.

* Utilizo duas vezes o especificador de formato `%d` de **decimal** pra informar ao código que eu espero uma entrada do tipo `int` pois ele é o especificador referente ao tipo `int`. Mais a frente explico o motivo de não ter usado o especificador de formato `%i` de **inteiro**, por mais que o mesmo exista e funcione perfeitamente nesse contexto.

* Como informei à função que eu esperava a entrada de dois valores inteiros, especifiquei, utilizando o operador de endereço de memória, que esses dois valores deveriam ser salvos nos endereços de memória das variáveis declaradas. Se esse papo de "endereço de memória" ficou meio confuso, posteriormente vou explicar um pouco sobre ponteiros dentro de `exercicios/C-ANSI/conceitos/`.

6º: Criei um `printf()` para cada operação matemática, onde eu exibia qual operação estava sendo feita e qual era o resultado.
* Eu poderia ter declarado variáveis para armazenar os resultados das operações e, assim, tornar o código mais legível. Mas *por que decidi realizar os calculos diretamente dentro do `printf()`?*
    - Criar variáveis ocupa um espaço na memória RAM, geralmente insignificante, ainda mais pra valores inteiros, mas ocupam. Realizando o calculo diretamente no `printf()`, o computador da o resultado e não precisa armazenar nada. É uma decisão técnica boba pra essa situação, mas tamo ai.

---

**Observações:**

O especificador de formato `%d` de **decimal**, que é utilizado para especificar valores do tipo `int` foi criado para aceitar apenas valores na **base decimal**, ou seja, **de base 10**.

O especificador de formato `%i` de **integer**(*inteiro*) aceita valores decimais, mas também aceita valorese em **octal** (se começar com zero, ex: 012) , ou um número **hexadecimal** (se começar com 0x, ex: 0x1A).

Questionei isso pra IA e ela me explicou que durante a criação das regras de formatação de entrada e saída por **Dennis Ritchie**(*Criador da linguagem C*) e **Ken Thompson**(*Criador da linguagem B, antecessora da linguagem C*), eles decidiram que precisavam de uma letra que representasse a base numérica do dado, e não necessariamente o nome cientifico do dado. 

- Por conta disso, existe o especificador de formato `x` para **hexadecimal**, `f` para **float**(*decimal de precisão simples*), `lf`(*long float*) para **Double**(*decimal de precisão dupla*), entre outros.