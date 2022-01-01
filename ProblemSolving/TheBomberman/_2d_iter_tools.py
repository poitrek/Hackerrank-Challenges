class unbounded_list(list):
    """List type that does not raise exception when indexing
    out of range. When getting item outside bounds, returns specified
    alternative value. When setting item outside bounds, does nothing.
    Applies for index above value of len() or below 0."""
    def __init__(self, iterable, alt_value):
        """:param alt_value: value to return when trying to access
        index out of range"""
        super().__init__(iterable)
        self.alt_value = alt_value

    def __getitem__(self, key):
        if key < 0 or key >= len(self):
            # return super().__getitem__(0)
            return self.alt_value
        else:
            return super().__getitem__(key)

    def __setitem__(self, key, val):
        if key >= 0 and key < len(self):
            super().__setitem__(key, val)


def is_iterable(obj):
    try:
        iter(obj)
    except TypeError:
        return False
    else:
        return True


class nested_unbounded_list(unbounded_list):
    """Special type of unbounded list to easily make multi-dimensional 
    unbounded lists. When constructing from an iterable with nested iterables, 
    they are also converted to the nested_unbounded_list type."""
    def __init__(self, iterable, alt_value):
        if is_iterable(alt_value):
            alt_value = nested_unbounded_list(alt_value, alt_value[0])
        for i in range(len(iterable)):
            if is_iterable(iterable[0]):
                iterable[i] = nested_unbounded_list(iterable[i], alt_value[0])
        super().__init__(iterable, alt_value)


# Isn't working
def flatten(iterable):
    for i in range(len(iterable)):
        for j in range(len(iterable[0])):
            yield iterable[i: i+1][0:1][j:j+1]

# This works
def update(iter2d, fun, inplace=False):
    """Updates each element of a 2-D iterable according to the function.
    Update in-place"""
    if inplace:
        for i in range(len(iter2d)):
            for j in range(len(iter2d[0])):
                iter2d[i][j] = fun(iter2d[i][j])
    else:
        return [[fun(iter2d[i][j]) for i in range(len(iter2d))] for j in range(len(iter2d[0]))]


if __name__ == '__main__':
    arr = [list(range(0, 5*i, i)) for i in range(1, 6)]
    print(arr)
    update(arr, lambda x: -5 if x == 0 else 2 * x)
    print(arr)
    a = list(range(15))
