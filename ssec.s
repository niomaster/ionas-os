entry start
start:
    mov ah, #0x03
    xor bh, bh
    int 0x10
    
    mov cx, #9
    mov bx, #0x0007
    mov bp, #mymsg
    mov ax, #0x1301
    int 0x10
    
ragequit:
    jmp ragequit
    
mymsg:
    .ascii "#YOLOSWAG"
