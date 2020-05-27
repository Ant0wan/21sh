/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 13:37:02 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/27 14:43:43 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"
#include "shell.h"

void		rl_ctrl_mode(union u_buffer u)
{
	static int		mark = 0;
	union u_buffer	c;
	int				ret;

	c = read_key();
	if (c.value == u.value)
	{
		ret = g_line.c_pos;
		g_line.c_pos = mark;
		mark = ret;
	}
	else
		g_bad_seq = c;
}

void		rl_eot(void)
{
	if (g_line.len == 0)
	{
		if (g_subprompt)
		{
			g_input_break = 1;
			g_eof = 1;
			return ;
		}
		place_cursor(g_line.len);
		free(g_line.line);
		if (write(g_dis.fd, "\n", 1) < 0)
			(void)g_dis.fd;
		deprep_terminal();
		rl_clear_signals();
		exit_clean(0);
	}
	else
		rl_delete();
}
