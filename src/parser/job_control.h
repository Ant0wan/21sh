#ifndef JOB_CONTROL_H
# define JOB_CONTROL_H

# include <sys/types.h>
# include <termios.h>

/* A process is a single process.  */
struct s_process
{
  struct s_process	*next;       /* next process in pipeline */
  char			**argv;      /* for exec */
  pid_t			pid;         /* process ID, given at fork time in job.c,
						uses waitpid (waitpid is not called when & at end of job) */
  char			completed;   /* true if process has completed */
  char			stopped;     /* true if process has stopped */
  int			status;      /* reported status value */
};

/* A job is a pipeline of processes.  */
struct s_job
{
  struct s_job		*next;          /* next active job */
  char			*command;       /* command line, used for messages */
  struct s_process	*first_process; /* list of processes in this job */
  pid_t			pgid;           /* process group ID */
  char			notified;       /* true if user told about stopped job */
  struct termios	tmodes;         /* saved terminal modes */
  int			stdin;          /* standard i/o channels */
  int			stdout;         /* standard i/o channels */
  int			stderr;         /* standard i/o channels */
};

typedef struct s_process	t_process;
typedef struct s_job		t_job;

/* The active jobs are linked into a list. This is its head. */
extern t_job	*first_job;

#endif
