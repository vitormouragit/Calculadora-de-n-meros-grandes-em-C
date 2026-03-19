🧮 Calculadora de Números Grandes em C

Projeto desenvolvido em linguagem C que implementa uma calculadora capaz de realizar operações com números inteiros muito grandes (além do limite dos tipos primitivos como int e long long).

📌 Objetivo

Esse projeto foi criado com o objetivo de praticar:

Manipulação de strings em C

Alocação dinâmica de memória (malloc, realloc, free)

Implementação manual de operações matemáticas

Lógica de algoritmos para números grandes

⚙️ Funcionalidades

A calculadora realiza as seguintes operações:

✅ Soma de números grandes

✅ Subtração de números grandes

✅ Multiplicação de números grandes

✅ Exponenciação

✅ Fatorial

Todas as operações são feitas utilizando strings, permitindo trabalhar com valores muito maiores do que os suportados nativamente pela linguagem.

🧠 Como funciona

Em vez de usar tipos numéricos padrão, os números são tratados como strings, e cada operação é implementada manualmente:

Soma (soma): realiza a soma dígito por dígito, controlando o "vai-um".

Subtração (subtracao): faz a subtração com controle de empréstimo.

Multiplicação (multiplicacao): baseada em somas sucessivas e deslocamento de casas decimais.

Exponenciação (exponenciacao): multiplica repetidamente a base.

Fatorial (fatorial): calcula usando multiplicações sucessivas.

🖥️ Exemplo de uso

=== CALCULADORA DE NUMEROS GRANDES ===

1 - Soma
2 - Subtracao
3 - Multiplicacao
4 - Exponenciacao
5 - Fatorial
0 - Sair
Opcao: 1

A: 999999999999999999
B: 1

Resultado: 1000000000000000000
⚠️ Observações

Os números devem ser informados sem espaços e apenas com dígitos.

O fatorial e a exponenciação utilizam atoi, então possuem limitação no tamanho do número (dependendo do tipo int).

A multiplicação não é otimizada (usa somas repetidas), podendo ser lenta para números muito grandes.

🚀 Possíveis melhorias

Implementar multiplicação mais eficiente (ex: algoritmo de Karatsuba)

Suporte a números negativos em todas as operações

Melhorar desempenho da exponenciação (exponenciação rápida)

Criar interface gráfica ou versão web

Validação de entrada do usuário

📚 Tecnologias utilizadas

Linguagem C

Biblioteca padrão:

stdio.h

stdlib.h

string.h
