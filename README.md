# Simple C Shell (Mini Shell)

Um interpretador de comandos simples implementado em C para sistemas Linux/Unix. Este projeto explora conceitos fundamentais de sistemas operacionais, como criação de processos, execução de programas e gerenciamento de memória.

## 🚀 Funcionalidades

- **Execução de comandos externos:** Suporta comandos padrão do Linux (ex: `ls`, `grep`, `pwd`, `echo`).
- **Comandos Built-in:**
  - `cd`: Altera o diretório atual (necessário pois `exec` roda em processo filho).
  - `help`: Mostra a lista de comandos internos.
  - `exit`: Encerra o shell.
- **Gerenciamento de Processos:** Utiliza `fork()`, `execvp()` e `waitpid()` para ciclo de vida dos processos.

## 🛠️ Como Compilar e Rodar

Certifique-se de ter o `gcc` e o `make` instalados (ambiente Linux/WSL/macOS).

1. Clone o repositório:
   ```bash
   git clone https://github.com/SEU_USUARIO/simple-c-shell.git
   cd simple-c-shell
   ```

2. Compile o projeto usando o Makefile:

```bash
make
```

3. Execute o shell:

```bash
./myshell
```

## 🧠 Como Funciona (Under the Hood)

O shell opera em um ciclo infinito de três etapas principais (REPL - Read, Eval, Print Loop):

- Read: Lê a entrada do usuário da stdin.
- Parse: Tokeniza a string de entrada separando comando e argumentos.
- Execute:

  - Verifica se é um comando built-in (como cd). Se sim, executa no processo pai.
  - Se não, chama fork() para criar um processo filho.
  - O filho usa execvp() para substituir sua imagem pelo programa desejado.
  - O pai usa waitpid() para aguardar o término do filho.

## 📚 Aprendizados

Este projeto foi desenvolvido para consolidar conhecimentos em:

- Linguagem C e Ponteiros.
- System Calls do Linux/Unix.
- Gerenciamento de memória (malloc/free).

Desenvolvido por Gustavo.

---

### Resumo do Projeto (Para você falar na entrevista)

Se um recrutador perguntar "O que é esse projeto?", você diz:

> "É uma implementação de um Shell Unix básico. Eu queria entender como o sistema operacional gerencia processos em baixo nível. Ele funciona lendo a entrada do usuário, fazendo o parsing dos argumentos e usando *system calls* como `fork` e `exec` para rodar os programas. Também implementei comandos internos como o `cd`, que precisam manipular o estado do próprio processo pai, algo que não dá para fazer apenas chamando um executável externo."

Isso mostra que você entende de **Sistemas Operacionais** e **Ponteiros**, duas coisas que a galera de engenharia valoriza muito.

---

**Próximo passo:** Salve os arquivos, compile com `make` para testar, e depois dê o `git push`. Quer ajuda com os comandos do Git?
