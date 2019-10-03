from tkinter import *
import random
import time

class CellularAutomataGUI:
    """
    A class for simulating two different kinds of cellular automata.

    Maze version: Will seed live cells randomly with every iteration.
    Life/death version: Will only seed one life which will then divide into a neighbouring cell
                        which in turn will divide and so on and so forth.

    In both versions all cells that have > 3 neighbours will be killed.
    """

    def __init__(self, master):
        self.WIDTH = 35
        self.HEIGHT = 35

        # A matrix containing life status of every cell: True means alive, False means dead!
        self.matrix=[ [ False for i in range(self.HEIGHT+1) ] for j in range(self.WIDTH+1) ]

        ## The main GUI window
        self.master = master
        self.master.title("Cellular Automata")

        ## A canvas for displaying our live/dead cells
        self.CELL_SIZE = int(1 + 500/self.WIDTH)
        self.canvas = Canvas(master, width=self.WIDTH*self.CELL_SIZE, height=self.HEIGHT * self.CELL_SIZE)
        self.canvas.pack()
        self.canvas.update()

        ## Buttons
        self.generate_maze_button = Button(master
                                      , text="Cellular automata maze"
                                      , command=lambda: self.cellular_automata("maze"))
        self.generate_maze_button.config( width=30 )
        self.generate_maze_button.pack()

        self.generate_life_button = Button(master
                                      , text="Cellular automata life/death simulator"
                                      , command=lambda: self.cellular_automata("lifedeath"))
        self.generate_life_button.config( width=30 )
        self.generate_life_button.pack()

        self.close_button = Button(master, text="Close", command=self.stop)
        self.close_button.pack()

        ## Will turn to False when the close button is clicked.
        self.running = True


    def cellular_automata(self, version):
        """
        A method for simulating two different versions of cellular automata.
        :param version: String saying what version of cellular automata we want to simulate.
        The options are: 1. "Maze"  2. "lifedeath"
        """
        # First cell pops into life!
        x = random.choice(range(0, self.WIDTH))
        y = random.choice(range(0, self.HEIGHT))
        self.matrix[x][y] = True

        while self.running:
            if version == "maze":
                # Will seed a random new life in our system.
                x = random.choice(range(0, self.WIDTH))
                y = random.choice(range(0, self.HEIGHT))
                self.matrix[x][y] = True

            for i in range(self.WIDTH):
                for j in range(self.HEIGHT):

                    if self.matrix[i][j]:               # if our current cell is alive.
                        if version == "lifedeath":
                            self.cell_division(i,j)     # A neighbour pops into life.

                        # Colours our cell, green if alive, gray if dead.
                        self.canvas.create_rectangle(
                                  i*self.CELL_SIZE
                                , j*self.CELL_SIZE
                                , (i+1)*self.CELL_SIZE
                                , (j+1)*self.CELL_SIZE
                                , outline="#5dcd3b"
                                , fill="#5dcd3b" if self.is_alive(i,j) else "#C4C4C4" )

            self.canvas.update()
            time.sleep(0.1)
            self.canvas.delete(ALL)

    def cell_division(self, i, j):
        """
        A method for dividing a living cell at i,j into two:
        a random neighbour pops into life.
        :param i: row
        :param j: column
        """
        m = 0
        n = 0
        while m==0 and n==0:
            m = random.choice(range(-1,2))
            n = random.choice(range(-1,2))

        self.matrix[i+m][j+n] = True


    def is_alive(self, i, j):
        """
        Checks if cell at i,j is alive or killed by overpopulated neighbourhood.
        :param i: row
        :param j: column
        :return: True if cell is alive, False if dead.
        """

        # Go through adjacent cells, count neighbours
        neighbour_count = 0
        for m in range(-1,2):
            for n in range(-1,2):
                if (not (m==0 and n==0)) and (self.matrix[i+m][j+n]):
                    neighbour_count += 1

        # If more than 3 neighbours: current cell is killed!
        if neighbour_count > 3:
            self.matrix[i][j] = not self.matrix[i][j]

        return self.matrix[i][j]


    def stop(self):
        """
        triggered when the close button is pressed.
        Will stop the application.
        """
        self.running = False
        self.master.quit()


root = Tk()
CellularAutomataGUI(root)
root.mainloop()
