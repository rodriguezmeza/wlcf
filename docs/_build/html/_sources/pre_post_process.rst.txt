
Pre/Post processing
===================

This section describes the various pre/pos processing for controlling
what the `wlcf` before/after main processing:

**Pre-processing**
------------------

Pre-processing involves preparing all required inputs before running **wlcf**.

Typical tasks include:

* Generating the **linear power spectrum** ( P(k) ) using external tools (e.g., CAMB or CLASS)
* Preparing the **weak lensing kernel** file (if `Wg=1`)
* Setting cosmological parameters consistently with the input data
* Organizing input files into accessible directories


.. note::

The accuracy of the final correlation functions strongly depends on the quality and consistency of the input power spectrum and cosmological parameters.



**Post-processing**
------------------

Post-processing refers to analyzing and visualizing the outputs produced by **wlcf**.

Typical tasks include:

* Reading output files such as:

  * `zetam*` (angular correlation functions)
  * `Bmells*` (projected bispectrum)
  * `Bnk*` (bispectrum in Fourier space)

* Plotting results (e.g., multipoles, angular correlations)

* Comparing results across different cosmologies

* Converting outputs into formats suitable for further analysis


**Notes**


* Pre-processing is external to **wlcf**; the code assumes inputs are already prepared.
* Post-processing is flexible and depends on the scientific goals.
* For large parameter scans, combining the Python interface with HPC resources is recommended.
