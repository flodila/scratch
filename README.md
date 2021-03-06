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
- Version 3 &mdash; because why start with 2 if there is 3?
- CPython &mdash; because why pick a rarity when just about starting out?

### Hello World with some Fancy Library

#### Idea
1. Development environment on Xubuntu 16.04
    1. virtualenv without committing 3rd party stuff to git.
    2. Editor: let's try [Atom](https://atom.io/).
2. Code
    1. Use some fancy library and print a fancy "Hello World"
3. Ship
    1. Build a docker image from some Python alpine base from docker-hub with the library and my script.
4. Run
    1. docker run.

##### virtualenv
1. Init new virtual environment.  
    `$ virtualenv --python python3 scratch-venv`
2. Add `scratch-venv` to `.gitignore`
3. Activate the shell with the new virtual environment  
    `$ source scratch-venv/bin/activate`
4. Install Python libraries  
    `$ pip install ${libname}`


- Deactivate the virtual environment  
    `$ deactivate`

I don't want to have all of the Python binaries and the used libraries in my git repository.

- **Freeze** (with active virtual environment _only!_):  
    `$ pip freeze > requirements.txt`
- **Install** (with active virtual environment _only!_):  
    `$ pip install -r requirements.txt`


##### Fancy Library
(UI toolkit to open a window and print Hello World)

- Let's try enaml &mdash; because why not  
`$ pip install enaml`
> failed with error code 1 in /tmp/pip-build-\_3bl4gab/atom/

- Let's try libavg &mdash; looks cool. LGPL.  
`$ pip install libavg`
> Could not find a version that satisfies the requirement libavg (from versions: )
No matching distribution found for libavg

- Let's try [PyGObject](https://pygobject.readthedocs.io/en/latest/) &mdash; not quite as fancy but hey. It should be able to do Hello World. What dosn't?  
`$ pip install PyGObject`
>Could not find a version that satisfies the requirement pygobject (from versions: )
No matching distribution found for pygobject

- OK. [So](https://mathieu.daitauha.fr/blog/2016/07/06/pip-install-pygobject/):  
`$ pip install git+https://git.gnome.org/browse/pygobject`
> failed with error code 1 in /tmp/pip-t2bhn81u-build/

- Let's try [Toga](https://pybee.org/project/projects/libraries/toga/)!  
`$ pip install Toga`
> **Successfully** installed Toga-0.2.15 colosseum-0.1.6 toga-core-0.2.15 toga-gtk-0.2.15

***Yay!***

##### Copy and Paste
from [Your first Toga app](https://toga.readthedocs.io/en/latest/tutorial/tutorial-0.html)

It works. Cool. It even says "Hello World" on the button out of the box. Nice!

### Citations
1. _Book_: [Kenneth Reitz & Tanya Schlusser, Hitchhiker´s Guide für Python, O’Reilly](https://www.oreilly.de/buecher/12951/9783960090458-hitchhiker%26acute%3Bs-guide-f%C3%BCr-python.html), June 2017
