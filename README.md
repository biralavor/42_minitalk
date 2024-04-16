# 42_minitalk
WIP - IPC (inter-process communication) between 'server' and 'client' process project at 42school.

It's about SIGNALS in UNIX ;)
The communication between the client and server has to be done only using UNIX signals.
In this project, it's only allowed two signals: SIGUSR1 and SIGUSR2.

### Basic knowledge
**Signals** inform processes of asynchronous events. Signals it's a short message sent to a process, or group of processes, containing a number identifying the signal. It's similar a event listner in Java (a.k.a. signal handler).
The Kernel determines the signal type. **Kernel** is the core interface between the harware and its processes, making a bridge communication, and managing resources as efficientle as possible.
_No data is delivered with traditional signals._
- Signal classification:
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
  - 2# SIGINT || Terminate || to kill a terminal process with ^C (ctrl+c)
  - 5# SIGTRAP || Core || to debbug a program with trace/breakpoints
  - 8# SIGFPE || Core || Arithmetic error
  - 9# SIGKILL || Terminate || lethal signal, and cannot be caught or ignored
  - 11# SIGSEGV || Core || invalid memory reference (seg fault?)
  - 14# SIGALRM || Terminate || Expiry of alarm clock timer
  - 15# SIGTERM || Terminate || A polite "please cleanup && terminate" signal (like shutdown a system)
  - 17# SIGCHLD || Ignore || Child process has terminated

**Sending Signals**
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

// Must always initialize the signal set first, by calling sigemptyset() or sigfillset()
```
**Signal system calls 1# exeample**
```
void cleanup (int signum)
{
  ft_printf("Caugth the signal number: %d\n", signum);
  ft_printf("Doing program clean-up and exiting...\n");
  exit(-1);
}

int main (int argc, char **argv)
{
  struct sigaction sigact;                      // signal action structure

  memset((void *)&sigact, 0, sizeof(sigact));   // zero memory for sigact struct
  sigact.sa_hanlder = cleanup;                  // set signal handler function
  sigemptyset(&(sigaction.sa_mask));            // set signals to block during execution to empty set
  if (sigaction(SIGINT, &sigact, NULL))
  {
    ft_printf("Error with sigaction: ");
    return (-1);
  }
  ft_printf("Starting the program...");
  sleep(30);
  ft_printf("No signals; ending the program\n\n");
  return(0);
}
```
**Signal system calls 2# exeample**
```
int	x = 100;		// global variable, just for this example ^.^

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
	signal(SIGINT, signal_handler01);		// task to perform = signal_handler01
	signal(SIGUSR1, sinal_handler02);		// task to perform = signal_handler02
	signal(SIGUSR3, sinal_handler03);		// task to perform = signal_handler03
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

**Socket**
- a socket is identified by an IP address concatenated with a port number (like-> 192.168.0.1:1625)
- the server waits for incomming client request by listening to a specified port. Once a request is received, the server accepts a conncetion from the client socket to complete the connection
- all ports below 1024 are considered well know, and already reserved. This means that there are ports for specific standard services like: telnet(23), ftp(23), http(80) and so on...
- every IPC process should have a client socket AND a server socket


