if __name__ == '__main__':
    case_no = '01'
    my_output = open('my_output' + case_no + '.txt').readlines()
    true_output = open('true_output' + case_no + '.txt').readlines()
    my_output = set(map(lambda s: s[:-1], my_output))
    true_output = set(map(lambda s: s[:-1], true_output))
    print(f'My output - {len(my_output)} elements')
    print(f'True output - {len(true_output)} elements')
    print(f'Correct: {true_output & my_output}')
    print(f'\nNot detected: {true_output - my_output}')
    print(f'\nDetected but wrong: {my_output - true_output}')
