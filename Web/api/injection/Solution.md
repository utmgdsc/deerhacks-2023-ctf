This is almost identifcal to our command injeciton workshop, the only thing different was the location of the file was now at /app/dont_share.txt.
To get the flag you had to upload a file with the following name: 
```md
test`cd ..;cd ..;cat /app/dont_share.txt`.mp3
```

Another flag is located in the "encrypt" binary. By reading the source code, we can determine that an encoded flag is stored as:
uint8_t flag[FLAG_SIZE] = {0x6b, 0x6f, 0x6a, 0x7b, 0x6d, 0x82, 0x3a, 0x55, 0x6a, 0x79, 0x80, 0x77, 0x3e, 0x3a, 0x6b, 0x66, 0x55, 0x37, 0x66, 0x74, 0x37, 0x59, 0x3a, 0x66, 0x58, 0x6f, 0x3f, 0x4d, 0x7d, 0x84};
When encrypting the file, each byte of flag is decremented by 7 and used to encode one of the file's bytes with XOR.

By analyzing the binary, this process can be observed in the following disassembly snippet:

...
0x000000000000129d <+180>:   mov    eax,DWORD PTR [rbp-0x10]
0x00000000000012a0 <+183>:   movsxd rdx,eax
0x00000000000012a3 <+186>:   imul   rdx,rdx,0xffffffff88888889
0x00000000000012aa <+193>:   shr    rdx,0x20
0x00000000000012ae <+197>:   add    edx,eax
0x00000000000012b0 <+199>:   sar    edx,0x4
0x00000000000012b3 <+202>:   mov    ecx,eax
0x00000000000012b5 <+204>:   sar    ecx,0x1f
0x00000000000012b8 <+207>:   sub    edx,ecx
0x00000000000012ba <+209>:   imul   ecx,edx,0x1e
0x00000000000012bd <+212>:   sub    eax,ecx
0x00000000000012bf <+214>:   mov    edx,eax
0x00000000000012c1 <+216>:   movsxd rax,edx
0x00000000000012c4 <+219>:   lea    rdx,[rip+0x2d45]        # 0x4010 <flag>
0x00000000000012cb <+226>:   movzx  eax,BYTE PTR [rax+rdx*1]
0x00000000000012cf <+230>:   mov    BYTE PTR [rbp-0x11],al
0x00000000000012d2 <+233>:   sub    BYTE PTR [rbp-0x11],0x7
0x00000000000012d6 <+237>:   mov    eax,DWORD PTR [rbp-0xc]
0x00000000000012d9 <+240>:   xor    al,BYTE PTR [rbp-0x11]
0x00000000000012dc <+243>:   movzx  eax,al
0x00000000000012df <+246>:   mov    esi,eax
0x00000000000012e1 <+248>:   lea    rax,[rip+0xd4e]        # 0x2036
0x00000000000012e8 <+255>:   mov    rdi,rax
0x00000000000012eb <+258>:   mov    eax,0x0
0x00000000000012f0 <+263>:   call   0x10b0 <printf@plt>
0x00000000000012f5 <+268>:   add    DWORD PTR [rbp-0x10],0x1
0x00000000000012f9 <+272>:   mov    rax,QWORD PTR [rbp-0x8]
0x00000000000012fd <+276>:   mov    rdi,rax
0x0000000000001300 <+279>:   call   0x10c0 <fgetc@plt>
0x0000000000001305 <+284>:   mov    DWORD PTR [rbp-0xc],eax
0x0000000000001308 <+287>:   cmp    DWORD PTR [rbp-0xc],0xffffffff
0x000000000000130c <+291>:   jne    0x129d <main+180>
...

Picking this apart, we see that the flag's address is loaded at <+219>. Then, a byte is loaded into eax, which is subsequently decremented by 7. This value is used in the XOR operation at <+240> to encode the byte taken from the input file. From here we have the motivation to try applying this -7 shift to the flag bytes by hand to see the key to the encrypted file. This comes out to be: dhctf{3Ncryp73d_N0_m0R3_Qh8Fv}
