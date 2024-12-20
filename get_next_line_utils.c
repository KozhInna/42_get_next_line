/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:55:18 by ikozhina          #+#    #+#             */
/*   Updated: 2024/12/20 10:26:53 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin_up_nl(char const *s1, char const *s2)
{
	char	*new_str;
	char	*ptr_newline;
	size_t	i;
	size_t	len_s2;

	i = 0;
	if (s1 == NULL)
		s1 = "";
	ptr_newline = ft_strchr(s2, '\n');
	if (ptr_newline)
		len_s2 = ptr_newline - s2 + 1;
	else
		len_s2 = ft_strlen(s2);
	new_str = malloc(ft_strlen(s1) + len_s2 + 1);
	if (new_str == NULL)
		return (NULL);
	while (*s1)
		new_str[i++] = *s1++;
	while (*s2 && (ptr_newline == NULL || s2 <= ptr_newline))
		new_str[i++] = *s2++;
	new_str[i] = '\0';
	return (new_str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (dest == src || n == 0)
		return (dest);
	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	i = 0;
	if (d > s)
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
