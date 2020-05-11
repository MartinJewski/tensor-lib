[Alpha]My bachelor thesis in which I am implementing tensors 
and the operations contraction, trace and reordering, with a special
focus on compile time vs. runtime execution. 

It contains an implementation at compile time
and runtime, where the runtime version is implemented using standard C++17
or the ranges-v3 library(C++20) and the compile time version is implemented
using only C++17 features.



tested on my machine using:
tested with gcc 9.2, 9.3

ranges-v3 by ericnibler https://github.com/ericniebler/range-v3

CLion IDE project option to use C++20
-CMAKE minimum VERSION 3.15
-CMAKE_CXX_STANDARD 20

Kubuntu 19.04

------ <br />
update gcc with the one-liner to install the gcc/g++ compiler< br />

sudo apt-get update -y && 
sudo apt-get upgrade -y && 
sudo apt-get dist-upgrade -y && 
sudo apt-get install build-essential software-properties-common -y && 
sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y && 
sudo apt-get update -y && 
sudo apt-get install gcc-9 g++-9 -y && 
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-9 60 --slave /usr/bin/g++ g++ /usr/bin/g++-9 && 
sudo update-alternatives --config gcc

(rec: by peterhanneman https://gist.github.com/application2000/73fd6f4bf1be6600a2cf9f56315a2d91)

