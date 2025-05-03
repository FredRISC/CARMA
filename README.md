# CARMA

Team CARMA explores efficient heterogeneous SoC design by integrating RISC-V scalar cores with a Vector Processing Unit (Saturn) and a Deep Neural Network accelerator (Gemmini) using the Chipyard framework. While existing accelerators excel at either vector-heavy or structured tasks, our hybrid architecture dynamically leverages both. Saturn outperforms in vector workloads like matrix transposition, while Gemmini leads in dense operations like GEMM. By configuring the accelerators and evaluating performance, we demonstrate the benefits of this modular approach. Future work includes full hybrid integration, dynamic workload scheduling, and post-layout performance/power/area (PPA) analysis.


## How to reproduce the project

Everything is required to use the Chipyard framework to configure, build, generate hardware, develope testbenches and run simulation.
To use our project, you'll need to install the Chipyard framework in your local machine or remote server, AWS EC2 F2 instance especially for FireSim simulatiom. 


Follow the following steps for installing and setting up Chipyard. (Or follow the guidance in Chipyard's website https://chipyard.readthedocs.io/en/latest/Chipyard-Basics/Initial-Repo-Setup.html)

1. Install conda
2. git clone https://github.com/ucb-bar/chipyard.git
3. cd chipyard
4. ./build-setup.sh riscv-tools

The Carma.scala is a config file which can be used to configure the generators.
After configuring, follow these steps for building the generator.

1. cd sims/verilator
2. make CONFIG=<your_config_class>

This will build the generator you have configured. If you want to build it with many given testbenches(in chipyard) 

1. make CONFIG=<your_config_class> run-binary BINARY=(for eg)../../generators/gemmini/software/gemmini-rocc-tests/build/baremetalC/template-baremetal (testbench file location)
