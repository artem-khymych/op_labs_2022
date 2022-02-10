def inputFile():
    inFile = open("inputFile.txt","w")
    print("enter the program")
    while (1):
            line = input()
            if line=="":
                inFile.write("\n")
                continue
            if ord(line[-1]) <= 31:
                inFile.write(line.replace(line[-1],""))
                break
            inFile.write(line + "\n")
    inFile.close()


def find_idents():
    
    inputFile = open("inputFile.txt","r")
    idents=""
    for line in inputFile:
        if line=="\n":
            continue
        elif line.find("==")!= -1 or line.find("!=")!= -1:
            continue
        elif line.find("+=")!= -1 or line.find("-=")!= -1:
            continue
        elif line.find("*=")!= -1 or line.find("/=")!= -1:
            continue
        if line.find("=")!= -1:
            idents+=line[:line.find("=")]+"\n"
    inputFile.close()
    return idents

def output(idents):
    outputFile = open("outputFile.txt","w")
    outputFile.write(idents)
    print("output file: ",idents)

inputFile()
idents = find_idents()
output(idents)