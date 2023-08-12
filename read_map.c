/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:29:52 by iszitoun          #+#    #+#             */
/*   Updated: 2023/08/02 18:30:01 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_read_str(int fd, char *str)
{
	char	*buff;
	int		bsread;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bsread = 1;
	while (bsread != 0)
	{
		bsread = read(fd, buff, BUFFER_SIZE);
		if (bsread == -1)
		{
			free(str);
			free(buff);
			return (NULL);
		}
		buff[bsread] = '\0';
		str = ft_strjoin1(str, buff);
	}
	free(buff);
	return (str);
}