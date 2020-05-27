/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <snunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 13:21:12 by snunes            #+#    #+#             */
/*   Updated: 2020/05/27 15:07:03 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static char	get_first_input(void)
{
	char	input;
	int		status;

	status = read(STDIN_FILENO, &input, 1);
	while (status > 0 && input != 27)
		status = read(STDIN_FILENO, &input, 1);
	return (input);
}

void		get_cursor_position(int *row, int *col)
{
	int		a;
	char	input[2];

	input[1] = 0;
	a = 0;
	*row = 0;
	*col = 0;
	if (write(g_dis.fd, "\033[6n", 4) < 0)
		(void)g_dis.fd;;
	input[0] = get_first_input();
	while (*input != 'R')
	{
		if (read(STDIN_FILENO, input, 1))
			(void)input;
		if (*input >= '0' && *input <= '9')
		{
			if (a == 0)
				*row = *row * 10 + ft_atoi(input);
			else
				*col = *col * 10 + ft_atoi(input);
		}
		a = (*input == ';') ? 1 : a;
	}
	*col -= (*col) ? 1 : 0;
	*row -= (*row) ? 1 : 0;
}
