/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:23:58 by minseok2          #+#    #+#             */
/*   Updated: 2022/07/15 11:11:22 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_length;
	size_t	src_length;
	size_t	i;

	dst_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	if (dstsize <= dst_length)
		return (dstsize + src_length);
	i = dst_length;
	while (*src && i < dstsize - 1)
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (dst_length + src_length);
}
