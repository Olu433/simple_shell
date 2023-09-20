/**
 * _strncmp - Compares n bytes in str1 and str2
 * @str1: First string to be compared
 * @str2: Second string to be compared
 * @n: Number of bytes to be checked
 *
 * Return: > 0 if str2 is less than str1, < 0 if str1 < str2,
 * 0 if str1 is equal to str2
 */
int _strncmp(char *str1, char *str2, int n)
{
    if (n <= 0)
        return 0;  // If n is non-positive, the strings are considered equal

    // Loop through the strings
    while (*str1 != '\0' && *str2 != '\0' && n > 0)
    {
        if (*str1 != *str2)
            return (*str1 - *str2);  // Compare characters and return the difference
        str1++;
        str2++;
        n--;
    }

    // If we reach here, either we reached the end of one or both strings
    if (n == 0)
        return 0;  // Strings match up to n characters

    if (*str1 != '\0')
        return 1;  // str2 is shorter

    if (*str2 != '\0')
        return -1;  // str1 is shorter

    return 0;  // Both strings are equal
}

