; Evaluate  loops and arrays in one program				(assignment3.asm )
; Program Description: Write a program with a loop and indexed addressing that exchanges every pair of values in an array with an even number of elements. Therefore, item i will exchange with item i+1, and item i+2 will exchange with item i+3, and so on.
; Creation date: 9/24/2021
; Revisions:	Started the process
; Date: 9/24/201			Modified by: Emiliano Viernes

.386
.model flat,stdcall
.stack 4096
ExitProcess PROTO, dwExitCode:DWORD
.data
intarray DWORD 100h, 200h, 300h, 400h, 500h, 600h
.code
main PROC
	mov edi, OFFSET intarray   ; 1:EDI = adress of intarray
	mov ecx, LENGTHOF intarray ; 2: initialize loop counter = 6
	mov ax,0				   ; 3: sum = 0

L1:							   ; 4: Marks the start of the loop
	add eax,[edi]
	add edi, TYPE intarray	   ; 6: point to next element (6 bytes)
	loop L1					   ; repeats until EXC = 0
	
	invoke ExitProcess, 0
main endp
end main