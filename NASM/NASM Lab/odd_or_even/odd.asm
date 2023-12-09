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

section .data
	array : db 1,2,3,4
	n : db 4
section .bss
	odd : resb 3

section .text
	global _start:
_start:
	xor cx,cx
	xor ax,ax
	xor bx,bx
	
	mov cl,[n]
	mov edx,array
	mov bl,2
	sub bl,'0'
  label:mov al,[edx]
  	div bl
  	cmp ah,0
  	jne od
  	inc edx
  	
     od:mov [odd],
    	print odd,3
    	inc edx
    	loop label
    	
    	mov eax,1
    	mov ebx,0
    	int 80h
	

