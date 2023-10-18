#include "my_string.h"

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#define MY_NULL 0

typedef long unsigned my_size_t;

int char_in_str(char c, const char *str);
void *my_memchr(const void *str, int c, my_size_t n);
int my_memcmp(const void *str1, const void *str2, my_size_t n);
void *my_memcpy(void *dest, const void *src, my_size_t n);
void *my_memmove(void *dest, const void *src, my_size_t n);
void *my_memset(void *str, int c, my_size_t n);
char *my_strcat(char *dest, const char *src);
char *my_strncat(char *dest, const char *src, my_size_t n);
char *my_strchr(const char *str, int c);
int my_strcmp(const char *str1, const char *str2);
int my_strncmp(const char *str1, const char *str2, my_size_t n);
char *my_strcpy(char *dest, const char *src);
char *my_strncpy(char *dest, const char *src, my_size_t n);
my_size_t my_strcspn(const char *str1, const char *str2);
my_size_t my_strlen(const char *str);
char *my_strpbrk(const char *str1, const char *str2);
char *my_strrchr(const char *str, int c);
my_size_t my_strspn(const char *str1, const char *str2);
char *my_strstr(const char *haystack, const char *needle);
char *my_strtok(char *str, const char *delim);
void *my_to_upper(const char *str);
void *my_to_lower(const char *str);
void *my_insert(const char *src, const char *str, my_size_t start_index);
void *my_trim(const char *src, const char *trim_chars);

/* -----------------------------------
helper functions
----------------------------------- */
int char_in_str(char c, const char *str) {
    int flag = 0;
    int len_of_flag = my_strlen(str);
    for (int j = 0; j < len_of_flag; j++) {
        if (str[j] == c) {
            flag = 1;
            break;
        }
    }
    return flag;
}

/* -----------------------------------
#1 Searches for the first occurrence of the character c
(an unsigned char) in the first n bytes of the string pointed to, by the
argument str.
----------------------------------- */
void *my_memchr(const void *str, int c, my_size_t n) {
    char *position = MY_NULL;
    char ch = (char)c;
    char *temp = (char *)str;
    for (my_size_t i = 0; i < n && *(temp + i) != MY_NULL; i++) {
        if (temp[i] == ch) {
            position = (temp + i);
            break;
        }
    }
    return (void *)position;
}
/* -----------------------------------
#2 Compares the first n bytes of str1 and str2.
----------------------------------- */
int my_memcmp(const void *str1, const void *str2, my_size_t n) {
    const unsigned char *s1 = (const unsigned char *)str1;
    const unsigned char *s2 = (const unsigned char *)str2;
    int dif = 0;
    for (; n--; s1++, s2++) {
        if (*s1 != *s2) {
            dif = *s1 - *s2;
            n = 0;
        }
    }
    return dif;
    // const unsigned char *st1 = str1, *st2 = str2;
    // int res = 0;
    // for (my_size_t i = 0; i < n; i++) {
    //     if ((res = st1[i] - st2[i]) != 0) {
    //         break;
    //     }
    // }

    // return res;
}
/* -----------------------------------
#3 Copies n characters from src to dest.
----------------------------------- */
void *my_memcpy(void *dest, const void *src, my_size_t n) {
    my_size_t i;
    char *cdest = (char *)dest;
    const char *csrc = (char *)src;
    for (i = 0; i < n; ++i) *cdest++ = *csrc++;
    return dest;

    // void *ret = dest;
    // while (n--) {
    //     *(char *)dest = *(char *)src;
    //     dest = (char *)dest + 1;
    //     src = (char *)src + 1;
    // }
    // return ret;
}
/* -----------------------------------
#4 Another function to copy n characters from str2 to str1.
----------------------------------- */
void *my_memmove(void *dest, const void *src, my_size_t n) {
    my_size_t k = n / sizeof(char);
    char *destStr = (char *)dest;
    const char *srcStr = src;
    if (srcStr < destStr) {
        my_size_t i = 1;
        while (i <= k) {
            destStr[k - i] = srcStr[k - i];
            i++;
        }
    }
    if (srcStr == destStr || srcStr > destStr) {
        my_size_t i = 0;
        while (i < k) {
            destStr[i] = srcStr[i];
            i++;
        }
    }
    return dest;
}
/* -----------------------------------
#5 Copies the character c (an unsigned char) to the first n characters of
the string pointed to, by the argument str.
----------------------------------- */
void *my_memset(void *str, int c, my_size_t n) {
    if (str != MY_NULL && n > 0) {
        int capacity = n / sizeof(char);
        char *array = (char *)str;
        for (int i = 0; i < capacity; i++) {
            array[i] = (char)c;
        }
    } else {
        printf("my_memset: invalid argument\n");
    }
    return str;
}
/* -----------------------------------
#6 Appends the string pointed to, by src to the end of the string pointed to by
dest.
----------------------------------- */
char *my_strcat(char *dest, const char *src) {
    my_size_t length_dest = my_strlen(dest);
    int length_src = 0;
    for (; *(src + length_src); length_src++) {
    }
    int i = 0;
    for (; *(src + i); i++) {
        *(dest + length_dest + i) = *(src + i);
    }
    *(dest + length_dest + i) = MY_NULL;
    return dest;
}
/* -----------------------------------
#7 Appends the string pointed to, by src to the end of the string pointed to,
by dest up to n characters long.
----------------------------------- */
char *my_strncat(char *dest, const char *src, my_size_t n) {
    char *s = dest;
    for (; *s; s++) {
    }
    for (int i = 0; (*src) && (i < n); src++, i++, s++) {
        *s = *src;
    }
    *s = '\0';
    return dest;
}
/* -----------------------------------
#8 Searches for the first occurrence of the character c (an unsigned char)
in the string pointed to, by the argument str.
----------------------------------- */
char *my_strchr(const char *str, int c) {
    char *p = MY_NULL;
    do {
        if (*str == c) {
            p = (char *)str;
            break;
        }
    } while (*str++);
    return p;
}
/* -----------------------------------
#9 Compares the string pointed to, by str1 to the string pointed to by str2.
----------------------------------- */
int my_strcmp(const char *str1, const char *str2) {
    for (; *str1 && *str1 == *str2; str1++, str2++) {
    }
    return *str1 - *str2;
}
/* -----------------------------------
#10 Compares at most the first n bytes of str1 and str2.
----------------------------------- */
int my_strncmp(const char *str1, const char *str2, my_size_t n) {
    my_size_t result = 0;
    my_size_t checkSize = n / sizeof(char);
    my_size_t i;
    if (checkSize == 0) {
        result = 0;
    } else if (*str1 == '\0' && *str2 == '\0') {
        result = 0;
    } else {
        for (i = 0; (i < checkSize) && str1[i] && str2[i]; i++) {
            if (str1[i] != str2[i]) {
                break;
            }
        }
        if (i == checkSize) {
            result = 0;
        } else if (i < checkSize) {
            result = (str1[i] - str2[i]);
        }
    }
    return (int)result;
}
/* -----------------------------------
#11 Copies the string pointed to, by src to dest.
----------------------------------- */
char *my_strcpy(char *dest, const char *src) {
    int i = 0;
    for (; *src; src++, i++) dest[i] = *src;
    dest[i] = MY_NULL;
    return dest;
}
/* -----------------------------------
#12 Copies up to n characters from the string pointed to, by src to dest.
----------------------------------- */
char *my_strncpy(char *dest, const char *src, my_size_t n) {
    char *d = dest;
    char *dl = dest;
    const char *sl = src;
    my_size_t dest_len = 0, src_len = 0;
    for (; *dl; dest_len++, dl++) {
    }
    for (; *sl; src_len++, sl++) {
    }
    for (my_size_t i = 0; (*src) && (i < n); src++, i++, d++) {
        *d = *src;
    }
    if ((dest_len > src_len) && (n > src_len)) {
        *d = '\0';
    }
    return dest;
}
/* -----------------------------------
#13 Calculates the length of the initial segment of str1 which
consists entirely of characters not in str2.
----------------------------------- */
my_size_t my_strcspn(const char *str1, const char *str2) {
    my_size_t l1 = my_strlen(str1);
    my_size_t l2 = my_strlen(str2);
    my_size_t i;
    int flag = 0;
    for (i = 0; i < l1; ++i) {
        for (my_size_t j = 0; j < l2; ++j) {
            if (str1[i] == str2[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            break;
        }
    }
    return i;
}
/* -----------------------------------
#14 Computes the length of the string str up to but not
including the terminating null character.
----------------------------------- */
my_size_t my_strlen(const char *str) {
    my_size_t length = 0;
    for (; *(str + length); length++) {
    }
    return length;
}
/* -----------------------------------
#15 Finds the first character in the string str1 that
matches any character specified in str2.
----------------------------------- */
char *my_strpbrk(const char *str1, const char *str2) {
    char *result = MY_NULL;
    char *position = (char *)str1;
    for (; *position; position++) {
        if (char_in_str(*position, str2)) {
            result = position;
            break;
        }
    }
    return result;
}
/* -----------------------------------
#16 Searches for the last occurrence of the character c
(an unsigned char) in the string pointed to by the argument str.
----------------------------------- */
char *my_strrchr(const char *str, int c) {
    char *s = MY_NULL;
    char *str1 = (char *)str;
    for (; str && *str1; str1++) {
        if (*str1 == c) {
            s = str1;
        }
    }
    return s;
}
/* -----------------------------------
#17 Calculates the length of the initial segment of str1 which consists entirely
of characters in str2.
----------------------------------- */
my_size_t my_strspn(const char *str1, const char *str2) {
    my_size_t n;
    const char *p;
    for (n = 0; *str1; str1++, n++) {
        for (p = str2; *p && *p != *str1; p++) {
        }
        if (!*p) break;
    }
    return n;
}
/* -----------------------------------
#18 Finds the first occurrence of the entire string needle
(not including the terminating null character) which appears in the string
haystack.
----------------------------------- */
char *my_strstr(const char *haystack, const char *needle) {
    char *p = MY_NULL;
    unsigned int x = 0;
    unsigned int flag = 0;

    if ((*needle) == '\0') {
        p = (char *)haystack;
    }
    while (haystack[x] != '\0') {
        if (haystack[x] == needle[0]) {
            unsigned int i = 1;
            while (haystack[x + i] == needle[i] && needle[i] != '\0') {
                i++;
            }
            if (needle[i] == '\0') {
                flag = 1;
                break;
            }
        }
        x++;
    }
    if (flag == 1) {
        p = (char *)(haystack + x);
    }
    return p;
}
/* -----------------------------------
#19 Breaks string str into a series of tokens separated by delim.
----------------------------------- */
char *my_strtok(char *str, const char *delim) {
    static char *end;
    char *result = MY_NULL;
    if (str) end = str;
    if (end) {
        int count = 1, indx = 0,  isFound = 0, totalLen = 0;
        int len = my_strlen(end);
        int dlen = my_strlen(delim);
      for (; totalLen < len  && isFound == 0; indx++, count++, totalLen++) {
        for (int k = 0; k < dlen; k++) {
          if (end[indx] == delim[k]) {
            isFound = 1;
            break;
          }
        }
        if (isFound == 1) {
              if (count > 1) {
                result = end;
                end = &end[indx + 1];
                result[indx] = '\0';
                break;
              }
                  end[indx] = '\0';
                  end++;
                  count--;
                  indx--;
                  isFound = 0;
        } else {
          result = end;
        }
      }
      if (len == indx) {
          end = MY_NULL;
      }
    }
    return result;
}
/* -----------------------------------
#1 bonus Returns a copy of string (str) converted to uppercase.
In case of any error, return NULL
----------------------------------- */
void *my_to_upper(const char *str) {
    char *temp = MY_NULL;
    if (str) {
        my_size_t len = my_strlen(str);
        if (len > 0) {
            temp = (char *)calloc((len + 1), sizeof(char));
            for (my_size_t i = 0; i < len; i++) {
                if (str[i] >= 'a' && str[i] <= 'z') {
                    temp[i] = (char)(str[i] - 32);
                } else {
                    temp[i] = str[i];
                }
            }
            temp[len] = '\0';
        }
    }
    return (void *)temp;
}
/* -----------------------------------
#2 bonus Returns a copy of string (str) converted to lowercase.
In case of any error, return NULL
----------------------------------- */
void *my_to_lower(const char *str) {
    char *temp = MY_NULL;
    if (str) {
        my_size_t len = my_strlen(str);
        if (len > 0) {
            temp = (char *)calloc((len + 1), sizeof(char));
            for (my_size_t i = 0; i < len; i++) {
                if (str[i] >= 'A' && str[i] <= 'Z') {
                    temp[i] = (char)(str[i] + 32);
                } else {
                    temp[i] = str[i];
                }
            }
            temp[len] = MY_NULL;
        } else {
            temp = MY_NULL;
        }
    }
    return (void *)temp;
}
/* -----------------------------------
#3 bonus Returns a new string in which a specified string (str)
is inserted at a specified index position (start_index) in the
given string (src). In case of any error, return NULL
----------------------------------- */
void *my_insert(const char *src, const char *str, my_size_t start_index) {
    char *result = MY_NULL;
    if (str && src) {
        my_size_t len_str = my_strlen(src);
        if (start_index <= len_str) {
            my_size_t len_src = my_strlen(str);
            result = (char *)calloc((len_src + len_str + 2), sizeof(char));
            char *temp = (char *)calloc(len_str + 1, sizeof(char));
            if (result && temp) {
                my_size_t i = 0;
                for (; src[i + start_index] != MY_NULL; i++) {
                    temp[i] = src[start_index + i];
                }
                temp[i] = MY_NULL;
                for (my_size_t j = 0; j < start_index; j++) {
                    result[j] = src[j];
                }
                for (my_size_t j = start_index; j < start_index + len_src;
                     j++) {
                    result[j] = str[j - start_index];
                }
                my_size_t j = start_index + len_src;
                for (; j < start_index + len_src + i; j++) {
                    result[j] = temp[j - start_index - len_src];
                }
                result[j] = MY_NULL;
                free(temp);
            }
        }
    }
    return (void *)result;
}
/* -----------------------------------
#4 bonus Returns a new string in which all leading and trailing occurrences
of a set of specified characters (trim_chars) from the given string (src) are
removed. In case of any error, return NULL
----------------------------------- */
void *my_trim(const char *src, const char *trim_chars) {
    my_size_t i = 0;
    my_size_t len = my_strlen(src);
    if (trim_chars == MY_NULL) {
        trim_chars = "\t ";
    }
    while (char_in_str(src[i], trim_chars)) {
        i++;
    }
    my_size_t j = len - 1;
    while (char_in_str(src[j], trim_chars)) {
        j--;
    }
    char *temp = MY_NULL;
    if (i <= j) {
        my_size_t k = j - i + 1;
        temp = (char *)calloc((k + 1), sizeof(char));
        if (temp) {
            for (my_size_t l = 0; l < k; l++) {
                temp[l] = src[i + l];
            }
            temp[k] = MY_NULL;
        }
    }
    return (void *)temp;
}
