
Python interface
================

This section describes how to interact with **wlcf** using Python, either through the command line interface or via the Cython wrapper.

**Using command line interface**

The simplest way to run **wlcf** from Python is by calling the executable through the system shell.

Example

python::

    import os

    os.system("../wlcf z=0.5 sigma8=0.8 fnamePS=./input/linear_pk.txt")


Alternatively, using `subprocess` :

python::

    import subprocess

    subprocess.run([
        "../wlcf",
        "z=0.5",
        "sigma8=0.8",
        "fnamePS=./input/linear_pk.txt"])


This approach allows you to:

* run parameter scans
* automate workflows
* integrate wlcf into larger pipelines

.. note::

When using the command line interface, parameters must be passed as `key=value` without spaces.

**Cython interface**

The code provides a **Cython wrapper** that allows direct interaction with wlcf from Python without invoking the executable.


example

python::

    from wlcfpy import wlcf

    w = wlcf()
    
    w.set(
        numberThreads=4,
        verbose=1,
        fnamePS="./input/linear_pk.txt")

    w.Run()



**Notes**

* The working directory should contain the required input files (e.g., power spectrum).
* Output files are written in the same way as the C executable.
* Some parameters (e.g., number of threads) may be controlled both via Python and internally by the code.



