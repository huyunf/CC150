#Write code to remove duplicates from an unsorted linked list.
#FOLLOW UP
#How would you solve this problem if a temporary buffer is not allowed?
###############################################################################
import sys

inputa = raw_input("input your array:\n")
print "input arrary: ", inputa
inputarray = list(inputa)
print inputarray

flag = inputarray[0]
for i in range(len(inputarray)):
    pivot = inputarray[i]
    if i>0 and pivot==flag:
        continue
    else:
        j = i+1
        while j < len(inputarray):
            if inputarray[j] == pivot:
                inputarray[j] = flag
            j=j+1

print inputarray

cur=1
ser=1
while ser < len(inputarray):
    if inputarray[ser] != flag:
        inputarray[cur] = inputarray[ser]
        ser = ser + 1
        cur = cur + 1
    else:
        ser = ser + 1


print inputarray
print "cur: %d, ser:%d" % (cur, ser)



