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

mov al,[num]
sub al,'0'
mov bl,'2'
sub bl,'0'
div bl

cmp ah,0
jne odd

print msg2,len2
print msg,len
mov eax,1
mov ebx,0
int 80h

odd:
print msg3,len3
print msg,len
mov eax,1
mov ebx,0
int 80h

section .data
msg1: db 'Enter the number : '
len1: equ $-msg1
msg2: db 'Number is even..!'
len2: equ $-msg2
msg3: db 'Number is odd..!'
len3: equ $-msg3
msg: db '',0Ah
len: equ $-msg

section .bss
num: resb 2
