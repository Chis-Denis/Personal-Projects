from Domain import Grid
from copy import deepcopy
class UI:

    def __init__(self):
        self.grid = Grid()

    def readcommand(self):
        cmd = input("Please type your command: ")
        cmd = cmd.split(" ", 1)

        if cmd[0] == "exit":
            return False

        if cmd[0] == "tick":
            if len(cmd) == 1:
                self.tick('1')
                return True
            else:
                self.tick(cmd[1])
                return True
        elif cmd[0] == "save":
            self.save(cmd[1])
            return True
        elif cmd[0] == "load":
            self.load(cmd[1])
            return True
        elif cmd[0] == "place":
            self.place(cmd[1])
            return True
        else:
            print("Wrong command!")
            return True

    def place(self, params):
        olddata = deepcopy(self.grid.data)
        patterns = self.grid.readpattern("Pattern.txt")
        prms = params.split()
        if len(prms) != 2:
            print("Wrong format for command!")
            return
        if len(prms[1]) != 3:
            print("Wrong format for command!")
            return
        if prms[1][1] != ",":
            print("Wrong format for command!")
            return
        if prms[1][0].isdigit() and prms[1][2].isdigit():
            x = int(prms[1][0])
            y = int(prms[1][2])
            if x > 7 or y > 7:
                print("Outside the board!")
                return
            if prms[0] in patterns:
                for i in range(len(patterns)):
                    if patterns[i] == prms[0]:
                        for j in range(len(patterns[i+1])):
                            for k in range(len(patterns[i+1][j])):
                                if patterns[i+1][j][k] == "X":
                                    if x+j > 7 or y+k > 7:
                                        print("Outside the board!!")
                                        self.grid.data = olddata
                                        return
                                    if self.grid.data[x+j][y+k] == "X":
                                        print("Life cells can not overlap!")
                                        self.grid.data = olddata
                                        return
                                    else:
                                        self.grid.data[x+j][y+k] = patterns[i+1][j][k]
                                if patterns[i+1][j][k] == "+":
                                    if x+j > 7 or y+k > 7:
                                        print("Outside the board!!")
                                        self.grid.data = olddata
                                        return
                                    if self.grid.data[x+j][y+k] == "X":
                                        print("Life cells can not overlap!")
                                        self.grid.data = olddata
                                        return
                                    self.grid.data[x+j][y+k] = " "
            else:
                print("No such pattern!")
        else:
            print("Parameters are not integers!")



    def save(self, fname):
        self.grid.writetofile(fname)

    def load(self, fname):
        self.grid.readfromfile(fname)

    def tick(self, param):
        if param.isdigit():
            prm = int(param)
            for i in range(prm):
                self.grid.change()
        else:
            print("The parameter is not a digit!")

    def main(self):

        print(self.grid)
        r = self.readcommand()
        while r != False:
            print(self.grid)
            r = self.readcommand()

ui = UI()
ui.main()