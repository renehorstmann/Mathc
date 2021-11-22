import os
import shutil
import jinja2

FLOAT = {
    'float': 'float',
    'FLOAT': 'FLOAT',
    'vec': 'vec',
    'VEC': 'VEC',
    'mat': 'mat',
    'MAT': 'MAT'
}

DOUBLE = {
    'float': 'double',
    'FLOAT': 'DOUBLE',
    'vec': 'dvec',
    'VEC': 'DVEC',
    'mat': 'dmat',
    'MAT': 'DMAT'
}

INT = {
    'float': 'int',
    'FLOAT': 'INT',
    'vec': 'ivec',
    'VEC': 'IVEC',
    'mat': 'imat',
    'MAT': 'IMAT'
}


def get_dst(dir, file):
    dir = 'out/mathc/' + dir
    if not os.path.isdir(dir):
        os.makedirs(dir)
    return dir + file


def publictypes(env, DICT, X):
    variables = DICT.copy()

    template = env.get_template('publictypes/vecX.h')
    for i in range(2, X+1):
        variables['X'] = i
        dst = get_dst('publictypes/', DICT['vec'] + str(i) + '.h')
        print('...', dst)
        template.stream(**variables).dump(dst)

    template = env.get_template('publictypes/matX.h')
    for i in range(2, X+1):
        variables['X'] = i
        dst = get_dst('publictypes/', DICT['mat'] + str(i) + '.h')
        print('...', dst)
        template.stream(**variables).dump(dst)

    template = env.get_template('publictypes/float.h')
    variables['X'] = X
    dst = get_dst('publictypes/', DICT['float'] + '.h')
    print('...', dst)
    template.stream(**variables).dump(dst)


def types(env, DICT, X):
    variables = DICT.copy()

    template = env.get_template('types/vecX.h')
    for i in range(2, X+1):
        variables['X'] = i
        dst = get_dst('types/', DICT['vec'] + str(i) + '.h')
        print('...', dst)
        template.stream(**variables).dump(dst)

    template = env.get_template('types/matX.h')
    for i in range(2, X+1):
        variables['X'] = i
        dst = get_dst('types/', DICT['mat'] + str(i) + '.h')
        print('...', dst)
        template.stream(**variables).dump(dst)

    template = env.get_template('types/float.h')
    variables['X'] = X
    dst = get_dst('types/', DICT['float'] + '.h')
    print('...', dst)
    template.stream(**variables).dump(dst)


def main():
    print('clean_up')
    shutil.rmtree('out')

    # vec2, ..., vecX
    X = 6

    env = jinja2.Environment(loader=jinja2.FileSystemLoader('in'))
    env.variable_start_string = '<{'
    env.variable_end_string = '}>'
    env.block_start_string = '<%'
    env.block_end_string = '%>'
    env.comment_start_string = '<#'
    env.comment_end_string = '#>'

    print('starting with X =', X)

    publictypes(env, FLOAT, X)
    publictypes(env, DOUBLE, X)
    publictypes(env, INT, X)

    types(env, FLOAT, X)
    types(env, DOUBLE, X)
    types(env, INT, X)

    print('finished with X =', X)

if __name__ == '__main__':
    main()
