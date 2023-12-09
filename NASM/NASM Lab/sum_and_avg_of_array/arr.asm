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
 
 xor ecx,ecx
 mov ecx,[n]
 
 xor eax,eax
 xor ebx,ebx
 mov edx,array
 
 label:mov ebx,[edx]
 add eax,ebx
 inc edx
 loop label
 
 add eax,'0'
 mov [total],eax
 print total,1
 print msg,len
 
 xor eax,eax
 xor ebx,ebx
 mov ebx,[n]
 mov eax,[total]
 sub eax,'0'
 sub ebx,'0'
 div ebx
 add eax,'0'
 
 mov [avg],al
 print avg,1
 
 mov eax,1
 mov ebx,0
 int 80h

section .data
array: db 1,2,3,
n: db 5
msg: db '',0Ah
len: equ $-msg

section .bss
total: resb 2
avg: resb 2
 
