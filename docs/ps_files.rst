
Linear power spectrum files
===========

This section describes the format of the linear power spectrum required to compute correlation functions using **wlcf**.


**Standard formats**

:columns-ascii: The linear power spectrum is provided as an ASCII file with two columns:


- ``k`` = wavenumber in units of \( h \,\mathrm{Mpc}^{-1} \)
- ``P(k)`` = linear matter power spectrum in units of \( (\mathrm{Mpc}/h)^3 \)

Each row corresponds to a value of \( k \) and its associated power spectrum.

Example::

    # k [h/Mpc]    P(k) [(Mpc/h)^3]
    1.000000e-03   2.345678e+04
    2.000000e-03   1.987654e+04
    5.000000e-03   1.234567e+04
    ...



**Usage in wlcf**

To use a power spectrum file, specify:

::

    fnamePS=./input/linear_pk.txt


The linear power spectrum can be generated using external Boltzmann solvers such as:

* **CAMB**
* **CLASS**

These tools allow you to compute ( P(k) ) for a given cosmological model.

.. note::

Make sure to export the power spectrum at the desired redshift and in the correct units.
