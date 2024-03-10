# ARM_Feature_Detect

A program to detect ARM64 (AARCH64) CPU features

## Building

Building using `make` and your favorite compiler. Just set `CC` and `LD` to your favorite toolchain. Run the binary in the `bin` folder in the root directory of the project.

### Note for MacOS

System Integrity Protection prevents from accessing these registers. To circumvent this, using a Hypervisor (Virtual Machine or a Container using `Hypervisor.Framework` aka `hvf`), will allow access to the registers. The Guest OS running does not need to be macOS.
