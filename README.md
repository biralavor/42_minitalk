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
**Signal system calls**
```
#include <sys/signal.h>    // for signals
#include <stdlib.h>        // for exit

struct sigaction           // structure for signal action
sigaction()                // change action for specified signal
sigemptyset()              // initialize signal set to exclude all signals
sigfillset()               // initialize signal set to include all signals

// Must always initialize the signal set first, by calling sigemptyset() or sigfillset()

int main (int argc, char **argv)
{
  struct sigaction sigact;                      // signal action structure
  memset((void *)&sigact, 0, sizeof(sigact));   // zero memory for sigact struct
}

```

**Socket**
- a socket is identified by an IP address concatenated with a port number (like-> 192.168.0.1:1625)
- the server waits for incomming client request by listening to a specified port. Once a request is received, the server accepts a conncetion from the client socket to complete the connection
- all ports below 1024 are considered well know, and already reserved. This means that there are ports for specific standard services like: telnet(23), ftp(23), http(80) and so on...
- every IPC process should have a client socket AND a server socket

**Sending Signals**
  - Process_ID + Signal Number (or symbolic constant like SIGTERM)
