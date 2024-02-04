#include "strutils.h"


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


char *str_insert(char *str, char *after, char *insert)
{
    char *match = strstr(str, after);
    if (match == NULL)
    {
        return(NULL);
    }

    size_t str_len = strlen(str);
    size_t after_len = strlen(after);
    size_t insert_len = strlen(insert);

    char *new_str = (char *)malloc(str_len + insert_len + 1);
    if (new_str == NULL)
    {
        return(NULL);
    }

    strncpy(new_str, str, match - str + after_len);
    new_str[match - str + after_len] = '\0';
    strcat(new_str, insert);
    strcat(new_str, match + after_len);
    return(new_str);
}


char *insert_in_beginning(char *str, char *insert)
{
    size_t insert_len = strlen(insert);

    char *new_str = (char *)malloc(strlen(str) + insert_len + 1);
    if (new_str == NULL)
    {
        return(NULL);
    }

    strncpy(new_str, insert, insert_len);
    new_str[insert_len] = '\0';
    strcat(new_str, str);
    return(new_str);
}


char *str_replace(char *str, char *old_sub, char *new_sub)
{
    char *match = strstr(str, old_sub);
    if (match == NULL)
    {
        return(NULL);
    }

    size_t old_len = strlen(old_sub);
    char *new_str = (char *)malloc(strlen(str) -
        old_len + strlen(new_sub) + 1);
    if (new_str == NULL)
    {
        return(NULL);
    }

    strncpy(new_str, str, match - str);
    new_str[match - str] = '\0';
    strcat(new_str, new_sub);
    strcat(new_str, match + old_len);
    return(new_str);
}


char *str_remove(char *str, char *remove)
{
    char *match = strstr(str, remove);
    if (match == NULL)
    {
        return(NULL);
    }

    size_t str_len = strlen(str);
    size_t remove_len = strlen(remove);

    char *new_str = (char *)malloc(str_len - remove_len + 1);
    if (new_str == NULL)
    {
        return(NULL);
    }

    strncpy(new_str, str, match - str);
    new_str[match -str] = '\0';
    strcat(new_str, match + remove_len);
    return(new_str);
}


int word_count(const char *str)
{
    if (str == NULL || *str == '\0')
    {
        return(0);
    }

    int count = 0;
    while (*str)
    {
        if (isspace(*str))
        {
            str++;
        }
        else
        {
            while (!isspace(*str))
            {
                str++;
            }

            count++;
        }
    }

    return(count);
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
