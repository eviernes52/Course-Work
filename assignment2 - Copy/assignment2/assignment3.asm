
; Evaluate  loops and arrays in one program				(assignment3.asm )
; Program Description:Write a program with a loop and indexed addressing that calculates the sum of all the gaps between successive array elements.
; Creation date: 9/28/2021
; Revisions:	Similar orignial structure to part a, then had to relate with the sum array previously seen. Also included a counter as a for loop would have count++ not sure if a different approach can be taken with project32 library
; Revisions:		Figured out code wasn't running after a comment was broken up with no semi colon making code not run for a long time
; Date: 10/3/2021			Modified by: Emiliano Viernes

.386
.model flat,stdcall
.stack 4096
ExitProcess PROTO, dwExitCode:DWORD

.data
array DWORD 0, 2, 5, 9, 10 ;orignial array with 5 values where the gaps from one value to another total to 10
gapCount DWORD ?		   ;dword that represents the count stored inside loop 1
.code
main PROC
	mov esi, OFFSET array      ; 1: ESI = address of array
	mov ecx, LENGTHOF array -1 ; 2: initialize loop counter = 5 however since alternating you want to stop at second to last integer in this case it being the 4th 
	mov eax,0				   ; 3: zero the accumulator sum = 0

L1:							   ; 4: Marks the start of the loop hence the name L1=(Loop1)
	mov eax,[esi]		       ; 5: moves esi, eax by derefrence
	add esi, 4				   ; 6: Take in to account that var is dword therfore 4 is needed (not sure about inclusion of pointerw however still works as is)
	mov ebx,[esi]		       ; 7: Take in to account that var is dword therfore 4 i needed
	sub ebx,eax				   ; 7: Subtracts eax and ebx 
	add gapCount,ebx		   ; 8: gap is the custom for loop counter like count++ in regards to c++ 
	add esi,TYPE array		   ; 9: point to the next element (5 bytes)
	loop L1					   ; 10: repeats loop until ecx = 0

	invoke ExitProcess, 0	   ; 11: exits program
main endp
end main