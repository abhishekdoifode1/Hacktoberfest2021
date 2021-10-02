def BWT(input):
    assert "$" not in input
    input = input + "$"
    rottable = [input[i:] + input[:i] for i in range(len(input))] # Table of rotations of the sequence
    print("Rotation table ",rottable)
    sorttable = sorted(rottable) # sortted rotation table
    print("Sorted table ",sorttable)
    lcol = [row[-1:] for row in sorttable]
    bwt = ''.join(lcol)
    print(" Burrow Wheeler Transform ",bwt)
    print("===============================================================================================================")
    IBWT(bwt)

def IBWT(bwt):
    invtable = [""] * len(bwt) # creating empty table
    for i in range(len(bwt)):
        invtable = [bwt[i] + invtable[i] for i in range(len(bwt))]
        print("Unsorted table : ",invtable)
        invtable = sorted(invtable)
        print("Sorted table : ",invtable)
        print()
    ibwt = [row for row in invtable if row.endswith("$")][0] # Finding the correct row i.e., row ending with $
    ibwt = ibwt.rstrip("$") # Getting rid of the start and end marker $
    print(" Inverse Burrow Wheeler Transform ",ibwt)

print("Example Sequence 1 : TTGGAAGA")
print(BWT('TTGGAAGA'))
print("Example Sequence 2 : TGGACAAG")
print(BWT('TGGACAAG'))
print("Example Sequence 3 : TTCTTTTT")
print(BWT('TTCTTTTT'))
print("Example Sequence 4 : AGAACCTG")
print(BWT('AGAACCTG'))