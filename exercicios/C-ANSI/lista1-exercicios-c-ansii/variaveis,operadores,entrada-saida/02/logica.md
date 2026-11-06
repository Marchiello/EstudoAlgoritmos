**Enunciado:** Leia a base e a altura de um retângulo (`double`) e mostre a área e o perímetro com 2 casas decimais.

* Código:

````c

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

````

1º: Importo a biblioteca `<stdio.h>`, de *Standard Input Output*, *Padrão de Entrada e Saída*, para usar funções como `printf()`, `puts()` e `scanf()`.

2º: Crio a função `main()`, função essa que é sempre executada independente de ser chamada ou não, informando que ela retornará um valor inteiro.
* Isso segue o padrão onde o programa retorna o valor `0` pro sistema operacional, valor padrão esse que informa que o programa foi executado sem nenhum erro ou problema.

3º: Declaro as variaveis `base` e `altura` na mesma linha, aproveitando o fato de que ambas são do mesmo tipo(`double`).

4º: Chamo a função `puts()` de **put string** pra informar que o usuário deve inserir um valor para a base do retangulo.

5º: Chamo a função `scanf()` para permitir com que o usuário insira um valor no programa. 
- Uso o *especificador de formato(ou mascara de leitura)* `%lf` de **long float**(alias pra `double`) para informar que o usuário irá inserir um valor do tipo `double`.

- Uso o operador de endereço de memória `&base` para informar ao `scanf()` que o valor inserido pelo usuário deverá ser salvo no endereço de memória utilizado pela variável `base`.

6º: Repito os passos `4º`e `5º` adaptados pra manipular o valor da altura do retangulo.

7º: Chamo a função `printf()`, ja que a mensagem exibida necessita de formatação, e exibo a mensagem informando o valor do perímetro do retangulo com as dimensões inseridas pelo usuário.
* Ao especificar a string que deve ser exibida pro usuário, uso, ao final, o especificador de formato `%2.f` pra informar que **o valor que será inserido nessa parte será um float com 2 casas decimais**, isso antes de utilizar o `\n` para quebrar a linha.

* Utilizo a fórmula `2*(base+altura) para calculo do perímetro. Anteriormente eu havia criado uma variavel própria pra armazenar o valor desse calculo, mas buscando uma solução mais elegante, achei a solução que empreguei no código.

---

**Sugestão:**

Durante a busca por uma solução mais eficiente, descobri que eu poderia usar a função `scanf()` da seguinte forma:

````c

puts("Insira a base e a altura do retangulo (separadas por espaco):");
scanf("%lf %lf", &base, &altura);

````

Dessa forma, utilizaria o código da seguinte forma:

````

Insira a base e a altura do retangulo (separadas por espaco):
<valor_base> <valor_altura>

````

É uma solução mais enxuta, mas ainda assim preferi dedicar uma um `scanf()` pra cada variável pra ficar mais didático e compreensível. Pretendo usar a forma mais enxuta nos próximos exercicios.