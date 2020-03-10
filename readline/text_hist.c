#include "ft_readline.h"

void hist_lookup(void)
{
	char buf[10000];
	char *tmp;
	char *prompt;
	union u_buffer c;
	int i;

	tmp = g_line.line;
	i = 0;
	c.value = 1;
	ft_bzero(buf, 10000);
	prompt = ft_strdup(g_dis.prompt);
	set_prompt("(reverse-i-search)");
	while (ft_isprint(buf[i]) || !buf[i])
	{
		ft_putstr(tgoto(g_termcaps.ch, 0, 0));
		ft_putstr(g_dis.prompt);
		ft_putstr(tgoto(g_termcaps.clreol, 0, 0));
		ft_printf("`%s': %s", buf, tmp);
		c = read_key();
		if (c.value == 127 && i > 0)
			i--;
		if (test_c_value(c))
			break ;
		if (i >= 0)
			buf[i] = (c.value == 127) ? '\0' : c.value;
		if (c.value != 127)
			i++;
		if (c.value != 127 && !(get_matching_hist(&tmp, buf)))
			set_prompt("(failed reverse-i-search)");
		else if (ft_strequ(g_dis.prompt, "(failed reverse-i-search)"))
			set_prompt("(reverse-i-search)");
	}
	g_hist_lookup_value = c.value;
	set_prompt(prompt);
	free(prompt);
	if (i != 0 || tmp[0])
	{
		free(g_line.line);
		if (!(g_line.line = (char *)ft_memalloc(sizeof(char) * g_line.size_buf)))
			ft_printf("./21sh: cannot allocate memory\n");
		g_line.line = ft_memcpy(g_line.line, tmp, ft_strlen(tmp));
		g_line.len = ft_strlen(tmp);
		g_dis.cbpos = g_line.len;
	}
	update_line();
	return ;
}

char *get_matching_hist(char **line, char *patern)
{
	char *tmp;


	tmp = *line;
	if (!tmp)
		return (tmp);
	while (!ft_strstr(tmp, patern) && g_hist->nb_line > 0)
		tmp = prev_hist();
	if (ft_strstr(tmp, patern))
		*line = tmp;
	else
	{
		while (!ft_strstr(tmp, *line)
	&& g_hist->nb_line < g_hist->total_lines)
			tmp = next_hist();
		*line = tmp;
		tmp = NULL;
	}
	return (tmp);
}

int test_c_value(union u_buffer c)
{
	if ((ft_isprint(c.value) && c.value != 9) || c.value == 127)
		return (0);
	if (enter_rc(c))
		return (1);
	if (isctrlkey(c))
		return (1);
	if (ismetachar(c))
		return (1);
	if (isstdkey(c.value))
		return (1);
	return (0);
}

void history_up(void)
{
	char *s;

	if (g_hist->offset == g_hist->used - 1)
	{
		if (g_original_cmd)
			free(g_original_cmd);
		if (!(g_original_cmd = ft_strdup(g_line.line)))
		{
			ft_printf("./21sh: cannot allocate mmemory\n");
			return ;
		}
	}
	s = prev_hist();
	clear_line();
	insert_text(s, ft_strlen(s));
}

void history_down(void)
{
	char *s;

	s = next_hist();
	clear_line();
	if (*s)
		insert_text(s, ft_strlen(s));
	else
		insert_text(g_original_cmd, ft_strlen(g_original_cmd));
}
