.386
.model flat,stdcall
.stack 4096
ExitProcess PROTO, dwExitCode:DWORD
.data
sum DWORD ?
.code
main PROC
	mov eax, 7 
	add eax, 4
	mov sum, eax

	invoke ExitProcess, 0

	main endp
	end main