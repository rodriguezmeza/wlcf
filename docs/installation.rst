

WLCF Installation
=================

The wlcf code is a C-based implementation for computing higher-order correlation functions in cosmology, with optional support for parallel execution via OpenMP and a Python interface for flexible workflows.
This section guides you through installing the code, compiling it, and running a first test example.

Requirements
------------

TThe code requires:

* A C compiler (recommended: `gcc >= 10`)

* Optional libraries:

  * **GSL** (GNU Scientific Library)
  * **FFTW3**

* Python (optional, for the wrapper interface):

  * `numpy`
  * `cython`

Compilation
-----------

Clone the repository:

.. code-block:: bash

    git clone https://github.com/your-repo/wlcf.git
    cd wlcf

Edit the file ``Makefile_machine`` if needed to specify library paths (GSL, FFTW).

Compile the code:

.. code-block:: bash

    make clean
    make

If GSL is not available, it can be disabled in `Makefile_settings` by setting:

.. code-block:: bash

   USEGSL = 0

If compilation is successful, the executable ``wlcf`` will be created in the main directory.

To verify the installation:

.. code-block:: bash

    cd tests
    ./wlcf


This runs the code using default parameters.

After execution, the following will be generated:

* `Output/` directory
* Correlation function files:

  * `zetam*`
  * `Bmells*`
  * `Bnk*`
* Log files (inside `Output/tmp`)
* Parameter file: `parameters_null-cballs-usedvalues*`


.. note::

This parameter file can be used as a template for custom runs.

**Python wrapper**

The code includes a Python interface for easier control and integration.

Build the wrapper

.. code-block:: bash

    make all

Install dependencies if needed:

You can use the wrapper as

.. code-block:: python

    from wlcfpy import wlcf

    w = wlcf()
    w.set(numberThreads=4, verbose=1)
    w.Run()

**Parallel execution (OpenMP)**

The code supports shared-memory parallelism using OpenMP.

To control the number of threads:

.. code-block:: bash

    export OMP_NUM_THREADS=8


.. note::

The code may also set the number of threads internally using the parameter `numberThreads`.


**HPC example (Perlmutter)**

On **NERSC Perlmutter**, a typical workflow in an interactive node is:

.. code-block:: bash

    module load gcc
    salloc -N 1 -C cpu -q interactive -t 01:00:00
    export OMP_NUM_THREADS=32
    cd wlcf/tests
    ../wlcf


**Notes**

* If compilation fails, verify library paths in `Makefile_machine`
* OpenMP requires a compatible compiler (e.g., `gcc` with `-fopenmp`)
* Performance may saturate at high thread counts depending on the workload
* For large runs, always use compute nodes rather than login nodes
