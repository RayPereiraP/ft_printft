# ft_printf

> Projeto desenvolvido como parte do currículo da Escola 42 por **rayperei**.

## 📖 Sobre o Projeto

O projeto **ft_printf** consiste em uma implementação personalizada da famosa função `printf()` da biblioteca padrão da linguagem C.

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

---

# 🎯 Objetivos de Aprendizagem

Durante o desenvolvimento deste projeto foram explorados diversos conceitos fundamentais da programação em C:

* utilização de funções variádicas através de `va_list`;
* entendimento do funcionamento interno do `printf`;
* manipulação de ponteiros;
* impressão de números em diferentes bases;
* implementação de algoritmos recursivos;
* separação de responsabilidades entre módulos;
* construção de bibliotecas estáticas utilizando `ar`;
* automação de compilação com `Makefile`.

Este projeto representa um dos primeiros contatos com abstrações mais avançadas da linguagem C e serve como base para projetos posteriores do currículo da 42.

---

# ⚙️ Especificadores Suportados

A implementação suporta os seguintes especificadores obrigatórios do projeto:

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

---

# 🧠 Arquitetura e Decisões Técnicas

A arquitetura foi projetada visando:

* simplicidade;
* baixo consumo de memória;
* facilidade de manutenção;
* escalabilidade para futuras expansões;
* conformidade total com a Norm da 42.

---

## 1. Gerenciamento de Argumentos Variádicos

O projeto utiliza as macros definidas em `<stdarg.h>`:

* `va_start()`
* `va_arg()`
* `va_end()`

Essas macros permitem percorrer dinamicamente a lista de argumentos recebidos pela função `ft_printf`.

O fluxo principal funciona da seguinte maneira:

1. A string de formatação é percorrida caractere por caractere.
2. Quando um `%` é encontrado, o próximo caractere é interpretado como um especificador.
3. Uma função despachante identifica o tipo solicitado.
4. O argumento correspondente é extraído da lista variádica.
5. A função responsável realiza a impressão e retorna a quantidade de caracteres escritos.

---

## 2. Conversão Numérica Utilizando Recursão

Uma das principais decisões técnicas do projeto foi utilizar recursão para a conversão de números em diferentes bases.

As funções:

* `ft_putnbr_count()`
* `ft_putunsigned_count()`
* `ft_puthex_count()`
* `ft_putptr_recursive()`

utilizam chamadas recursivas para percorrer os dígitos do número do mais significativo para o menos significativo.

### Exemplo de funcionamento

Para imprimir:

```text
12345
```

O algoritmo realiza internamente:

```text
12345
 └── 1234
      └── 123
           └── 12
                └── 1
```

Durante o retorno das chamadas recursivas ocorre a impressão:

```text
1 2 3 4 5
```

### Benefícios da abordagem recursiva

* elimina a necessidade de vetores temporários;
* evita alocações com `malloc()`;
* reduz o risco de vazamentos de memória;
* simplifica a implementação;
* mantém a complexidade espacial extremamente baixa.

---

## 3. Controle Preciso do Número de Caracteres

Assim como a implementação original da libc, todas as funções retornam exatamente a quantidade de caracteres escritos.

Exemplo:

```c
ft_printf("Olá %s", "mundo");
```

Retorno:

```text
9
```

Cada função auxiliar acumula sua própria contagem e propaga o resultado para a função principal.

---

# 📂 Estrutura do Projeto

```text
ft_printf/
│
├── ft_printf.c
├── ft_printf_utils.c
├── ft_print_hex.c
├── ft_printf.h
├── Makefile
│
└── printfTester/
```

---

## ft_printf.c

Contém:

* implementação principal da função `ft_printf()`;
* função despachante `ft_check_flag()`;
* implementação personalizada de `ft_strchr()`.

---

## ft_printf_utils.c

Responsável por:

* impressão de caracteres;
* impressão de strings;
* impressão de inteiros;
* impressão de inteiros sem sinal;
* contagem dos caracteres escritos.

---

## ft_print_hex.c

Responsável por:

* impressão hexadecimal;
* impressão de endereços de memória;
* conversões entre bases;
* implementação recursiva dos ponteiros.

---

## ft_printf.h

Contém:

* protótipos das funções;
* bibliotecas necessárias;
* definições utilizadas pelo projeto.

---

## Makefile

O projeto inclui um `Makefile` completo que:

* compila apenas arquivos modificados;
* evita relinkagem desnecessária;
* utiliza as flags obrigatórias:

  * `-Wall`
  * `-Wextra`
  * `-Werror`
* gera automaticamente a biblioteca estática `libftprintf.a`.

---

# 🚀 Compilação

```bash
make
```

Será gerado:

```text
libftprintf.a
```

---

# 🔗 Utilização

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o program
```

ou:

```bash
cc main.c libftprintf.a -o program
```

---

# 🧪 Testes

Os testes encontram-se no diretório:

```text
printfTester/
```

Execução:

```bash
cd printfTester
make test
```

---

# 🧹 Limpeza

Remover arquivos objeto:

```bash
make clean
```

Remover todos os arquivos gerados:

```bash
make fclean
```

Recompilar completamente:

```bash
make re
```

---

# 📚 Conceitos Aplicados

Durante este projeto foram aplicados conhecimentos relacionados a:

* funções variádicas;
* ponteiros;
* recursão;
* manipulação de strings;
* conversão entre bases numéricas;
* bibliotecas estáticas;
* Makefiles;
* chamadas de sistema (`write`);
* organização modular de software.

---

# 🤖 Utilização de Inteligência Artificial

Este projeto foi desenvolvido priorizando o aprendizado prático e a resolução de problemas de forma independente, conforme a filosofia pedagógica da Escola 42.

A utilização de ferramentas de IA ocorreu apenas em atividades secundárias, tais como:

* revisão textual;
* melhoria da documentação;
* validação de decisões arquiteturais;
* organização do README.

Nenhuma ferramenta de IA foi utilizada para:

* implementação das funcionalidades principais;
* definição da arquitetura do projeto;
* resolução dos desafios centrais;
* escrita das funções obrigatórias.

Toda a lógica implementada representa o processo de aprendizado adquirido através de estudo, experimentação, testes e depuração realizados durante o desenvolvimento do projeto.

---

# 🏁 Conclusão

O projeto **ft_printf** demonstra uma implementação robusta e eficiente de funções variádicas em C, utilizando técnicas de recursão e gerenciamento manual de saída para reproduzir o comportamento do `printf` original da libc.

A ausência de alocações dinâmicas para conversão numérica reduz significativamente a complexidade do gerenciamento de memória e minimiza riscos de vazamentos.

Além disso, a estrutura modular adotada facilita futuras expansões, manutenção e reutilização do código em outros projetos do ecossistema da Escola 42.

Este projeto representa um importante marco na evolução como desenvolvedora de sistemas de baixo nível, consolidando conhecimentos fundamentais da linguagem C e preparando terreno para desafios mais complexos dentro da formação da 42.

---

# 👨‍💻 Autor

**Rayane Pereira Silva Morais**

**Login 42:** `rayperei`

Engenharia de Dados • Desenvolvimento de Software • Linguagem C • Sistemas de Baixo Nível

Projeto desenvolvido no contexto do currículo da Escola 42.
