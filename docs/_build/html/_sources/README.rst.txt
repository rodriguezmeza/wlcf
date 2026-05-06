wlcf: Weak Lensing Correlation Function
---------------------------------------

**Authors:** A. Aviles, J.C. Hidalgo, E.A. Moreno-Alcala, G. Niz, S. Ramirez, Mario A. Rodriguez-Meza, S. Samario-Nava

For download and information, see https://github.com/rodriguezmeza/wlcf.git .

Introduction
------------

**wlcf** is a C code designed to compute cosmological correlation functions using theoretical frameworks such as Standard Perturbation Theory (SPT), Effective Field Theory (EFT), and the Halo Model. Currently, it focuses on the computation of the **three-point correlation function (3PCF)** for galaxy weak lensing convergence in a plane-wave expansion.
Paper available at (https://arxiv.org/abs/2408.16847). 

Compiling and getting started
-----------------------------

Download the code by cloning it from:
https://github.com/rodriguezmeza/wlcf.git .

**Dependencies:**
`wlcf` optionally requires **GSL (GNU Scientific Library)** and **FFTW3** installed in your system. Make sure to adapt the paths to these libraries in `Makefile_machine`.

Tu run the code go to the `wlcf` directory and compile the code::


    $ cd wlcf
    $ make clean
    $ make all


The code has been tested with modern versions of `gcc`. OpenMP support is optional but recommended for parallel execution. In addition, the code provides a Python wrapper that allows it to be run and controlled directly from Python.


To verify that the code runs correctly::

    $ cd tests
    $ ./wlcf

This will execute the code using default parameters. A directory named `Output` will be created inside `tests`, where all results are stored, including:

* output data files (e.g., `zetam*`, `Bmells*`, `Bnk*`)
* a log file inside `Output/tmp`

You can consult man page::

    $ man ../docs/wlcf.1

or open with a browser the html file: docs/man/wlcf.html


License
-------

wlcf is written by A. Aviles et al., and is distributed under the `MIT license <https://github.com/rodriguezmeza/wlcf/blob/main/LICENSE>`_. If you use this program in research work that results in publications, please cite the following paper:

`Abraham Arvizu et al., arXiv:2048.16847 <https://arxiv.org/abs/2408.16847>`_


Acknowledgements
----------------

wlcf use/is based on the following codes or projects:

* `FFTLog <https://github.com/xfangcosmo/2DFFTLog>`_
* `The BiHaloFit model of Takahashi <https://cosmo.phys.hirosaki-u.ac.jp/takahasi/codes_e.htm>`_
* `Zeno <https://home.ifa.hawaii.edu/users/barnes/zeno/index.html>`_
* `Numerical recipies <https://numerical.recipes/>`_
* `GSL <https://www.gnu.org/software/gsl/>`_
* `CLASS <https://github.com/lesgourg/class_public>`_

