#ifndef MATHC_PUBLICTYPES_<{FLOAT}>_H
#define MATHC_PUBLICTYPES_<{FLOAT}>_H

<% for i in range(2, X+1) -%>
#include "<{vec}><{i}>.h"
<% endfor %>

<% for i in range(2, X+1) -%>
#include "<{mat}><{i}>.h"
<% endfor %>

#endif //MATHC_PUBLICTYPES_<{FLOAT}>_H
