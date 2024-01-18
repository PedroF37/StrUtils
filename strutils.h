#ifndef _STRUTILS_
#define _STRUTILS_


#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>


/* Cuida de capitalizar primeira letra de palavra
 * ola -> Ola */
void title_case_word(char *word);


/* Cuida de capitalizar primeira letra de cada
 * palavra em uma frase: ola mundo -> Ola Mundo */
void title_case_sentence(char *sentence);


/* Cuida de converter palavra ou frase para maiúscula */
void convert_to_upper(char *c);


/* Cuida de converter palavra ou frase para minúscula */
void convert_to_lower(char *c);


/* Cuida de inserir uma substring em uma string depois de dada substring
 * Exemplo:
 *
 * string -> "Programar em C é bom!"
 * substring para inserir -> " demais"
 * inserir depois de substring -> "bom"
 * Resultado -> "Programar em C é bom demais!"
 *
 * Retorna uma nova string, a string original fica igual */
char *str_insert(char *str, char *after, char *insert);


/* Cuida de substituir susbstring por outra subtring em string
 * Exemplo:
 *
 * string -> "Adoro programar em Python, é bom demais!"
 * substring para remover -> "Python"
 * substring para inserir -> "C"
 * Resultado -> "Adoro programar em C, é bom demais!"
 *
 * Retorna uma nova string, a sting original fica igual */
char *str_replace(char *str, char *old_sub, char *new_sub);


/* Cuida de remover substring em string
 * Exemplo:
 *
 * string -> "Eu acertei todas as respostas na prova, mas só copiando!"
 * substring para remover -> ", mas só copiando"
 * Resultado -> "Eu acertei todas as respostas na prova!"
 *
 * Retorna uma nova string, a string original fica igual */
char *str_remove(char *str, char *remove);


/* Cuida de verificar se palavra (ou frase)
 * começa com prefixo*/
bool starts_with(char *str, char *prefix);


/* Cuida de verificar se palavra (ou frase)
 * termina com sufixo*/
bool ends_with(char *str, char *suffix);


/* Cuida de verificar se string contem algum dos
 * items em array */
bool is_in_string(char *string, char *arr[]);


#endif
