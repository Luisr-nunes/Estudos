# Estudos

[Read in English](README.en.md)

Exercícios e pequenos projetos feitos durante cursos livres e estudo por conta própria, em várias linguagens.

## Conteúdo

| Pasta | Linguagem | Arquivo | O que pratica |
| --- | --- | --- | --- |
| `C++/` | C++ | `SinglyLinkedList.cpp` | Lista encadeada simples com classes e ponteiros |
| `Java/` | Java | `BasicTaskManager.java` | Gerenciador de tarefas no terminal: classes, listas, datas e `Scanner` |
| `Java/complexidade_algoritmica/` | Java | `O(1)`, `O(log n)`, `O(n)`, `O(n log n)`, `O(n²)` | Um exemplo de algoritmo para cada ordem de complexidade |
| `python/` | Python | `data_cleaner_and_analyzer.py` | Gera transações simuladas, limpa os dados e calcula médias móveis e somas acumuladas, só com a biblioteca padrão |
| `HTML/` | HTML, CSS, JS | `dashboard.html` | Painel pessoal de desenvolvedor em uma única página |
| `frontend/react-product-showcase/` | React (JSX) | `index.HTML`, `app.jsx` | Vitrine de produtos com componentes, `useState`, `useEffect` e busca, carregando React, Babel e Tailwind por CDN |

## Como executar

```bash
git clone https://github.com/Luisr-nunes/Estudos.git
cd Estudos

# C++
g++ -o lista C++/SinglyLinkedList.cpp && ./lista

# Java (exemplos de complexidade, Java 11+)
java "Java/complexidade_algoritmica/O(n)_linear.java"

# Python
python python/data_cleaner_and_analyzer.py
```

O `BasicTaskManager.java` declara `public class Main`, então o `javac` exige que o arquivo se chame `Main.java`. Para rodar sem alterar o repositório:

```bash
mkdir tmp && cp Java/BasicTaskManager.java tmp/Main.java
javac -d tmp tmp/Main.java && java -cp tmp BasicTaskManager.Main
```

Para as páginas web, abra `HTML/dashboard.html` no navegador. A vitrine em React precisa de um servidor local, porque o Babel busca o `app.jsx` por requisição:

```bash
cd frontend/react-product-showcase
npx serve .
```

O `index.HTML` referencia `App.jsx` com "A" maiúsculo, enquanto o arquivo se chama `app.jsx`; isso funciona no Windows, mas falha em sistemas que diferenciam maiúsculas e minúsculas.

## Autor

Luís Nunes — [GitHub](https://github.com/Luisr-nunes) · [LinkedIn](https://www.linkedin.com/in/luis-nunes-dev/)
