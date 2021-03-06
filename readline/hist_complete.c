/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_complete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <snunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 12:12:38 by snunes            #+#    #+#             */
/*   Updated: 2020/05/27 14:41:44 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void		insert_hist_compl(void)
{
	char			*hist_compl;
	unsigned int	offset_save;

	if (g_dumb_term)
		return ;
	if (!g_line.c_pos || !g_hist.total_lines)
		return ;
	offset_save = g_hist.offset;
	hist_compl = g_hist.history_content + g_hist.offset;
	hist_compl = get_beg_matching_hist(&hist_compl, g_line.line);
	if (hist_compl)
	{
		insert_text(hist_compl + g_line.c_pos, ft_strlen(hist_compl + \
					g_line.c_pos), 1);
	}
	while (g_hist.offset < offset_save)
		next_hist();
}

static void	print_range(char *compl)
{
	int	v_pos;
	int	c_pos;
	int	track;
	int	len;

	len = ft_strlen(compl);
	calc_dcursor(g_line.len, &v_pos, &c_pos);
	v_pos = 0;
	track = 0;
	while (track < len)
	{
		if (c_pos == g_sc.w || compl[track] == '\n')
		{
			c_pos = 0;
			v_pos += 1;
		}
		else
			c_pos++;
		if (v_pos > g_sc.height - 1 && v_pos--)
			break ;
		track++;
	}
	if (write(g_dis.fd, compl, track) < 0)
		(void)g_dis.fd;
	if (g_dis.start_line + v_pos >= g_sc.height)
		g_dis.start_line -= g_dis.start_line + v_pos - g_sc.height + 1;
}

void		print_hist_compl(void)
{
	char			*hist_compl;
	unsigned int	offset_save;

	if (g_hist.total_lines == 0 || g_dumb_term || (g_vim_mode && g_vim_cmd))
		return ;
	offset_save = g_hist.offset;
	hist_compl = g_hist.history_content + g_hist.offset + 1;
	hist_compl = get_beg_matching_hist(&hist_compl, g_line.line);
	if (hist_compl)
	{
		place_cursor(g_line.len);
		ft_putstr_fd(HIST_COMPL_COLOR, g_dis.fd);
		print_range(hist_compl + g_line.len);
		ft_putstr_fd(END_OF_COLOR, g_dis.fd);
		place_cursor(g_line.c_pos);
	}
	while (g_hist.offset < offset_save)
		next_hist();
}

void		remove_completion(void)
{
	if (g_dumb_term)
		return ;
	place_cursor(g_line.len);
	ft_putstr_fd(g_termcaps.clreol, g_dis.fd);
}
