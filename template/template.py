import os
import re

#
# This file generates the Mathc library files from the template files of dir "in/*"
# The generated files will be output in the dir "out/*"
#
# No standard template engine was used, but a regex substitution system
# The "template" files were written as if they were for the float type
# The sized types have an "__X__" specifier, that will be replaced with the actual size (vec__X__ -> vec4)
# Their also some conditional lines with "/*/ cond /*/[//]".
#   If cond is true, only the condition comment is removed
#   If cond is false, the whole line is removed
#   The conditions are not actually evaluated, only testet for their existence
#   The following conditions are used:
#       0       (remove that line)
#       1       (keep that line, used with the optional [//] line comment, just to pleasure the ide)
#       float   (only for floating point types like float, double)
#       int     (only for integer types like int, unsigned char)
#       signed  (only for signed types like int, float)
#       bool    (only for the bool type)
#       !bool   (not for the bool type)
#       X==i, !=, >, >=, <, <=  (i from 2 to 5, see X_MIN, X_MAX below)
#

X_MIN = 2
X_MAX = 5


def regex_name(name: str):
    """selects a full name in a C file"""
    return r'(?<![a-zA-Z0-9_])' + name + r'(?![a-zA-Z0-9_])'


def regex_name_prefix(name_prefix: str):
    """selects a name with unknown end in a C file"""
    return r'(?<![a-zA-Z0-9_])' + name_prefix


def regex_name_postfix(name_postfix: str):
    """selects a name with unknown start in a C file"""
    return name_postfix + r'(?![a-zA-Z0-9_])'


def regex_condition(cond: str, select_only_condition: bool):
    """will select either only the condition comment "/*/ cond /*/[//]" or the whole line"""
    if select_only_condition:
        return r'\/\*\/\s*' + cond + r'\s*\/\*\/(\/\/)?'
    return r'\/\*\/\s*' + cond + r'\s*\/\*\/.*\n'


def apply_regex_replace_list(text: str, replace: list):
    """replace list is a list of tuples (select, replace) that will be used on the text"""
    for item in replace:
        # regex substitute
        text = re.sub(item[0], item[1], text)
    return text


def apply_replace(src_file, dst_file, replace: list):
    """reads in the src file, applies the replace list and saves the generated file under dst (and creates all dirs)"""
    file = open(src_file, 'r')
    text = file.read()
    file.close()

    text = apply_regex_replace_list(text, replace)

    os.makedirs(os.path.dirname(dst_file), exist_ok=True)
    file = open(dst_file, 'w')
    file.write(text)
    file.close()


def create_replace_conditions(template: dict, X=0):
    """creates all line conditions "/*/ cond /*/[//]" """
    replace = []

    replace.append((regex_condition('0', False), ''))
    replace.append((regex_condition('1', True), ''))
    is_float = 'is_integer' not in template or not template['is_integer']
    replace.append((regex_condition('float', is_float), ''))
    replace.append((regex_condition('int', not is_float), ''))
    replace.append((regex_condition('signed', is_float or ('is_integer' in template and template['is_signed'])), ''))
    replace.append((regex_condition('bool', 'is_bool' in template and template['is_bool']), ''))
    replace.append((regex_condition('!bool', not 'is_bool' in template or not template['is_bool']), ''))
    for x in range(X_MIN, X_MAX+1):
        replace.append((regex_condition('X==%i' % x, X == x), ''))
        replace.append((regex_condition('X!=%i' % x, X != x), ''))
        replace.append((regex_condition('X>%i' % x, X > x), ''))
        replace.append((regex_condition('X>=%i' % x, X >= x), ''))
        replace.append((regex_condition('X<%i' % x, X < x), ''))
        replace.append((regex_condition('X<=%i' % x, X <= x), ''))
    return replace


def create_replace_list(template: dict, X=0, prefix=''):
    """creates the whole replace list for the Mathc template files, based on the float data type"""
    replace = create_replace_conditions(template, X)

    # start with X, to first replace vec__X__* with vec2, 3, 4
    replace.append(('__X__', '%i' % X))

    prefix = template['prefix'].lower()
    PREFIX = template['prefix'].upper()

    # prefix __prefix__ (quat -> dquat, RANDOM -> dRANDOM)
    replace.append(('__prefix__', prefix))
    replace.append(('__PREFIX__', PREFIX))

    # float file (before float below)
    replace.append((regex_name('float.h'), template['float_file'] + '.h'))

    # float
    replace.append((regex_name('float'), template['float']))

    # float really_a_float (after float above)
    replace.append((regex_name('really_a_float'), 'float'))

    # sca_ functions
    replace.append((regex_name_prefix('sca_'), prefix + 'sca_'))

    # vecN_ functions
    replace.append((regex_name_prefix('vecN_'), prefix + 'vecN_'))

    # matN_ functions
    replace.append((regex_name_prefix('matN_'), prefix + 'matN_'))

    # vecn.h include
    replace.append((regex_name_postfix('vecn.h'), prefix + 'vecn.h'))

    # matn.h include
    replace.append((regex_name_postfix('matn.h'), prefix + 'matn.h'))

    # _FLOAT_H header
    replace.append((regex_name_postfix('_FLOAT_H'), '_' + template['FLOAT'] + '_H'))

    # _VECN_H header
    replace.append((regex_name_postfix('_VECN_H'), '_' + PREFIX + 'VECN_H'))

    # _MATN_H header
    replace.append((regex_name_postfix('_MATN_H'), '_' + PREFIX + 'MATN_H'))

    # MATHC_VEC* macro
    replace.append((regex_name_prefix('MATHC_VEC'), 'MATHC_' + PREFIX + 'VEC'))

    # MATHC_MAT* macro
    replace.append((regex_name_prefix('MATHC_MAT'), 'MATHC_' + PREFIX + 'MAT'))
    
    # SCA_* constands
    replace.append((regex_name_prefix('SCA_'), PREFIX + 'SCA_'))

    for x in range(X_MIN, X_MAX + 1):
        # vecX_ functions
        replace.append((regex_name_prefix('vec%i_' % x), prefix + 'vec%i_' % x))

        # matX_ functions
        replace.append((regex_name_prefix('mat%i_' % x), prefix + 'mat%i_' % x))

        # vecX type
        replace.append((regex_name('vec%i' % x), prefix + 'vec%i' % x))

        # matX type
        replace.append((regex_name('mat%i' % x), prefix + 'mat%i' % x))

        # mathc_vecX type
        replace.append((regex_name('mathc_vec%i' % x), 'mathc_' + prefix + 'vec%i' % x))

        # mathc_matX type
        replace.append((regex_name('mathc_mat%i' % x), 'mathc_' + prefix + 'mat%i' % x))

        # _VECX_H header
        replace.append((regex_name_postfix('_VEC%i_H' % x), '_' + PREFIX + 'VEC%i_H' % x))

        # _MATX_H header
        replace.append((regex_name_postfix('_MAT%i_H' % x), '_' + PREFIX + 'MAT%i_H' % x))

    return replace


def apply_template(src_file, dst_file, template: dict, X=0, prefix=''):
    """creates a replace list of the given template and applies it on the given src file to create the dst file"""
    replace = create_replace_list(template, X, prefix)
    apply_replace(src_file, dst_file, replace)


def create_publictypes(template: dict, X_list_vec, X_list_mat):
    """creates the Mathc publictypes files for the given template"""
    replace_to_float_basic = create_replace_list(template)

    apply_template('in/publictypes/float.h',
                   apply_regex_replace_list('out/publictypes/float.h', replace_to_float_basic),
                   template)
    
    for x in X_list_vec:
        apply_template('in/publictypes/vecX.h',
                       apply_regex_replace_list('out/publictypes/vec%i.h' % x, replace_to_float_basic),
                       template, x)

    for x in X_list_mat:
        apply_template('in/publictypes/matX.h',
                       apply_regex_replace_list('out/publictypes/mat%i.h' % x, replace_to_float_basic),
                       template, x)


def create_types(template: dict, X_list_vec, X_list_mat):
    """creates the Mathc types files for the given template"""
    replace_to_float_basic = create_replace_list(template)

    apply_template('in/types/float.h',
                   apply_regex_replace_list('out/types/float.h', replace_to_float_basic),
                   template)

    for x in X_list_vec:
        apply_template('in/types/vecX.h',
                       apply_regex_replace_list('out/types/vec%i.h' % x, replace_to_float_basic),
                       template, x)

    for x in X_list_mat:
        apply_template('in/types/matX.h',
                       apply_regex_replace_list('out/types/mat%i.h' % x, replace_to_float_basic),
                       template, x)


def create_io(template: dict, X_list_vec, X_list_mat):
    """creates the Mathc types files for the given template"""
    replace_to_float_basic = create_replace_list(template)

    apply_template('in/io/float.h',
                   apply_regex_replace_list('out/io/float.h', replace_to_float_basic),
                   template)

    apply_template('in/io/vecn.h',
                   apply_regex_replace_list('out/io/vecn.h', replace_to_float_basic),
                   template)

    for x in X_list_vec:
        apply_template('in/io/vecX.h',
                       apply_regex_replace_list('out/io/vec%i.h' % x, replace_to_float_basic),
                       template, x)


def create_vec(template: dict, X_list):
    """creates the Mathc vec files for the given template"""
    replace_to_float_basic = create_replace_list(template)

    apply_template('in/vec/float.h',
                   apply_regex_replace_list('out/vec/float.h', replace_to_float_basic),
                   template)

    apply_template('in/vec/vecn.h',
                         apply_regex_replace_list('out/vec/vecn.h', replace_to_float_basic),
                         template)
    for x in X_list:
        apply_template('in/vec/vecX.h',
                             apply_regex_replace_list('out/vec/vec%i.h' % x, replace_to_float_basic),
                             template, x)


def create_mat(template: dict, X_list):
    """creates the Mathc mat files for the given template"""
    replace_to_float_basic = create_replace_list(template)

    apply_template('in/mat/float.h',
                   apply_regex_replace_list('out/mat/float.h', replace_to_float_basic),
                   template)

    apply_template('in/mat/matn.h',
                         apply_regex_replace_list('out/mat/matn.h', replace_to_float_basic),
                         template)
    for x in X_list:
        apply_template('in/mat/matX.h',
                             apply_regex_replace_list('out/mat/mat%i.h' % x, replace_to_float_basic),
                             template, x)


def create_all(template: dict, X_list_vec, X_list_mat):
    """creates the Mathc publictypes, types, vec and mat files for the given template"""
    create_publictypes(template, X_list_vec, X_list_mat)
    create_types(template, X_list_vec, X_list_mat)
    create_io(template, X_list_vec, X_list_mat)
    create_vec(template, X_list_vec)
    create_mat(template, X_list_mat)


def create_bool(X_list):
    """creates the Mathc bool files"""
    replace_to_float_basic = create_replace_list(BOOL)

    create_publictypes(BOOL, X_list, [])
    create_types(BOOL, X_list, [])
    create_io(BOOL, X_list, [])

    apply_template('in/vec/float.h',
                   apply_regex_replace_list('out/vec/float.h', replace_to_float_basic),
                   BOOL)

    apply_replace('in/vec/bvecn.h', 'out/vec/bvecn.h', [])
    for X in X_list:
        replace = create_replace_conditions({}, X)
        replace.append(('__X__', '%i' % X))

        apply_replace('in/vec/bvecX.h', 'out/vec/bvec%i.h' % X, replace)


def create_util(template: dict):
    """creates the Mathc util files for the given template, should be floating point type"""
    replace_to_float_basic = create_replace_list(template)
    apply_template('in/utils/float.h', apply_regex_replace_list('out/utils/float.h', replace_to_float_basic),
                   template)
    apply_template('in/utils/camera.h', 'out/utils/%scamera.h' % template['prefix'], template)
    apply_template('in/utils/color.h', 'out/utils/%scolor.h' % template['prefix'], template)
    apply_template('in/utils/intersection.h', 'out/utils/%sintersection.h' % template['prefix'], template)
    apply_template('in/utils/quat.h', 'out/utils/%squat.h' % template['prefix'], template)
    apply_template('in/utils/random.h', 'out/utils/%srandom.h' % template['prefix'], template)
    apply_template('in/utils/rotation.h', 'out/utils/%srotation.h' % template['prefix'], template)



#
# templates
#

FLOAT = {
    'float': 'float',
    'FLOAT': 'FLOAT',
    'float_file': 'float',
    'prefix': '',
    'is_bool': False,       # if not available: False
    'is_integer': False,    # if not available: False
    'is_signed': True,      # if not available: True
}

BOOL = {
    'float': 'bool',
    'FLOAT': 'BOOL',
    'float_file': 'bool',
    'prefix': 'b',
    'is_bool': True,
}

DOUBLE = {
    'float': 'double',
    'FLOAT': 'DOUBLE',
    'float_file': 'double',
    'prefix': 'd',
}

LONGDOUBLE = {
    'float': 'long double',
    'FLOAT': 'LONGDOUBLE',
    'float_file': 'longdouble',
    'prefix': 'ld',
}

CHAR = {
    'float': 'signed char',     # signed, because char alone may be unsigned
    'FLOAT': 'CHAR',
    'float_file': 'char',
    'prefix': 'c',
    'is_integer': True,
    'is_signed': True,
}

SHORT = {
    'float': 'short',
    'FLOAT': 'SHORT',
    'float_file': 'short',
    'prefix': 's',
    'is_integer': True,
    'is_signed': True,
}

INT = {
    'float': 'int',
    'FLOAT': 'INT',
    'float_file': 'int',
    'prefix': 'i',
    'is_integer': True,
    'is_signed': True,
}

LONGLONG = {
    'float': 'long long',
    'FLOAT': 'LONGLONG',
    'float_file': 'longlong',
    'prefix': 'll',
    'is_integer': True,
    'is_signed': True,
}

UCHAR = {
    'float': 'unsigned char',
    'FLOAT': 'UCHAR',
    'float_file': 'uchar',
    'prefix': 'uc',
    'is_integer': True,
    'is_signed': False,
}

USHORT = {
    'float': 'unsigned short',
    'FLOAT': 'USHORT',
    'float_file': 'ushort',
    'prefix': 'us',
    'is_integer': True,
    'is_signed': False,
}

UINT = {
    'float': 'unsigned int',
    'FLOAT': 'UINT',
    'float_file': 'uint',
    'prefix': 'ui',
    'is_integer': True,
    'is_signed': False,
}

ULONGLONG = {
    'float': 'unsigned long long',
    'FLOAT': 'ULONGLONG',
    'float_file': 'ulonglong',
    'prefix': 'ull',
    'is_integer': True,
    'is_signed': False,
}

if __name__ == '__main__':
    import shutil

    if os.path.exists('out'):
        shutil.rmtree('out')

    # copy static files
    os.makedirs('out/io')
    os.makedirs('out/sca')
    shutil.copyfile('in/mathc.h', 'out/mathc.h')
    shutil.copyfile('in/bool.h', 'out/bool.h')
    shutil.copyfile('in/float.h', 'out/float.h')
    shutil.copyfile('in/double.h', 'out/double.h')
    shutil.copyfile('in/int.h', 'out/int.h')
    shutil.copyfile('in/uchar.h', 'out/uchar.h')
    shutil.copyfile('in/io/terminalcolor.h', 'out/io/terminalcolor.h')
    shutil.copyfile('in/sca/bool.h', 'out/sca/bool.h')
    shutil.copyfile('in/sca/float.h', 'out/sca/float.h')
    shutil.copyfile('in/sca/double.h', 'out/sca/double.h')
    shutil.copyfile('in/sca/longdouble.h', 'out/sca/longdouble.h')
    shutil.copyfile('in/sca/char.h', 'out/sca/char.h')
    shutil.copyfile('in/sca/short.h', 'out/sca/short.h')
    shutil.copyfile('in/sca/int.h', 'out/sca/int.h')
    shutil.copyfile('in/sca/longlong.h', 'out/sca/longlong.h')
    shutil.copyfile('in/sca/uchar.h', 'out/sca/uchar.h')
    shutil.copyfile('in/sca/ushort.h', 'out/sca/ushort.h')
    shutil.copyfile('in/sca/uint.h', 'out/sca/uint.h')
    shutil.copyfile('in/sca/ulonglong.h', 'out/sca/ulonglong.h')

    # minimum should be [2, 3, 4]
    X_list_vec = [2, 3, 4]
    X_list_mat = [2, 3, 4]

    create_bool(X_list_vec)

    # floating point types
    create_all(FLOAT, X_list_vec, X_list_mat)
    create_all(DOUBLE, X_list_vec, X_list_mat)
    # create_all(LONGDOUBLE, X_list_vec, X_list_mat)

    # integer types
    create_all(UCHAR, X_list_vec, X_list_mat)
    # create_all(CHAR, X_list_vec, X_list_mat)
    # create_all(USHORT, X_list_vec, X_list_mat)
    # create_all(SHORT, X_list_vec, X_list_mat)
    # create_all(UINT, X_list_vec, X_list_mat)
    create_all(INT, X_list_vec, X_list_mat)
    # create_all(ULONGLONG, X_list_vec, X_list_mat)
    # create_all(LONGLONG, X_list_vec, X_list_mat)

    # mathc/utils (floating point types)
    create_util(FLOAT)
    create_util(DOUBLE)
    # create_util(LONGDOUBLE)
