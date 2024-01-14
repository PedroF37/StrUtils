# StrUtils
## Biblioteca de manipulação de strings para meus projetos de aprendizado em C
* Biblioteca criada com o comando: `clang -shared -fPIC -o libstrutils.so strutils.c`
* Localização dos arquivos no meu sistema para usar com meus projetos:
* Arquivo .so `/usr/local/lib64/`
* Arquivo .h `/usr/local/include/`
* Flag usada na compilação dos projetos que usam a bibloteca: `-lstrutils`
* Ex: `clang -Wall -Wextra --pedantic -std=c99 -lstrutils -o arquivo arquivo.c`
