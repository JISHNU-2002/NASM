section .text
global _start:
_start:

mov eax,4
mov ebx,1
mov ecx,msg1
mov edx,len1
int 80h

mov eax,3
mov ebx,2
mov ecx,num1
mov edx,2
int 80h

mov eax,4
mov ebx,1
mov ecx,msg1
mov edx,len1
int 80h

mov eax,3
mov ebx,2
mov ecx,num2
mov edx,2
int 80h

mov eax,[num1]
sub eax,'0'
mov ebx,[num2]
sub ebx,'0'

mul ebx

add eax,'0'
mov [sum],al

mov eax,4
mov ebx,1
mov ecx,msg2
mov edx,len2
int 80h

mov eax,4
mov ebx,1
mov ecx,sum
mov edx,2
int 80h

mov eax,4
mov ebx,1
mov ecx,msg3
mov edx,len3
int 80h

mov eax,1
mov ebx,0
int 80h

section .data
msg1: db 'enter digits : '
len1: equ $-msg1
msg2: db 'product is : '
len2: equ $-msg2
msg3: db '',0Ah
len3: equ $-msg3

section .bss
num1: resb 2
num2: resb 2
sum: resb 2
