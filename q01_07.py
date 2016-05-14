# Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column is set to 0.
##########################################################################################################
import sys
from copy import deepcopy

class Matrix:

    row = 0
    col = 0
    OriginalMatrix = []
    ZeroForAllMatrix = []

    def __init__(self, InputM, x=0, y=0):
        if x!=0 and y!=0:
            # validate the input Matrix
            if len(InputM) != x*y:
                print "Invalid Input Matrix That Length of col*row != len(input array)"
            else:
                print "Input %dx%d Matrix!" % (x, y)
                self.row = y
                self.col = x
                for i in range(y):
                    a = []
                    for j in range(x):
                        a.append(InputM[i*x+j])
                    self.OriginalMatrix.append(a)
        else:
            colSize = len(InputM[0])
            for row in InputM:
                if len(row) != colSize:
                    print "Invalid Input Matrix that the row size %d different with first row size %d" % (len(row), colSize)
                else:
                    self.row = len(InputM)
                    self.col = len(InputM[0])
                    self.OriginalMatrix = InputM

    @staticmethod
    def DumpMatrix(Matrix, x, y):
        print '----------------------------'
        for row in range(y):
            print Matrix[row]
        print '----------------------------'

    def ZeroForAllExchange(self):
        RCount = [0 for i in range(self.row)]
        CCount = [0 for i in range(self.col)]
        self.ZeroForAllMatrix = [[0 for i in range(self.col)] for j in range(self.row)]
        for i in range(self.row):
            for j in range(self.col):
                if self.OriginalMatrix[i][j]==0:
                    RCount[i] = 1
                    CCount[j] = 1
        a = []
        for i in range(self.row):
            if RCount[i] == 1:
                a = [0 for j in range(self.col)]
            else:
                a = deepcopy(self.OriginalMatrix[i])
                for j in range(self.col):
                    if CCount[j] == 1:
                        a[j] = 0
            self.ZeroForAllMatrix[i] = a
        #print self.ZeroForAllMatrix


if __name__ == '__main__':

    TestM = [
                [1, 2, 3, 4],
                [5, 6, 0, 8],
                [1, 3, 4, 9],
                [0, 3, 9, 7]
            ]

    M = Matrix(TestM)
    M.DumpMatrix(M.OriginalMatrix, M.col, M.row)
    M.ZeroForAllExchange()
    M.DumpMatrix(M.ZeroForAllMatrix, M.col, M.row)

    N = Matrix([1,2,3,4,0,5,2,4,6,0,5,4,2,5,78,9,0,1,5,1], 4, 5)
    N.DumpMatrix(N.OriginalMatrix, N.col, N.row)
    N.ZeroForAllExchange()
    N.DumpMatrix(N.ZeroForAllMatrix, N.col, N.row)

