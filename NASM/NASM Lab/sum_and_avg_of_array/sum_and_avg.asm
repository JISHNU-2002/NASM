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
xor eax,eax
xor ebx,ebx
mov edx,array

label:
mov bl,[edx]
add ax,bx
inc edx
loop label

mov [res],ax
print msg1,len1
print res,2
print msg,len

mov bl,[n]
div bl
add al,'0'
mov [avg],al
print msg2,len2
print avg,2
print msg,len

mov eax,1
mov ebx,0
int 80h

section .data
msg1: db 'Sum of elements : '
len1: equ $-msg1
msg2: db 'Average of elements : '
len2: equ $-msg2
msg: db '',0Ah
len: equ $-msg

array: db 1,2,3
n: db 3

section .bss
res: resb 2
avg: resb 2
