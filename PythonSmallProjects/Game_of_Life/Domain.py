from copy import deepcopy
from texttable import Texttable
import unittest
from unittest import TestCase

class Grid:

    def __init__(self):
        self.data = [[" ", " ", " ", " ", " ", " ", " ", " "] for i in range(8)]

    def __str__(self):
        self.table = Texttable()
        self.table.add_rows(self.data, [])
        return self.table.draw()

    def change(self):
        """
        Input: none
        Output: no return per se, but the data of the board is changed accordingly to the rules stated
        the neighbours are checked and based on their values the new board is created
        """
        data = deepcopy(self.data)
        for i in range(8):
            for j in range(8):
                #checking the neighbours
                contorlive = 0
                contordead = 0
                if i - 1 >= 0 and j - 1 >= 0:
                    if data[i - 1][j - 1] == "X":
                        contorlive += 1
                    else:
                        contordead += 1
                if i - 1 >= 0:
                    if data[i - 1][j] == "X":
                        contorlive += 1
                    else:
                        contordead += 1
                if j - 1 >= 0:
                    if data[i][j - 1] == "X":
                        contorlive += 1
                    else:
                        contordead += 1
                if i + 1 < 8 and j + 1 < 8:
                    if data[i + 1][j + 1] == "X":
                        contorlive += 1
                    else:
                        contordead += 1
                if i + 1 < 8:
                    if data[i + 1][j] == "X":
                        contorlive += 1
                    else:
                        contordead += 1
                if j + 1 < 8:
                    if data[i][j + 1] == "X":
                        contorlive += 1
                    else:
                        contordead += 1
                if i - 1 >= 0 and j + 1 < 8:
                    if data[i - 1][j + 1] == "X":
                        contorlive += 1
                    else:
                        contordead += 1
                if i + 1 < 8 and j - 1 >= 0:
                    if data[i + 1][j - 1] == "X":
                        contorlive += 1
                    else:
                        contordead += 1
                #based on the results, the current space is modified or not
                if data[i][j] == "X":
                    if contorlive > 3 or contorlive < 2:
                        self.data[i][j] = " "
                if data[i][j] == " ":
                    if contorlive == 3:
                        self.data[i][j] = "X"

    def readfromfile(self, fname):
        with open(fname, 'r') as f:
            lines = f.readlines()
            i = 0
            for line in lines:
                for j in range(8):
                    if line[j] == "+":
                        self.data[i][j] = " "
                    elif line[j] == "X":
                        self.data[i][j] = "X"
                i += 1
        f.close()

    def writetofile(self, fname):
        with open(fname, "w") as f:
            for line in self.data:
                for elem in line:
                    if elem == " ":
                        f.write("+")
                    else:
                        f.write(elem)
                f.write("\n")
        f.close()

    def readpattern(self, fname):
        """
        param fname: filename - string
        return: a list containing the patterns and their data
        The function reads the pattern from the file Pattern.txt and creates a list with
        the name of the pattern and its data
        """
        patterns = []
        with open(fname, "r") as f:
            lines = f.readlines()
            newlines = []
            for line in lines:
                newline = line.strip()
                newlines.append(newline)
            lines = newlines
            for i in range(len(lines)):
            #we identify the kind of pattern read
                if lines[i] == "block":
                    blockdata = []
                    line = [lines[i+1][0], lines[i+1][1]]
                    blockdata.append(line)
                    line = [lines[i + 2][0], lines[i + 2][1]]
                    blockdata.append(line)
                    patterns.append("block")
                    patterns.append(blockdata)
                if lines[i] == "tub":
                    tubdata = []
                    line = [lines[i + 1][0], lines[i + 1][1], lines[i + 1][2]]
                    tubdata.append(line)
                    line = [lines[i + 2][0], lines[i + 2][1], lines[i + 2][2]]
                    tubdata.append(line)
                    line = [lines[i + 3][0], lines[i + 3][1], lines[i + 3][2]]
                    tubdata.append(line)
                    patterns.append("tub")
                    patterns.append(tubdata)
                if lines[i] == "blinker":
                    blinkerdata = []
                    line = [lines[i + 1][0], lines[i + 1][1], lines[i + 1][2]]
                    blinkerdata.append(line)
                    line = [lines[i + 2][0], lines[i + 2][1], lines[i + 2][2]]
                    blinkerdata.append(line)
                    line = [lines[i + 3][0], lines[i + 3][1], lines[i + 3][2]]
                    blinkerdata.append(line)
                    patterns.append("blinker")
                    patterns.append(blinkerdata)
                if lines[i] == "beacon":
                    beacondata = []
                    line = [lines[i + 1][0], lines[i + 1][1], lines[i + 1][2],lines[i + 1][3]]
                    beacondata.append(line)
                    line = [lines[i + 2][0], lines[i + 2][1], lines[i + 2][2], lines[i + 2][3]]
                    beacondata.append(line)
                    line = [lines[i + 3][0], lines[i + 3][1], lines[i + 3][2], lines[i + 3][3]]
                    beacondata.append(line)
                    line = [lines[i + 4][0], lines[i + 4][1], lines[i + 4][2], lines[i + 4][3]]
                    beacondata.append(line)
                    patterns.append("beacon")
                    patterns.append(beacondata)
                if lines[i] == "spaceship":
                    spaceshipdata = []
                    line = [lines[i + 1][0], lines[i + 1][1], lines[i + 1][2], lines[i + 1][3]]
                    spaceshipdata.append(line)
                    line = [lines[i + 2][0], lines[i + 2][1], lines[i + 2][2], lines[i + 2][3]]
                    spaceshipdata.append(line)
                    line = [lines[i + 3][0], lines[i + 3][1], lines[i + 3][2], lines[i + 3][3]]
                    spaceshipdata.append(line)
                    line = [lines[i + 4][0], lines[i + 4][1], lines[i + 4][2], lines[i + 4][3]]
                    spaceshipdata.append(line)
                    patterns.append("spaceship")
                    patterns.append(spaceshipdata)
        f.close()
        return patterns

class Tests(TestCase):

    def test_grid_tick(self):
        grid = Grid()
        grid.data[4][0] = "X"
        grid.data[4][1] = "X"
        grid.data[4][2] = "X"
        grid.data[3][2] = "X"
        grid.data[2][1] = "X"
        grid.change()
        grid.change()
        grid.change()
        grid.change()
        assert grid.data[5][1] == "X"
        assert grid.data[5][2] == "X"
        assert grid.data[5][3] == "X"
        assert grid.data[4][3] == "X"
        assert grid.data[3][2] == "X"
        assert grid.data[2][1] != "X"

    def test_grid_place(self):
        grid = Grid()
        l = grid.readpattern("Pattern.txt")
        assert "beacon" in l
        assert "blinker" in l
        assert [["X","X"],["X","X"]] in l
        assert [["X", "X"], ["X", " "]] not in l

if __name__ == '__main__':
    unittest.main()




