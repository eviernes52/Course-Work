; Given this code as a starting point				(assignment4.asm )
; Program Description: Write a program that locates the first nonzero value in the array. If none is found make ESI point to sentinel value
; Creation date: 10/21/2021
; Revisions:	Rewrote including an array counter. Made ecx the lengthcount decrease by 1. Rewrote entire loop 1 as exchange required. 
; Date: 10/23/201			Modified by: Emiliano Viernes

.386
.model flat,stdcall
.stack 4096
ExitProcess PROTO, dwExitCode:DWORD
if( ebx <= ecx )
{
 eax = 5;
 edx = 6;
}
3. Write a program that implements th