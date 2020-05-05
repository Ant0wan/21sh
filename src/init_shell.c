/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:32:23 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/05 19:11:29 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_errno.h"
#include "shell.h"
#include "error.h"
#include "builtins.h"

pid_t			g_shell_pgid;
struct termios	shell_tmodes;
int				g_shell_terminal;
int				g_shell_is_interactive;
int				g_job_control_enabled = ON;
int				g_retval;
char			g_pwd[] = {0};

static void	get_progname(char *av)
{
	if (!ft_strncmp("./", av, 2))
		g_progname = &av[2];
	else
		g_progname = av;
}

static int	init_shell_suite(void)
{
	extern char	**environ;

	if (!(environ = ft_tabcpy(environ)))
	{
		psherror(e_cannot_allocate_memory, g_progname, e_cmd_type);
		return (1);
	}
	init_hash_table();
	g_retval = e_success;
	if ((g_retval = set_minimal_env()))
	{
		psherror(g_retval, g_progname, e_cmd_type);
		ft_tabdel(&environ);
		return (1);
	}
	get_env_list(environ);
	init_history();
	load_config();
	return (0);
}

int			init_shell(char *argv, int argc)
{
	(void)argc;
	get_progname(argv);
	g_shell_terminal = STDIN_FILENO;
	g_shell_is_interactive = isatty(g_shell_terminal);
	if (g_shell_is_interactive)
	{
		while (tcgetpgrp(g_shell_terminal) != (g_shell_pgid = getpgrp()))
			kill(-g_shell_pgid, SIGTTIN);
		init_shell_sset();
		g_shell_pgid = getpid();
		if (setpgid(g_shell_pgid, g_shell_pgid) < 0)
		{
			ft_perror("Couldn't put the shell in its own process group");
			return (1);
		}
		tcsetpgrp(g_shell_terminal, g_shell_pgid);
		tcgetattr(g_shell_terminal, &shell_tmodes);
	}
	if (init_shell_suite())
		return (1);
	return (0);
}

void		set_minimal_env2(char **tmp)
{
	if (PATH_MAX > 0)
	{
		*tmp = ft_getenv("PWD");
		if (ft_strlen(*tmp) <= PATH_MAX)
			ft_strcpy(g_pwd, ft_getenv("PWD"));
	}
}

int			set_minimal_env(void)
{
	char	*tmp;
	int		shlvl;

	tmp = getcwd(NULL, 0);
	if (ft_setenv("PWD", tmp, 1))
		return (e_cannot_allocate_memory);
	ft_memdel((void**)&tmp);
	if (!(tmp = ft_getenv("SHLVL")))
	{
		if (ft_setenv("SHLVL", "1", 1))
			return (e_cannot_allocate_memory);
	}
	else
	{
		shlvl = ft_atoi(tmp) + 1;
		tmp = ft_itoa(shlvl);
		if (ft_setenv("SHLVL", tmp, 1))
			return (e_cannot_allocate_memory);
		ft_memdel((void**)&tmp);
	}
	set_minimal_env2(&tmp);
	return (e_success);
}
