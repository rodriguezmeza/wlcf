
Parameters
========================

This section describes the various parameters **wlcf** needs for controlling
the computation of the three-point correlation function (3PCF) for weak lensing convergence.

Parameters related to the cosmological model
-------------------------------------------

:z: (float) Redshift at which the correlation functions are evaluated.

:h: (float) Dimensionless Hubble parameter.

:sigma8: (float) Normalization of the matter power spectrum.

:Omb: (float) Baryon density parameter.

:Omc: (float) Cold dark matter density parameter.

:Omnu: (float, default=0.0) Massive neutrino density parameter.

:ns: (float) Spectral index of the primordial power spectrum.

:w: (float, default=-1.0) Dark energy equation of state parameter.

Parameters to control the input power spectrum
-------------------------------------

:fnamePS: (str) [alias: ps] File containing the linear matter power spectrum ( P(k) ).


Use it as::

    fnamePS=./input/linear_pk.txt


Parameters related to the weak lensing kernel
---------------------------------------------


:Wg: (int, default=0) Controls how the lensing kernel is defined.

- ``0`` = Dirac delta at the redshift bin
- ``1`` = Read kernel from file

:fWgchi: (str) [alias: fwgchi] File containing the weak lensing kernel ( W_g(\chi) ).


Use it as::

    fWgchi=./input/Wg_Takahashi_z05078.txt


Parameters controlling the model and numerical setup
--------------------------------------------------

:tree_level: (int, default=3) [alias: tlev] Model used for the bispectrum calculation.


- ``1`` = Standard Perturbation Theory (SPT)  
- ``2`` = Tree-level approximation  
- ``3`` = Effective Field Theory (EFT)  
- ``4`` = Halo Model (HM)  


:zbin: (float) Redshift bin used in the projection.

:mMax: (int) Maximum multipole order for the expansion.

:chiQuadSteps: (int) [alias: chiqst] Number of integration steps over comoving distance.

:GLpoints: (int) [alias: gl] Number of Gauss–Legendre points.

:Nell: (int) Number of angular multipoles.

:ellmin: (float) Minimum multipole value.

:ellmax: (float) Maximum multipole value.



Parameters to control output files
----------------------------------


:rootDir: (str, default="Output") [alias: root] Directory where output files will be written.

:prefix: (str, default="run1_") [alias: pre] Prefix for output file names.

:path_Bells: (str, default="Bell_outputs") [alias: bellout] Directory where angular correlation functions are stored.

:writevectors: (bool, default=true) Whether to write intermediate vectors.





Miscellaneous parameters
----------------------------------

:verbose: (int, default=2) [alias: verb] Controls the amount of information printed to the terminal.


- 0 = no output unless there is an error  
- 1 = warnings  
- 2 = progress information  
- 3 = debugging output  


:verbose_log: (int, default=1) [alias: verblog] Controls logging to file inside `Output/tmp`.

:chatty: (int, default=2) Additional verbosity level for internal messages.

:numberThreads: (int, default=4) [alias: nthreads] Number of OpenMP threads used during execution.


It is required to enable OpenMP by setting::

    OPENMPMACHINE = 1

in ``Makefile_settings`` and recompiling the code.


:options: (str, default="") [alias: opt] Additional options controlling code behavior.



.. note::

* It is not necessary to specify all parameters. Only the relevant ones need to be provided. The rest will take default values.

* A parameter file is automatically generated after each run::

    Output/parameters_null-cballs-usedvalues

This file can be used as a template for custom configurations.

* When specifying `rootDir`, avoid using `./` at the beginning or `/` at the end if it is a local directory.
