%macro print 2
mov eax,4
mov ebx,1
mov ecx,%1
mov edx,%2
int 80h
%endmacro

%macro read 2
mov eax,3
mov ebx,2
mov ecx,%1
mov edx,%2
int 80h
%endmacro

section .text
global _start:
_start:

print msg1,len1
read num,2

mov bl,[num]
sub bl,'0'
mov al,1

label:
mul bl
dec bl
jnz label

add al,'0'
mov [fac],al

print msg2,len2
print fac,3
print msg3,len3

mov eax,1
mov ebx,0
int 80h

section .data
msg1: db 'Entet number : '
len1: equ $-msg1
msg2: db 'Factorial of number : '
len2: equ $-msg2
msg3: db '',0Ah
len3: equ $-msg3

section .bss
num: resb 2
fac: resb 2
