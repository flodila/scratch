# scratch
Anything but Nothing at all &rArr; Here is of no interest.

## Little Python First Steps

### Motivation
I'm pretty eloquent in Java and Javascript but sick of writing my shell scripts in [JJS](https://en.wikipedia.org/wiki/Nashorn_(JavaScript_engine)). While it works really well, it needs the bulky dependency [JVM](https://en.wikipedia.org/wiki/Java_virtual_machine), and it has to start it up each time a script is called --- which means overhead.

And I've already written `#!/bin/bash` scripts but failed to find any love for the syntax.

So, [Python](https://www.python.org/) it is. It just seems to be the obvious choice right now.

### Caveats
There's a package manager. _Nothing is simple anymore._ Of course, there are benefits. But how can I ship my stuff? Debian packages? [Docker](https://www.docker.com/) images? So many possibilities.

### Flavor
- Version 3 --- because why start with 2 if there is 3?
- CPython --- because why pick a rarity when just about starting out?

### Hello World with some Fancy Library

#### Idea
1. Development environment on Xubuntu 16.04
1.1 virtualenv without committing 3rd party stuff to git.
1.2 Editor: let's try [Atom](https://atom.io/).
2. Code
2.1 Use some fancy library and print a fancy "Hello World"
3. Ship
3.1 Build a docker image from some Python alpine base from docker-hub with the library and my script.
4. Run
4.1 docker run.

##### virtualenv
`$ virtualenv --python python3 scratch-venv`
Use github's [VirtualEnv.gitignore](https://github.com/github/gitignore/blob/master/Global/VirtualEnv.gitignore).
`$ source scratch-venv/bin/activate`
Later: `$ pip freeze > requirements.txt`
Redo: `$ pip install -r requirements.txt`

##### Fancy Library
UI toolkit to open a window and print Hello World

Let's try enaml --- because why not
`$ pip install enaml`
> failed with error code 1 in /tmp/pip-build-_3bl4gab/atom/

Let's try libavg --- looks cool. LGPL.
`$ pip install libavg`
> Could not find a version that satisfies the requirement libavg (from versions: )
No matching distribution found for libavg

Let's try [PyGObject](https://pygobject.readthedocs.io/en/latest/) --- not quite as fancy but hey. It should be able to do Hello World. What dosn't?
`$ pip install PyGObject`
>Could not find a version that satisfies the requirement pygobject (from versions: )
No matching distribution found for pygobject

OK. [So](https://mathieu.daitauha.fr/blog/2016/07/06/pip-install-pygobject/):
`$ pip install git+https://git.gnome.org/browse/pygobject`
>Command "/home/florian/dev/scratch/scratch-venv/bin/python3 -u -c "import setuptools, tokenize;\__file\__='/tmp/pip-t2bhn81u-build/setup.py';f=getattr(tokenize, 'open', open)( \__file\__);code=f.read().replace('\r\n', '\n');f.close();exec(compile(code, \__file\__, 'exec'))" install \--record /tmp/pip-6gn75fel-record/install-record.txt \--single-version-externally-managed \--compile \--install-headers /home/florian/dev/scratch/scratch-venv/include/site/python3.5/pygobject" failed with error code 1 in /tmp/pip-t2bhn81u-build/

This is not even funny anymore. Perhaps Python is a mess after all.

Let's try [Toga](https://pybee.org/project/projects/libraries/toga/)!
`$ pip install Toga`
> Successfully installed Toga-0.2.15 colosseum-0.1.6 toga-core-0.2.15 toga-gtk-0.2.15

***Yay!*** I cannot find a license though. Yes I can. [BSD3](https://github.com/pybee/toga).

##### Copy'n'Paste
from [Your first Toga app](https://toga.readthedocs.io/en/latest/tutorial/tutorial-0.html)

It works. Cool. It even says "Hello World" on the button out of the box. Nice!

### Citations
1. _Book_: [Kenneth Reitz & Tanya Schlusser, Hitchhiker´s Guide für Python, O’Reilly](https://www.oreilly.de/buecher/12951/9783960090458-hitchhiker%26acute%3Bs-guide-f%C3%BCr-python.html), June 2017
