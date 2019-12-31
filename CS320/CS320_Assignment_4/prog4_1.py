import sys

print("Assignment #4-1, kingofthenorth, kingofthenorth@gmail.com")

fileName = open(sys.argv[1])
for line in fileName.readlines():
    if str(line.split()):
        print(",".join(line.split()))

# fileName = file itself
# text = text within file
# line = line within file
