#include "libft.h"
#include "error.h"
#include "shell.h"

/* Debugg */
static void	debug_r(t_redirection *r)
{
	static int	i;

	i = 0;
	ft_printf("\n");
//	while (r)
//	{
		ft_printf("\nUNDO redir:%d\n", i++);
		ft_printf("\tr->redirectee.dest: %d\n", r->redirectee.dest);
		ft_printf("\tr->save: %d\n", r->save);
		r = r->next;
//	}
//	ft_printf("\n");
}


static int	undo_iowrite(t_redirection *r)
{
	dup2(r->save, r->redirector.dest);
	close(r->save);
	return (0);
}

static int	undo_ioread(t_redirection *r)
{
	debug_r(r); /* Debug */
	/* Multiple close of STDIN are done */
	/* HERE IS THE HUGE BUG CLOSING STDIN multiple times, need fcntl to check ?*/
	dup2(r->save, r->redirectee.dest);
	close(r->save);
	return (0);
}

int	undo_redirection_internal(t_redirection *r)
{
	while (r)
	{
		if (r->done == 1)
		{
			if (r->instruction == IOWRITE)
				undo_iowrite(r);
			else if (r->instruction == IOCAT)
				undo_iowrite(r);
			else if (r->instruction == IOREAD)
				undo_ioread(r);
			else if (r->instruction == IODUP && !(r->flags & FDCLOSE))
				undo_iowrite(r);
			else if (r->instruction == (IODUP | IOREAD) && !(r->flags & FDCLOSE))
				undo_ioread(r);
		}
		r = r->next;
	}
	return (0);
}

int	undo_redirection(t_redirection *r)
{
	if (r)
	{
		undo_redirection_internal(r);
		/* should we free at that point ? */
		r = r->next;
	}
	return (0);
}
