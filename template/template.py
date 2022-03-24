import os
import re

FLOAT = {}

DOUBLE = {
    'FLOAT' : 'DOUBLE',
    'VEC(?!_)' : 'DVEC',
    'MAT(?!HC|_)' : 'DMAT',
    '(?<!_)float(?!\ \*cast|.h)' : 'double',
    'float(?=.h)' : 'double',
    '(?<!\/|_)sca(?!\/)'   : 'dsca',
    '(?<!b|_)vec(?!\/)' : 'dvec',
    'mat(?!hc|\/)' : 'dmat'
}

LONGDOUBLE = {
    'FLOAT' : 'LONGDOUBLE',
    'VEC(?!_)' : 'LDVEC',
    'MAT(?!HC|_)' : 'LDMAT',
    '(?<!_)float(?!\ \*cast|.h)' : 'long double',
    'float(?=.h)' : 'longdouble',
    '(?<!\/|_)sca(?!\/)'   : 'ldsca',
    '(?<!b|_)vec(?!\/)' : 'ldvec',
    'mat(?!hc|\/)' : 'ldmat'
}

INT = {
    '//SIGNED ' : ''
}

UNSIGNED = {
    'INT' : 'UNSIGNED',
    'IVEC(?!_)' : 'UVEC',
    'IMAT(?!HC|_)' : 'UMAT',
    '(?<!_)int(?!\ \*cast|.h)' : 'unsigned',
    'int(?=.h)' : 'unsigned',
    '(?<!\/|_)isca(?!\/)'   : 'usca',
    '(?<!b|_)ivec(?!\/)' : 'uvec',
    'imat(?!hc|\/)' : 'umat'
}

CHAR = {
    '//SIGNED ' : '',
    'INT' : 'CHAR',
    'IVEC(?!_)' : 'CVEC',
    'IMAT(?!HC|_)' : 'CMAT',
    '(?<!_)int(?!\ \*cast|.h)' : 'signed char',
    'int(?=.h)' : 'char',
    '(?<!\/|_)isca(?!\/)'   : 'csca',
    '(?<!b|_)ivec(?!\/)' : 'cvec',
    'imat(?!hc|\/)' : 'cmat'
}

UCHAR = {
    'INT' : 'UCHAR',
    'IVEC(?!_)' : 'UCVEC',
    'IMAT(?!HC|_)' : 'UCMAT',
    '(?<!_)int(?!\ \*cast|.h)' : 'unsigned char',
    'int(?=.h)' : 'uchar',
    '(?<!\/|_)isca(?!\/)'   : 'ucsca',
    '(?<!b|_)ivec(?!\/)' : 'ucvec',
    'imat(?!hc|\/)' : 'ucmat'
}

def x_template(template_dict, x: int):
    t = template_dict.copy()
    t['(?<!=)4'] = '%i' % x
    for i in range(1, 5):
        if x > i:
            t['//X>%i ' % i] = ''
        if x >= i:
            t['//X>=%i ' % i] = ''
        if x < i:
            t['//X<%i ' % i] = ''
        if x <= i:
            t['//X<=%i ' % i] = ''
        if x == i:
            t['//X==%i ' % i] = ''
        if x != i:
            t['//X!=%i ' % i] = ''
    return t


def apply_template_regex(text, template_dict):
    for key, value in template_dict.items():
        text = re.sub(key, value, text)
    return text


def apply_template(src_file, dst_file, template_dict):
    file = open(src_file, 'r')
    text = file.read()
    file.close()

    text = apply_template_regex(text, template_dict)

    os.makedirs(os.path.dirname(dst_file), exist_ok=True)
    file = open(dst_file, 'w')
    file.write(text)
    file.close()


def create_float_files(src_path, dst_root_path, template_dict):
    if src_path[-1] != '/':
        src_path += '/'
    if dst_root_path[-1] != '/':
        dst_root_path += '/'

    src = src_path
    dst = dst_root_path

    os.makedirs(dst + 'sca', exist_ok=True)
    shutil.copyfile(src + apply_template_regex('sca/float.h', template_dict),
                    dst + apply_template_regex('sca/float.h', template_dict))

    apply_template(src + 'publictypes/float.h',
                   dst + apply_template_regex('publictypes/float.h', template_dict),
                   template_dict)
    apply_template(src + 'types/float.h',
                   dst + apply_template_regex('types/float.h', template_dict),
                   template_dict)
    #
    # vec
    #
    apply_template(src + 'vec/float.h',
                   dst + apply_template_regex('vec/float.h', template_dict),
                   template_dict)
    apply_template(src + 'vec/vecn.h',
                   dst + apply_template_regex('vec/vecn.h', template_dict),
                   template_dict)
    apply_template(src + 'vec/vec4X.h',
                   dst + apply_template_regex('vec/vec2.h', template_dict),
                   x_template(template_dict, 2))
    apply_template(src + 'vec/vec4X.h',
                   dst + apply_template_regex('vec/vec3.h', template_dict),
                   x_template(template_dict, 3))
    apply_template(src + 'vec/vec4X.h',
                   dst + apply_template_regex('vec/vec4.h', template_dict),
                   x_template(template_dict, 4))
    #
    # mat
    #
    apply_template(src + 'mat/float.h',
                   dst + apply_template_regex('mat/float.h', template_dict),
                   template_dict)
    apply_template(src + 'mat/matn.h',
                   dst + apply_template_regex('mat/matn.h', template_dict),
                   template_dict)
    apply_template(src + 'mat/mat2.h',
                   dst + apply_template_regex('mat/mat2.h', template_dict),
                   template_dict)
    apply_template(src + 'mat/mat3.h',
                   dst + apply_template_regex('mat/mat3.h', template_dict),
                   template_dict)
    apply_template(src + 'mat/mat4.h',
                   dst + apply_template_regex('mat/mat4.h', template_dict),
                   template_dict)


def create_int_files(src_path, dst_root_path, template_dict):
    if src_path[-1] != '/':
        src_path += '/'
    if dst_root_path[-1] != '/':
        dst_root_path += '/'

    src = src_path
    dst = dst_root_path

    os.makedirs(dst + 'sca', exist_ok=True)
    shutil.copyfile(src + apply_template_regex('sca/int.h', template_dict),
                    dst + apply_template_regex('sca/int.h', template_dict))

    apply_template(src + 'publictypes/int.h',
                   dst + apply_template_regex('publictypes/int.h', template_dict),
                   template_dict)
    apply_template(src + 'types/int.h',
                   dst + apply_template_regex('types/int.h', template_dict),
                   template_dict)
    #
    # vec
    #
    apply_template(src + 'vec/int.h',
                   dst + apply_template_regex('vec/int.h', template_dict),
                   template_dict)
    apply_template(src + 'vec/ivecnX.h',
                   dst + apply_template_regex('vec/ivecn.h', template_dict),
                   template_dict)
    apply_template(src + 'vec/ivec4X.h',
                   dst + apply_template_regex('vec/ivec2.h', template_dict),
                   x_template(template_dict, 2))
    apply_template(src + 'vec/ivec4X.h',
                   dst + apply_template_regex('vec/ivec3.h', template_dict),
                   x_template(template_dict, 3))
    apply_template(src + 'vec/ivec4X.h',
                   dst + apply_template_regex('vec/ivec4.h', template_dict),
                   x_template(template_dict, 4))
    #
    # mat
    #
    apply_template(src + 'mat/int.h',
                   dst + apply_template_regex('mat/int.h', template_dict),
                   template_dict)
    apply_template(src + 'mat/imatn.h',
                   dst + apply_template_regex('mat/imatn.h', template_dict),
                   template_dict)
    apply_template(src + 'mat/imat2.h',
                   dst + apply_template_regex('mat/imat2.h', template_dict),
                   template_dict)
    apply_template(src + 'mat/imat3.h',
                   dst + apply_template_regex('mat/imat3.h', template_dict),
                   template_dict)
    apply_template(src + 'mat/imat4.h',
                   dst + apply_template_regex('mat/imat4.h', template_dict),
                   template_dict)



if __name__ == '__main__':
    import shutil
    if os.path.exists('out'):
        shutil.rmtree('out')

    os.makedirs('out/sca')
    shutil.copyfile('in/sca/float.h', 'out/sca/float.h')
    shutil.copyfile('in/sca/double.h', 'out/sca/double.h')
    shutil.copyfile('in/sca/longdouble.h', 'out/sca/longdouble.h')
    shutil.copyfile('in/sca/int.h', 'out/sca/int.h')
    shutil.copyfile('in/sca/uchar.h', 'out/sca/uchar.h')
    os.makedirs('out/publictypes')
    shutil.copyfile('in/publictypes/bool.h', 'out/publictypes/bool.h')
    os.makedirs('out/types')
    shutil.copyfile('in/types/bool.h', 'out/types/bool.h')
    os.makedirs('out/vec')

    create_float_files('in', 'out', FLOAT)
    create_float_files('in', 'out', DOUBLE)
    # create_float_files('in', 'out', LONGDOUBLE)

    create_int_files('in', 'out', INT)
    create_int_files('in', 'out', UCHAR)
