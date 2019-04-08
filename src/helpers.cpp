// Copyright (c) 2019 Ivan Blagopoluchnyy. Email: nuclearrazor@gmail.com

#include <cstdlib>
#include <cassert>
#include "xserial.hpp"

LPWSTR char_to_lpwstr(const char * text)
{
    size_t _len = mbsrtowcs(NULL, &text, 0, NULL);
    wchar_t * buf = new wchar_t[_len + 1]();

    _len = mbsrtowcs(buf, &text, _len + 1, NULL);

    assert(text == NULL);

	LPWSTR ptr = buf;
	
	return ptr;
}
