/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_match.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 23:09:36 by frmarinh          #+#    #+#             */
/*   Updated: 2015/12/21 03:38:22 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	print_all_match(int *all_match)
{
	int i;
	int match_tmp;

	i = 0;
	match_tmp = 0;
	while (all_match[i])
	{
		match_tmp = all_match[i];
		while (match_tmp != 0)
		{
			if (all_match[i] > 1)
				ft_putchar('|');
			match_tmp--;
		}
		if (all_match[i] > 1)
			ft_putchar('\n');
		i++;
	}
}

int		read_player_entry(int match, int nbr)
{
	char	*buffer;
	int		fd;

	fd = STDIN_FILENO;
	buffer = ft_strnew(BUFF_SIZE_ENTRY);
	while (1)
	{
		read(fd, buffer, BUFF_SIZE_ENTRY);
		nbr = ft_atoi(buffer);
		if (nbr > 0 && nbr <= 3)
		{
			if (nbr > match)
				ft_putstr(WORD_PERROR_2);
			else
			{
				match = match - nbr;
				break ;
			}
		}
		else
			ft_putstr(WORD_PERROR_1);
		ft_bzero(buffer, 16);
	}
	free(buffer);
	return (match);
}

void	print_winner_round(int turn)
{
	if (turn)
	{
		ft_putstr("YOU WON THIS ROUND, CONGRATULATIONS !\n");
		round_player++;
	}
	else
	{
		ft_putstr("You lose this round, get rekt noob.\n");
		round_ia++;
	}
}

int		play_match(int *all_match, int pos)
{
	int turn_to;
	int to_subtract;

	turn_to = 0;
	to_subtract = 0;
	while (all_match[pos] > 1)
	{
		if (!turn_to)
		{
			ft_putstr(WORD_PTURN);
			to_subtract = read_player_entry(all_match[pos], 0);
			turn_to = 1;
		}
		else if (turn_to == 1 && !(turn_to = 0))
		{
			to_subtract = ia_turn(all_match[pos]);
			ft_putstr(IA_TURN_START);
		}
		all_match[pos] = to_subtract;
		print_all_match(all_match);
		if (!turn_to)
			ft_putstr(IA_TURN_END);
	}
	print_winner_round(turn_to);
	return (all_match[pos]);
}

void	start_match(int *all_match, int i)
{
	round_player = 0;
	round_ia = 0;
	print_all_match(all_match);
	while (all_match[i])
	{
		while (all_match[i] > 1)
			all_match[i] = play_match(all_match, i);
		i--;
	}
	ft_putstr("------------------\n");
	print_winner(round_player, round_ia);
}
