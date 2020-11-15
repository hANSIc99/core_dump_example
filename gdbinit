set disassembly-flavor intel
set write on
break *0x401110
run
layout asm
layout reg
