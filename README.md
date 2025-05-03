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


## Build the hardware (SoC)

The Carma.scala is a config file which can be used to configure the generators (hardware).
After downloading the CARMA.scala, put it in ($Chipyard_Base)/generators/chipyard/src/main/scala/config. Now, go to each generator's directory for more detailed configurations.

Next, if everything is ready, follow these steps for building the generator.

1. cd sims/verilator
2. make CONFIG=<your_config_class>

This will build the generator you have configured. 


## Test your hardware (SoC) with testbenches

Some testbences of Saturn-Soc and Gemmini-SoC are provided in the CARMA_tb.
If you want to build  the hardware and test it with a given testbench in a single make command

1. make CONFIG=<your_config_class> run-binary BINARY=(for eg)../../generators/gemmini/software/gemmini-rocc-tests/build/baremetalC/template-baremetal (testbench file location)




## Statements:

1. The codes are mostly from UC-Berkely and ETH Zurich and University of Bologna
2. We cannot put everything on this github repo since Chipyard is large.

