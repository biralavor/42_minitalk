# 42_minitalk
WIP - IPC (inter-process communication) between 'server' and 'client' process project at 42school.

It's about SIGNALS in UNIX ;)
The communication between the client and server has to be done only using UNIX signals.
In this project, it's only allowed two signals: SIGUSR1 and SIGUSR2.

The SIGUSR1 and SIGUSR2 signals are set aside for you to use any way you want. They’re useful for simple interprocess communication, if you write a signal handler for them in the program that receives the signal. (source: https://www.gnu.org/software/libc/manual/2.34/html_node/Standard-Signals.html)

# Basic knowledge
**Signals** inform processes of asynchronous events. Signals it's a short message sent to a process, or group of processes, containing a number identifying the signal. It's similar a event listner in Java (a.k.a. signal handler).
The Kernel determines the signal type. **Kernel** is the core interface between the harware and its processes, making a bridge communication, and managing resources as efficientle as possible.
_No data is delivered with traditional signals._
## Signal classification:
  - Process termination
    -  exit process
    -  child parameter death
  - Process induced exceptions
    -  outside virtual address was accessed
    -  write on a read-only memory
    -  hardware error or priviledge instruction execution
  - Unrecoverable conditions, during a system call
    -  running out of system resource
  - Tracing a process execution
  - Unexpected error condition
    -  nonexisting system call
    -  writing a pipe that has no reader process
    -  illegal reference value for the lseek system call
  - User mode process
    -  signal alarm after a time
    -  arbritary signals to each other to kill a system call
  - Terminal interaction
    -  hangs up terminal
    -  press 'break' or 'delete' keys on terminal
  - Kernel checks recipe
    -  when process is about to return from user mode kernel
    -  when it enters of leaves the sleep state mode

  //// (signal name || default handler action || description)
  - 1# SIGHUP || Terminate || to block 
  - 2# SIGINT || Terminate || to INTerrupt a terminal process with ^C (ctrl+c)
  - 3# SIGQUIT || Terminate || QUIT a process (ctrl+d)
  - 5# SIGTRAP || Core || to debbug a program with trace/breakpoints
  - 8# SIGFPE || Core || Arithmetic error
  - 9# SIGKILL || Terminate || lethal signal, and cannot be caught or ignored
  - 11# SIGSEGV || Core || invalid memory reference (seg fault?)
  - 14# SIGALRM || Terminate || Expiry of alarm clock timer
  - 15# SIGTERM || Terminate || A polite "please cleanup && TERMinate" signal (like shutdown a system)
  - 17# SIGCHLD || Ignore || Child process has terminated
  - ??# SIG_DFL || Reset || Modify the signal to the default action


## Sending && Handling Signals - Use Cases
  - Process_ID + Signal Number (or symbolic constant like SIGTERM)

**Signal handler (int signum)** is a function invoked to response to a given signal, ex.:
```
\\ implement signal handler
signal(SIGINT, signal_callback_handler);

void  signal_callback_handler(int signum)
{
  ft_printf("Cautght signal %d\n", signum);
  exit(signum);
}
```
**Signal system calls headers**
```
#include <sys/signal.h>    // for signals
#include <stdlib.h>        // for exit
#include <unistd.h>        // for sleep
#include <string.h>        // for memset

struct sigaction {
	void		(*sa_handler)(int);
	void		(*sa_sigaction)(int, siginfo_t *, void *);
	sigset_t	sa_mask;
	int			sa_flags;
	void		(*sa_restorer)(void);
};

// Must always initialize the signal set first, by calling sigemptyset() or sigfillset()
```
**Signal system calls 1# case**

Here I'm using sigaction(2) (source: https://man7.org/linux/man-pages/man2/sigaction.2.html)
```
void	cleanup (int signum)
{
	printf("Caugth the signal number: %d\n", signum);
	printf("Doing program clean-up and exiting...\n");
	exit(-1);
}
void	handle_sigtstp(int sig)
{
	printf("\nNOT TODAY, haha\n");
}

int	main (int argc, char **argv)
{
	struct sigaction	sigact;					// signal action structure
	char	*client_char;

	client_char = NULL;
	memset((void *)&sigact, 0, sizeof(sigact));	// zero memory for sigact struct
	// sigact.sa_handler = cleanup;				// set signal handler function
	sigact.sa_handler = &handle_sigtstp;		// another set signal handler function
	sigact.sa_flags = SA_RESTART;

	if (argc == 2)
	{
		client_char = argv[1];
		sigaction(SIGTSTP, &sigact, NULL);
		// SIGTSTP = to avoid terminate with 'Ctrl+Z' signal
		// in this case, the 3rd param will be NULL because I don't have another
		// sigaction to use the actual result in that sigaction
		while (1)
		{
			printf("client char = %s -> pid[%d}\n", client_char, getpid());
			sleep(1);
		}
		return (0);
	}
	else
	{
		printf("Usage: ./a.out [char]\n");
		return (-1);
	}
	return(0);
}
```
**Signal system calls 2# case**

Here I'm using signal function, which reproduces the same behavior of sigaction.

However, as the manual signal(2) says: _the behaviour of signal() varies across UNIX versions, and has also vired historically across different version of Lunix. AVOID ITS USE. Use sigcation(2) instead._
```
int	x = 100;	// global variable, just for this example ^.^

void signal_handler01(int signum)
{
	x +=10;
	ft_printf("#1 task :: x =%d\n", x);
}

void signal_handler02(int signum)
{
	x +=200;
	ft_printf("#2 task :: x =%d\n", x);
}

void signal_handler03(int signum)
{
	x +=3000;
	ft_printf("#3 task :: x =%d\n", x);
}

int	main(void)
{
	pid_t pid;
	signal(SIGINT, signal_handler01);	// task to perform = signal_handler01
	signal(SIGUSR1, sinal_handler02);	// task to perform = signal_handler02
	signal(SIGUSR3, sinal_handler03);	// task to perform = signal_handler03
	pid = fork();
	if (pid == 0)
	{
		pid_t parent = getpid();
		kill(parent, SIGINT);
		sleep(1);
		kill(parent, SIGUSR1);
		sleep(1);
		kill(parent, SIGUSR2);
		sleep(1);
		ft_printf("Child fork says x = %d\n", x);
		return (0);
	}
	else
	{
		int stat;
		wait(&stat);
	}
```

## Socket
- a socket is identified by an IP address concatenated with a port number (like-> 192.168.0.1:1625)
- the server waits for incomming client request by listening to a specified port. Once a request is received, the server accepts a conncetion from the client socket to complete the connection
- all ports below 1024 are considered well know, and already reserved. This means that there are ports for specific standard services like: telnet(23), ftp(23), http(80) and so on...
- every IPC process should have a client socket AND a server socket


