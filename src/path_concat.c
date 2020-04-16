/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_concat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 13:03:13 by abarthel          #+#    #+#             */
/*   Updated: 2020/04/16 15:38:08 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell.h"
#include "error.h"

int	path_concat(char **bin, char *beg, char *env, char *dir)
{
	char	*pathname;

	if (!(beg = get_shell_var_value("PATH", g_env)))
	{
		ft_memdel((void**)bin);
		return (e_command_not_found);
	}
	env = ft_strdup(beg);
	beg = env;
	while ((dir = ft_strsep(&env, ":")))
	{
		pathname = ft_strnjoin(3, dir, "/", *bin);
		if (!access(pathname, F_OK))
			break ;
		ft_memdel((void**)&pathname);
	}
	ft_memdel((void**)&beg);
	ft_memdel((void**)bin);
	if (dir)
	{
		*bin = pathname;
		return (e_success);
	}
	return (e_command_not_found);
}
