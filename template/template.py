import os
import re


def regex_name(name: str):
    return r'(?<![a-zA-Z0-9_])' + name + r'(?![a-zA-Z0-9_])'


def regex_name_prefix(name_prefix: str):
    return r'(?<![a-zA-Z0-9_])' + name_prefix


def regex_name_postfix(name_postfix: str):
    return name_postfix + r'(?![a-zA-Z0-9_])'


def regex_condition(cond: str, select_only_condition: bool):
    if select_only_condition:
        return r'\/\*\/\s*' + cond + r'\s*\/\*\/'
    return r'\/\*\/\s*' + cond + r'\s*\/\*\/.*\n'


def apply_regex_replace_list(text: str, replace: list):
    for item in replace:
        text = re.sub(item[0], item[1], text)
    return text


def apply_replace(src_file, dst_file, replace: list):
    file = open(src_file, 'r')
    text = file.read()
    file.close()

    text = apply_regex_replace_list(text, replace)

    os.makedirs(os.path.dirname(dst_file), exist_ok=True)
    file = open(dst_file, 'w')
    file.write(text)
    file.close()


RESULT_TPYE_FLOAT = 0
RESULT_TYPE_INT = 1
RESULT_TYPE_UNSIGNED = 2


def create_replace_list(template: dict, X=0):
    # 2, 3, 4
    X_MIN = 2
    X_MAX = 4

    replace = []

    # start with X, to first replace vec__X__* with vec2, 3, 4
    replace.append(('__X__', '%i' % X))

    # conditional lines:
    replace.append((regex_condition('0', False), ''))
    replace.append((regex_condition('float', 'is_integer' not in template or not template['is_integer']), ''))
    replace.append((regex_condition('int', 'is_integer' in template and template['is_integer']), ''))
    replace.append((regex_condition('signed', 'is_integer' in template and template['is_signed']), ''))
    for x in range(X_MIN, X_MAX + 1):
        replace.append((regex_condition('X==%i' % x, X == x), ''))
        replace.append((regex_condition('X!=%i' % x, X != x), ''))
        replace.append((regex_condition('X>%i' % x, X > x), ''))
        replace.append((regex_condition('X>=%i' % x, X >= x), ''))
        replace.append((regex_condition('X<%i' % x, X < x), ''))
        replace.append((regex_condition('X<=%i' % x, X <= x), ''))

    # primitive file (before primitive below)
    replace.append((regex_name('float.h'), template['primitive_file'] + '.h'))

    # primitive
    replace.append((regex_name('float'), template['primitive']))

    # primitive really_a_float (after primitive above)
    replace.append((regex_name('really_a_float'), 'float'))

    # sca_ functions
    replace.append((regex_name_prefix('sca_'), template['sca'] + '_'))

    # vecN_ functions
    replace.append((regex_name_prefix('vecN_'), template['vec'] + 'N_'))

    # matN_ functions
    replace.append((regex_name_prefix('matN_'), template['mat'] + 'N_'))

    # vecn.h include
    replace.append((regex_name_postfix('vecn.h'), template['vec'] + 'n.h'))

    # matn.h include
    replace.append((regex_name_postfix('matn.h'), template['mat'] + 'n.h'))

    # _FLOAT_H header
    replace.append((regex_name_postfix('_FLOAT_H'), '_' + template['primitive_header'] + '_H'))

    # _VECN_H header
    replace.append((regex_name_postfix('_VECN_H'), '_' + template['vec_header'] + 'N_H'))

    # _MATN_H header
    replace.append((regex_name_postfix('_MATN_H'), '_' + template['mat_header'] + 'N_H'))

    for x in range(X_MIN, X_MAX + 1):
        # vecX_ functions
        replace.append((regex_name_prefix('vec%i_' % x), template['vec'] + '%i_' % x))

        # matX_ functions
        replace.append((regex_name_prefix('mat%i_' % x), template['mat'] + '%i_' % x))

        # vecX type
        replace.append((regex_name('vec%i' % x), template['vec'] + '%i' % x))

        # matX type
        replace.append((regex_name('mat%i' % x), template['mat'] + '%i' % x))

        # mathc_vecX type
        replace.append((regex_name('mathc_vec%i' % x), 'mathc_' + template['vec'] + '%i' % x))

        # mathc_matX type
        replace.append((regex_name('mathc_mat%i' % x), 'mathc_' + template['mat'] + '%i' % x))

        # _VECX_H header
        replace.append((regex_name_postfix('_VEC%i_H' % x), '_' + template['vec_header'] + '%i_H' % x))

        # _MATX_H header
        replace.append((regex_name_postfix('_MAT%i_H' % x), '_' + template['mat_header'] + '%i_H' % x))

    return replace


def apply_template(src_file, dst_file, template: dict, X=0):
    replace = create_replace_list(template, X)
    apply_replace(src_file, dst_file, replace)


def create_files(template: dict):
    # 2, 3, 4
    X_MIN = 2
    X_MAX = 4

    replace_to_float_basic = create_replace_list(template)

    # types
    apply_template('in/publictypes/float.h',
                         apply_regex_replace_list('out/publictypes/float.h', replace_to_float_basic),
                         template)
    apply_template('in/types/float.h',
                         apply_regex_replace_list('out/types/float.h', replace_to_float_basic),
                         template)

    # vec
    apply_template('in/vec/float.h',
                         apply_regex_replace_list('out/vec/float.h', replace_to_float_basic),
                         template)
    apply_template('in/vec/vecn.h',
                         apply_regex_replace_list('out/vec/vecn.h', replace_to_float_basic),
                         template)
    for x in range(X_MIN, X_MAX + 1):
        apply_template('in/vec/vecX.h',
                             apply_regex_replace_list('out/vec/vec%i.h' % x, replace_to_float_basic),
                             template, x)

    # mat
    apply_template('in/mat/float.h',
                         apply_regex_replace_list('out/mat/float.h', replace_to_float_basic),
                         template)
    apply_template('in/mat/matn.h',
                         apply_regex_replace_list('out/mat/matn.h', replace_to_float_basic),
                         template)
    for x in range(X_MIN, X_MAX + 1):
        apply_template('in/mat/matX.h',
                             apply_regex_replace_list('out/mat/mat%i.h' % x, replace_to_float_basic),
                             template, x)


def create_bool_vec_files():
    # 2, 3, 4
    X_MIN = 2
    X_MAX = 4

    for X in range(X_MIN, X_MAX+1):
        replace = []
        # start with X, to first replace vec__X__* with vec2, 3, 4
        replace.append(('__X__', '%i' % X))
        # conditional lines:
        for x in range(X_MIN, X_MAX+1):
            replace.append((regex_condition('0', False), ''))
            replace.append((regex_condition('X==%i' % x, X == x), ''))
            replace.append((regex_condition('X!=%i' % x, X != x), ''))
            replace.append((regex_condition('X>%i' % x, X > x), ''))
            replace.append((regex_condition('X>=%i' % x, X >= x), ''))
            replace.append((regex_condition('X<%i' % x, X < x), ''))
            replace.append((regex_condition('X<=%i' % x, X <= x), ''))

        apply_replace('in/vec/bvecX.h', 'out/vec/bvec%i.h' % X, replace)


def create_util_files(template: dict, prefix: str):
    apply_template('in/utils/float.h', 'out/utils/%sfloat.h' % prefix, template)
    apply_template('in/utils/camera.h', 'out/utils/%scamera.h' % prefix, template)
    apply_template('in/utils/color.h', 'out/utils/%scolor.h' % prefix, template)
    apply_template('in/utils/intersection.h', 'out/utils/%sintersection.h' % prefix, template)
    apply_template('in/utils/quat.h', 'out/utils/%squat.h' % prefix, template)
    apply_template('in/utils/random.h', 'out/utils/%srandom.h' % prefix, template)
    apply_template('in/utils/rotation.h', 'out/utils/%srotation.h' % prefix, template)


FLOAT = {
    'primitive': 'float',
    'sca': 'sca',
    'vec': 'vec',
    'mat': 'mat',
    'primitive_header': 'FLOAT',
    'vec_header': 'VEC',
    'mat_header': 'MAT',
    'primitive_file': 'float'
}

DOUBLE = {
    'primitive': 'double',
    'sca': 'dsca',
    'vec': 'dvec',
    'mat': 'dmat',
    'primitive_header': 'DOUBLE',
    'vec_header': 'DVEC',
    'mat_header': 'DMAT',
    'primitive_file': 'double'
}

LONGDOUBLE = {
    'primitive': 'long double',
    'sca': 'ldsca',
    'vec': 'ldvec',
    'mat': 'ldmat',
    'primitive_header': 'LONGDOUBLE',
    'vec_header': 'LDVEC',
    'mat_header': 'LDMAT',
    'primitive_file': 'longdouble'
}

INT = {
    'primitive': 'int',
    'sca': 'isca',
    'vec': 'ivec',
    'mat': 'imat',
    'primitive_header': 'INT',
    'vec_header': 'IVEC',
    'mat_header': 'IMAT',
    'primitive_file': 'int',
    'is_integer': True,
    'is_signed': True
}

UCHAR = {
    'primitive': 'unsigned char',
    'sca': 'ucsca',
    'vec': 'ucvec',
    'mat': 'ucmat',
    'primitive_header': 'UCHAR',
    'vec_header': 'UCVEC',
    'mat_header': 'UCMAT',
    'primitive_file': 'uchar',
    'is_integer': True,
    'is_signed': False
}

LONGLONG = {
    'primitive': 'long long',
    'sca': 'llsca',
    'vec': 'llvec',
    'mat': 'llmat',
    'primitive_header': 'LONGLONG',
    'vec_header': 'LLVEC',
    'mat_header': 'LLMAT',
    'primitive_file': 'longlong',
    'is_integer': True,
    'is_signed': True
}

if __name__ == '__main__':
    import shutil

    if os.path.exists('out'):
        shutil.rmtree('out')

    os.makedirs('out/sca')
    shutil.copyfile('in/sca/float.h', 'out/sca/float.h')
    shutil.copyfile('in/sca/double.h', 'out/sca/double.h')
    shutil.copyfile('in/sca/longdouble.h', 'out/sca/longdouble.h')
    shutil.copyfile('in/sca/int.h', 'out/sca/int.h')
    shutil.copyfile('in/sca/longlong.h', 'out/sca/longlong.h')
    shutil.copyfile('in/sca/uchar.h', 'out/sca/uchar.h')
    os.makedirs('out/publictypes')
    shutil.copyfile('in/publictypes/bool.h', 'out/publictypes/bool.h')
    os.makedirs('out/types')
    shutil.copyfile('in/types/bool.h', 'out/types/bool.h')
    os.makedirs('out/vec')
    shutil.copyfile('in/vec/bool.h', 'out/vec/bool.h')
    shutil.copyfile('in/vec/bvecn.h', 'out/vec/bvecn.h')

    create_bool_vec_files()

    create_files(FLOAT)
    create_files(DOUBLE)
    # create_files(LONGDOUBLE)

    create_util_files(FLOAT, '')
    create_util_files(DOUBLE, 'd')
    # create_util_files(LONGDOUBLE, 'ld')

    create_files(INT)
    create_files(UCHAR)
    # create_files(LONGLONG)
