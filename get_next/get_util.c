#include "get_next_line.h"

void    *ft_memset(void *s, int c, size_t n)
{
    unsigned char   *p;

    p = (unsigned char *)s;
    while (n--)
        *p++ = (unsigned char)c;
    return (s);
}

char *ft_strnew(size_t size)
{
    char *str = (char *)malloc(size + 1);
    if (!str)
        return (NULL);
    ft_memset(str, 0, size + 1);
    return (str);
}


size_t ft_strlen(const char *str) 
{
    size_t length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*str1;
	const unsigned char	*str2;

	if (n == 0 || (!dest && !src))
		return (dest);
	i = 0;
	str1 = (unsigned char *)dest;
	str2 = (const unsigned char *)src;
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	return (dest);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(s);
	dst = (char *)malloc((sizeof(char) * len) + 1);
	if (!dst)
		return (0);
	ft_memcpy(dst, s, len);
	dst[len] = '\0';
	return (dst);
}
char *ft_strcpy(char *dest, const char *src) 
{
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; 
    return dest;
}


char	*ft_strjoin_free(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}

