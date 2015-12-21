/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 22:13:55 by frmarinh          #+#    #+#             */
/*   Updated: 2015/12/21 00:12:57 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int		check_char_nbrmatch(char *buffer, int i, int i_2)
{
	char *nbr;
	int nbr_match;

	nbr_match = 0;
	nbr = ft_strnew(16);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			nbr_match = ft_atoi(nbr);
			if (nbr_match < 2 || nbr_match > 10000)
				return (0);
			i_2 = 0;
			ft_bzero(nbr, 16);
		}
		if (!(ft_isdigit(buffer[i])) && buffer[i] != '\n')
			return (0);
		if (buffer[i] != '\n')
		{
			nbr[i_2] = buffer[i];
			i_2++;
		}
		i++;
	}
	free(nbr);
	return (1);
}

int 	get_match_nbr(char *buffer)
{
	int lines;
	int i;

	i = 0;
	lines = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			lines++;
		i++;
	}
	return (lines);
}

int		*get_nbr(char *buffer, int i, int i_2, int lines)
{
	int		*all_match;
	char *nbr;
	int nbr_match;

	nbr = ft_strnew(16);
	nbr_match = 0;
	all_match = (int *)malloc(sizeof(int) * get_match_nbr(buffer));
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			nbr_match = ft_atoi(nbr);
			all_match[lines] = nbr_match;
			i_2 = 0;
			ft_bzero(nbr, 16);
			lines++;
		}
		if (buffer[i] != '\n')
		{
			nbr[i_2] = buffer[i];
			i_2++;
		}
		i++;
	}
	all_match[lines] = 0;
	return (all_match);
}

void	check_map(char *buffer)
{
	if (check_char_nbrmatch(buffer, 0, 0))
		start_match(get_nbr(buffer, 0, 0, 0), (get_match_nbr(buffer) - 1));
	else
		ft_putstr("ERROR\n");
}
