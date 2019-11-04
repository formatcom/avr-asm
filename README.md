## INSTALL
~~~
- avr-gcc
- avr-gcc-c++
- avr-libc
- avr-gdb
- avrdude
- simavr
- radare2
~~~

## BUILD
~~~
$ avr-gcc -Wall -g -Os -mmcu=atmega328 -o demo.elf hello.c
~~~

### ENTRYPOINT -> Vector Reset

## headers/Intermix source code with disassembly
~~~
$ avr-objdump -h -S demo.elf
~~~

## the .data section 
### ref: https://www.microchip.com/webdoc/AVRLibcReferenceManual/mem_sections_1sec_dot_data.html
~~~
REF:
microchip.com/webdoc/AVRLibcReferenceManual/mem_sections_1sec_dot_noinit.html#mem_sections_1harvard_arch

Because of the Harvard architecture of the AVR devices, you must manually add 0x800000 to the address
you pass to the linker as the start of the section. Otherwise, the linker thinks you want to put the
.noinit section into the .text section instead of .data/.bss and will complain.


- Harvard architecture 

--------------------                      -------------------                      ------------------
|		   |       address bus    |                 |     address bus      |                |
|  Program Memory  |    <--------------   |                 |   -------------->    |   Data Memory  |
|	(ROM)      |       data bus       |      (CPU)      |      data bus        |      (RAM)     |
|		   |    -------------->   |                 |   <--------------    |                |
--------------------                      -------------------                      ------------------
~~~

## AVR Memory Usage
~~~
$ avr-size -C demo.elf
~~~

## Generating Intel Hex Files
### REF: https://www.microchip.com/webdoc/AVRLibcReferenceManual/group__demo__project_1demo_ihex.html
~~~
$ avr-objcopy -j .text -j .data -O ihex demo.elf demo.hex
~~~

## hex disassembly
~~~
$ avr-objdump --no-show-raw-insn -m avr --prefix-addresses -D demo.hex > demo.asm
~~~

## simavr mode debug demo.elf
~~~
$ simavr -g -m atmega328 demo.elf
~~~

## simavr mode debug demo.hex
~~~
$ simavr -g -m atmega328 -f 16000000 demo.hex
~~~

## connect debug with radare2
~~~
$ r2 -a avr -d gdb://localhost:1234
~~~

## dump
~~~
$ avrdude -F -v -pm328p -cstk500 -P/dev/ttyUSB0 -D -Uflash:r:reverse.hex:i
~~~
