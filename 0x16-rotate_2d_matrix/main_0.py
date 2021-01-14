#!/usr/bin/python3
"""
Test 0x16 - Rotate 2D Matrix
"""
rotate_2d_matrix = __import__('0-rotate_2d_matrix').rotate_2d_matrix

if __name__ == "__main__":
    matrix = [[1, 2, 3],
              [4, 5, 6],
              [7, 8, 9]]

    rotate_2d_matrix(matrix)
    print(matrix)
    rotate_2d_matrix(matrix)
    print(matrix)
    rotate_2d_matrix(matrix)
    print(matrix)
    matrix = [[1, 2, 3, 11],
              [4, 5, 6, 66],
              [7, 8, 9, 99],
              [22, 33, 44, 55]]

    rotate_2d_matrix(matrix)
    print(matrix)
    matrix = [[1, 2, 3, 11, 12, 13, 14],
              [4, 5, 6, 66, 61, 62, 63],
              [7, 8, 9, 99, 91, 92, 93],
              [20, 21, 22, 23, 24, 25, 26],
              [30, 31, 32, 33, 34, 35, 36],
              [40, 41, 42, 43, 44, 45, 46],
              [50, 51, 52, 53, 54, 55, 56],
              ]

    rotate_2d_matrix(matrix)
    for i in matrix:
        print(i)
