*This project has been created as part of the 42 curriculum by rayperei.*

## Description

O projeto **ft_printf** consiste em uma implementação personalizada da função `printf()` da biblioteca padrão da linguagem C.

O principal objetivo deste projeto é aprofundar os conhecimentos sobre:

* Funções variádicas;
* Manipulação de argumentos utilizando `<stdarg.h>`;
* Conversão entre bases numéricas;
* Recursividade;
* Organização modular de código;
* Desenvolvimento de bibliotecas estáticas;
* Gerenciamento eficiente de memória;
* Escrita de código seguindo normas rígidas de estilo e arquitetura.

Além disso, o projeto busca reproduzir com máxima fidelidade o comportamento da implementação original da libc, respeitando o valor de retorno e o tratamento de casos especiais.

### Objetivos de Aprendizagem

* utilização de funções variádicas através de `va_list`;
* entendimento do funcionamento interno do `printf`;
* manipulação de ponteiros;
* impressão de números em diferentes bases;
* implementação de algoritmos recursivos;
* separação de responsabilidades entre módulos;
* construção de bibliotecas estáticas utilizando `ar`;
* automação de compilação com `Makefile`.

### Especificadores Suportados

| Especificador | Descrição                                   |
| ------------- | ------------------------------------------- |
| `%c`          | Imprime um único caractere                  |
| `%s`          | Imprime uma string                          |
| `%p`          | Imprime um ponteiro em hexadecimal          |
| `%d`          | Imprime um número decimal com sinal         |
| `%i`          | Imprime um inteiro decimal                  |
| `%u`          | Imprime um inteiro sem sinal                |
| `%x`          | Imprime um hexadecimal em letras minúsculas |
| `%X`          | Imprime um hexadecimal em letras maiúsculas |
| `%%`          | Imprime o caractere `%`                     |

### Estrutura do Projeto

```text
ft_printf/
│
├── ft_printf.c
├── ft_printf_utils.c
├── ft_printf_hex.c
├── ft_printf.h
├── Makefile
└── main.c
```

* **ft_printf.c** — implementação principal da função `ft_printf()`, a função despachante `ft_check_flag()` e a implementação personalizada de `ft_strchr()`.
* **ft_printf_utils.c** — impressão de caracteres, strings, inteiros com e sem sinal, e contagem dos caracteres escritos.
* **ft_printf_hex.c** — impressão hexadecimal, impressão de endereços de memória e conversões entre bases.
* **ft_printf.h** — protótipos das funções, bibliotecas necessárias e definições utilizadas pelo projeto.
* **main.c** — arquivo de teste pessoal, não faz parte da biblioteca entregável (não está listado no `SRCS` do Makefile).

---

## Instructions

### Compilação

```bash
make
```

Isso gera a biblioteca estática `libftprintf.a` na raiz do repositório.

### Uso

Compilando junto com um arquivo de teste próprio:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test_printf
./test_printf
```

Ou linkando pela lib instalada localmente:

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test_printf
./test_printf
```

### Limpeza

```bash
make clean   # remove os arquivos .o
make fclean  # remove .o e a biblioteca final
make re      # limpa tudo e recompila do zero
```

---

## Resources

Referências consultadas durante o desenvolvimento:

* [man 3 printf](https://man7.org/linux/man-pages/man3/printf.3.html) — comportamento de referência de cada especificador e do valor de retorno.
* [cppreference — Variadic functions](https://en.cppreference.com/w/c/variadic) — documentação de `va_start`, `va_arg`, `va_end`.
* [man 2 write](https://man7.org/linux/man-pages/man2/write.2.html) — syscall usada para toda a saída do projeto.
* Subject oficial do projeto `ft_printf` (42 School intranet).

### Uso de Inteligência Artificial

Ferramentas de IA foram utilizadas apenas em atividades de apoio:

* revisão e organização textual dos comentários do código;
* organização e formatação deste README;
* simulação de perguntas de banca para preparação da defesa oral.

A implementação das funções obrigatórias, a definição da arquitetura (separação em `ft_printf.c`, `ft_printf_utils.c`, `ft_printf_hex.c`) e a resolução dos desafios centrais (recursão para conversão numérica, tratamento de casos especiais como `NULL` e `INT_MIN`) foram feitas de forma independente, sem uso de IA.

---

## Arquitetura e Decisões Técnicas

A arquitetura foi projetada visando simplicidade, baixo consumo de memória, facilidade de manutenção e conformidade total com a Norm da 42.

### Gerenciamento de Argumentos Variádicos

O projeto utiliza as macros de `<stdarg.h>` (`va_start`, `va_arg`, `va_end`) para percorrer dinamicamente a lista de argumentos recebidos pela função `ft_printf`. O fluxo funciona assim:

1. A string de formatação é percorrida caractere por caractere.
2. Quando um `%` é encontrado, o próximo caractere é interpretado como especificador.
3. Uma função despachante (`ft_check_flag`) identifica o tipo solicitado.
4. O argumento correspondente é extraído da lista variádica.
5. A função responsável realiza a impressão e retorna a quantidade de caracteres escritos.

### Por que Recursão para Conversão Numérica

As funções `ft_putnbr_count`, `ft_putunsigned_count`, `ft_puthex_count` e `ft_putptr_recursive` usam recursão para percorrer os dígitos do número do mais significativo para o menos significativo.

**Exemplo — imprimir 12345:**

```text
12345 → 1234 → 123 → 12 → 1   (chamadas recursivas "descendo")
1 → 2 → 3 → 4 → 5              (impressão durante o retorno)
```

**Benefícios dessa abordagem:**

* elimina a necessidade de vetores/buffers temporários;
* evita alocações com `malloc()`, reduzindo o risco de vazamentos de memória a zero;
* simplifica a implementação;
* resolve naturalmente a ordem de impressão dos dígitos sem precisar inverter nada manualmente.

### Controle Preciso do Retorno

Assim como a implementação original da libc, todas as funções retornam exatamente a quantidade de caracteres escritos. Cada função auxiliar acumula sua própria contagem (`count +=`) e propaga o resultado para a função principal, que soma tudo e retorna o total.

---

## Conclusão

O projeto **ft_printf** implementa uma versão fiel das conversões obrigatórias do `printf` original da libc, utilizando recursão para eliminar a necessidade de alocação dinâmica e uma arquitetura modular que separa claramente o fluxo de parsing, o despacho de especificadores e as funções de impressão de baixo nível.

---

## Autor

**Rayane Pereira Silva Morais**
**Login 42:** `rayperei`
