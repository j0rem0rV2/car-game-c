# Jogo de Corrida de Carros em C

Bem-vindo ao **Jogo de Corrida de Carros**!  
Esse é um jogo simples feito em C que roda direto no terminal. O objetivo? Desviar dos obstáculos controlando seu carro com as teclas `A` (para a esquerda) e `D` (para a direita).

![Demonstração do Jogo](https://via.placeholder.com/400x200.png?text=Game+Demo)  
*Imagem ilustrativa — substitua pelo screenshot real do jogo!*

---

## Funcionalidades

- **Controle do carro:** Movimente seu carro (`^`) para evitar obstáculos (`#`).
- **Pontuação dinâmica:** Quanto mais você avança, maior a pontuação.
- **Compatibilidade:** Funciona tanto em **Windows** quanto em **Linux** (códigos separados).

---

## Requisitos

### Windows
- Compilador C (ex: [MinGW](http://www.mingw.org/)).
- Biblioteca `conio.h` (já vem com o ambiente Windows).

### Linux
- Compilador C (como o `gcc`).
- Bibliotecas padrão do Unix: `termios.h`, `fcntl.h` e `unistd.h`.

---

## Como Compilar e Executar

### Versão Windows (`corrida_windows.c`)
1. **Compile:**
   ```bash
   gcc corrida_windows.c -o corrida_windows
   ```
2. **Execute:**
   ```bash
   ./corrida_windows
   ```

### Versão Linux (`corrida_linux.c`)
1. **Compile:**
   ```bash
   gcc corrida_linux.c -o corrida_linux
   ```
2. **Execute:**
   ```bash
   ./corrida_linux
   ```

---

## Estrutura do Código

| Função           | Descrição                                       |
|------------------|-------------------------------------------------|
| `draw_game()`    | Renderiza o carro, obstáculos e a pontuação.    |
| `update_game()`  | Atualiza posições e verifica colisões.          |
| `handle_input()` | Captura os movimentos do jogador.               |

---

## Melhorias Futuras

- Adicionar múltiplos obstáculos simultâneos.
- Implementar menu de início/pausa.
- Aumentar a velocidade progressivamente.

---

## Notas Técnicas

- **Linux:** O jogo reconfigura o terminal temporariamente para permitir leitura não bloqueante.
- **Saída:** Use `Ctrl+C` para sair do jogo. No Linux, o terminal é restaurado automaticamente após a saída.

---

## Contribuições

Contribuições são super bem-vindas! Se quiser ajudar a melhorar o jogo, abra uma _issue_ ou envie um _pull request_. Algumas ideias:
- Adicionar gráficos via NCurses.
- Melhorar a física do movimento.
- Implementar um sistema de highscore.


---
