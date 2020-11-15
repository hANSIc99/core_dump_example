set disassembly-flavor intel
set write on
break *0x401110
run -c2
layout asm
layout reg
