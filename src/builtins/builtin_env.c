/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 18:17:17 by yforeau           #+#    #+#             */
/*   Updated: 2020/05/21 10:19:10 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell.h"
#include "builtins.h"

static int	exec_env_command(char **argv)
{
	char	**envp;
	int		ret;
	pid_t	pid;

	ret = 0;
	envp = get_env_tab();
	argv = ft_tabcpy(argv);
	if (!(pid = fork()))
	{
		restore_procmask();
		if (argv)
			ret = execute_env_process(argv, envp, NULL, NULL);
		exit_clean(ret);
	}
	else if (pid < 0)
		ft_dprintf(STDERR_FILENO, "fork(2) failed\n");
	else if (pid)
		waitpid(pid, &ret, WUNTRACED);
	if (pid > 0 && WIFSTOPPED(ret))
		kill(pid, SIGKILL);
	ft_tabdel(&envp);
	ft_tabdel(&argv);
	return (pid < 0 ? 1 : WEXITSTATUS(ret));
}

static int	print_env_var(t_shell_var *svar)
{
	if ((svar->flag & EXPORT) && svar->value)
	{
		ft_printf("%s=%s\n", svar->name, svar->value);
		return (0);
	}
	return (1);
}

static int	get_env_opt(char *arg, int *end_opt)
{
	char	*ptr;

	ptr = arg + 1;
	while (*ptr == 'i')
		++ptr;
	if (!*ptr && ptr != arg + 1)
		empty_env(&g_env);
	else if (*ptr == '-' && ptr == arg + 1 && !ptr[1])
		*end_opt = 1;
	else
	{
		pbierror("%s: invalid option%c.", arg, ft_strlen(arg) == 2 ? 0 : 's');
		pbierror("usage: %s [name[=value] ...] [-i [command]]",
			g_builtin_name);
		return (2);
	}
	return (0);
}

static int	get_env_options_and_assignments(int *argc, char ***argv)
{
	int	ret;
	int	end_opt;

	ret = 0;
	end_opt = 0;
	while (**argv && !ret)
	{
		if (!end_opt && ***argv == '-')
			ret = get_env_opt(**argv, &end_opt);
		else if (is_valid_assignment(**argv))
			ret = set_temp_variable(**argv);
		else
			break ;
		--(*argc);
		++(*argv);
	}
	return (ret);
}

int			cmd_env(int argc, char **argv)
{
	int	ret;

	++argv;
	--argc;
	ret = 0;
	if (argc && (ret = get_env_options_and_assignments(&argc, &argv)))
		return (ret);
	if (!argc)
		print_shell_var(g_env, print_env_var);
	else
		ret = exec_env_command(argv);
	unset_temp_shell_variables();
	return (ret);
}
