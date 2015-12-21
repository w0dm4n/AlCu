/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 20:12:25 by frmarinh          #+#    #+#             */
/*   Updated: 2015/12/19 20:13:21 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H
#include "libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
# define BUFF_SIZE_FILE 512
# define BUFF_SIZE_ENTRY 16
void		check_map(char *buffer);
void		start_match(int *all_match, int i);
int 		ia_turn(int match);
void		print_winner(int round_player, int round_ia);
# define WORD_PTURN "It's your turn to play, enter a number between 1-3 !\n"
# define WORD_PERROR_1 "You need to insert a number between 1-3 !\n"
# define WORD_PERROR_2 "You can't set this number, try again with a smaller !\n"
# define IA_TURN_END "IA turn is ended !\n"
# define IA_TURN_START "It's now IA turn !\n"
static int round_player;
static int round_ia;
#endif