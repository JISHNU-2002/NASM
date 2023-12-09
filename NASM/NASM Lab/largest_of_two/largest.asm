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
read num1,2
print msg2,len2
read num2,2

mov al,[num1]
mov bl,[num2]
sub al,'0'
sub bl,'0'

cmp al,bl
je eq
jg first

print msg3,len3
print num2,2
print line,lenl
mov eax,1
mov ebx,0
int 80h

first:
print msg3,len3
print num1,2
print line,lenl
mov eax,1
mov ebx,0
int 80h

eq:
print msg,len
print line,lenl
mov eax,1
mov ebx,0
int 80h

section .data
msg1: db 'Enter first number : '
len1: equ $-msg1
msg2: db 'Enter second number : '
len2: equ $-msg2
msg3: db 'Largest number is : '
len3: equ $-msg3
msg: db 'Both numbers are equal..!',0Ah
len: equ $-msg
line: db '',0Ah
lenl: equ $-line

section .bss
num1: resb 2
num2: resb 2

