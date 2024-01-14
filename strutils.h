#ifndef _STRUTILS_
#define _STRUTILS_


#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>


/* Dá-nos o tipo de erro na função str_remove
 * caso retorne NULL */
enum str_remove_error{Null, O_Range, Q_Range};


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


/* Cuida de inserir substring em dada posição de string
 * Exemplo: string -> texto, substring ->Pre,
 * Resultado -> Pretexto. Não sobescreve (remove) apenas adiciona
 * String original fica igual, cria uma nova
 * string que tem que ser liberada (free()) depois de usar */
char *str_insert(char *str, char *substr, size_t position);


/* Cuida de sobescrever parte da string com substring
 * Exemplo: string -> Contexto, substring -> Pre,
 * Resultado -> Pretexto. String original fica igual, cria uma nova
 * string que tem que ser liberada (free()) depois de usar */
char *str_replace(char *original, char *replacement, size_t position);


/* Cuida de remover dada parte da string. Offstet é a posição
 * inicial para começar a remover, Quantity é a quantidade de
 * caracteres, a partir de Offstet incluíndo, para remover. Offset começa
 * a contagem a partir o 0 e Quantity começa a contagem a partir
 * de 1. Exemplo:
 *
 * char *string = "Contexto e Pretexto";
 * char *new_str = NULL;
 * new_str = str_remove(string, 0, 11); -> new_str == "Pretexto";
 *
 * new_str = str_remove(string, 8, 11) -> new_str == "Contexto";
 *
 * Erro -> Q_Range (Quantity_Range)
 * new_str = str_remove(string, 8, 12) -> new_str == NULL; */
char *str_remove(char *str, int offset, int quantity);


/* Faz par com a função str_remove, para pegar o tipo de
 * erro quando str_remove retorna NULL */
enum str_remove_error get_enum_error(void);


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
