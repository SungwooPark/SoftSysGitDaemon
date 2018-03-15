# Project Proposal

## Git Daemon by Sungwoo Park

### Goal

To create a daemon written in C that provides a number of useful functionalities. Low-hanging first-pass goal is to implement a functionality that keeps track of time and number of lines of code written since last commit and notifies a user after certain time has passed or certain number of lines has bbeen written. This functionality is intended to remind user a good practice of commiting work to git often.

A stretch goal would be implementing the same functionality in more elegant way. Potential ways that I am thinking as of right now includes file hook that automatically awakes the daemon and runs the functionality instead of continuously running the program.

~~Stretch goal would be adding additional useful git-related functionality to this daemon.~~ (Considering that the first part of the project - research phase - has taken much more time than I had anticipated, I don't think I will get to this goal. Therefore, I am readjusting my goal.)

### Learning goals

My primary learning goal is to get more proficient in C through working on this project. Secondary learning goal is to practice writing a well-designed program, following good practices like modularization and abstraction.

Another learning goal that come as a byproduct of working on daemon is to gain a deeper understanding of how operating system works. Daemonizing a process involves a lot of "low-level" procedures that requires me to really understand what goes on under the hood of the operating system. By working on this project, I am hoping that I will gain more thorough understanding of how operating system (especially in an individual process level) works.

### Current progress and next steps

A biggest timesink so far is to familiarize myself with how linux daemon works. This is an area that I have no experience and writing a daemon is not a straightforward task, so the initial learning curve has been pretty steep. It seems like I have gained a pretty good understanding of "big picture", but I am having little trouble understanding ins and outs of the daemon writing process. Since I am having a hard time fully familiarizing myself with this subject, my speed of implementation has been very slow.

There are a limited amount of resources on this topic and most of the resources that I come across are very technical, which requires me a lot of time to go through. Since there are still a lot of stuff that I don't know, research process will continue.

Since I am getting near the project deadline, I will shift my focus of this project from mainly research to start writing code. Even though I don't feel like I know enough to write a well-written program, I take the approach of "write-first, fix later".

Specific tasks that I will be getting started on are:
- Having a better understanding of the difference between SysV and systemd method of writing a daemon: These two methods are two major ways of writing a daemon and I don't have clear understanding of differences between them. I am going with systemd method but having clear idea of how those differ will help me understand daemon better. My "definition of done" is having enough knowledge on this matter to be able to confidently articulate the technical reasons why I chose systemd method for this particular project.
- Figuring out how to run a terminal command within a daemon: This task is completed when I have a functioning daemon that runs `git status` periodically.
- Figuring out how to parse terminal output within a daemon: This task is completed when I have a daemon that can parse through the terminal output of `git status` and determine whether there is a change to be committed or not.
