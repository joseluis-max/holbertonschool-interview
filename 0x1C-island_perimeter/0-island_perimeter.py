#!/usr/bin/python3
"""This module contains the island_perimeter function
"""


def island_perimeter(grid):
    """Returns the perimeter of the island described in grid
    """
    if grid == []:
        return

    height = len(grid)
    width = len(grid[0])
    perimeter = 0

    row, column = 0, 0

    while row < height:
        column = 0

        while column < width:
            if grid[row][column] == 1:
                perimeter += check_perimeter(grid, row, column)

            column += 1

        row += 1

    return perimeter


def check_perimeter(grid, row, column):
    """Checks if there are water(number 0) around the number 1
    """
    height = len(grid)
    width = len(grid[0])
    perimeter = 0

    if (column + 1) < width:
        if grid[row][column + 1] == 0:
            perimeter += 1
    else:
        perimeter += 1

    if column - 1 >= 0:
        if grid[row][column - 1] == 0:
            perimeter += 1
    else:
        perimeter += 1

    if row + 1 < height:
        if grid[row + 1][column] == 0:
            perimeter += 1
    else:
        perimeter += 1

    if row - 1 >= 0:
        if grid[row - 1][column] == 0:
            perimeter += 1
    else:
        perimeter += 1

    return perimeter
