%macro print 2
mov eax,4
mov ebx,1
mov ecx,%1
mov edx,%2
int 80h
%endmacro

section .data
array db 3,6,2,1,9,5
n db 5
key db 2
msg1: db 'Key found..!'
len1: equ $-msg1
msg2: db 'Key not found..!'
len2: equ $-msg2
msg3: db 0Ah
len3: equ $-msg3

section .text
global _start:
_start:

xor eax,eax
xor ebx,ebx
xor cx,cx

mov cl,[n]
mov edx,array
mov al,[key]

label:mov bl,[edx]
cmp al,bl
jz found
inc edx
loop label
jmp notfound

found:
print msg1,len1
jmp last

notfound:
print msg2,len2

last:print msg3,len3
mov eax,1
mov ebx,0
int 80h

