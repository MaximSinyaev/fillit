/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <aolen@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 11:37:47 by aolen             #+#    #+#             */
/*   Updated: 2019/09/16 19:17:19 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

/*
** Protected stlen whic checks pointer
*/

static size_t	ft_strlen_p(char *s)
{
	unsigned int len;

	len = 0;
	while (s && *(s + len))
		len++;
	return (len);
}

/*
** Function that clears all data written by malloc
*/

static int		del(char **tmp, char **file_line, char **line)
{
	ft_strdel(tmp);
	ft_strdel(file_line);
	ft_strdel(line);
	return (MEM_ERR);
}

/*
** Function than search for SEPARATOR and if found writes all symbol till
** SEPARATOR in (line) and check for remainder, if it exist writes it to
** static variable
*/

static int		function(char **tmp, char **file_line, int ret, char **line)
{
	int		i;
	size_t	len;
	int		error;

	i = 0;
	error = 0;
	ft_strdel(file_line);
	len = ft_strlen_p(*tmp);
	while ((*tmp)[i] != SEPARATOR && (size_t)i < len)
		i++;
	if ((*tmp)[i] == SEPARATOR)
	{
		(*tmp)[i] = 0;
		if (!(*line = ft_strdup(*tmp)))
			return (del(tmp, file_line, line));
		if ((i < ret - 1) || ((size_t)i < len - 1))
			if (!(*file_line = ft_strdup(&((*tmp)[i + 1]))))
				return (del(tmp, file_line, line));
		ft_strdel(tmp);
		return (1);
	}
	if (len && !(*file_line = ft_strdup(*tmp)))
		return (del(tmp, file_line, line));
	ft_strdel(tmp);
	return (0);
}

/*
** Function which return -1 on error, 1 if we wrote something in (line)
** and 0 if we have nothing to write in (line)
*/

static int		returning_function(int ret, char **file_line, char **line)
{
	if (ret < 0)
		return (-1);
	if (ret == 0)
	{
		if (*file_line)
		{
			if (!(*line = ft_strdup((*file_line))))
				return (del(NULL, file_line, line));
			ft_strdel(file_line);
			return (1);
		}
		return (0);
	}
	if (*line)
		return (1);
	return (0);
}

/*
** Main part of function in which we check if remainder exist and
** check it for SEPARATOR. If it is no reamainder for this file or
** no SEPARATOR in remainder we reading till find EOF or SEPARATOR
*/

int				get_next_line(const int fd, char **line)
{
	static char	*file_lines[MAX_FILES] = {0};
	int			ret;
	char		*tmp;
	char		str[BUFF_SIZE + 1];

	tmp = NULL;
	if (fd < 0 || !line)
		return (-1);
	if (file_lines[fd] && fd < MAX_FILES)
	{
		if (!(tmp = ft_strjoin(tmp, file_lines[fd])))
			return (del(&tmp, &file_lines[fd], line));
		else if ((ret = function(&tmp, &file_lines[fd], 0, line)) != 0)
			return (ret < 0 ? del(&tmp, &file_lines[fd], line) : 1);
	}
	while ((ret = read(fd, str, BUFF_SIZE)) > 0)
	{
		str[ret] = 0;
		if (!(tmp = ft_strjoin(file_lines[fd], str)))
			return (del(&tmp, &file_lines[fd], line));
		if ((str[BUFF_SIZE] = function(&tmp, &file_lines[fd], ret, line)) != 0)
			return (str[BUFF_SIZE] < 0 ? del(&tmp, &file_lines[fd], line) : 1);
	}
	ft_strdel(&tmp);
	return (returning_function(ret, &file_lines[fd], line));
}
