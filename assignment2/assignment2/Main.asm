; Evaluate  loops and arrays in one program				(assignment3.asm )
; Program Description: Write a program with a loop and indexed addressing that exchanges every pair of values in an array with an even number of elements. Therefore, item i will exchange with item i+1, and item i+2 will exchange with item i+3, and so on.
; Creation date: 9/24/2021
; Revisions:	Rewrote including an array counter. Made ecx the lengthcount decrease by 1. Rewrote entire loop 1 as exchange required. 
; Revisions:    Instead of manual swap I took a look at lecture 4 slides and performed XCHG as before I was rewriting and including an inverse order.
; Date: 10/3/201			Modified by: Emiliano Viernes

.386
.model flat,stdcall
.stack 4096
ExitProcess PROTO, dwExitCode:DWORD
.data
array DWORD 100, 200, 300, 
.code
main PROC
	mov edi, OFFSET array      ; 1: EDI = adress of intarray
	mov ecx, LENGTHOF array -1 ; 2: initialize loop counter = 6 minus the inital or last depending on perspective therefore -1 or dec to make the proper 3 swaps
	mov eax, 0			       ; 3: sum = 0

L1:							   ; 4: Marks the start of the loop
	mov eax, [edi]		       ; 5: moves from array to eax
	add edi, 3				   
	XCHG eax, [edi]			   ; 6:	perform the exchange of the values of two operand (performs my swap)
	mov [edi], eax			   ; 7: moves eax starting exchange
	add edi, TYPE array	       ; 8: from edi points to next element (6 bytes with 3 pairs that must be exhanged)
	loop L1					   ; 9: repeats until EXC = 0
	invoke ExitProcess, 0      ; 10: exits  program after last loop is terminated
main endp
end main