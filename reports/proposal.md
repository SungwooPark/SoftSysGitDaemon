# Project Proposal

## Git Daemon

### Goal

To create a daemon written in C that provides a number of useful functionalities. Low-hanging first-pass goal is to implement a functionality that keeps track of time and number of lines of code written since last commit and notifies a user after certain time has passed or certain number of lines has bbeen written. This functionality is intended to remind user a good practice of commiting work to git often.

Next step and goal would be implementing the same functionality in more elegant way. Potential ways that I am thinking as of right now includes file hook that automatically awakes the daemon and runs the functionality instead of continuously running the program.

Stretch goal would be adding additional useful git-related functionality to this daemon.

### Learning goals

My primary learning goal is to get more proficient in C through working on this project. Secondary learning goal is to practice writing a well-designed program, following good practices like modularization and abstraction.

### Next steps

Few resources that I will be consulting in the beginning to get me started are listed below.
- [Stack Overflow thread on creating simple daemon](https://stackoverflow.com/questions/17954432/creating-a-daemon-in-linux)
- [Linux Daemon man page](https://www.freedesktop.org/software/systemd/man/daemon.html)
- [Example of simple daemon written in C](https://github.com/jirihnidek/daemon)

Tasks that I will be getting started on are:
- Read the aforementioned resources to get myself more familiarized with how to write a daemon.
- Write a simple daemon that does very simple task.
- Think of a way to interact with git in my shell. (ex. through parsing the output of `git status`? Or more elegant way?)
