/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 20:52:32 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/12 19:30:49 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "shell.h"
#include "builtins.h"

int	g_noexit = 0;
int	g_last_exit = 0;

static void		print_exit(int stopped_jobs)
{
	if (stopped_jobs)
		ft_dprintf(STDERR_FILENO, "\nThere are stopped jobs.\n");
	if (!g_noexit && g_shell_is_interactive)
		ft_dprintf(STDERR_FILENO, "exit\n");
}

static int		part_sep(int argc, char **argv)
{
	unsigned char	status;

	status = g_retval;
	if (!ft_strcmp("--", argv[1]))
	{
		if (argc == 2)
		{
			ft_tabdel(&argv);
			print_exit(0);
			exit_clean(status);
		}
		return (2);
	}
	return (1);
}

static int		numarg_exit(int argc, char **argv, int i, int s)
{
	print_exit(0);
	if (argc > i + 1)
	{
		pbierror("too many arguments");
		return (1);
	}
	ft_tabdel(&argv);
	return (exit_clean(s));
}

static void		nomatter_exit(char **argv, int i)
{
	print_exit(0);
	pbierror("%s: numeric argument required", argv[i]);
	ft_tabdel(&argv);
	exit_clean(2);
}

int				cmd_exit(int argc, char **argv)
{
	unsigned char	status;
	int				i;

	status = g_retval;
	update_status();
	if (g_job_control_enabled && are_stopped_jobs() && !g_last_exit)
	{
		print_exit(1);
		g_last_exit = 1;
		return (1);
	}
	if (argc > 1)
	{
		i = part_sep(argc, argv);
		status = ft_atol(argv[i]);
		if (g_errno == E_EINVAL)
			nomatter_exit(argv, i);
		else if (g_errno == E_EOVERFLOW)
			return (numarg_exit(argc, argv, i, ft_atoi(argv[i])));
		status = ft_atoi(argv[i]);
	}
	ft_tabdel(&argv);
	print_exit(0);
	return (exit_clean(status));
}
