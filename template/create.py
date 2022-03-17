import os
import shutil
import jinja2

# in active work, just a project idea...

FLOAT = {
    'real': True,
    'float': 'float',
    'FLOAT': 'FLOAT',
    'vec': 'vec',
    'VEC': 'VEC',
    'mat': 'mat',
    'MAT': 'MAT',
    'dotzero': '.0f',
    'fabsf': 'fabsf',
    'powf': 'powf',
    'sqrtf': 'sqrtf',
    'floorf': 'floorf',
    'ceilf': 'ceilf',
    'expf': 'expf',
    'exp2f': 'exp2f',
    'logf': 'logf',
    'log2f': 'log2f',
    'sinf': 'sinf',
    'cosf': 'cosf',
    'tanf': 'tanf',
    'asinf': 'asinf',
    'acosf': 'acosf',
    'atanf': 'atanf',
    'atan2f': 'atan2f'
}

DOUBLE = {
    'real': True,
    'float': 'double',
    'FLOAT': 'DOUBLE',
    'vec': 'dvec',
    'VEC': 'DVEC',
    'mat': 'dmat',
    'MAT': 'DMAT',
    'dotzero': '.0',
    'fabsf': 'absf',
    'powf': 'pow',
    'sqrtf': 'sqrt',
    'floorf': 'floor',
    'ceilf': 'ceil',
    'expf': 'exp',
    'exp2f': 'exp2',
    'logf': 'log',
    'log2f': 'log2',
    'sinf': 'sin',
    'cosf': 'cos',
    'tanf': 'tan',
    'asinf': 'asin',
    'acosf': 'acos',
    'atanf': 'atan',
    'atan2f': 'atan2',
}

INT = {
    'float': 'int',
    'FLOAT': 'INT',
    'vec': 'ivec',
    'VEC': 'IVEC',
    'mat': 'imat',
    'MAT': 'IMAT',
    'dotzero': '',
    'fabsf': 'abs',
    'powf': '(int) pow'
}

UCHAR = {
    'unsigned': True,
    'float': 'unsigned char',
    'FLOAT': 'UCHAR',
    'vec': 'ucvec',
    'VEC': 'UCVEC',
    'mat': 'ucmat',
    'MAT': 'UCMAT',
    'dotzero': '',
    'powf': '(unsigned char) pow'
}


def get_dst(dir, file):
    dir = 'out/mathc/' + dir
    if not os.path.isdir(dir):
        os.makedirs(dir)
    return dir + file


def publictypes(env, DICT, X):
    variables = DICT.copy()

    template = env.get_template('publictypes/vecX.h')
    for i in range(2, X + 1):
        variables['X'] = i
        dst = get_dst('publictypes/', DICT['vec'] + str(i) + '.h')
        print('...', dst)
        template.stream(**variables).dump(dst)

    template = env.get_template('publictypes/matX.h')
    for i in range(2, X + 1):
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
    for i in range(2, X + 1):
        variables['X'] = i
        dst = get_dst('types/', DICT['vec'] + str(i) + '.h')
        print('...', dst)
        template.stream(**variables).dump(dst)

    template = env.get_template('types/matX.h')
    for i in range(2, X + 1):
        variables['X'] = i
        dst = get_dst('types/', DICT['mat'] + str(i) + '.h')
        print('...', dst)
        template.stream(**variables).dump(dst)

    template = env.get_template('types/float.h')
    variables['X'] = X
    dst = get_dst('types/', DICT['float'] + '.h')
    print('...', dst)
    template.stream(**variables).dump(dst)


def vec(env, DICT, x):
    variables = DICT.copy()

    template = env.get_template('vec/vecn.h')
    dst = get_dst('vec/', DICT['vec'] + 'n.h')
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
    publictypes(env, UCHAR, X)

    types(env, FLOAT, X)
    types(env, DOUBLE, X)
    types(env, INT, X)
    types(env, UCHAR, X)

    vec(env, FLOAT, X)
    vec(env, DOUBLE, X)
    vec(env, INT, X)
    vec(env, UCHAR, X)

    print('finished with X =', X)


if __name__ == '__main__':
    main()
