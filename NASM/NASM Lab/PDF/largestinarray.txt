%macro print 2
mov eax,4
mov ebx,1
mov ecx,%1
mov edx,%2
int 80h
%endmacro

section .text
global _start:
_start:

xor cx,cx
mov cl,[n]
xor ax,ax
xor bx,bx
mov edx,array
mov al,[edx]

label:inc edx
mov bl,[edx]
cmp ax,bx
jg first
mov ax,bx

first:
loop label
add ax,'0'
mov [result],ax
print result,2
mov eax,1
mov ebx,0
int 80h

section .data
array db 3,6,2,1,9,5
n db 5

section .bss
result resb 2
