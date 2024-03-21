/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <7353718@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:21:26 by smoreron          #+#    #+#             */
/*   Updated: 2024/03/21 04:19:11 by smoreron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	i;

	len_src = ft_strlen(src);
	if (dstsize < 1)
		return (len_src);
	i = 0;
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len_src);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(s1) + 1;
	copy = (char *)malloc(len);
	if (copy == NULL)
		return (NULL);
	ft_strlcpy(copy, s1, len);
	return (copy);
}

int	open_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		perror("Failed to open file");
	return (fd);
}

void	close_file(int fd)
{
	if (fd >= 0)
		close(fd);
}

char	**ft_allocate_map(int height)
{
	char	**map;

	map = (char **)malloc(sizeof(char *) * (height + 1));
	if (map == NULL)
		return (NULL);
	map[height] = NULL;
	return (map);
}
