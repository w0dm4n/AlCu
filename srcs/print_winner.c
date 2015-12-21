/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_winner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 00:55:40 by frmarinh          #+#    #+#             */
/*   Updated: 2015/12/21 01:06:31 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	print_winner(int round_player, int round_ia)
{
	if (round_player > round_ia)
	{
		ft_putstr("You won the game with a score of ");
		ft_putnbr(round_player);
		ft_putstr(" against : ");
		ft_putnbr(round_ia);
	}
	else if (round_player < round_ia)
	{
		ft_putstr("You lose the game with a score of ");
		ft_putnbr(round_player);
		ft_putstr(" against ");
		ft_putnbr(round_ia);
	}
	else
	{
		ft_putstr("Equality with a score of ");
		ft_putnbr(round_player);
	}
	ft_putstr("\n");
}
