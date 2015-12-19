/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 20:10:48 by frmarinh          #+#    #+#             */
/*   Updated: 2015/12/19 21:17:56 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	read_entry(void)
{
	int fd;
	char *buffer;
	int res;

	buffer = ft_strnew((BUFF_SIZE * 20));
	if (!buffer)
	{
		ft_putstr("ERROR\n");
		exit(-1);
	}
	fd = STDIN_FILENO;
	while ((res = read(fd, buffer, BUFF_SIZE)))
	{
		if (buffer[0] == '\n')
			break ;
	}
}

void	read_file(char *file_name)
{
	int fd;
	char *buffer;
	int res;

	buffer = ft_strnew((BUFF_SIZE * 20));
	if (!buffer)
	{
		ft_putstr("ERROR\n");
		exit(-1);
	}
	fd = open(file_name, O_RDONLY);
	if (fd != -1)
	{
		while ((res = read(fd, buffer, BUFF_SIZE)))
			;
		ft_putstr(buffer);
	}
	else
		ft_putstr("ERROR\n");
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
