%macro prints 2
mov eax,4
mov ebx,1
mov ecx,%1
mov edx,%2
int 80h
%endmacro

%macro reads 2
mov eax,3
mov ebx,2
mov ecx,%1
mov edx,%2
int 80h
%endmacro

section .data
msg :db 'enter two numbers',0Ah
len: db $-msg

section .bss
a: resb 2
b:resb 2
c: resb 2


section .text
global _start:
_start:
prints msg,len
reads a,2
prints msg,len
reads b,2

prints b,2


mov eax,1
mov ebx,0
int 80h
