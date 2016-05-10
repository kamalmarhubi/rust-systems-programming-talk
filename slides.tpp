--## TODO: ADJUST FOOTER
--footer                                     @kamalmarhubi
--bgcolor white
--fgcolor black
--sethugefont smblock
--huge    Systems   programming   in   Rust!




--sethugefont wideterm
--huge                                                        Kamal   Marhubi


--##############################################################################
--newpage outline
--sethugefont wideterm
--huge                      outline

---
                  * how I got started
---
                  * what is systems programming
---
                  * what is Rust
---
                  * how Rust can make systems programming easier
---
                  * some ideas on how *you* could get started

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


--huge    I  built  a  basic  shell ( like  bash)

--huge    from scratch

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
--huge    Interprocess communication

--huge    benchmarks


--##############################################################################
--newpage sysprog


--sethugefont smblock
--huge    what  is  systems  programming ?

--##############################################################################
--newpage kernel


--sethugefont smblock
--huge    the  kernel

--##############################################################################
--newpage syscalls


--sethugefont smblock
--huge    system  calls :  the  kernel' s  API

--##############################################################################
--newpage syscall-ex

--sethugefont wideterm
--huge                      some  system  calls

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


--huge    layers  between  the  kernel

--huge    and  code  you  write

--##############################################################################
--newpage libc


--sethugefont smblock
--huge     libc

--##############################################################################
--newpage libc


--sethugefont smblock
--huge    wraps  up  system  calls

--huge    so  you  can  call  them  from  C

--##############################################################################
--newpage stdlib
--sethugefont smblock


--huge    standard library

--##############################################################################
--newpage std-idioms
--sethugefont smblock

--huge    provides  appropriate  interface

--huge    for  the  language

--##############################################################################
--newpage std-abstractions
--sethugefont smblock

--huge    provides  abstractions

--huge    over  OS  concepts


--##############################################################################
--newpage layer-dia
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
--newpage rust

--sethugefont smblock
--huge      what  is  Rust ?

--##############################################################################
--newpage c-fork
---


--beginoutput
#include <signal.h>
#include <unistd.h>

int main(void) {
    pid_t child = fork();
    if (child) {  // in parent
        sleep(5);
        kill(child, SIGKILL);
    } else {  // in child
        for (;;);  // loop until killed
    }

    return 0;
}
--endoutput

--##############################################################################
--newpage c-fork-example-compiles-no-errors
--sethugefont smblock
--huge     it    compiles...


--beginshelloutput
$ cc -Wall -Wextra -Werror fork.c
$
--endshelloutput


---
--huge        ... with no errors or warnings

--##############################################################################
--newpage c-fork-bad

--sethugefont smblock
--huge   but  it's  *really*  not  correct!


--##############################################################################
--newpage fork-ret

--sethugefont wideterm
--huge     from   POSIX  spec  for  fork


        Otherwise, -1 shall be returned to the parent process,
        no child process shall be created, and errno shall be
        set to indicate the error.


--##############################################################################
--newpage kill-arg

--sethugefont wideterm
--huge     from   POSIX  spec  for  kill


        If pid is -1, sig shall be sent to all processes
        [...] for which the process has permission to send
        that signal.


--##############################################################################
--newpage all-procs
--sethugefont smblock


--huge      ALL  PROCESSES

--##############################################################################
--newpage c-fork


--beginoutput
#include <signal.h>
#include <unistd.h>

int main(void) {
    pid_t child = fork();
    if (child) {  // in parent
        sleep(5);
        kill(child, SIGKILL);
    } else {  // in child
        for (;;);  // loop until killed
    }

    return 0;
}
--endoutput

--##############################################################################
--newpage
--sethugefont smblock

--huge    what would  it look like

--huge    in Rust ?


--##############################################################################
--newpage rust-fork
--beginoutput
extern crate nix;

use nix::sys::signal::*;
use nix::unistd::*;

fn main() {
    match fork().unwrap() {
        ForkResult::Parent { child } => {
            sleep(5);
            kill(child, SIGKILL).unwrap();
        }
        ForkResult::Child => {
            loop {}  // until killed
        }
    }
}
--endoutput
--##############################################################################
--newpage c-fork


--beginoutput
#include <signal.h>
#include <unistd.h>

int main(void) {
    pid_t child = fork();
    if (child) {  // in parent
        sleep(5);
        kill(child, SIGKILL);
    } else {  // in child
        for (;;);  // loop until killed
    }

    return 0;
}
--endoutput

--##############################################################################
--newpage forkresult



--beginoutput
pub enum ForkResult {
    Parent {
        child: pid_t
    },
    Child
}
--endoutput


--##############################################################################
--newpage pattern

--beginoutput
match fork_result {
    ForkResult::Parent { child } => {
        // stuff to do if we're in the parent
    }
    ForkResult::Child => {
        // stuff do do if we're in the child
    }
}
--endoutput

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
--newpage match-full

--beginoutput
match fork() {
    Ok(ForkResult::Parent { child }) => {
        // stuff to do if we're in the parent
    }
    Ok(ForkResult::Child) => {
        // stuff do do if we're in the child
    }
    Err(errno) => {
        // stuff to do if there was an error
    }
}
--endoutput

--##############################################################################
--newpage unwrap

--sethugefont smblock
--huge    result.unwrap( )
---

--huge    exit  if  there  was  an  error

--##############################################################################
--newpage rust-fork
--beginoutput
extern crate nix;

use nix::sys::signal::*;
use nix::unistd::*;

fn main() {
    match fork().unwrap() {
        ForkResult::Parent { child } => {
            sleep(5);
            kill(child, SIGKILL).unwrap();
        }
        ForkResult::Child => {
            loop {}  // until killed
        }
    }
}
--endoutput

--##############################################################################
--newpage takeaways

--sethugefont smblock
--huge        systems  programming  is  an

--huge        excellent  way  to  get  better

--huge        at  programming



--##############################################################################
--newpage takeaways
--sethugefont smblock
--huge        some ways that


--huge                       YOU

--huge        could get started

--##############################################################################
--newpage takeaway-sysprog

--sethugefont smblock
--huge    try some systems programming:

--huge    write a shell!


--sethugefont wideterm
--huge    http://j.mp/shell-workshop

--##############################################################################
--newpage takeaways-rust

--sethugefont smblock
--huge  learn Rust!


--sethugefont wideterm
--huge https://www.rust-lang.org/

--##############################################################################
--newpage takeaways-sysprog-rust

--sethugefont smblock
--huge    try systems programming in Rust

--huge    with nix!


--sethugefont wideterm
--huge     https://github.com/nix-rust/nix
