#Design an algorithm and write code to remove the duplicate characters in a string without
#using any additional buffer. NOTE: One or two additional variables are fine. An extra copy of the array is not.
#FOLLOW UP
#Write the test cases for this method.
##################################################################################################
import sys

class NonDupString:
    OriginalString  = ""
    TargetString    = ""
    DupMap          = {}

    def __init__(self, s):
        self.OriginalString = s

    def check(self):
        print "Original String: %s, TargetString: %s" % (self.OriginalString, self.TargetString)

    def RemoveDup(self):
        self.DupMap.clear()
        for s in self.OriginalString:
            if self.DupMap.has_key(s):
                self.DupMap[s] = self.DupMap[s]+1
            else:
                self.DupMap[s] = 1
                self.TargetString = self.TargetString + s

if __name__=='__main__':

    if len(sys.argv) == 1:
        InputString = 'hello'
    else:
        InputString = sys.argv[1]

    NS = NonDupString(InputString)

    NS.check()

    NS.RemoveDup()

    NS.check()

    print NS.DupMap

