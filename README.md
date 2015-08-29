# CMSIS_LM3S
Hi There!!!

##What is This?
This is a **LM3S Cortex-M3 Series** startup project using *CMSIS DSP_Lib*,
*NEWLIB* and the *arm-none-eabi-gcc* toolchain.

##Why the LM3S Series?
At this time is the only **Cortex-M3** supported by **QEMU** so this is
intended as a ready to run project meanwhile you get a real development board.

##What do I need?
This was tested with:
* newlib v2.1
* arm-none-eabi-gcc v4.8.2
* arm-none-eabi-gdb v7.6.50
* QUEMU v2.0.0

All these tools are available on debian/ubuntu standard repositories.

##How do I compile this?
Edit *makedefs* file to point to your toolchain, then execute:
```
make
```

##How do I run this on QEMU?
```
cd ./examples/uart_hello_world/gcc
qemu-system-arm -M lm3s811evb -nographic -kernel uart_hello_world.bin
```
`Ctrl+a x` to quit QEMU

##How do I debug this with GDB?
Make with the *DEBUG symbols*
```
make clean
make DEBUG=1
```
Run QEMU stopped on the *Reset_Handler* with a dubugger server:
```
cd ./examples/uart_hello_world/gcc
qemu-system-arm -M lm3s811evb -nographic -kernel uart_hello_world.bin -s -S
```
On another terminal connect GDB to QEMU:
```
cd ./examples/uart_hello_world/gcc
arm-none-eabi-gdb
```
And on the gdb prompt execute:
```
file uart_hello_world.axf
target remote localhost:1234
```

##How do I link against the DSP_LIB?
You will need to edit your project *Makefile*:

1. Modify the `VPATH` variable on the project to include the required DSP_LIB subdirectories.

2. Add the needed object modules as a requirement for the <proyect>.afx task  
Make will automagically generate them.

###Example: *examples/arm_fir_example/Makefile*
Relevant code lines:
```
VPATH=../../CMSIS/DSP_Lib/Source/FilteringFunctions/
```
 
```
${COMPILER}/arm_fir_example_f32.axf: ${COMPILER}/arm_fir_f32.o
${COMPILER}/arm_fir_example_f32.axf: ${COMPILER}/arm_fir_init_f32.o

```

##Licences and stuff:
Linker, startup and configuration files for the lm3s where taken 
from *Stellaris CMSIS Package*  
Makefiles where also taken from *Stellaris CMSIS Package* and slightly modified
to work with CMSIS DSP_Lib examples  
All conserve the original LMI lincese on the file header.

./CMSIS/DSP_Lib and ./CMSIS/Include files are released under the terms of the BSD licence.

UART hello world and QEMU debug instructions were adapted from [this blog post]
(https://balau82.wordpress.com/2010/02/28/hello-world-for-bare-metal-arm-using-qemu/)

For everything else send me a cookie.
