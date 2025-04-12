
#line 1 "src/ini_parser.rl"

#line 2 "src/ini_parser.c"
static const char _ini_parser_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	3, 1, 4, 2, 0, 3, 2, 4, 
	0
};

static const char _ini_parser_key_offsets[] = {
	0, 0, 4, 5, 7, 18, 21, 25, 
	32, 39, 49, 60, 63, 64, 71, 76, 
	78, 85, 99, 113
};

static const char _ini_parser_trans_keys[] = {
	9, 10, 13, 32, 10, 10, 13, 9, 
	32, 45, 61, 95, 48, 57, 65, 90, 
	97, 122, 9, 32, 61, 9, 32, 33, 
	126, 9, 10, 13, 32, 35, 33, 126, 
	9, 10, 13, 32, 35, 33, 126, 9, 
	32, 45, 95, 48, 57, 65, 90, 97, 
	122, 9, 32, 45, 93, 95, 48, 57, 
	65, 90, 97, 122, 9, 32, 93, 10, 
	9, 10, 13, 32, 35, 33, 126, 9, 
	10, 13, 32, 35, 10, 13, 9, 10, 
	13, 32, 35, 33, 126, 9, 10, 13, 
	32, 35, 45, 91, 95, 48, 57, 65, 
	90, 97, 122, 9, 10, 13, 32, 35, 
	45, 91, 95, 48, 57, 65, 90, 97, 
	122, 9, 10, 13, 32, 35, 45, 91, 
	95, 48, 57, 65, 90, 97, 122, 0
};

static const char _ini_parser_single_lengths[] = {
	0, 4, 1, 2, 5, 3, 2, 5, 
	5, 4, 5, 3, 1, 5, 5, 2, 
	5, 8, 8, 8
};

static const char _ini_parser_range_lengths[] = {
	0, 0, 0, 0, 3, 0, 1, 1, 
	1, 3, 3, 0, 0, 1, 0, 0, 
	1, 3, 3, 3
};

static const unsigned char _ini_parser_index_offsets[] = {
	0, 0, 5, 7, 10, 19, 23, 27, 
	34, 41, 49, 58, 62, 64, 71, 77, 
	80, 87, 99, 111
};

static const char _ini_parser_indicies[] = {
	0, 2, 3, 0, 1, 2, 1, 2, 
	3, 4, 5, 5, 6, 7, 6, 6, 
	6, 6, 1, 8, 8, 9, 1, 9, 
	10, 11, 1, 12, 13, 14, 15, 16, 
	11, 1, 17, 18, 19, 10, 20, 11, 
	1, 21, 21, 22, 22, 22, 22, 22, 
	1, 23, 23, 24, 25, 24, 24, 24, 
	24, 1, 26, 26, 27, 1, 18, 1, 
	28, 13, 14, 29, 31, 30, 1, 32, 
	18, 19, 32, 33, 1, 18, 19, 33, 
	34, 13, 14, 31, 31, 35, 33, 0, 
	2, 3, 0, 4, 36, 21, 36, 36, 
	36, 36, 1, 37, 38, 39, 37, 40, 
	41, 42, 41, 41, 41, 41, 1, 27, 
	2, 3, 27, 4, 36, 21, 36, 36, 
	36, 36, 1, 0
};

static const char _ini_parser_trans_targs[] = {
	1, 0, 17, 2, 3, 5, 4, 6, 
	5, 6, 7, 13, 8, 18, 12, 7, 
	16, 8, 18, 12, 16, 9, 10, 11, 
	10, 19, 11, 19, 14, 13, 13, 16, 
	14, 15, 15, 16, 4, 1, 17, 2, 
	3, 4, 9
};

static const char _ini_parser_trans_actions[] = {
	0, 0, 0, 0, 0, 5, 0, 5, 
	0, 0, 1, 1, 7, 7, 7, 11, 
	11, 0, 0, 0, 1, 0, 1, 3, 
	0, 3, 0, 0, 7, 7, 0, 7, 
	0, 0, 7, 0, 1, 9, 9, 9, 
	9, 14, 9
};

static const char _ini_parser_eof_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 9, 0
};

static const int ini_parser_start = 17;
static const int ini_parser_first_final = 17;
static const int ini_parser_error = 0;

static const int ini_parser_en_main = 17;


#line 51 "src/ini_parser.rl"






#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char *DELIMETER = "=======================\n\n";

int store(char** target, const char *te, const char *ts) {
  size_t len = te - ts;
  free(*target);
    if (*target = malloc(len + 1)) {
      memcpy(*target, ts, len);
      (*target)[len] = '\0';
    }
}

int main() {
    const char *data =
        "# Comment\n"
        "[server]\n"
        "host = \"localhost\"\n"
        "port = 8080\n"
        "\n"
        "[database]\n"
        "user = \'admin\'\n"
        "password = \"secret\"\n";

    // const char *data = "[server]bla bla bla";

    const char *p = data;
    const char *pe = data + strlen(data);
    const char *eof = pe;
    const char *ts = NULL, *te = NULL;

    int cs = 0;

    size_t len = 0;
    char *section = NULL;
    char *key = NULL;
    char *value = NULL;

    
#line 146 "src/ini_parser.c"
	{
	cs = ini_parser_start;
	}

#line 98 "src/ini_parser.rl"
    
#line 149 "src/ini_parser.c"
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
#line 8 "src/ini_parser.rl"
	{
    te = p;
    store(&section, te, ts);
    // printf("PARSED| Section: \"%s\"\n", section);
  }
	break;
	case 2:
#line 14 "src/ini_parser.rl"
	{
    te = p;
    store(&key, te, ts);
    // printf("PARSED|  Key: \"%s\"\n", key);
  }
	break;
	case 3:
#line 20 "src/ini_parser.rl"
	{
    te = p;
    store(&value, te, ts);
    // printf("PARSED|  Value: \"%s\"\n", value);
  }
	break;
	case 4:
#line 25 "src/ini_parser.rl"
	{
    printf("Section:{%s}\nKey:\t{%s}\nValue:\t{%s}\n%s", section, key, value, DELIMETER);
  }
	break;
#line 251 "src/ini_parser.c"
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
	case 4:
#line 25 "src/ini_parser.rl"
	{
    printf("Section:{%s}\nKey:\t{%s}\nValue:\t{%s}\n%s", section, key, value, DELIMETER);
  }
	break;
#line 271 "src/ini_parser.c"
		}
	}
	}

	_out: {}
	}

#line 99 "src/ini_parser.rl"

    if (cs == ini_parser_error) {
        fprintf(stderr, "Parse error!\n");
        return 1;
    }

    return 0;
}