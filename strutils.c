#include "strutils.h"


static enum str_remove_error ERROR;


void title_case_word(char *word)
{
    if (*word != '\0')
    {
        *word = (char)toupper((unsigned char)*word);
    }
}


void title_case_sentence(char *sentence)
{
    char *word = sentence;

    while (*word)
    {
        while (*word && !isalpha(*word))
        {
            word++;
        }

        if (*word)
        {
            *word = (char)toupper((unsigned char)*word);
        }

        while (*word && isalpha(*word))
        {
            word++;
        }
    }
}


void convert_to_upper(char *c)
{
    while(*c)
    {
        if (*c >= 'a' && *c <= 'z')
        {
            *c = (char)toupper((unsigned char)*c);
        }

        c++;
    }
}


void convert_to_lower(char *c)
{
    while(*c)
    {
        if (*c >= 'A' && *c <= 'Z')
        {
            *c = (char)tolower((unsigned char)*c);
        }

        c++;
    }
}


char *str_insert(char *str, char *substr, size_t position)
{
    size_t str_len = strlen(str);
    size_t substr_len = strlen(substr);

    if ((int)position < 0 || position > str_len)
    {
        return(NULL);
    }

    char *new_str = (char *)malloc(str_len +
        substr_len + 1 * sizeof(char));
    if (new_str == NULL)
    {
        return(NULL);
    }

    strncpy(new_str, str, position);
    strcat(new_str, substr);
    strcat(new_str, str + position);

    return(new_str);
}


char *str_replace(char *original, char *replacement, size_t position)
{
    size_t orig_len = strlen(original);
    size_t rep_len = strlen(replacement);

    if ((int)position < 0 || position == orig_len
        || position + rep_len > orig_len)
    {
        return(NULL);
    }

    char *new_str = (char *)malloc(orig_len + 1 * sizeof(char));
    if (new_str == NULL)
    {
        return(NULL);
    }

    size_t size = position + rep_len;
    strncpy(new_str, original, position);
    strcat(new_str, replacement);
    strcat(new_str, original + size);
    return(new_str);
}


char *str_remove(char *str, int offset,
    int quantity)
{
    size_t str_len = strlen(str);
    size_t leftover = str_len - offset;

    if (offset < 0|| (size_t)offset > str_len)
    {
        ERROR = O_Range;
        return(NULL);
    }


    if (quantity < 0 || (size_t)quantity > str_len ||
        (size_t)quantity > leftover)
    {
        ERROR = Q_Range;
        return(NULL);
    }

    char *new_str = (char *)malloc(
        str_len - quantity + 1 * sizeof(char));
    if (new_str == NULL)
    {
        ERROR = Null;
        return(NULL);
    }

    strncpy(new_str, str, offset);
    strcat(new_str, str + offset + quantity);
    return(new_str);
}


enum str_remove_error get_enum_error(void)
{
    return(ERROR);
}


bool starts_with(char *str, char *prefix)
{
    if (str == NULL || prefix == NULL)
    {
        return(false);
    }

    size_t str_len = strlen(str);
    size_t prefix_len = strlen(prefix);

    /* Qualquer string começa com string vazia */
    if (prefix_len == 0)
    {
        return(true);
    }

    if (prefix_len > str_len)
    {
        return(false);
    }

    return(strncmp(str, prefix, prefix_len) == 0);
}


bool ends_with(char *str, char *suffix)
{
    if (str == NULL || suffix == NULL)
    {
        return(false);
    }

    size_t str_len = strlen(str);
    size_t suffix_len = strlen(suffix);

    if (suffix_len == 0)
    {
        return(true);
    }

    if (suffix_len > str_len)
    {
        return(false);
    }

    return(strncmp(str + (str_len - suffix_len),
        suffix, suffix_len) == 0);
}


bool is_in_string(char *string, char *arr[])
{
    if (string == NULL || arr == NULL)
    {
        return(false);
    }

    for (int i = 0; *arr != NULL; i++)
    {
        if (strstr(string, arr[i]) != NULL)
        {
            return(true);
        }
    }

    return(false);
}
