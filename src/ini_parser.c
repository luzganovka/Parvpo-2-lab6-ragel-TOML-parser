
#line 1 "src/ini_parser.rl"

#line 2 "src/ini_parser.c"
static const char _ini_parser_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	3, 2, 2, 3, 2, 3, 0
};

static const char _ini_parser_key_offsets[] = {
	0, 0, 4, 5, 7, 18, 21, 31, 
	41, 52, 55, 69, 83, 97, 112
};

static const char _ini_parser_trans_keys[] = {
	9, 10, 13, 32, 10, 10, 13, 9, 
	32, 45, 61, 95, 48, 57, 65, 90, 
	97, 122, 9, 32, 61, 9, 32, 45, 
	95, 48, 57, 65, 90, 97, 122, 9, 
	32, 45, 95, 48, 57, 65, 90, 97, 
	122, 9, 32, 45, 93, 95, 48, 57, 
	65, 90, 97, 122, 9, 32, 93, 9, 
	10, 13, 32, 35, 45, 91, 95, 48, 
	57, 65, 90, 97, 122, 9, 10, 13, 
	32, 35, 45, 91, 95, 48, 57, 65, 
	90, 97, 122, 9, 10, 13, 32, 35, 
	45, 91, 95, 48, 57, 65, 90, 97, 
	122, 9, 10, 13, 32, 35, 45, 61, 
	91, 95, 48, 57, 65, 90, 97, 122, 
	9, 10, 13, 32, 35, 45, 61, 91, 
	95, 48, 57, 65, 90, 97, 122, 0
};

static const char _ini_parser_single_lengths[] = {
	0, 4, 1, 2, 5, 3, 4, 4, 
	5, 3, 8, 8, 8, 9, 9
};

static const char _ini_parser_range_lengths[] = {
	0, 0, 0, 0, 3, 0, 3, 3, 
	3, 0, 3, 3, 3, 3, 3
};

static const char _ini_parser_index_offsets[] = {
	0, 0, 5, 7, 10, 19, 23, 31, 
	39, 48, 52, 64, 76, 88, 101
};

static const char _ini_parser_indicies[] = {
	0, 2, 3, 0, 1, 2, 1, 2, 
	3, 4, 5, 5, 6, 7, 6, 6, 
	6, 6, 1, 8, 8, 9, 1, 9, 
	9, 10, 10, 10, 10, 10, 1, 11, 
	11, 12, 12, 12, 12, 12, 1, 13, 
	13, 14, 15, 14, 14, 14, 14, 1, 
	16, 16, 17, 1, 0, 2, 3, 0, 
	4, 18, 11, 18, 18, 18, 18, 1, 
	19, 20, 21, 19, 22, 23, 24, 23, 
	23, 23, 23, 1, 17, 2, 3, 17, 
	4, 18, 11, 18, 18, 18, 18, 1, 
	25, 20, 21, 25, 22, 23, 7, 24, 
	23, 23, 23, 23, 1, 26, 2, 3, 
	26, 4, 18, 9, 11, 18, 18, 18, 
	18, 1, 0
};

static const char _ini_parser_trans_targs[] = {
	1, 0, 10, 2, 3, 5, 4, 6, 
	5, 6, 11, 7, 8, 9, 8, 12, 
	9, 12, 4, 12, 10, 2, 3, 13, 
	7, 14, 14
};

static const char _ini_parser_trans_actions[] = {
	0, 0, 0, 0, 0, 5, 0, 5, 
	0, 0, 1, 0, 1, 3, 0, 3, 
	0, 0, 1, 7, 7, 7, 7, 12, 
	7, 9, 0
};

static const char _ini_parser_eof_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 7, 0, 7, 0
};

static const int ini_parser_start = 10;
static const int ini_parser_first_final = 10;
static const int ini_parser_error = 0;

static const int ini_parser_en_main = 10;


#line 48 "src/ini_parser.rl"


#include <stdio.h>
#include <string.h>

int main() {
    const char *data =
        "# Comment\n"
        "[server]\n"
        "host = localhost\n"
        "port = 8080\n"
        "\n"
        "[database]\n"
        "user = \"admin\"\n"
        "password = \"secret\"\n";

    // const char *data = "[server]bla bla bla";

    const char *p = data;
    const char *pe = data + strlen(data);
    const char *eof = pe;
    const char *ts = NULL, *te = NULL;

    int cs = 0;

    
#line 114 "src/ini_parser.c"
	{
	cs = ini_parser_start;
	}

#line 74 "src/ini_parser.rl"
    
#line 117 "src/ini_parser.c"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_keys = _ini_parser_trans_keys + _ini_parser_key_offsets[cs];
	_trans = _ini_parser_index_offsets[cs];

	_klen = _ini_parser_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (unsigned int)(_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _ini_parser_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += (unsigned int)((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	_trans = _ini_parser_indicies[_trans];
	cs = _ini_parser_trans_targs[_trans];

	if ( _ini_parser_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _ini_parser_actions + _ini_parser_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 6 "src/ini_parser.rl"
	{ ts = p; }
	break;
	case 1:
#line 7 "src/ini_parser.rl"
	{
    te = p;
    printf("PARSED| Section: \"%.*s\"\n", (int)(te - ts), ts);
  }
	break;
	case 2:
#line 11 "src/ini_parser.rl"
	{
    te = p;
    printf("PARSED|  Key: \"%.*s\"\n", (int)(te - ts), ts);
  }
	break;
	case 3:
#line 15 "src/ini_parser.rl"
	{
    te = p;
    printf("PARSED|  Value: \"%.*s\"\n", (int)(te - ts), ts);
  }
	break;
#line 211 "src/ini_parser.c"
		}
	}

_again:
	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	if ( p == eof )
	{
	const char *__acts = _ini_parser_actions + _ini_parser_eof_actions[cs];
	unsigned int __nacts = (unsigned int) *__acts++;
	while ( __nacts-- > 0 ) {
		switch ( *__acts++ ) {
	case 3:
#line 15 "src/ini_parser.rl"
	{
    te = p;
    printf("PARSED|  Value: \"%.*s\"\n", (int)(te - ts), ts);
  }
	break;
#line 232 "src/ini_parser.c"
		}
	}
	}

	_out: {}
	}

#line 75 "src/ini_parser.rl"

    if (cs == ini_parser_error) {
        fprintf(stderr, "Parse error!\n");
        return 1;
    }

    return 0;
}