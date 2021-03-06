/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:14:17 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/27 14:43:18 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "ft_readline.h"

void	kill_line(void)
{
	if (write(g_dis.fd, "^C", 2) < 0)
		(void)g_dis.fd;
	g_retval = SIGINT + 128;
	if (g_back)
		stack_delete(&g_back, del_stat_line);
	if (!g_dumb_term)
		place_cursor(g_line.len);
	ft_bzero(g_line.line, g_line.size_buf);
	g_line.len = 0;
	g_line.c_pos = 0;
	g_dis.start_line++;
	g_line.is_modified = 1;
	if (g_subprompt)
		g_input_break = 1;
	ft_putchar_fd('\n', g_dis.fd);
	if (!g_dumb_term)
		display_prompt();
}

void	rl_insert(int c)
{
	char s[1];

	s[0] = (char)c;
	insert_text(s, 1, 1);
}

void	cursor_l(void)
{
	if (g_line.c_pos > 0)
		g_line.c_pos--;
}

void	cursor_r(void)
{
	if (g_vim_mode && g_vim_cmd)
	{
		if (g_line.c_pos < g_line.len - 1)
			g_line.c_pos++;
		return ;
	}
	if (g_line.c_pos < g_line.len)
		g_line.c_pos++;
	else
		insert_hist_compl();
}

void	cursor_d(void)
{
	int	c_pos;
	int	v_pos;
	int	start_v_pos;
	int	start_c_pos;

	calc_dcursor(g_line.c_pos, &start_v_pos, &start_c_pos);
	calc_dcursor(g_line.len, &v_pos, &c_pos);
	if (start_v_pos == v_pos)
		return ;
	calc_dcursor(g_line.c_pos, &v_pos, &c_pos);
	while (g_line.c_pos < g_line.len && (start_v_pos == v_pos \
			|| c_pos < start_c_pos))
	{
		g_line.c_pos++;
		calc_dcursor(g_line.c_pos, &v_pos, &c_pos);
		if (v_pos - start_v_pos >= 2)
		{
			g_line.c_pos--;
			break ;
		}
	}
}
