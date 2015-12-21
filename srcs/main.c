/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 20:10:48 by frmarinh          #+#    #+#             */
/*   Updated: 2015/12/21 03:32:12 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

char	*add_in_tmp(char *tmp, char *toadd, int i, int res)
{
	int		len;
	char	*tmp_2;
	int		i_2;

	i_2 = 0;
	len = ft_strlen(tmp);
	tmp_2 = ft_strnew(len);
	while (tmp[i])
	{
		if (ft_isdigit(tmp[i]) || tmp[i] == '\n')
		{
			tmp_2[i_2] = tmp[i];
			i_2++;
		}
		i++;
	}
	tmp_2[i_2] = '\0';
	tmp = ft_strnew((len + ft_strlen(toadd)));
	tmp = ft_strcat(tmp, tmp_2);
	tmp = ft_strncat(tmp, toadd, res);
	free(tmp_2);
	return (tmp);
}

void	read_entry(void)
{
	int		fd;
	char	*buffer;
	int		res;
	char	*map;

	buffer = ft_strnew(BUFF_SIZE_FILE);
	if (!buffer)
		ft_putstr("ERROR\n");
	else
	{
		fd = STDIN_FILENO;
		while ((res = read(fd, buffer, BUFF_SIZE_ENTRY)))
		{
			if (buffer[0] == '\n')
				break ;
			map = add_in_tmp(map, buffer, 0, res);
		}
		check_map(map);
	}
}

void	read_file(char *file_name)
{
	int		fd;
	char	*buffer;
	int		res;

	buffer = ft_strnew(BUFF_SIZE_FILE);
	if (!buffer)
		ft_putstr("ERROR\n");
	else
	{
		fd = open(file_name, O_RDONLY);
		if (fd != -1)
		{
			while ((res = read(fd, buffer, BUFF_SIZE_FILE)))
				;
			check_map(buffer);
		}
		else
			ft_putstr("ERROR\n");
	}
}

int		main(int argc, char **argv)
{
	if (argc != 1)
	{
		if (argc != 2)
			ft_putstr("ERROR\n");
		else
			read_file(argv[1]);
	}
	else
		read_entry();
	return (1);
}
