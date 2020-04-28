/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vim_keymap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 13:35:56 by abarthel          #+#    #+#             */
/*   Updated: 2020/04/28 15:34:20 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

struct s_keymap_entry g_vim_standard_insert_keymap[] =
{
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, kill_line },
	{ ISFUNC, rl_eot },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, autocomplete },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, cut_prev_wd },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISKMAP, vim_escape },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_insert },
	{ ISFUNC, rl_backspace }
};

struct s_keymap_entry g_vim_ctlx_insert_keymap[] =
{
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_delete },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, history_up },
	{ ISFUNC, history_down },
	{ ISFUNC, cursor_r },
	{ ISFUNC, cursor_l },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_end },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_home },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, cursor_u },
	{ ISFUNC, cursor_d },
	{ ISFUNC, wd_right },
	{ ISFUNC, wd_left },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void }
};

struct s_keymap_entry g_vim_meta_insert_keymap[] =
{
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void }
};

struct s_keymap_entry g_vim_standard_cmd_keymap[] =
{
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, kill_line },
	{ ISFUNC, rl_eot },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, cursor_r },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, vim_hash },
	{ ISFUNC, rl_end },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_home },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, last_goto },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, insert_mode_last },
	{ ISFUNC, wd_left },
	{ ISFUNC, cmaj_motion },
	{ ISFUNC, dmaj_motion },
	{ ISFUNC, end_next_wd },
	{ ISFUNC, goto_chr_left },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, insert_mode_first },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, paste_all_r },
	{ ISFUNC, rl_void },
	{ ISFUNC, replace_mode },
	{ ISFUNC, clear_all_l },
	{ ISFUNC, goto_pchr_left },
	{ ISFUNC, undo_lastb },
	{ ISFUNC, rl_void },
	{ ISFUNC, beg_next_wd },
	{ ISFUNC, rl_backspace },
	{ ISFUNC, yank_eol },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_home },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, insert_mode_next },
	{ ISFUNC, beg_last_alnum },
	{ ISFUNC, c_motion },
	{ ISFUNC, d_motion },
	{ ISFUNC, end_next_alnum },
	{ ISFUNC, goto_chr_right },
	{ ISFUNC, rl_void },
	{ ISFUNC, cursor_l },
	{ ISFUNC, vim_insert },
	{ ISFUNC, history_down },
	{ ISFUNC, history_up },
	{ ISFUNC, cursor_r },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, paste_all_l },
	{ ISFUNC, rl_void },
	{ ISFUNC, replace_wd },
	{ ISFUNC, rl_void },
	{ ISFUNC, goto_pchr_right },
	{ ISFUNC, undo_last },
	{ ISFUNC, call_fc },
	{ ISFUNC, beg_next_alnum },
	{ ISFUNC, rl_delete },
	{ ISFUNC, yank_c },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_home },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void }
};

struct s_keymap_entry g_vim_ctlx_cmd_keymap[] =
{
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, history_up },
	{ ISFUNC, history_down },
	{ ISFUNC, cursor_r },
	{ ISFUNC, cursor_l },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_end },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_home },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, cursor_u },
	{ ISFUNC, cursor_d },
	{ ISFUNC, wd_right },
	{ ISFUNC, wd_left },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void }
};

struct s_keymap_entry g_vim_meta_cmd_keymap[] =
{
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void }
};
