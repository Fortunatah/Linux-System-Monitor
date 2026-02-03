Linux System Monitor
A lightweight command-line utility written in C to monitor real-time system performance and hardware information on Linux systems.

Features
CPU Monitoring: Displays CPU model and the number of available cores.

Resource Usage: Real-time tracking of CPU usage percentage and memory consumption (Total, Used, Free, and Usage %).

System Status: Monitors total and currently running processes.

Uptime: Calculates and displays the duration the system has been active.

Live Updates: Refreshes the system status every 3 seconds.

File Structure
src/main.c: Contains the main application loop and the menu display logic.

include/get_system_info.c: Implements functions to parse system data from /proc files like /proc/stat, /proc/meminfo, and /proc/uptime.

include/get_system_info.h: Header file defining the sysInfo data structure and function prototypes.

MakeFile.mk: Compilation script to build the project.

Prerequisites
A Linux-based operating system (required for /proc filesystem access).

gcc compiler.

make utility.

Building the Project
To compile the project, use the provided Makefile:

Bash
make -f MakeFile.mk
This will create a build directory and compile the source code into an executable named main located in build/main.

Usage
Run the compiled executable from the root directory:

Bash
./build/main
The monitor will start in your terminal and update automatically every 3 seconds. To exit the monitor, press Ctrl + C.

How It Works
The program gathers data by reading and parsing several virtual files in the Linux kernel:

/proc/stat: Used for calculating CPU usage percentage.

/proc/cpuinfo: Used to identify the CPU model and core count.

/proc/meminfo: Used to calculate total and available RAM.

/proc/uptime: Used to determine system uptime.

/proc/loadavg: Used to retrieve process counts.
