/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_shell_variables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 13:54:08 by abarthel          #+#    #+#             */
/*   Updated: 2020/04/16 16:05:11 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell.h"

static char	**tab_remove_first_elem(int *ac, char **av)
{
	char	**new_tab;
	int		i;

	i = 0;
	new_tab = NULL;
	if (*ac > 1)
	{
		new_tab = (char**)malloc(sizeof(char*) * *ac);
		if (new_tab == NULL)
			return (NULL);
		while (i + 1 < *ac)
		{
			new_tab[i] = ft_strdup(av[i + 1]);
			i++;
		}
		new_tab[i] = NULL;
	}
	ft_free_tab(*ac, &av);
	(*ac)--;
	return (new_tab);
}

static int	cmp_flags(uint64_t *flags, t_shell_var *svar)
{
	return ((svar->flag & *flags) != *flags);
}

void		unset_temp_shell_variables(void)
{
	uint64_t	flags;

	flags = TEMP;
	ft_lst_del_if(&g_env, (void *)&flags, del, cmp_flags);
	ft_lstaddend(&g_env, g_tmp_env);
	g_tmp_env = NULL;
	ft_merge_sort(&g_env, alpha_sort);
}

int			treat_shell_variables(t_process *p, uint64_t flags)
{
	t_list			*elem;
	char			*name;
	char			*value;

	if (!p->argv[0])
		return (0);
	while (p->argv != NULL && (value = is_valid_assignment(p->argv[0])))
	{
		name = ft_strndup(p->argv[0], value - p->argv[0]);
		value = ft_strdup(value + 1);
		elem = get_shell_var(name, g_env);
		if (!name || !value
			|| set_shell_var(elem, name, value, flags) == FAILURE)
			return (FAILURE);
		p->argv = tab_remove_first_elem(&p->argc, p->argv);
	}
	ft_merge_sort(&g_env, &alpha_sort);
	return (SUCCESS);
}
