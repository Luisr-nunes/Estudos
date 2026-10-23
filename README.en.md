# Studies

<!-- badges -->
![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=flat-square&logo=cplusplus&logoColor=white) ![Java](https://img.shields.io/badge/Java-ED8B00?style=flat-square&logo=openjdk&logoColor=white) ![Python](https://img.shields.io/badge/Python-3776AB?style=flat-square&logo=python&logoColor=white) ![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=flat-square&logo=javascript&logoColor=black) ![HTML5](https://img.shields.io/badge/HTML5-E34F26?style=flat-square&logo=html5&logoColor=white) ![React](https://img.shields.io/badge/React-61DAFB?style=flat-square&logo=react&logoColor=black)

[Ler em Português](README.md)

Exercises and small projects from online courses and self-study, in several languages.

## Contents

| Folder | Language | File | What it practices |
| --- | --- | --- | --- |
| `C++/` | C++ | `SinglyLinkedList.cpp` | Singly linked list with classes and pointers |
| `Java/` | Java | `BasicTaskManager.java` | Terminal task manager: classes, lists, dates and `Scanner` |
| `Java/complexidade_algoritmica/` | Java | `O(1)`, `O(log n)`, `O(n)`, `O(n log n)`, `O(n²)` | One example algorithm for each complexity class |
| `python/` | Python | `data_cleaner_and_analyzer.py` | Generates simulated transactions, cleans the data and computes moving averages and running totals, standard library only |
| `HTML/` | HTML, CSS, JS | `dashboard.html` | Single-page personal developer dashboard |
| `frontend/react-product-showcase/` | React (JSX) | `index.HTML`, `app.jsx` | Product showcase with components, `useState`, `useEffect` and search, loading React, Babel and Tailwind from a CDN |

## Running

```bash
git clone https://github.com/Luisr-nunes/Estudos.git
cd Estudos

# C++
g++ -o list C++/SinglyLinkedList.cpp && ./list

# Java (complexity examples, Java 11+)
java "Java/complexidade_algoritmica/O(n)_linear.java"

# Python
python python/data_cleaner_and_analyzer.py
```

`BasicTaskManager.java` declares `public class Main`, so `javac` requires the file to be named `Main.java`. To run it without changing the repository:

```bash
mkdir tmp && cp Java/BasicTaskManager.java tmp/Main.java
javac -d tmp tmp/Main.java && java -cp tmp BasicTaskManager.Main
```

For the web pages, open `HTML/dashboard.html` in a browser. The React showcase needs a local server, because Babel fetches `app.jsx` over HTTP:

```bash
cd frontend/react-product-showcase
npx serve .
```

`index.HTML` references `App.jsx` with a capital "A" while the file is named `app.jsx`; this works on Windows but fails on case-sensitive systems.

## Author

Luís Nunes — [GitHub](https://github.com/Luisr-nunes) · [LinkedIn](https://www.linkedin.com/in/luis-nunes-dev/)
