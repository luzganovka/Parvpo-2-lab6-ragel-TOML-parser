
#line 1 "src/ini_parser.rl"

#line 2 "src/ini_parser.c"
static const char _ini_parser_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	3, 2, 0, 3, 2, 1, 2, 2, 
	2, 3, 2, 3, 0, 3, 1, 2, 
	3
};

static const short _ini_parser_key_offsets[] = {
	0, 0, 4, 5, 7, 18, 21, 25, 
	35, 46, 49, 62, 67, 73, 85, 98, 
	103, 117, 123, 135, 139, 153, 175, 197, 
	219, 233, 255, 268, 290, 311, 334, 348, 
	371, 393, 406, 428, 443, 466, 489, 504, 
	527, 549, 563, 585, 601
};

static const char _ini_parser_trans_keys[] = {
	9, 10, 13, 32, 10, 10, 13, 9, 
	32, 45, 61, 95, 48, 57, 65, 90, 
	97, 122, 9, 32, 61, 9, 32, 33, 
	126, 9, 32, 45, 95, 48, 57, 65, 
	90, 97, 122, 9, 32, 45, 93, 95, 
	48, 57, 65, 90, 97, 122, 9, 32, 
	93, 9, 10, 13, 32, 45, 61, 95, 
	48, 57, 65, 90, 97, 122, 9, 10, 
	13, 32, 61, 9, 10, 13, 32, 33, 
	126, 9, 10, 13, 32, 45, 95, 48, 
	57, 65, 90, 97, 122, 9, 10, 13, 
	32, 45, 93, 95, 48, 57, 65, 90, 
	97, 122, 9, 10, 13, 32, 93, 9, 
	10, 13, 32, 45, 61, 93, 95, 48, 
	57, 65, 90, 97, 122, 9, 10, 13, 
	32, 61, 93, 9, 32, 45, 61, 93, 
	95, 48, 57, 65, 90, 97, 122, 9, 
	32, 61, 93, 9, 10, 13, 32, 35, 
	45, 91, 95, 48, 57, 65, 90, 97, 
	122, 9, 10, 13, 32, 35, 45, 91, 
	95, 33, 47, 48, 57, 58, 64, 65, 
	90, 92, 96, 97, 122, 123, 126, 9, 
	10, 13, 32, 35, 45, 91, 95, 33, 
	47, 48, 57, 58, 64, 65, 90, 92, 
	96, 97, 122, 123, 126, 9, 10, 13, 
	32, 35, 45, 91, 95, 33, 47, 48, 
	57, 58, 64, 65, 90, 92, 96, 97, 
	122, 123, 126, 9, 10, 13, 32, 35, 
	45, 91, 95, 48, 57, 65, 90, 97, 
	122, 9, 10, 13, 32, 35, 45, 91, 
	95, 33, 47, 48, 57, 58, 64, 65, 
	90, 92, 96, 97, 122, 123, 126, 9, 
	10, 13, 32, 45, 91, 95, 48, 57, 
	65, 90, 97, 122, 9, 10, 13, 32, 
	35, 45, 91, 95, 33, 47, 48, 57, 
	58, 64, 65, 90, 92, 96, 97, 122, 
	123, 126, 9, 10, 13, 32, 45, 91, 
	95, 33, 47, 48, 57, 58, 64, 65, 
	90, 92, 96, 97, 122, 123, 126, 9, 
	10, 13, 32, 35, 45, 61, 91, 95, 
	33, 47, 48, 57, 58, 64, 65, 90, 
	92, 96, 97, 122, 123, 126, 9, 10, 
	13, 32, 45, 61, 91, 95, 48, 57, 
	65, 90, 97, 122, 9, 10, 13, 32, 
	35, 45, 61, 91, 95, 33, 47, 48, 
	57, 58, 64, 65, 90, 92, 96, 97, 
	122, 123, 126, 9, 10, 13, 32, 35, 
	45, 91, 95, 33, 47, 48, 57, 58, 
	64, 65, 90, 92, 96, 97, 122, 123, 
	126, 9, 10, 13, 32, 45, 91, 95, 
	48, 57, 65, 90, 97, 122, 9, 10, 
	13, 32, 35, 45, 61, 91, 92, 93, 
	94, 96, 33, 47, 48, 57, 58, 64, 
	65, 122, 123, 126, 9, 10, 13, 32, 
	45, 61, 91, 93, 95, 48, 57, 65, 
	90, 97, 122, 9, 10, 13, 32, 35, 
	45, 61, 91, 95, 33, 47, 48, 57, 
	58, 64, 65, 90, 92, 96, 97, 122, 
	123, 126, 9, 10, 13, 32, 35, 45, 
	61, 91, 95, 33, 47, 48, 57, 58, 
	64, 65, 90, 92, 96, 97, 122, 123, 
	126, 9, 10, 13, 32, 35, 45, 61, 
	91, 95, 48, 57, 65, 90, 97, 122, 
	9, 10, 13, 32, 35, 45, 61, 91, 
	95, 33, 47, 48, 57, 58, 64, 65, 
	90, 92, 96, 97, 122, 123, 126, 9, 
	10, 13, 32, 35, 45, 91, 95, 33, 
	47, 48, 57, 58, 64, 65, 90, 92, 
	96, 97, 122, 123, 126, 9, 10, 13, 
	32, 35, 45, 91, 95, 48, 57, 65, 
	90, 97, 122, 9, 10, 13, 32, 35, 
	45, 61, 91, 92, 93, 94, 96, 33, 
	47, 48, 57, 58, 64, 65, 122, 123, 
	126, 9, 10, 13, 32, 35, 45, 61, 
	91, 93, 95, 48, 57, 65, 90, 97, 
	122, 9, 10, 13, 32, 35, 45, 61, 
	91, 95, 33, 47, 48, 57, 58, 64, 
	65, 90, 92, 96, 97, 122, 123, 126, 
	0
};

static const char _ini_parser_single_lengths[] = {
	0, 4, 1, 2, 5, 3, 2, 4, 
	5, 3, 7, 5, 4, 6, 7, 5, 
	8, 6, 6, 4, 8, 8, 8, 8, 
	8, 8, 7, 8, 7, 9, 8, 9, 
	8, 7, 12, 9, 9, 9, 9, 9, 
	8, 8, 12, 10, 9
};

static const char _ini_parser_range_lengths[] = {
	0, 0, 0, 0, 3, 0, 1, 3, 
	3, 0, 3, 0, 1, 3, 3, 0, 
	3, 0, 3, 0, 3, 7, 7, 7, 
	3, 7, 3, 7, 7, 7, 3, 7, 
	7, 3, 5, 3, 7, 7, 3, 7, 
	7, 3, 5, 3, 7
};

static const short _ini_parser_index_offsets[] = {
	0, 0, 5, 7, 10, 19, 23, 27, 
	35, 44, 48, 59, 65, 71, 81, 92, 
	98, 110, 117, 127, 132, 144, 160, 176, 
	192, 204, 220, 231, 247, 262, 279, 291, 
	308, 324, 335, 353, 366, 383, 400, 413, 
	430, 446, 458, 476, 490
};

static const char _ini_parser_indicies[] = {
	0, 2, 3, 0, 1, 2, 1, 2, 
	3, 4, 5, 5, 6, 7, 6, 6, 
	6, 6, 1, 8, 8, 9, 1, 9, 
	10, 11, 1, 12, 12, 13, 13, 13, 
	13, 13, 1, 14, 14, 15, 16, 15, 
	15, 15, 15, 1, 17, 17, 18, 1, 
	19, 2, 3, 19, 20, 21, 20, 20, 
	20, 20, 4, 22, 2, 3, 22, 23, 
	4, 23, 2, 3, 24, 25, 4, 26, 
	2, 3, 26, 27, 27, 27, 27, 27, 
	4, 28, 2, 3, 28, 29, 30, 29, 
	29, 29, 29, 4, 31, 2, 3, 31, 
	32, 4, 33, 2, 3, 33, 34, 21, 
	30, 34, 34, 34, 34, 4, 35, 2, 
	3, 35, 23, 32, 4, 36, 36, 37, 
	7, 16, 37, 37, 37, 37, 1, 38, 
	38, 9, 18, 1, 0, 2, 3, 0, 
	4, 39, 12, 39, 39, 39, 39, 1, 
	40, 41, 42, 43, 44, 45, 46, 45, 
	11, 45, 11, 45, 11, 45, 11, 1, 
	47, 2, 3, 10, 25, 48, 49, 48, 
	11, 48, 11, 48, 11, 48, 11, 1, 
	50, 41, 42, 51, 53, 54, 55, 54, 
	52, 54, 52, 54, 52, 54, 52, 1, 
	18, 2, 3, 18, 4, 39, 12, 39, 
	39, 39, 39, 1, 56, 41, 42, 53, 
	53, 58, 59, 58, 57, 58, 57, 58, 
	57, 58, 57, 4, 32, 2, 3, 32, 
	60, 26, 60, 60, 60, 60, 4, 61, 
	41, 42, 62, 44, 63, 64, 63, 25, 
	63, 25, 63, 25, 63, 25, 4, 65, 
	2, 3, 24, 66, 67, 66, 25, 66, 
	25, 66, 25, 66, 25, 4, 68, 41, 
	42, 69, 53, 58, 70, 59, 58, 57, 
	58, 57, 58, 57, 58, 57, 4, 71, 
	2, 3, 71, 60, 23, 26, 60, 60, 
	60, 60, 4, 72, 41, 42, 73, 53, 
	58, 74, 59, 58, 57, 58, 57, 58, 
	57, 58, 57, 4, 75, 41, 42, 59, 
	53, 76, 59, 76, 57, 76, 57, 76, 
	57, 76, 57, 4, 77, 2, 3, 77, 
	78, 26, 78, 78, 78, 78, 4, 79, 
	41, 42, 80, 53, 81, 70, 59, 57, 
	82, 57, 57, 57, 81, 57, 81, 57, 
	4, 83, 2, 3, 83, 60, 23, 26, 
	32, 60, 60, 60, 60, 4, 84, 41, 
	42, 85, 53, 58, 74, 59, 58, 57, 
	58, 57, 58, 57, 58, 57, 4, 86, 
	41, 42, 87, 53, 54, 88, 55, 54, 
	52, 54, 52, 54, 52, 54, 52, 1, 
	89, 2, 3, 89, 4, 39, 9, 12, 
	39, 39, 39, 39, 1, 90, 41, 42, 
	91, 53, 54, 92, 55, 54, 52, 54, 
	52, 54, 52, 54, 52, 1, 93, 41, 
	42, 55, 53, 94, 55, 94, 52, 94, 
	52, 94, 52, 94, 52, 1, 95, 2, 
	3, 95, 4, 96, 12, 96, 96, 96, 
	96, 1, 97, 41, 42, 98, 53, 99, 
	88, 55, 52, 100, 52, 52, 52, 99, 
	52, 99, 52, 1, 101, 2, 3, 101, 
	4, 39, 9, 12, 18, 39, 39, 39, 
	39, 1, 102, 41, 42, 103, 53, 54, 
	92, 55, 54, 52, 54, 52, 54, 52, 
	54, 52, 1, 0
};

static const char _ini_parser_trans_targs[] = {
	1, 0, 20, 2, 3, 5, 4, 6, 
	5, 6, 21, 23, 7, 8, 9, 8, 
	24, 9, 24, 11, 10, 12, 11, 12, 
	27, 25, 13, 14, 15, 14, 26, 15, 
	26, 17, 16, 17, 19, 18, 19, 4, 
	22, 20, 2, 21, 25, 37, 40, 22, 
	37, 40, 24, 23, 23, 25, 37, 40, 
	26, 25, 29, 32, 10, 28, 27, 29, 
	32, 28, 29, 32, 30, 31, 27, 30, 
	30, 31, 27, 33, 34, 33, 16, 35, 
	36, 34, 25, 35, 35, 36, 38, 39, 
	21, 38, 38, 39, 21, 41, 42, 41, 
	18, 43, 44, 42, 23, 43, 43, 44
};

static const char _ini_parser_trans_actions[] = {
	0, 0, 0, 0, 0, 5, 0, 5, 
	0, 0, 1, 1, 0, 1, 3, 0, 
	3, 0, 0, 5, 0, 5, 0, 0, 
	1, 1, 0, 1, 3, 0, 3, 0, 
	0, 12, 0, 0, 12, 0, 0, 1, 
	7, 7, 7, 9, 9, 9, 9, 0, 
	1, 1, 7, 7, 0, 7, 18, 7, 
	7, 0, 18, 7, 1, 7, 9, 9, 
	9, 0, 1, 1, 15, 15, 5, 0, 
	7, 7, 0, 7, 9, 0, 1, 21, 
	21, 18, 3, 0, 7, 7, 15, 15, 
	5, 0, 7, 7, 0, 7, 9, 0, 
	1, 21, 21, 18, 3, 0, 7, 7
};

static const char _ini_parser_eof_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 7, 0, 7, 
	0, 7, 0, 7, 0, 7, 0, 7, 
	7, 0, 7, 0, 7, 7, 0, 7, 
	7, 0, 7, 0, 7
};

static const int ini_parser_start = 20;
static const int ini_parser_first_final = 20;
static const int ini_parser_error = 0;

static const int ini_parser_en_main = 20;


#line 41 "src/ini_parser.rl"


#include <stdio.h>
#include <string.h>

int main() {
    const char *data =
        "# Comment\n"
        "[server]\n"
        "host = \"localhost\"\n"
        "port = 8080\n"
        "\n"
        "[database]\n"
        "user = \"admin\"\n"
        "password = \"secret\"\n";

    const char *p = data;
    const char *pe = data + strlen(data);
    const char *eof = pe;
    const char *ts = NULL, *te = NULL;

    int cs = 0; // 🛡️ Избавляет от warning о неинициализированной переменной

    
#line 264 "src/ini_parser.c"
	{
	cs = ini_parser_start;
	}

#line 65 "src/ini_parser.rl"
    
#line 267 "src/ini_parser.c"
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
    printf("Section: %.*s\n", (int)(te - ts), ts);
  }
	break;
	case 2:
#line 10 "src/ini_parser.rl"
	{
    printf("  Key: %.*s = ", (int)(te - ts), ts);
  }
	break;
	case 3:
#line 13 "src/ini_parser.rl"
	{
    printf("%.*s\n", (int)(te - ts), ts);
  }
	break;
#line 358 "src/ini_parser.c"
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
#line 13 "src/ini_parser.rl"
	{
    printf("%.*s\n", (int)(te - ts), ts);
  }
	break;
#line 378 "src/ini_parser.c"
		}
	}
	}

	_out: {}
	}

#line 66 "src/ini_parser.rl"

    if (cs == ini_parser_error) {
        fprintf(stderr, "Parse error!\n");
        return 1;
    }

    return 0;
}