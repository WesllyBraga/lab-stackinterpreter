

# repl-maquina-pilha1

# Laboratório Um: REPL para uma máquina baseada em pilha Máquina de Pilha com Variáveis - Interpretador

📌 Descrição
Este projeto é um interpretador de uma máquina virtual baseada em pilha, que executa comandos interativos (modo REPL) ou a partir de arquivos de texto. Na Etapa 2, o sistema foi ampliado para incluir o suporte a variáveis nomeadas usando uma lista encadeada.



## Grupo:

- Weslly Silveira Braga  

# Objetivos da Etapa 2
- Manipular valores usando uma pilha.
- Armazenar e atualizar variáveis usando uma lista encadeada.
- Integrar pilha e lista no interpretador.
- Ler comandos interativos (REPL) ou de arquivo.

# Estrutura do Projeto
```bash
maquina-pilha/
├── main.c             // Loop principal (REPL) e leitura de arquivos
├── interpret.c        // Interpretador dos comandos
├── interpret.h
├── stack.c            // Implementação da pilha
├── stack.h
├── lista.c            // Lista encadeada para as variáveis
├── lista.h
├── README.md          // Este arquivo
```

## Instruções de Compilação e Uso

### Compilar:
```bash
gcc main.c interpret.c stack.c lista.c -o maquina-pilha
```

# Como Executar
## Modo REPL (linha por linha):
```bash
./maquina-pilha
```
## Exemplo de entrada manual:
```perl
push 42
push 5
add
print

```
# Novos Comandos da Etapa 2 (variáveis)
## push <valor | nome_variável>
Se for um número inteiro → empilha o valor.

Se for o nome de uma variável existente → busca o valor na lista e empilha.

Se a variável não existir → mostra erro.

Exemplo:
```bash
push a
```

## pop <nome_variável>
Desempilha um valor da pilha.

Se a variável já existir → atualiza o valor.

Se não existir → cria um novo nó com o nome e valor.

Exemplo:
```bash
pop resultado
```
## Exemplo de um programa completo (arquivo de entrada):
```perl
push 42
push 5
add
push 8
sub
pop a
push 56
push 8
add
pop b
push a
push b
add
push 6
add
print
```
## Saída Esperada:
```bash
109
```
# Comandos Suportados
```bash
| Comando    | Ação                                  |
| ---------- | ------------------------------------- |
| push <n>   | Empilha um número                     |
| push <var> | Empilha o valor de uma variável       |
| pop <var>  | Salva o topo da pilha na variável     |
| add        | Soma os dois últimos valores da pilha |
| sub        | Subtrai os dois últimos valores       |
| mul        | Multiplica os dois últimos valores    |
| div        | Divide os dois últimos valores        |
| print      | Exibe o topo da pilha                 |
| exit       | Encerra o interpretador               |

```
