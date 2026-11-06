# Guia de estudo de C (ANSI C89)

Referência rápida em ANSI C (C89/C90): comandos, palavras reservadas, tópicos e bibliotecas.

## Índice

1. [Estrutura de um programa](#estrutura-de-um-programa)
2. [Tipos de dados](#tipos-de-dados)
3. [Palavras reservadas](#palavras-reservadas-32-no-c89)
4. [Operadores](#operadores)
5. [Controle de fluxo](#controle-de-fluxo)
6. [Funções](#funções)
7. [Arrays e strings](#arrays-e-strings)
8. [Ponteiros](#ponteiros)
9. [struct, union, enum e typedef](#struct-union-enum-e-typedef)
10. [Memória dinâmica](#memória-dinâmica)
11. [Entrada e saída](#entrada-e-saída)
12. [Bibliotecas padrão](#bibliotecas-padrão-do-ansi-c)
13. [Pré-processador](#pré-processador)
14. [Compilar e depurar](#compilar-e-depurar)
15. [Erros comuns de iniciante](#erros-comuns-de-iniciante)
16. [Roteiro de estudo](#roteiro-de-estudo-sugerido)

---

## Estrutura de um programa

Todo programa começa na função `main`. No C89, as variáveis são declaradas no início do bloco, e comentários usam `/* */`.

```c
#include <stdio.h>

int main(void)
{
    int idade;                       /* declarações primeiro */

    printf("Qual sua idade? ");
    scanf("%d", &idade);
    printf("Voce tem %d anos.\n", idade);

    return 0;                        /* 0 = sucesso */
}
```

## Tipos de dados

| Tipo | Uso | printf |
|---|---|---|
| `char` | Um caractere (ou inteiro de 1 byte) | `%c` / `%d` |
| `short`, `int`, `long` | Inteiros de tamanhos crescentes | `%hd`, `%d`, `%ld` |
| `unsigned` | Inteiro sem sinal (só positivos) | `%u`, `%lu` |
| `float` | Real, precisão simples | `%f` |
| `double` | Real, precisão dupla (o padrão para reais) | `%f` (saída), `%lf` (scanf) |
| `void` | Sem valor (funções sem retorno, `void *`) | - |

Os tamanhos dependem da máquina. Use `sizeof(tipo)` para descobrir e consulte `<limits.h>` e `<float.h>` para os limites. O C89 não tem `bool`: use `int` com 0 (falso) e qualquer outro valor (verdadeiro).

Modificadores: `const` (não pode mudar), `static` (vive durante todo o programa), `volatile`, `register`, `extern`.

## Palavras reservadas (32 no C89)

**Tipos e modificadores**

`char` `short` `int` `long` `float` `double` `void` `signed` `unsigned` `const` `volatile` `static` `extern` `register` `auto`

**Estruturas de dados**

`struct` `union` `enum` `typedef` `sizeof`

**Controle de fluxo**

`if` `else` `switch` `case` `default` `for` `while` `do` `break` `continue` `goto` `return`

Palavras novas em padrões posteriores (não existem no ANSI C): `inline`, `restrict`, `_Bool` (C99); `_Generic`, `_Static_assert`, `_Atomic` (C11).

## Operadores

| Categoria | Operadores |
|---|---|
| Aritméticos | `+ - * / %` (o `%` só funciona com inteiros) |
| Incremento | `++ --` (prefixo muda antes de usar; sufixo, depois) |
| Relacionais | `== != < > <= >=` |
| Lógicos | `&& \|\| !` (avaliação em curto-circuito) |
| Bit a bit | `& \| ^ ~ << >>` |
| Atribuição | `= += -= *= /= %= &= \|= ^= <<= >>=` |
| Ponteiros e acesso | `&` (endereço), `*` (conteúdo), `.`, `->`, `[]` |
| Outros | `?:` (ternário), `,` (vírgula), `sizeof`, `(tipo)` (cast) |

Cuidado clássico: `=` atribui, `==` compara. Divisão entre dois inteiros descarta a parte decimal (`7 / 2` vale `3`).

## Controle de fluxo

### if / else if / else

```c
if (nota >= 7)       printf("Aprovado\n");
else if (nota >= 5)  printf("Recuperacao\n");
else                 printf("Reprovado\n");
```

### switch

```c
switch (opcao) {
    case 1:  printf("Um\n");  break;   /* sem break, cai no próximo case */
    case 2:  printf("Dois\n"); break;
    default: printf("Outro\n");
}
```

### for, while, do-while

```c
int i;
for (i = 0; i < 10; i++)  printf("%d ", i);

while (i > 0)  i--;           /* testa antes */

do { i++; } while (i < 5);    /* executa ao menos uma vez */
```

`break` sai do laço, `continue` pula para a próxima volta, `goto` existe mas quase nunca vale a pena.

## Funções

Declare o protótipo antes de usar. Em C, parâmetros são passados **por valor**: para alterar a variável original, passe um ponteiro.

```c
int soma(int a, int b);            /* protótipo */

void troca(int *x, int *y)         /* altera os originais */
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int fatorial(int n)                /* recursão */
{
    if (n <= 1) return 1;
    return n * fatorial(n - 1);
}

/* uso: troca(&a, &b); */
```

## Arrays e strings

```c
int v[5] = {1, 2, 3, 4, 5};       /* índices de 0 a 4 */
int m[3][3];                       /* matriz */

char nome[20] = "Ana";             /* string = char[] terminado em '\0' */
char *p = "texto";                 /* literal: não modifique */
```

C não verifica limites: acessar `v[5]` acima é comportamento indefinido. Um array passado para função vira ponteiro, então envie também o tamanho.

### Funções de `<string.h>`

| Função | O que faz |
|---|---|
| `strlen(s)` | Tamanho (sem o `'\0'`) |
| `strcpy(d, s)` / `strncpy` | Copia a string |
| `strcat(d, s)` / `strncat` | Concatena |
| `strcmp(a, b)` | Compara: 0 se iguais, negativo ou positivo caso contrário |
| `strchr`, `strstr` | Busca caractere ou substring |
| `memcpy`, `memset`, `memcmp` | Operam em blocos de bytes |

## Ponteiros

Um ponteiro guarda o **endereço** de outra variável. É o tópico central do C.

```c
int x = 10;
int *p = &x;          /* p aponta para x */
*p = 20;              /* x agora vale 20 */

int v[3] = {1, 2, 3};
int *q = v;           /* nome do array = endereço do 1o elemento */
printf("%d", *(q + 1)); /* 2, igual a v[1] */

int *nulo = NULL;     /* sempre inicialize; nunca desreferencie NULL */
```

Aritmética de ponteiros soma em unidades do tipo apontado. Também existem ponteiros para ponteiros (`int **`) e ponteiros para função (`int (*f)(int)`).

## struct, union, enum e typedef

```c
struct Aluno {
    char nome[30];
    int  idade;
    float nota;
};

struct Aluno a = {"Beto", 20, 8.5f};
struct Aluno *pa = &a;
printf("%s %d\n", a.nome, pa->idade);   /* . direto, -> via ponteiro */

typedef struct Aluno Aluno;             /* agora basta "Aluno" */

enum Cor { VERMELHO, VERDE, AZUL };     /* 0, 1, 2 */

union Valor { int i; float f; };        /* membros dividem a mesma memória */
```

## Memória dinâmica

Funções de `<stdlib.h>`. Tudo que você aloca, você precisa liberar.

```c
int *v = (int *) malloc(10 * sizeof(int));
if (v == NULL) { /* falhou: trate o erro */ }

v = (int *) realloc(v, 20 * sizeof(int));   /* redimensiona */

free(v);        /* libera */
v = NULL;       /* evita uso após free */
```

`calloc(n, tam)` aloca já zerado. Ferramenta para achar vazamentos: `valgrind ./programa` (Linux) ou `-fsanitize=address` no GCC.

## Entrada e saída

| Função | Uso |
|---|---|
| `printf` | Saída formatada no terminal |
| `scanf` | Entrada formatada (passe o endereço: `&x`) |
| `fgets(buf, tam, stdin)` | Lê uma linha com segurança. Prefira a `gets`, que é perigosa e foi removida do padrão |
| `getchar` / `putchar` | Um caractere por vez |
| `fopen`, `fclose` | Abre e fecha arquivos (`"r"`, `"w"`, `"a"`, `"rb"`, `"wb"`) |
| `fprintf`, `fscanf`, `fgets`, `fputs` | Texto em arquivos |
| `fread`, `fwrite`, `fseek`, `ftell`, `rewind` | Arquivos binários e posicionamento |

### Formatos mais usados

| Código | Tipo | Código | Tipo |
|---|---|---|---|
| `%d` | int | `%c` | char |
| `%u` | unsigned | `%s` | string |
| `%ld` | long | `%p` | ponteiro |
| `%f` | float/double | `%x` | hexadecimal |
| `%.2f` | 2 casas decimais | `%5d` | largura mínima 5 |

```c
FILE *f = fopen("dados.txt", "r");
if (f == NULL) { perror("fopen"); return 1; }
/* ... usa o arquivo ... */
fclose(f);
```

## Bibliotecas padrão do ANSI C

| Header | Para que serve | Destaques |
|---|---|---|
| `stdio.h` | Entrada e saída | `printf scanf fgets fopen fclose` |
| `stdlib.h` | Utilidades gerais | `malloc free atoi strtol rand srand exit qsort abs` |
| `string.h` | Strings e blocos de memória | `strlen strcpy strcmp memcpy memset` |
| `math.h` | Matemática (compile com `-lm`) | `sqrt pow sin cos fabs floor ceil log exp` |
| `ctype.h` | Classificar caracteres | `isdigit isalpha isspace toupper tolower` |
| `time.h` | Data e hora | `time clock difftime strftime` |
| `limits.h`, `float.h` | Limites dos tipos | `INT_MAX INT_MIN CHAR_BIT DBL_EPSILON` |
| `assert.h` | Verificações em tempo de execução | `assert(cond)` |
| `stddef.h` | Definições comuns | `NULL size_t offsetof` |
| `stdarg.h` | Funções com argumentos variáveis | `va_list va_start va_arg va_end` |
| `errno.h` | Códigos de erro | `errno` |
| `setjmp.h`, `signal.h`, `locale.h` | Saltos, sinais e idioma | Usos avançados |

Fora do padrão ANSI, mas muito úteis depois: `stdint.h` e `stdbool.h` (C99), `pthread.h` (threads no POSIX), `unistd.h` e `sys/socket.h` (sistema e rede, Linux).

## Pré-processador

```c
#include <stdio.h>           /* headers do sistema */
#include "meu.h"             /* seus próprios headers */

#define PI 3.14159           /* constante */
#define QUAD(x) ((x) * (x))  /* macro: use parênteses em tudo */

#ifndef MEU_H                /* include guard: evita duplicar o header */
#define MEU_H
/* declarações aqui */
#endif
```

Outros: `#if`, `#ifdef`, `#else`, `#undef`, `#error`. Macros predefinidas: `__FILE__`, `__LINE__`, `__DATE__`, `__STDC__`.

## Compilar e depurar

```bash
gcc -ansi -pedantic -Wall -Wextra prog.c -o prog      # ANSI C com avisos
gcc -ansi -pedantic -Wall prog.c -o prog -lm           # com math.h
gcc -g prog.c -o prog                                  # símbolos de depuração
gcc -std=c11 -Wall -Wextra prog.c -o prog              # C moderno

gdb ./prog          # break main | run | next | step | print x | quit
valgrind ./prog     # vazamentos e acessos inválidos
```

Projetos com vários arquivos: compile cada `.c` para `.o` (`gcc -c`), una com o linker, e automatize com `make`.

## Erros comuns de iniciante

- Usar `=` no lugar de `==` dentro do `if`.
- Esquecer o `&` no `scanf` (exceto em strings).
- Estourar o limite do array, ou esquecer espaço para o `'\0'` da string.
- Comparar strings com `==`: use `strcmp`.
- Usar variável sem inicializar: o valor é lixo.
- Esquecer o `break` no `switch`.
- Ponto e vírgula depois do `if` ou `for`, que deixa o bloco sem efeito.
- Esquecer o `free`, ou usar o ponteiro depois dele.
- Devolver o endereço de uma variável local da função.
- Dividir inteiros esperando resultado decimal.

## Roteiro de estudo sugerido

1. Variáveis, tipos, operadores e `printf`/`scanf`.
2. Condicionais e laços (faça exercícios de tabuada, primos, Fibonacci).
3. Funções e recursão.
4. Arrays, matrizes e strings.
5. Ponteiros (reserve bastante tempo aqui e use o depurador).
6. `struct`, `enum`, `typedef`.
7. Memória dinâmica: listas encadeadas, pilhas e filas.
8. Arquivos e projetos com vários módulos.
9. Passar para C99/C11 e estudar bibliotecas do sistema.

Livro de referência: *The C Programming Language*, de Kernighan e Ritchie (2ª edição, escrita em ANSI C).
