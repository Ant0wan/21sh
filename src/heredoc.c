#include "libft.h"
#include "shell.h"
#include "quotes.h"

static char	*return_heredoc(char *tmp, char *hereword)
{
	if (g_input_break && !g_eof)
	{
		free(tmp);
		free(hereword);
		return (NULL);
	}
	if (!tmp && g_shell_is_interactive)
	{
		free(hereword);
		return (NULL);
	}
	free(tmp);
	return (hereword);
}

static int	get_heredoc_qmode(char **eof, int qmode)
{
	qmode = ft_strchr(*eof, '"') || ft_strchr(*eof, '\'') ? NO_QUOTE : qmode;
	rm_quotes(eof, NO_QUOTE);
	return (qmode);
}

char		*heredoc(int fd, char **eof, int qmode)
{
	char	*tmp;
	char	*hereword;
	char	*line;

	qmode = get_heredoc_qmode(eof, qmode);
	tmp = NULL;
	line = NULL;
	hereword = ft_strdup("");
	tmp = get_input_fd(fd, qmode, "> ");
	while (tmp && ft_strcmp(*eof, tmp) && !g_input_break)
	{
		line = ft_strjoin(tmp, "\n");
		free(tmp);
		tmp = ft_strjoin(hereword, line);
		free(hereword);
		free(line);
		hereword = tmp;
		tmp = get_input_fd(fd, qmode, "> ");
		if (!tmp && !g_shell_is_interactive)
			g_eof = 1;
	}
	add_hentry(hereword, ft_strlen(hereword));
	if (qmode)
		treat_single_exp(&hereword, 0, NULL);
	return (return_heredoc(tmp, hereword));
}
