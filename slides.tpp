--## TODO: ADJUST FOOTER
--footer                                     @kamalmarhubi
--bgcolor white
--fgcolor black
--sethugefont smblock
--huge    Systems   programming

--huge    in   Rust!




--sethugefont wideterm
--huge                                               Kamal   Marhubi


--##############################################################################
--newpage outline
--sethugefont wideterm
--huge                  outline

---
              * how I got started
---
              * what is systems programming
---
              * how Rust and nix make systems programming easier
---
              * how you can get started
---
              * how you can help!

--##############################################################################
--newpage rc
         ████████████
         █          █  
         █ ████████ █          ▛▀▖                  
         █  █ █ ███ █          ▙▄▘▞▀▖▞▀▖▌ ▌▙▀▖▞▀▘▞▀▖
         █ ████████ █          ▌▚ ▛▀ ▌ ▖▌ ▌▌  ▝▀▖▛▀ 
         █ █  █  ██ █          ▘ ▘▝▀▘▝▀ ▝▀▘▘  ▀▀ ▝▀▘
         █ ████████ █          
         █ ████████ █         
         █          █                  ▞▀▖      ▐        
         ████████████                  ▌  ▞▀▖▛▀▖▜▀ ▞▀▖▙▀▖
             ████                      ▌ ▖▛▀ ▌ ▌▐ ▖▛▀ ▌  
          ██████████                   ▝▀ ▝▀▘▘ ▘ ▀ ▝▀▘▘  
         ███ █ █ █ ██
         ██ █ █ █ ███   
         ████████████


            ｈｔｔｐｓ：／／ｗｗｗ．ｒｅｃｕｒｓｅ．ｃｏｍ／

--##▛▀▖                   ▞▀▖      ▐        
--##▙▄▘▞▀▖▞▀▖▌ ▌▙▀▖▞▀▘▞▀▖ ▌  ▞▀▖▛▀▖▜▀ ▞▀▖▙▀▖
--##▌▚ ▛▀ ▌ ▖▌ ▌▌  ▝▀▖▛▀  ▌ ▖▛▀ ▌ ▌▐ ▖▛▀ ▌  
--##▘ ▘▝▀▘▝▀ ▝▀▘▘  ▀▀ ▝▀▘ ▝▀ ▝▀▘▘ ▘ ▀ ▝▀▘▘  




--##############################################################################
--newpage shell
--sethugefont smblock
--huge    I  built  a  basic  shell

--huge    ( like  bash)

--huge    from  scratch

--##############################################################################
--newpage lsaddr
---


--beginshelloutput
$ ./lsaddr
10.0.2.136
172.17.0.1
--endshelloutput

--##############################################################################
--newpage ipc
--sethugefont smblock
--huge    interprocess

--huge    communication

--huge    benchmarks


--##############################################################################
--newpage containy-thing
--beginshelloutput
$ ./containy-thing --help
containy-thing 

USAGE:
        containy-thing [OPTIONS] <ROOTFS> [--] [ARGS]

OPTIONS:
    -h, --help                                Prints help information
    -m, --mount <container-dir> <host-dir>    Mount <host-dir> at <container-dir>
    -V, --version                             Prints version information

ARGS:
    ROOTFS     Path to the extracted rootfs
    COMMAND    Command to run
    ARG...     Arguments for COMMAND
--endshelloutput


--##############################################################################
--newpage sysprog
--sethugefont smblock
--huge    what  is  systems

--huge    programming ?

--##############################################################################
--newpage kernel
--sethugefont smblock
--huge    the  kernel



--##############################################################################
--newpage syscalls
--sethugefont smblock
--huge    system  calls :

--huge        the  kernel' s  API

--##############################################################################
--newpage syscall-ex

--sethugefont wideterm
--huge                  some  system  calls

---
              * file operations: open, read, write
---
              * processes: fork, exec, kill
---
              * networking: socket, connect, listen, accept

--##############################################################################
--newpage syscalls
--sethugefont smblock


--huge    *very*  low-level

--##############################################################################
--newpage layers
--sethugefont smblock
--huge    layers  between

--huge    the  kernel

--huge    and  code  you  write

--##############################################################################
--newpage libc


--sethugefont smblock
--huge     libc

--##############################################################################
--newpage libc
--sethugefont smblock
--huge    wraps  up  system  calls

--huge    so  you  can  call  them

--huge    from  C

--##############################################################################
--newpage stdlib
--sethugefont smblock


--huge    standard  library
--##############################################################################
--newpage std-abstractions
--sethugefont smblock

--huge    provides  abstractions

--huge    over  OS  concepts

--##############################################################################
--newpage std-idioms
--sethugefont smblock
--huge    provides  idiomatic

--huge    interface  for  the

--huge    language



--##############################################################################
--newpage dia
--## TODO FIX

--beginoutput
--center |                         |
--center |                         |
--center |                         |
--center |                         |
--center |                         |
--center |                         |
--center +-------------------------+
--center |       THE KERNEL        |
--endoutput
       



--##############################################################################
--newpage
--## TODO FIX

--beginoutput
--center |                         |
--center |                         |
--center |                         |
--center |                         |
--center +-------------------------+
--center |          libc           |
--center +-------------------------+
--center |       THE KERNEL        |
--endoutput

--##############################################################################
--newpage

--beginoutput
--center |                         |
--center +-------------------------+
--center |       standard          |
--center |        library          |
--center +-------------------------+
--center |          libc           |
--center +-------------------------+
--center |       THE KERNEL        |
--endoutput

--##############################################################################
--newpage

--beginoutput
--center |       YOUR CODE         |
--center +-------------------------+
--center |       standard          |
--center |        library          |
--center +-------------------------+
--center |          libc           |
--center +-------------------------+
--center |       THE KERNEL        |
--endoutput


--##############################################################################
--newpage nix

--sethugefont smblock
--huge      what  is  nix ?



--##############################################################################
--newpage nix
--sethugefont smblock
--huge    a  *very*  thin  wrapper

--huge    to  make  libc  more  Rusty

--##############################################################################
--newpage dia

--beginoutput
--center |       YOUR CODE         |
--center +-------------------------+
--center |       standard          |
--center |        library          |
--center +-------------------------+
--center |          libc           |
--center +-------------------------+
--center |       THE KERNEL        |
--endoutput

--##############################################################################
--newpage dia-nix

--beginoutput
--center |       YOUR CODE         |
--center |                         |
--center |                         |
--center |                         |
--center +-------------------------+
--center |        nix+libc         |
--center +-------------------------+
--center |       THE KERNEL        |
--endoutput


--##############################################################################
--newpage dia-nix

--beginoutput
--center |       YOUR CODE         |
--center +           +-------------+
--center |           |  standard   |
--center |           |   library   |
--center +-----------+-------------+
--center |        nix+libc         |
--center +-------------------------+
--center |       THE KERNEL        |
--endoutput

--##############################################################################
--newpage sysprog
--sethugefont smblock
--huge    what  does  nix  do ?


--##############################################################################
--newpage sysprog
--sethugefont smblock
--huge    errors  via  Result

--huge    instead  of  errno

--##############################################################################
--newpage result
--beginoutput
#[must_use]
pub enum Result<T, E> {
    Ok(T),
    Err(E),
}
--endoutput


--##############################################################################
--newpage
--sethugefont smblock
--huge    this  is  really  great!


--##############################################################################
--newpage sysprog
--sethugefont smblock
--huge    return  complex  types

--huge    instead  of  initializing

--huge    pointer

--##############################################################################
--newpage sysprog
--beginoutput
// C
int pipe_fds[2];
if (pipe(pipe_fds)) {
    return -1;
}
--endoutput


--##############################################################################
--newpage sysprog
--beginoutput
// Rust
let (rd, wr) = try!(pipe());
--endoutput


--##############################################################################
--newpage sysprog
--sethugefont smblock
--huge    flag  arguments  as

--huge    bitflags


--##############################################################################
--newpage sysprog
--beginoutput
// C
#define O_RDONLY 0
#define O_WRONLY 1
#define O_RDWR   2
// ...

int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);
--endoutput

--##############################################################################
--newpage sysprog
--beginoutput
// Rust
bitflags!(
    flags OFlag: c_int {
        const O_RDONLY    = libc::O_RDONLY,
        const O_WRONLY    = libc::O_WRONLY,
        const O_RDWR      = libc::O_RDWR,
        // ...
    }
);

pub fn open<P: ?Sized + NixPath>(path: &P,
                                 oflag: OFlag,
                                 mode: Mode) -> Result<RawFd> { ... }
--endoutput


--##############################################################################
--newpage sysprog
--sethugefont smblock
--huge    logical  enums  are

--huge    actual  enums

--##############################################################################
--newpage sysprog
--sethugefont smblock
--beginoutput
// C
#define SIGHUP  1
#define SIGINT  2
#define SIGQUIT 3
// ...

int kill(pid_t pid, int sig);
--endoutput

--##############################################################################
--newpage sysprog
--sethugefont smblock
--beginoutput
// Rust
pub enum Signal {
    SIGHUP = libc::SIGHUP,
    SIGINT = libc::SIGINT,
    SIGQUIT = libc::SIGQUIT,
    // ...
}

pub fn kill(pid: libc::pid_t, signal: Signal) -> Result<()> { ... }
--endoutput

--##############################################################################
--newpage sysprog
--sethugefont smblock
--huge    Option< _ >  instead  of

--huge    sentinel  values

--##############################################################################
--newpage sysprog
--beginoutput
// C
int chown(const char *pathname, uid_t owner, gid_t group);
// man 2 chown:
// If the owner or group is specified as -1, then that ID is not
// changed.

---
// Rust
pub fn chown<P: ?Sized + NixPath>(path: &P,
                                  owner: Option<uid_t>,
                                  group: Option<gid_t>) -> Result<()>
    { ... }
--endoutput

--##############################################################################
--newpage sysprog
--sethugefont smblock
--huge    references  instead  of

--huge    pointers

--##############################################################################
--newpage sysprog
--beginoutput
// C
int bind(int sockfd, const struct sockaddr *addr,
         socklen_t addrlen);

---
// Rust
pub fn bind(fd: RawFd, addr: &SockAddr) -> Result<()> { ... }
--endoutput

--##############################################################################
--newpage sysprog
--sethugefont smblock
--huge    slices  instead  of

--huge    pointers  &  lengths

--##############################################################################
--newpage sysprog
--sethugefont smblock
--beginoutput
// C
ssize_t read(int fd, void *buf, size_t count);
ssize_t write(int fd, const void *buf, size_t count);

---
// Rust
pub fn read(fd: RawFd, buf: &mut [u8]) -> Result<usize> { ... }
pub fn write(fd: RawFd, buf: &[u8]) -> Result<usize> { ... }
--endoutput


--##############################################################################
--newpage sysprog
--sethugefont smblock
--huge    enums  instead  of

--huge    conflating  meanings

--##############################################################################
--newpage sysprog
--beginoutput
// C
pid_t fork(void);
// man 2 fork:
// On success, the PID of the child process is returned in the
// parent, and 0 is returned in the child. On failure, -1 is
// returned in the parent, no child process is created, and errno is
// set appropriately.
--endoutput


--##############################################################################
--newpage sysprog
--beginoutput
// Rust
pub enum ForkResult {
    Parent {
        child: pid_t
    },
    Child
}
pub fn fork() -> Result<ForkResult> { ... }
--endoutput

--##############################################################################
--newpage rust-fork
--beginoutput
match fork().unwrap() {
    ForkResult::Parent { child } => {
        // stuff to do in parent
    }
    ForkResult::Child => {
        // stuff to do in child
    }
}
--endoutput

--##############################################################################
--newpage sysprog
--sethugefont smblock
--huge    project  status

--##############################################################################
--newpage sysprog
--sethugefont smblock
--huge    warts

--##############################################################################
--newpage sysprog
--sethugefont smblock
--huge    string  passing

--##############################################################################
--newpage sysprog
--sethugefont smblock
--huge    not  consistent  across

--huge    all  APIs

--##############################################################################
--newpage sysprog
--sethugefont smblock
--huge    socket

--##############################################################################
--newpage sysprog
--sethugefont smblock
--huge    ioctl

--##############################################################################
--newpage sysprog
--sethugefont smblock
--huge    fcntl

--##############################################################################
--newpage sysprog
--sethugefont smblock
--huge    implementing  an  RFC

--huge    process


                        https://github.com/nix-rust/rfcs/pull/1/

--##############################################################################
--newpage takeaways
--sethugefont smblock
--huge    systems  programming  is

--huge    an  excellent  way  to  get

--huge    better  at  programming

--##############################################################################
--newpage sysprog
--sethugefont smblock
--huge    Rust  makes  systems

--huge    programming  more  fun

--##############################################################################
--newpage takeaways
--sethugefont smblock
--huge        some ways that


--huge                       YOU

--huge        could get started

--##############################################################################
--newpage takeaway-sysprog
--sethugefont smblock
--huge    try some systems

--huge    programming:

--huge    write a shell!

   http://j.mp/shell-workshop


--##############################################################################
--newpage takeaways-sysprog-rust

--sethugefont smblock
--huge    try  systems  programming

--huge    in  Rust  with  nix!



   https://github.com/nix-rust/nix

--##############################################################################
--newpage contribute

--sethugefont smblock
--huge    contribute  to  nix!








   https://github.com/nix-rust/nix

--##############################################################################
--newpage sysprog
--sethugefont smblock
--huge    Thanks for listening!





--huge                                  @kamalmarhubi
