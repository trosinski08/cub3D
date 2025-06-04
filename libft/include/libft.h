/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 02:50:09 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/29 17:51:34 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <limits.h>

/*
** ---------------------------------------------------------------------------
** Comprehensive C library combining three essential 42 School projects:
** - libft: Custom implementations of standard C library functions
** - ft_printf: Custom printf implementation
** - get_next_line: Function for reading from file descriptors line by line
**
** This unified library provides essential functionality for C programming,
** organized by categories for easy navigation and use.
** ---------------------------------------------------------------------------
*/

# include <unistd.h>
# include <stdlib.h>
# include "../gnl42/include/get_next_line.h"
# include "../ft_printf/include/ft_printf.h"

/**
 * @brief Structure for a linked list node
 * 
 * This structure represents a node in a singly linked list.
 * It can store any type of content as a void pointer.
 */
typedef struct s_list
{
	void			*content; // Pointer to the content stored in the node
	struct s_list	*next; // Pointer to the next node in the list
}					t_list;

//./char

/**
 * @brief Converts a string to an integer (atoi replacement)
 *
 * Converts the initial portion of the string pointed to by num to int.
 * The behavior is the same as the standard atoi function from <stdlib.h>.
 * Handles whitespace, signs, and numeric characters correctly.
 *
 * @param num The string to be converted to an integer
 * @return The converted integer value
 */
int		ft_atoi(const char *num);

/**
 * @brief Checks if a character is alphanumeric (isalnum replacement)
 *
 * Tests if the character c is either a decimal digit or an alphabetic letter.
 * 
 * @param c The character to test
 * @return Non-zero if c is alphanumeric, zero otherwise
 */
int		ft_isalnum(int c);

/**
 * @brief Checks if a character is alphabetic (isalpha replacement)
 *
 * Tests if the character c is an alphabetic letter.
 * 
 * @param c The character to test
 * @return Non-zero if c is alphabetic, zero otherwise
 */
int		ft_isalpha(int c);

/**
 * @brief Checks if a character is ASCII (isascii replacement)
 *
 * Tests if the character c is in the ASCII character set (0-127).
 * 
 * @param c The character to test
 * @return Non-zero if c is ASCII, zero otherwise
 */
int		ft_isascii(int c);

/**
 * @brief Checks if a character is a decimal digit (isdigit replacement)
 *
 * Tests if the character c is a decimal digit (0-9).
 * 
 * @param c The character to test
 * @return Non-zero if c is a decimal digit, zero otherwise
 */
int		ft_isdigit(int c);

/**
 * @brief Checks if a character is printable (isprint replacement)
 *
 * Tests if the character c is a printable character (32-126).
 * 
 * @param c The character to test
 * @return Non-zero if c is printable, zero otherwise
 */
int		ft_isprint(int c);

/**
 * @brief Checks if a character is a whitespace character (isspace replacement)
 *
 * Tests if the character c is a whitespace char (space, tab, newline, etc.).
 * 
 * @param c The character to test
 * @return Non-zero if c is a whitespace character, zero otherwise
 */
int		ft_isspace(int c);

/**
 * @brief Converts an integer to a string
 *
 * Allocates memory and returns a string representing the integer num.
 * Handles negative numbers and the full range of int values.
 * 
 * @param num The integer to convert
 * @return A newly allocated string representing the integer,
 * or NULL if allocation fails
 */
char	*ft_itoa(int num);

/**
 * @brief Converts a character to lowercase (tolower replacement)
 *
 * If the character is an uppercase letter, returns the lowercase equivalent.
 * Otherwise, returns the character unchanged.
 * 
 * @param c The character to convert
 * @return The lowercase equivalent if c is uppercase, c unchanged otherwise
 */
int		ft_tolower(int c);

/**
 * @brief Converts a character to uppercase (toupper replacement)
 *
 * If the character is a lowercase letter, returns the uppercase equivalent.
 * Otherwise, returns the character unchanged.
 * 
 * @param c The character to convert
 * @return The uppercase equivalent if c is lowercase, c unchanged otherwise
 */
int		ft_toupper(int c);

//./memory

/**
 * @brief Fills memory with zeros (bzero replacement)
 *
 * Writes n zeroed bytes to the string s. If n is zero, bzero() does nothing.
 * 
 * @param s Pointer to memory area to be zeroed
 * @param n Number of bytes to zero
 */
void	ft_bzero(void *s, size_t n);

/**
 * @brief Allocates zeroed memory (calloc replacement)
 *
 * Allocates memory for an array of counter elements of size bytes each and
 * initializes all bytes to zero.
 * 
 * @param counter Number of elements
 * @param sizer Size of each element
 * @return Pointer to the allocated memory, or NULL if allocation fails
 */
void	*ft_calloc(size_t counter, size_t sizer);

/**
 * @brief Locates a byte in memory (memchr replacement)
 *
 * Locates the first occurrence of c (converted to an unsigned char)
 * in the first n bytes of the memory area pointed to by s.
 * 
 * @param s Pointer to memory area to search
 * @param c Byte value to search for
 * @param n Number of bytes to search
 * @return Pointer to the matching byte, or NULL if not found
 */
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compares memory areas (memcmp replacement)
 *
 * Compares the first n bytes of memory areas s1 and s2.
 * 
 * @param s1 First memory area
 * @param s2 Second memory area
 * @param n Number of bytes to compare
 * @return <0 if s1<s2, 0 if s1=s2, >0 if s1>s2
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Copies memory area (memcpy replacement)
 *
 * Copies n bytes from memory area src to memory area dest. The memory areas 
 * must not overlap. Use ft_memmove if the memory areas overlap.
 * 
 * @param dest Destination memory area
 * @param src Source memory area
 * @param n Number of bytes to copy
 * @return Pointer to dest
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Copies memory area even if they overlap (memmove replacement)
 *
 * Copies len bytes from memory area src to memory area dst. The memory areas 
 * may overlap: copying takes place as though the bytes in src are first 
 * copied into a temporary array that does not overlap src or dst, and then 
 * the bytes from the temporary array are copied to dst.
 * 
 * @param dst Destination memory area
 * @param src Source memory area
 * @param len Number of bytes to copy
 * @return Pointer to dst
 */
void	*ft_memmove(void *dst, const void *src, size_t len);

/**
 * @brief Fills memory with a constant byte (memset replacement)
 *
 * Fills the first n bytes of the memory area pointed to by s 
 * with the constant byte c.
 * 
 * @param s Pointer to memory area
 * @param c Byte value to fill with
 * @param n Number of bytes to fill
 * @return Pointer to s
 */
void	*ft_memset(void *s, int c, size_t n);

//./print

/**
 * @brief Outputs a character to a file descriptor
 *
 * Writes the character c to the given file descriptor fd.
 * 
 * @param c Character to output
 * @param fd File descriptor to write to
 * @return Number of characters written (1) or -1 on error
 */
int		ft_putchar_fd(char c, int fd);

/**
 * @brief Outputs a string followed by a newline to a file descriptor
 *
 * Writes the string s followed by a newline to the given file descriptor fd.
 * 
 * @param s String to output
 * @param fd File descriptor to write to
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief Outputs an integer to a file descriptor
 *
 * Writes the integer n to the given file descriptor fd.
 * 
 * @param n Integer to output
 * @param fd File descriptor to write to
 */
void	ft_putnbr_fd(int n, int fd);

/**
 * @brief Outputs a string to a file descriptor
 *
 * Writes the string s to the given file descriptor fd.
 * 
 * @param s String to output
 * @param fd File descriptor to write to
 */
void	ft_putstr_fd(char *s, int fd);

//./string

/**
 * @brief Splits a string using a character as delimiter
 *
 * Allocates and returns an array of strings obtained by splitting s using c
 * as a delimiter. The array is NULL-terminated.
 * 
 * @param s String to be split
 * @param c Delimiter character
 * @return Array of resulting strings, or NULL if allocation fails
 */
char	**ft_split(char const *s, char c);

/**
 * @brief Locates a character in a string (strchr replacement)
 *
 * Locates the first occurrence of c in the string s.
 * 
 * @param s String to search
 * @param c Character to locate
 * @return Pointer to the located character, or NULL if not found
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Creates a duplicate of a string (strdup replacement)
 *
 * Allocates memory and creates a copy of string s.
 * 
 * @param s String to duplicate
 * @return Pointer to the duplicated string, or NULL if allocation fails
 */
char	*ft_strdup(const char *s);

/**
 * @brief Applies a function to each character of a string with its index
 *
 * Applies function f to each character of string str, passing its index
 * and address as arguments.
 * 
 * @param str String to iterate through
 * @param f Function to apply to each character
 */
void	ft_striteri(char *str, void (*f)(unsigned int, char*));

/**
 * @brief Concatenates two strings (strjoin replacement)
 *
 * Allocates memory and returns a new string which is the result of
 * concatenating s1 and s2.
 * 
 * @param s1 First string
 * @param s2 Second string
 * @return New concatenated string, or NULL if allocation fails
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Appends a string to a sized buffer (strlcat replacement)
 *
 * Appends the NUL-terminated string source to the string dest, but
 * for at most destsz-strlen(dest)-1 bytes, NUL-terminating the result.
 * 
 * @param dest Destination string buffer
 * @param source Source string
 * @param destsz Size of destination buffer
 * @return Total length of the string tried to create
 */
size_t	ft_strlcat(char *dest, const char *source, size_t destsz);

/**
 * @brief Copies a string to a sized buffer (strlcpy replacement)
 *
 * Copies up to size-1 characters from the NUL-terminated string src to dst,
 * NUL-terminating the result.
 * 
 * @param dst Destination buffer
 * @param src Source string
 * @param size Size of destination buffer
 * @return Length of the source string
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * @brief Calculates the length of a string (strlen replacement)
 *
 * Computes the length of the string str up to, but not including
 * the terminating null character.
 * 
 * @param str String to measure
 * @return Number of characters in the string
 */
size_t	ft_strlen(const char *str);

/**
 * @brief Maps a function to each character of a string
 *
 * Applies function f to each character of string s, creating a new string
 * with the results.
 * 
 * @param s String to map
 * @param f Function to apply to each character
 * @return New string with the results, or NULL if allocation fails
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Compares two strings (strcmp replacement)
 *
 * Compares the strings s1 and s2 lexicographically.
 * 
 * @param s1 First string
 * @param s2 Second string
 * @return <0 if s1<s2, 0 if s1=s2, >0 if s1>s2
 */
int		ft_strcmp(const char *s1, const char *s2);

/**
 * @brief Compares two strings (strncmp replacement)
 *
 * Compares the first n characters of strings s1 and s2.
 * 
 * @param s1 First string
 * @param s2 Second string
 * @param n Maximum number of characters to compare
 * @return <0 if s1<s2, 0 if s1=s2, >0 if s1>s2
 */
int		ft_strncmp(char *s1, char *s2, int n);

/**
 * @brief Locates a substring in a string (strnstr replacement)
 *
 * Locates the first occurrence of the null-terminated string needle in the
 * string haystack, where not more than len characters are searched.
 * 
 * @param haystack String to search in
 * @param needle String to search for
 * @param len Maximum number of characters to search
 * @return Pointer to the found string, or NULL if not found
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/**
 * @brief Locates the last occurrence of a character in a string 
 * (strrchr replacement)
 *
 * Locates the last occurrence of c in the string s.
 * 
 * @param s String to search
 * @param c Character to locate
 * @return Pointer to the located character, or NULL if not found
 */
char	*ft_strrchr(const char *s, int c);

/**
 * @brief Trims specified characters from the beginning and end of a string
 *
 * Allocates memory and returns a copy of s1 with the characters in set
 * removed from the beginning and end of the string.
 * 
 * @param s1 String to trim
 * @param set Characters to remove
 * @return New trimmed string, or NULL if allocation fails
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Creates a substring from a string
 *
 * Allocates memory and returns a substring from string s starting at
 * index start and of maximum size len.
 * 
 * @param s Source string
 * @param start Starting index
 * @param len Maximum length of substring
 * @return New substring, or NULL if allocation fails
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

//./bonus

/**
 * @brief Creates a new list element
 *
 * Allocates memory and creates a new list element with the given content.
 * 
 * @param content Content for the new element
 * @return The new element, or NULL if allocation fails
 */
t_list	*ft_lstnew(void *content);

/**
 * @brief Adds an element at the beginning of a list
 *
 * Adds the element 'new' at the beginning of the list 'lst'.
 * 
 * @param lst Address of a pointer to the first element
 * @param new Element to add
 */
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Counts the elements in a list
 *
 * Counts the number of elements in a list.
 * 
 * @param lst First element of the list
 * @return The number of elements
 */
int		ft_lstsize(t_list *lst);

/**
 * @brief Returns the last element of a list
 *
 * Returns the last element of the list 'lst'.
 * 
 * @param lst First element of the list
 * @return The last element
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief Adds an element at the end of a list
 *
 * Adds the element 'new' at the end of the list 'lst'.
 * 
 * @param lst Address of a pointer to the first element
 * @param new Element to add
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Deletes a single element from a list
 *
 * Takes an element and frees its content using the function 'del'.
 * The memory of the element is then freed.
 * 
 * @param lst Element to free
 * @param del Function to delete the content
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*));

/**
 * @brief Deletes and frees a list
 *
 * Deletes and frees all elements in the list 'lst' using the function 'del'.
 * The pointer to the list is set to NULL.
 * 
 * @param lst Address of a pointer to the first element
 * @param del Function to delete the content
 */
void	ft_lstclear(t_list **lst, void (*del)(void*));

/**
 * @brief Applies a function to each element of a list
 *
 * Iterates the list 'lst' and applies the function 'f' to the content of
 * each element.
 * 
 * @param lst First element of the list
 * @param f Function to apply
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Creates a new list by mapping a function to each element
 *
 * Iterates the list 'lst' and applies the function 'f' to the content of
 * each element. Creates a new list with the results. The 'del' function
 * is used to delete the content of an element if needed.
 * 
 * @param lst First element of the list
 * @param f Function to apply
 * @param del Function to delete content if needed
 * @return The new list, or NULL if allocation fails
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif