import re


def get_content(filename):
    with open(filename) as f:
        f.readline()
        return f.readlines()


if __name__ == '__main__':
    in_filename = 'input01.txt'

    domains = ['com', 'gov', 'in', 'org', 'net', 'tv']
    pattern2 = r'https?://(w{2,3}[2-5]?\.)?(([-a-z0-9]+\.)+(' + '|'.join(domains) + '))'
    pattern = r'https?://(www[0-9]?\.)?(([-a-z0-9]+\.)+[a-z]+)'
    # print("pattern:", pattern)
    dom_names = set()
    for line in get_content(in_filename):
        dom_names |= set([rs[1] for rs in re.findall(pattern, line)])
    dom_names = sorted(dom_names)
    # print(';'.join(dom_names))
    print(dom_names)
    out_filename = 'my_output' + re.match('[a-zA-Z]*(\d+)\.[a-z]+', in_filename).group(1) + '.txt'
    with open(out_filename, mode='w') as f_out:
        # f_out.writelines(dom_names)
        for dm in dom_names:
            f_out.write(dm + '\n')

