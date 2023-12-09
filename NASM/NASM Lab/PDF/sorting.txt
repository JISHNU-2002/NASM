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

l3:mov esi,array
mov bl,[n]
dec bl

l2:mov al,[esi]
inc esi
cmp al,[esi]
jl l1
xchg al,[esi]
dec esi
mov [esi],al
inc esi

l1:dec bl
jnz l2
dec cl
jnz l3

mov esi,array
mov r8b,[n]
l4:add byte[esi],'0'
print esi,1
inc esi
dec r8b
jnz l4

mov eax,1
mov ebx,0
int 80h

section .data
array db 3,6,2,1,9,5
n db 6
