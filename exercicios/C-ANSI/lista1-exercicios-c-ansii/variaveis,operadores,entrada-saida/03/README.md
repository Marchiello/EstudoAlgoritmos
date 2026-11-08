**Enunciado:** Leia uma temperatura em Celsius e converta para Fahrenheit e Kelvin.

* Código:

````c

#include <stdio.h>

int main()
{
    double temperatura;

    puts("Insira uma temperatura em graus Celsius");
    scanf("%lf", &temperatura);

    printf("%.2f em graus Celsius equivale a %.2f graus Fahrenheit e %.2f graus Kelvin\n", temperatura, (temperatura*1.8)+32, temperatura+273.15);

    return 0;
}

````

1º: Importo a biblioteca `<stdio.h>`, *Standard Input Output ou Padrão de Entrada e Saída*, para utilizar as funções de entrada e saída do C.

2º: Crio a função `int main()` para que ela siga o padrão de retornar o valor `0` para o sistema operacional caso tudo ocorra sem erros.

3º: Declaro o variável `temperatura` do tipo `double`.

4º: Chamo a função `puts()`, de **put string** para "printar" uma mensagem informando que o usuário deve inserir uma temperatura em graus Celsius.

5º: Chamo a função `scanf()` para permitir com que o usuário insira a temperatura. Uso o especificador de formato `%lf` de **long float**, um alias para `double`. Além disso, uso o operador de endereço de memória `&temperatura` para armazenar o valor inserido pelo usuário na variável `temperatura`.

6º: Chamo a função `printf()` para "imprimir" a mensagem para o usuário, usando o especificador de formato `%.2f` para imprimir um valor `float` com 2 casas decimais. Além disso, especifico quais variáveis devem ser imprimidas respectivamente, usando as fórmulas de conversão `(temperatura*1.8)+32` para Fahrenheit e `temperatura+273.15` para Kelvin.

---

**Observações:**

- De inicio, tentei executar o seguinte bloco de código:

````c

double temperatura = scanf("%lf");

````

Esse trecho de código, ao inserir o valor `10` durante a execução do código, me retornava o valor `1`.

Isso ocorre pois a função `scanf()` retorna o número de itens lidos com sucesso. Como o trecho de código esperava que o usuário entrasse com um valor `double` válido e foi isso que eu fiz, ele retornou `1`.

---

Portanto, se o código esperar `n` entradas dento da função `scanf()`, caso todas entradas sejam válidas, ele retornará o valor `n`.

- Ex:

````c

// Código:

[...]

double base, altura;

puts("Separando os valores com um espaço, insira um valor referente a base e um valor referente a altura de um retangulo:");

int entradasValidas = scanf("%lf %lf", &base, &altura);

printf("Numero de entradas validas:\n%d", entradasValidas);

[...]


````

````
Terminal:


Separando os valores com um espaço, insira um valor referente a base e um valor referente a altura de um retangulo:

50, 40

Numero de entradas validas:
2

````

- Esse retorno da função `scanf()` é comumente usada pra verificar se todos valores pedidos foram inseridos corretamente e, assim, fazer algum tratamento de erro.

````c

double temperatura;

int resultado = scanf("%lf", &temperatura);

if (resultado == 1){
    puts("Entrada válida");
}else{
    puts("O usuário inseriu um valor inválido")
}

````