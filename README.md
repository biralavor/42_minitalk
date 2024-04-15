# 42_minitalk
WIP - IPC (inter-process communication) between 'server' and 'client' process project at 42school.

It's about SIGNALS ;)
The communication between the client and server has to be done only using UNIX signals.
In this project, it's only allowed two signals: SIGUSR1 and SIGUSR2.

### Basic knowledge
- **Signals** (signal name || default handler action || description)
  - 1# SIGHUP || Terminate || to block 
  - 2# SIGINT || Terminate || to kill a terminal process with ^C (ctrl+c)
  - 5# SIGTRAP || Core || to debbug a program with trace/breakpoints
  - 8# SIGFPE || Core || Arithmetic error
  - 9# SIGKILL || Terminate || lethal signal, and cannot be caught or ignored
  - 11# SIGSEGV || Core || invalid memory reference (seg fault?)
  - 14# SIGALRM || Terminate || Expiry of alarm clock timer
  - 15# SIGTERM || Terminate || A polite "please cleanup && terminate" signal (like shutdown a system)
  - 17# SIGCHLD || Ignore || Child process has terminated
- **Socket**
  - a socket is identified by an IP address concatenated with a port number (like-> 192.168.0.1:1625)
  - the server waits for incomming client request by listening to a specified port. Once a request is received, the server accepts a conncetion from the client socket to complete the connection
  - all ports below 1024 are considered well know, and already reserved. This means that there are ports for specific standard services like: telnet(23), ftp(23), http(80) and so on...
  - every IPC process should have a client socket AND a server socket
