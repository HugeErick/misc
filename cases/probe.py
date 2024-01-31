import datetime

currTime = datetime.datetime.now().strftime("%H:%M%p")

r0 = 18 #int
r1 = 16 #int
r2 = 14 #int
r3 = 3000 #int

theRegisters = [r0, r1, r2, r3]

mMemory = [None] * 21 

mMemory[15] = 30
mMemory[8] = 15

mMemory = ["trash" if item is None else item for item in mMemory]

def checkValues(theMemory, registers):
    print("registers values\n",registers) 
    print("memory\n",theMemory) 

print("\nCURRENT TIME\t" + currTime)
print("inital configuration\n")
print(", ".join(map(str, mMemory)))

print("\ncase 1")
print("memory[20] = r0 + r1")

mMemory[20] = theRegisters[0] + theRegisters[1] 
checkValues(mMemory, theRegisters)

print("\ncase 2")
print("r2 = memory[15]")

theRegisters[2] = int(mMemory[15])
checkValues(mMemory, theRegisters)

print("\ncase 3")
print("r2 = r2 - r2")
print("flags: cero")

theRegisters[2] -= theRegisters[2]
checkValues(mMemory, theRegisters)

print("\ncase 4")
print("r2 = memory[8]")

theRegisters[2] = int(mMemory[8])
checkValues(mMemory, theRegisters)

print("\ncase 5")
print("memory[9] = r0 - r3")
print("flags: unsigned overflow, negative")

mMemory[9] = theRegisters[0] - theRegisters[3] 
checkValues(mMemory, theRegisters)

print("\ncase 6")
print("r0 = memory[9]")

theRegisters[0] = int(mMemory[9])
checkValues(mMemory, theRegisters)

print("\ncase 7")
print("memory[0] = r0 | r3")
print("flags: negative")

mMemory[0] = theRegisters[0] | theRegisters[3] 
checkValues(mMemory, theRegisters)

print("\ncase 8")
print("r1 = memory[0]")

theRegisters[1] = int(mMemory[0])
checkValues(mMemory, theRegisters)

print("\ncase 9")
print("memory[1] = r1 & r3")

mMemory[1] = theRegisters[1] & theRegisters[3] 
checkValues(mMemory, theRegisters)




