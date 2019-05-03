Corewar
======

About
-----

>Core War is a 1984 programming game created by D. G. Jones and A. K. Dewdney in which two or more battle programs (called "warriors") compete for control of a virtual computer.
These battle programs are written in an abstract assembly language called Redcode.

42 Version
----------

Here's how it looks like:

![Corewar](resources/screenshots/vm_sample.gif)

We don't use the same set of assembly instructions as the original Corewar and we have some modulo limitations for the read and write ranges.

Subjects: [corewar.fr.pdf](subject/corewar.fr.pdf) or [corewar.en.pdf](subject/corewar.en.pdf)

##### How to use it ?

* First you'll need to write a .s file with a set of assembly instructions
    * You can create your own champion with [this set below](#assembler-instructions)
    * Or you can just use one of the many warriors in the resources/champs directory
* Then you'll have to compile it using the `asm` binary
* Then just execute the `corewar` binary with your warrior(s) as arguments

>This was the final project of the Algorithm branch.

## Set up
------------

Just run `make`... then enjoy!

Works on OS X and Linux Debian / Ubuntu. The `nCurses` library is used for the viewer.

## Usage
-----

#### corewar - Virtual Machine
`./corewar [-hcvdD [cycle nb]] ([-n nb] file.cor) ...`

![usage_corewar](resources/screenshots/corewar_usage.jpg)

You can combine some flags. For example the flags -c (nCurses) and -v (Verbose)

![verbose](resources/screenshots/vm_sample_verbose.gif)

##### Keys
* `spacebar` Play / Pause
* `▲` or `▶` Speed up (respectively +1 or +10)
* `▼` or `◀` Speed down (respectively -1 or -10)
* `@` Go to cycle ... Then an integer superior than the current cycle is expected. Validate with `Enter`
* `end` Quit properly the program

#### asm - Assembler
`./asm [-adfh] file.s`

![usage_corewar](resources/screenshots/asm_usage.jpg)

#### rasm - Disassembler
`./rasm file.cor ...`

![usage_corewar](resources/screenshots/rasm_usage.jpg)

## Assembler instructions
--------

| OP | Effects | Charge | Changes the `carry` ? | Octal Coding | `DIR` Bytes |
|:-: | ------- | :----------------: | :--------------------: | :----------: | :----------------: |
| **`live`** → `DIR` | `live` is followed by 4 bytes which represents the player's number as unsigned int. This instruction means the player is alive. | 10 | No | No | 4 |
| **`ld`** → `DIR`⎮`IND`,`REG` | Loads a value from an address into a register.  *Example: `ld 34,r3` stores `REG_SIZE` octets from 34 bytes after the current address (`PC + (34 % IDX_MOD)`) into the register `r3`.*| 5 | Yes | Yes | 4 |
| **`st`** → `REG`,`IND`⎮`REG` | Stores the value of a register to an address or into an other register.  *Example1: `st r4,34` stores the value of `r4` to the address `(PC + (34 % IDX_MOD))`*  *Example2: `st r3,r8` copies `r3` into `r8`* | 5 | No | Yes | - |
| **`add`** → `REG`,`REG`,`REG` | The third parameter is the result of the addition of the first two.  *Example: `add r2,r3,r5` sums `r2` and `r3` and stores the result into `r5`* | 10 | Yes | Yes | - |
| **`sub`** → `REG`,`REG`,`REG` | Like `add` with a substraction. | 10 | Yes | Yes | - |
| **`and`** → `REG`⎮`DIR`⎮`IND`,`REG`⎮`DIR`⎮`IND`,`REG` | Applies a binary AND '&' to the first two parameters. Then stores the result into a register.  *Example: `and r2,%0,r3` stores the result of `r2 & %0` into `r3`* | 6 | Yes | Yes | 4 |
| **`or`** → `REG`⎮`DIR`⎮`IND`,`REG`⎮`DIR`⎮`IND`,`REG` | Like `and` with a binary OR 'âŽ®'. | 6 | Yes | Yes | 4 |
| **`xor`** → `REG`⎮`DIR`⎮`IND`,`REG`⎮`DIR`⎮`IND`,`REG` | Like `and` with a binary EXCLUSIVE OR '^'. | 6 | Yes | Yes | 4 |
| **`zjmp`** → `DIR` | Takes an index and makes a jump to this index if the carry is set to 1. If the carry is null, `zjmp` does nothing but consumes the same amount of time.  *Example: `zjmp %23` (with carry == 1) PC becames `(PC + (23 % IDX_MOD))`* | 20 | No | No | 2 |
| **`ldi`** → `REG`⎮`DIR`⎮`IND`,`REG`⎮`DIR`,`REG` | Sums the first two parameters. Considers this sum as a relative address. Then reads `REG_SIZE` bytes from this address and stores it into a register.  *Example: `ldi 3,%4,r1` reads `IND_SIZE` bytes at `(PC + (3 % IDX_MOD))` and adds 4 to this value. Lets call this sum `S`. Then reads `REG_SIZE` bytes at `(PC + (S % IDX_MOD))` and copies the value into `r1`.* | 25 | No | Yes | 2 |
| **`sti`** → `REG`,`REG`⎮`DIR`⎮`IND`,`REG`⎮`DIR` | Sums the last two parameters and considers it as an address. Then copies `REG_SIZE` bytes of a register (1st parameter) and stores it at the calculated address.  *Example:`sti r2,%4,%5` copies  `REG_SIZE` bytes from `r2` at the address `(4 + 5)`.*| 25 | No | Yes | 2 |
| **`fork`** → `DIR` | Creates a new process at the address `(PC + (FIRST_PARAMETER % IDX_MOD))`. The new process inherits the attributes of his father. | 800 | No | No | 2 |
| **`lld`** → `DIR`⎮`IND`,`REG` | Like `ld` without scope limit `%IDX_MOD` | 10 | Yes | Yes | 4 |
| **`lldi`** → `REG`⎮`DIR`⎮`IND`,`REG`⎮`DIR`,`REG` | Like `ldi` without scope limit `%IDX_MOD`. | 50 | Yes | Yes | 2 |
| **`lfork`** → `DIR` | Like `fork` without scope limit `%IDX_MOD`. | 1000 | No | No | 2 |
| **`aff`** → `REG` | Displays the an ASCII character into a buffer. The buffer is displayed at the end of the game.  *Example: `ld %42,r3` then `aff r3` will display '\*'.* | 2 | No | Yes | - |

* `DIR`: Direct type: Number as unsigned int (4 bytes) or adress as unsigned short (2 bytes)
* `IND`: Indirect type: Relative address
* `REG`: Register type: Register which stores a numeric value
* `IDX_MOD`: is a scope limit