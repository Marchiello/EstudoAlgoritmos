**Enunciado:** Escreva um programa que imprima seu nome e sua cidade em duas linhas

- Código:

 ````c
#include <stdio.h>

int main()
{
    printf("< Meu Nome >\n< Minha cidade >");
    return 0;
}
````

1º: Importo  o `<stdio.h>`, biblioteca responsável pela entrada e saída de valores. Seu nome vem de `standard input output`, biblioteca padrão de entrada e saída.

2ª: Crio a função `main()`(função que o código sempre executa independente de ser chamada ou não) informando que ela irá retornar um valor inteiro(por isso `int main()`)

    - Essa prática se da pois o código retorna `0` pro sistema operacional. O valor zero indica que tudo ocorreu bem.

3º: Uso a função `printf()` pra imprimir ambos valores(Meu nome e minha cidade).
- Uso o `\n` para *quebrar a linha* e usar um único `printf()` para imprimir dois valores em linhas diferentes.

---

**Sugestão:**
Descobri que existe uma função adequada pra imprimir valores simples, sem mistura de texto, formatação e coisas do tipo. A função `puts()`, de **put string**.
- Essa função quebra linha automaticamente sempre que é chamada, como se tivesse um `\n` presente no final da string imprimida. Isso não acontece com o `printf()`, onde você precisaria inserir o `\n`.

* **Detalhe importante**: A função `puts()` só aceita entradas *string*. Portanto, inserir valores ou variáveis de outros tipos vai retornar um erro.