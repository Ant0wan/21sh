/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:51:41 by abarthel          #+#    #+#             */
/*   Updated: 2020/05/22 14:16:54 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdarg.h>

enum								e_minishell_error
{
	e_success,
	e_heredoc_warning,
	e_invalid_input,
	e_no_builtin,
	e_bad_substitution,
	e_cannot_assign_list_to_array_member,
	e_ambiguous_redirect,
	e_bad_file_descriptor,
	e_no_job_control,
	e_redir_no_file,
	e_redir_directory,
	e_redir_denied,
	e_redir_symlink,
	e_syntax_error,
	e_unexpected_eof_2,
	e_filename_arg_required,
	e_cannot_allocate_memory,
	e_system_call_error,
	e_permission_denied,
	e_is_a_directory,
	e_too_many_lvl_symlink,
	e_command_not_found,
	e_no_such_file_or_directory,
	e_resource_tmp_unavailable,
	e_signal_interrupt,
	e_unexpected_eof_130
};

enum								e_error_message_types
{
	e_invalid_type,
	e_parsing_type,
	e_cmd_type
};

typedef enum e_minishell_error		t_error;

struct								s_error_desc
{
	int		code;
	char	*message;
};

extern const struct s_error_desc	g_errordesc[];
extern char							*g_progname;

int									psherror(int e_error, char *str, \
		int e_message_type);

int									pbierror(const char *err_fmt,
		...) __attribute__((format(printf,1,2)));

#endif
