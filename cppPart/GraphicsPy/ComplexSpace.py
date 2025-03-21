from matplotlib import pyplot as plt
import numpy as np
import argparse

def plot_complex_space(Ax1, Ay1, Ax2, Ay2, Ax3, Ay3):
    fig, ax = plt.subplots()
    ax.set_xlim(-10, 10)
    ax.set_ylim(-10, 10)
    ax.plot(Ax1, Ay1, 'ro')
    ax.plot(Ax2, Ay2, 'ro')
    ax.plot(Ax3, Ay3, 'ro')
    ax.plot([Ax1, Ax2], [Ay1, Ay2], 'r-')
    ax.plot([Ax2, Ax3], [Ay2, Ay3], 'r-')
    ax.plot([Ax3, Ax1], [Ay3, Ay1], 'r-')
    plt.show()

def main():
    parser = argparse.ArgumentParser(description="Plot complex numbers in a 2D space")
    
    parser.add_argument("--x1", type=float, required=True)
    parser.add_argument("--y1", type=float, required=True)
    parser.add_argument("--x2", type=float, required=True)
    parser.add_argument("--y2", type=float, required=True)
    parser.add_argument("--x3", type=float, required=True)
    parser.add_argument("--y3", type=float, required=True)

    args = parser.parse_args()

    plot_complex_space(args.x1, args.y1, args.x2, args.y2, args.x3, args.y3)

if __name__ == "__main__":
    main()
