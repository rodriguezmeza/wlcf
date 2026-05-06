# wlcf: Weak leansing correlation function modeling

Author:
- Alejandro Aviles (ICF-UNAM, Mexico), avilescervantes@gmail.com, aviles@icf.unam.mx

Major contributors:
- Juan Carlos Hidalgo (ICF-UNAM, Mexico), hidalgo@icf.unam.mx
- Eladio A. Moreno-Alcala (UG, Mexico), ea.morenoalcala@ugto.mx
- Gustavo Niz-Quevedo (UG, Mexico), g.niz@ugto.mx
- Sadi Ramirez (ICF-UNAM, Mexico), sadi@icf.unam.mx
- Mario A. Rodriguez-Meza (ININ, Mexico), marioalberto.rodriguezmeza@gmail.com
- Sofia del Pilar Samario-Nava (ICF-UNAM, Mexico), sabiduria_sofy@hotmail.com

## Table of Contents

-   [Introduction](#introduction)
-   [Compiling and getting started](#compiling-and-getting-started)
-   [Configuration](#configuration)
-   [Parameters](#parameters)
-   [Python](#python)
-   [License](#license)
-   [Acknowledgements](#acknowledgements)

## Introduction

**w**lcf is a C code for computing correlation functions using SPT, EFT and Halo model. So far can compute only the 3-point correlation function (3pcf) for galaxy weak leansing convergence in a plane wave expansion.

A short documentation can be found in a html version of the man (linux manual) version man. Look for it (`docs/man/wlcf.html`) an open it with a web explorer.

## Compiling and getting started

Download the code by cloning it from https://github.com/rodriguezmeza/wlcf.

Dependencies: wlcf needs gsl and fftw3 installed in your system. Sources are included. Try installing them. In case of problems go to web page https://www.gnu.org/software/gsl/ for details or ask to your system administrator. Make necessary changes in `Makefile_machine` file and look up for `GSL` and `FFTW·.

Go to the wlcf directory (`cd wlcf/`) and compile (`make clean; make all`). If the first compilation attempt fails, you may need to open the Makefile_machine file and adapt the name of the compiler (default: gcc), of the optimization flag (default: `-O4 -ffast-math`) and of the OpenMP flag (default: `-fopenmp`; this flag is facultative, you are free to compile without OpenMP if you don't want parallel execution; note that you need the version 4.2 or higher of gcc to be able to compile with `-fopenmp`). The code has been tested with gcc version 10 and 12 and would be working with version 11, and 13. (In particular, for compiling on Mac >= 10.9 despite of the clang incompatibility with OpenMP).

To check that the code runs, if you are in `wlcf` directory, type:

    $ make clean; make all
    $ cd tests
    $ ../wlcf

It will run using all default values and a directory named `Output` will be created under `tests`. **wlcf** will save all output files and a log file in `Output/tmp`. A file with the parameter values use in the run named `parameters_null-usedvalues` will also be saved. You may use it as a template to create your own parameter files.

You may consult the code´s man page for more detailed information on how to run **wlcf**:

    $ man ../docs/man/wlcf.1


## Configuration

wlcf can be configured by switching on/off several options. Configuration file is `Makefile_setting`.

| Option         | Description                                                                                                                                                   |
|:--------------:|---------------------------------------------------------------------------------------------------------------------------------------------------------------|
| `USEGSL`       | `= 1` switch on/off computation using GSL routines. Optional.                                                                                                                      |
| `GSLINTERNAL`     | `= 1` for enabling GSL internal sources<br />(if `= 0`, specify the corresponding compiler flags in `Makefile_machine` file)                                                             |
| `OPENMPMACHINE`     | `= 1` for enabling OpenMP parallelism<br />(Specify the corresponding compiler flag in `Makefile_machine` file)                                                             |
| `SINGLEPON`    | `= 0` for disabling single precision                                                                                                                             |
| `LONGINTON`    | `= 1` for enabling long integers                                                                                                                             |
| `ADDONSON`  | `= 1` for adding more funcionality to the code, like other searching methods, other catalog formats                                                                                                |

**Note**:
After changing `Makefile_settings` in order to have the new settings active in **wlcf** you have to re-compile the code: `make clean; make`. 

Also, note that `GSLINTERNAL` is not available yet. It will be activated soon. `USEGSL` must be always set to 1.

## Parameters

The list of available command line parameters can be consulted using the `-h` or `--help` flags:

    $ ../wlcf --help

See also the man page as explained above. If you execute:

    $ ../wlcf --clue

you will receive in response how **wlcf** should be executed using command line parameters. Just pick up the parameteres you need and, if necessary, modify their values according to your needs.

## Python

To install wlcf python module (wlcfpy) just execute (you already do it...):

    $ make clean; make all

To test it go to directory `tests` and run:

    $ python ./python/Bell.py

Note: this interface in Cython was tested in a python environment with `python3.12`.

## Plotting utilities

Several Jupyter notebooks, written by Sadi Ramírez, are available to process wlcf results. They are in the folder `tests\notebooks`. 

Other python scripts are in directory `tests/python`.


## License

**wlcf** is written by A. Aviles et al., is open source and distributed under the [MIT license](LICENSE). If you use this program in research work that results in publications, please cite the following paper:

Abraham Arvizu et al., [arXiv:2048.16847](https://arxiv.org/abs/2408.16847)

## Acknowledgements

wlcf use/is based on the following codes or projects:
-   [FFTLog routines by Xiao Fanga](https://github.com/xfangcosmo/2DFFTLog)
-   [The BiHaloFit model of Takahashi](http://cosmo.phys.hirosaki-u.ac.jp/takahasi/codes_e.htm)
-   [Zeno](https://home.ifa.hawaii.edu/users/barnes/zeno/index.html)
-   [Numerical recipies](https://numerical.recipes/)
-   [GSL](https://www.gnu.org/software/gsl/)
-   [CLASS](https://github.com/lesgourg/class_public)

Also Alejandro Aviles acknowledges support by grants UNAM PAPIIT IA101825 and SECIHTI CBF2023-2024-162.
