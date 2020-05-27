# 21sh [![42](https://i.imgur.com/9NXfcit.jpg)](i.imgur.com/9NXfcit.jpg)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/d9485b7923204fa3b69323aee56e4506)](https://www.codacy.com/manual/antoinepaulbarthelemy/42sh?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=Ant0wan/42sh&amp;utm_campaign=Badge_Grade) [![Build Status](https://travis-ci.org/Ant0wan/21sh.svg?branch=master)](https://travis-ci.org/Ant0wan/21sh)

An implementation of a very small **shell** [a 42 project].

This project follows [Minishell](https://github.com/Ant0wan/Minishell) and aims at getting a better grasp of the parsing theories, job control and general programming in Unix environment.


## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See below sections for notes on how to build and run the project on a live system.

```shell=
git clone https://github.com/Ant0wan/21sh
```

### Prerequisites

Here are the things you need to build and use 21sh.

A C compiler and some utilities:
```shell=
apt-get install -y gcc make
```

The Termcap library
```shell=
apt-get install -y libncurses5-dev
```

In order to run the automated tests some additional utilities are required or need to be updated
```shell=
apt-get install -y bash perl
```

### Build

There is only one step to build 21sh

```shell=
make -j
```

## Running the tests

In order to run the automated tests on your system make sure prerequisites are met, then simply execute the command
```shell=
make test
```
