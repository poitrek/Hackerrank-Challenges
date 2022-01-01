from _2d_iter_tools import update, nested_unbounded_list
from copy import deepcopy


def replace_2d(iterable, value, new_value):
    """Replaces value in a 2-D iterable. First parameter has to contain
    iterable objects of the same size"""
    for i in range(len(iterable)):
        for j in range(len(iterable)):
            if iterable[i][j] == value:
                iterable[i][j] = new_value


class BombermanSimulator:
    # @abc.abstractstaticmethod
    @staticmethod
    def simulate(grid, n_steps):
        pass


class SlowBombermanSimulator(BombermanSimulator):
    
    @staticmethod
    def _add_borders(arr: list, value):
        """Adds unused borders to a 2D list in order to simplify operations
        in the next() method. Deprecated"""
        n = len(arr[0])
        for row in arr:
            row.insert(0, value)
            row.append(value)
        arr.insert(0, [value] * (n+2))
        arr.append([value] * (n+2))

    @staticmethod
    def _to_precise_grid(grid):
        """converts simple grid view to the precise one with bomb counters
        'O' -> 3, '.' -> 0"""
        return update(grid, lambda x: 3 if x == 'O' else 0)

    @staticmethod
    def _to_simple_grid(grid):
        """converts precise grid to the simple view
        0 -> '.', 1|2|3 -> 'O'"""
        return update(grid, lambda x: '.' if x == 0 else 'O')

    @staticmethod
    def simulate(grid, n_steps):
        grid = SlowBombermanSimulator._to_precise_grid(grid)
        grid = nested_unbounded_list(grid, [0])
        for i in range(n_steps):
            SlowBombermanSimulator.next(grid, i % 2)
        # if n_steps > 0:
        #     SlowBombermanSimulator.next(grid, 0)
        #     for i in range(n_steps-1):
        #         SlowBombermanSimulator.next(grid, i % 2)
        return SlowBombermanSimulator._to_simple_grid(grid)
        # update(grid, str)
    
    @staticmethod
    def sim_generator(grid):
        grid = SlowBombermanSimulator._to_precise_grid(grid)
        grid = nested_unbounded_list(grid, [0])
        state = 0
        while True:
            SlowBombermanSimulator.next(grid, state)
            yield update(grid, str)
            # yield SlowBombermanSimulator._to_simple_grid(grid)
            state = 1 - state

    @staticmethod
    def next(grid: nested_unbounded_list, state: int):
        if state == 0: # grid consisting of 1-sec. bombs & 3-sec. bombs
            # for i in range(1, len(grid)-1):
                # for j in range(1, len(grid[0])-1):
                    # pass
            for i in range(len(grid)):
                for j in range(len(grid[0])):
                    # decrease the bomb timer
                    if grid[i][j] not in [0, 1]:
                        grid[i][j] = grid[i][j] - 1
                    elif grid[i][j] == 1:
                        # detonate the bomb
                        for x, y in [(i, j), (i-1, j), (i, j-1)]:
                            grid[x][y] = 0
                        for x, y in [(i+1, j), (i, j+1)]:
                            if grid[x][y] != 1:
                                grid[x][y] = 0
        else: # grid consisting of empty cells & 2-sec. bombs
            for i in range(len(grid)):
                for j in range(len(grid[0])):
                    if grid[i][j] == 0:
                        grid[i][j] = 3
                    else:
                        grid[i][j] = grid[i][j] - 1


class FastBombermanSimulator(BombermanSimulator):
    @staticmethod
    def simulate(grid, n_steps):
        if n_steps <= 2:
            return SlowBombermanSimulator.simulate(grid, n_steps)
        else:
            return SlowBombermanSimulator.simulate(grid, (n_steps+1) % 4 + 3)



def print_grid(grid):
    # print(*["".join(row) for row in grid], sep='\n')
    print(*map(lambda x: "".join(x), grid), sep='\n')


def print_grid_old(grid):
    """Prints grid with artificial borders. Deprecated"""
    for i in range(1, len(grid)-1):
        print("".join(grid[i][1: len(grid[0])-1]))
    print()


if __name__ == '__main__':
    r, _, n = tuple(map(int, input().split(' ')))
    grid = [list(input()) for _ in range(r)]
    print_grid(FastBombermanSimulator.simulate(grid, n))
    # Manual test
    # grid = [
    #     list('...'),
    #     list('.O.'),
    #     list('...')
    # ]
    # grid = [
    #     list('.......'),
    #     list('...O...'),
    #     list('....O..'),
    #     list('.......'),
    #     list('OO.....'),
    #     list('OO.....'),
    # ]
    # print_grid(grid)
    # gsim = SlowBombermanSimulator.sim_generator(grid)
    # print_grid(next(gsim))
    # print_grid(next(gsim))
    # print_grid(next(gsim))
