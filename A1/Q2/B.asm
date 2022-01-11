extern C
section .data
  text db " This is funtion C",10

section .bss
  var resb 8
section .text
  global B
B:
  mov [var],rdi
  mov rax,1
  mov rdi,1
  mov rsi,var
  mov rdx,8
  syscall

  mov rax,1
  mov rdi,1
  mov rsi,text
  mov rdx,19
  syscall

  push C 
  ret