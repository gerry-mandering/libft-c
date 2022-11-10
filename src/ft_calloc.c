/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:34:32 by minseok2          #+#    #+#             */
/*   Updated: 2022/07/12 19:12:53 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	if (size != 0 && count > (SIZE_MAX - 8192) / size)
		return (NULL);
	ptr = (unsigned char *)malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		*(ptr + i) = 0;
		i++;
	}
	return (ptr);
}
