#include "get_next_line.h"


char	*ft_returnline(char *remainder)
{
	char *str;
	int i;
	i = 0;
	if (!remainder[i])
	{
		return (NULL);
	}
	while ((remainder[i] != '\n') && (remainder[i] != '\0'))
		i++;
	str = ft_strnew((i+1));
	if(!str)
		return (NULL);
	i = 0;
	while ((remainder[i] != '\n') && (remainder[i] != '\0'))
	{
		str[i] = remainder[i];
		i++;
	}
	if (remainder[i] == '\n')
	{
		str[i] = remainder[i];
		str[i+1] = '\0';
	}
	return (str);
}

char	*ft_remainderline(char *remainder)
{
	char *str;
	//char *tmp;
	int i;
	int j;	
	i = 0;
	j = 0;
	//str = NULL;
	while (remainder[i] != '\0' && remainder[i] != '\n')
		i++;
	if(!remainder[i])
	{
		free(remainder);
		return (NULL);
	}
	str = ft_strnew((ft_strlen(remainder) - i + 1));
	if(!str)
		return (NULL);
	i++;
	while (remainder[i] != '\0')
		str[j++] = remainder[i++];
	str[j] = '\0';
	free(remainder);
	return str;	
}

char	*ft_newline(int fd, char *remainder)

{
	char *buffer;
	//char *str;
	int len;
	//int i;
	len = 1;
	//i = 0;
	buffer = ft_strnew(BUFFER_SIZE+1);
	if(!buffer)
		return(NULL);

	while (len != 0)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len	== -1)
		{
			free(buffer);
			
			return (NULL);
		}
		buffer[len] = '\0';
		remainder = ft_strjoin_free(remainder, buffer);
		if((ft_strchr(remainder, '\n')))
			len = 0;
	}
	free(buffer);
	return (remainder);
}


char	*get_next_line(int fd)
{
	static char * remainder = NULL;
	char * line;
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		free (remainder);
		remainder = NULL;
		return (NULL);
	}
	remainder = ft_newline(fd, remainder);
	line = ft_returnline(remainder);
	remainder = ft_remainderline(remainder);
	return (line);
}