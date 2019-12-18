/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 20:52:32 by abarthel          #+#    #+#             */
/*   Updated: 2019/12/18 15:55:23 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	parse_opt(int argc, t_process *p, _Bool *b)
{
	int	opt;

	*b = 0;
	g_opterr = 1;
	g_optind = RESET_OPTIND;
	while ((opt = ft_getopt(argc, p->argv, "+LP")) != -1)
	{
		if (opt == 'P')
			*b |= 1;
		else if (opt == '?')
		{
			ft_dprintf(p->errfile, "%1$s: usage: %1$s [-L|-P]\n", p->argv[0]);
			return (2);
		}
	}
	return (e_success);
}

int	cmd_pwd(int argc, t_process *p)
{
	char	*cwd;
	int	ret;
	_Bool	b;

	b = 0;
	ret = 0;
	g_optind = RESET_OPTIND;
	if ((ret = parse_opt(argc, p, &b)))
		return (ret);
	if (b)
	{
		cwd = getcwd(NULL, 0);
		if (!cwd)
			return (1);
		else
		{
			ft_dprintf(p->outfile, "%s\n", cwd);
			ft_memdel((void**)&cwd);
		}
	}
	else if (*g_pwd)
		ft_dprintf(p->outfile, "%s\n", g_pwd);
	else if	((cwd = ft_getenv("PWD")))
		ft_dprintf(p->outfile, "%s\n", cwd);
	else
	{
		cwd = getcwd(NULL, 0);
		if (!cwd)
			return (1);
		else
		{
			ft_dprintf(p->outfile, "%s\n", cwd);
			ft_memdel((void**)&cwd);
		}
	}
	return (0);
}
