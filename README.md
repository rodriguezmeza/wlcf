# wlcf: Weak leansing correlation function modeling

Authors: 
- Alejandro Aviles (ICF-UNAM, Mexico), avilescervantes@gmail.com, aviles@icf.unam.mx
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

Download the code by cloning it from https://github.com/rodriguezmeza/cTreeBalls.

Dependencies: wlcf needs gsl and fftw3 installed in your system. Sources are included. Therefore no need to make any changes. In case of problems go to web page https://www.gnu.org/software/gsl/ for details or ask to your system administrator. Make necessary changes in `Makefile_machine` file and look up for `GSL`.

Go to the wlcf directory (`cd wlcf/`) and compile (`make clean; make all`). If the first compilation attempt fails, you may need to open the Makefile_machine file and adapt the name of the compiler (default: gcc), of the optimization flag (default: `-O4 -ffast-math`) and of the OpenMP flag (default: `-fopenmp`; this flag is facultative, you are free to compile without OpenMP if you don't want parallel execution; note that you need the version 4.2 or higher of gcc to be able to compile with `-fopenmp`). The code has been tested with gcc version 10 and 12 and would be working with version 11, and 13. (In particular, for compiling on Mac >= 10.9 despite of the clang incompatibility with OpenMP).

To check that the code runs, if you are in `wlcf` directory, type:

    $ make clean; make all
    $ cd tests
    $ ../wlcf

It will run using all default values and a directory named `Output` will be created under `tests`. **wlcf** will save all output files and a log file in `Output/tmp`. A file with the parameter values use in the run named `parameters_null-usedvalues` will also be saved. You may use it as a template to create your own parameter files.

If you execute:

    $ ../cballs options=post-processing script="python scripts/plot2pcf.py"

will do the same but now will plot the 2pcf and save it as a pdf file. Now, let us use a parameter file, execute:

    $ ../wlcf ./In/parameters_explained

Directory `Output` is already created then **wlcf** will overwritte all histograms files, parameter file as was run, and the log file. The parameters_explained file is a reference input file, containing (and explaining) the use of all possible input parameters. In this case as can be seen in `parameters_explained` file a catalog of points is read from the file `kappa_nres12_zs9NS256r000.bin`.

To see a plot of the 2pcf, edit parameters_explained and set option to "post-processing" and execute again:
 
    $ ../cballs parameters_explained

At the end of the run you will, as before, have a pdf file of the plot.

By default **cBalls** reads/writes catalog of points to analyzed files in 4-column format with x, y, z columns first and then value of the convergence field. It has a two line header:

    # nbody NDIM Lx Ly Lz
    # nbody-value NDIM-value Lx Ly Lz - values

Try running:

    $ ../cballs nbody=6480 o=points_on_sphere testmodel=unit-sphere-random options=stop

In the `Output` directory you will have a file: `points_on_sphere.txt`. View its contents to see the two lines header and the 4 columns structure of data. You can plot this file:

    $ python scripts/plot3D_points-on-sphere.py

Note: in the above example `points_on_sphere` was not given an extension. By default **cBalls** gives to the output files the extension `.txt`.

You may also consult the code´s man page for more detailed information on how to run **cBalls**:

    $ man ../docs/man/cballs.m


## Configuration

cBalls can be configured by switching on/off several options. Configuration file is `Makefile_setting`.

| Option         | Description                                                                                                                                                   |
|:--------------:|---------------------------------------------------------------------------------------------------------------------------------------------------------------|
| `DEFDIMENSION`       | `= 3` select dimension of the run: 2 or 3                                                                                                                     |
| `USEGSL`       | `= 1` switch on/off computation using GSL routines. Optional.                                                                                                                      |
| `GSLINTERNAL`     | `= 1` for enabling GSL internal sources<br />(if `= 0`, specify the corresponding compiler flags in `Makefile_machine` file)                                                             |
| `OPENMPMACHINE`     | `= 1` for enabling OpenMP parallelism<br />(Specify the corresponding compiler flag in `Makefile_machine` file)                                                             |
| `SINGLEPON`    | `= 0` for disabling single precision                                                                                                                             |
| `LONGINTON`    | `= 1` for enabling long integers                                                                                                                             |
| `ADDONSON`  | `= 1` for adding more funcionality to the code, like other searching methods, other catalog formats                                                                                                |

**Note**:
After changing `Makefile_settings` in order to have the new settings active in **cBalls** you have to re-compile the code: `make clean; make`. 

## Parameters

The list of available command line parameters can be consulted using the `-h` or `--help` flags:

    $ ../cballs --help

See also the man page as explained above. If you execute:

    $ ../cballs --clue

you will receive in response how **cBalls** should be executed using command line parameters. Just pick up the parameteres you need and, if necessary, modify their values according to your needs.

## Python

To install cBalls python module (cballys) just execute (you already do it...):

    $ make clean; make all

To test it go to directory `tests` and run:

    $ python ./In/test_cython_balls.py

Note: this interface in Cython was tested in a python environment with `python3.12`.

## Plotting utilities

Several Jupyter notebooks, written by Abraham Arvizu and Eladio Moreno, are available to process cBalls results. They are in the github repository: 

https://github.com/joar-cafe/CBalls_plots/tree/main/benchmarks

Other python scripts are in directory `tests/scripts`.


## License

**cBalls** is written by A. Aviles et al., is open source and distributed under the [MIT license](LICENSE). If you use this program in research work that results in publications, please cite the following paper:

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
