
#line 1 "src/ini_parser.rl"

#line 2 "src/ini_parser.c"
static const char _ini_parser_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	3, 1, 4, 2, 0, 3, 2, 4, 
	0
};

static const unsigned char _ini_parser_key_offsets[] = {
	0, 0, 4, 5, 7, 18, 21, 29, 
	39, 49, 59, 70, 73, 74, 84, 89, 
	91, 92, 93, 98, 104, 105, 106, 107, 
	121, 135
};

static const char _ini_parser_trans_keys[] = {
	9, 10, 13, 32, 10, 10, 13, 9, 
	32, 45, 61, 95, 48, 57, 65, 90, 
	97, 122, 9, 32, 61, 9, 32, 33, 
	34, 36, 60, 62, 126, 9, 10, 13, 
	32, 34, 35, 33, 60, 62, 126, 9, 
	10, 13, 32, 34, 35, 33, 60, 62, 
	126, 9, 32, 45, 95, 48, 57, 65, 
	90, 97, 122, 9, 32, 45, 93, 95, 
	48, 57, 65, 90, 97, 122, 9, 32, 
	93, 10, 9, 10, 13, 32, 33, 35, 
	36, 60, 62, 126, 9, 10, 13, 32, 
	35, 10, 13, 34, 34, 9, 10, 13, 
	32, 35, 9, 10, 13, 32, 34, 35, 
	34, 34, 34, 9, 10, 13, 32, 35, 
	45, 91, 95, 48, 57, 65, 90, 97, 
	122, 9, 10, 13, 32, 35, 45, 91, 
	95, 48, 57, 65, 90, 97, 122, 9, 
	10, 13, 32, 35, 45, 91, 95, 48, 
	57, 65, 90, 97, 122, 0
};

static const char _ini_parser_single_lengths[] = {
	0, 4, 1, 2, 5, 3, 4, 6, 
	6, 4, 5, 3, 1, 6, 5, 2, 
	1, 1, 5, 6, 1, 1, 1, 8, 
	8, 8
};

static const char _ini_parser_range_lengths[] = {
	0, 0, 0, 0, 3, 0, 2, 2, 
	2, 3, 3, 0, 0, 2, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 3, 
	3, 3
};

static const unsigned char _ini_parser_index_offsets[] = {
	0, 0, 5, 7, 10, 19, 23, 30, 
	39, 48, 56, 65, 69, 71, 80, 86, 
	89, 91, 93, 99, 106, 108, 110, 112, 
	124, 136
};

static const char _ini_parser_indicies[] = {
	0, 2, 3, 0, 1, 2, 1, 2, 
	3, 4, 5, 5, 6, 7, 6, 6, 
	6, 6, 1, 8, 8, 9, 1, 9, 
	10, 11, 12, 11, 11, 1, 13, 14, 
	15, 16, 12, 17, 11, 11, 1, 18, 
	19, 20, 10, 12, 21, 11, 11, 1, 
	22, 22, 23, 23, 23, 23, 23, 1, 
	24, 24, 25, 26, 25, 25, 25, 25, 
	1, 27, 27, 28, 1, 19, 1, 29, 
	14, 15, 30, 31, 17, 31, 31, 1, 
	32, 19, 20, 32, 21, 1, 19, 20, 
	21, 34, 33, 35, 33, 29, 14, 15, 
	29, 17, 1, 29, 14, 15, 29, 36, 
	17, 1, 37, 36, 38, 36, 35, 36, 
	0, 2, 3, 0, 4, 39, 22, 39, 
	39, 39, 39, 1, 40, 41, 42, 40, 
	43, 44, 45, 44, 44, 44, 44, 1, 
	28, 2, 3, 28, 4, 39, 22, 39, 
	39, 39, 39, 1, 0
};

static const char _ini_parser_trans_targs[] = {
	1, 0, 23, 2, 3, 5, 4, 6, 
	5, 6, 7, 13, 16, 8, 24, 12, 
	7, 15, 8, 24, 12, 15, 9, 10, 
	11, 10, 25, 11, 25, 14, 13, 13, 
	14, 17, 19, 18, 20, 21, 22, 4, 
	1, 23, 2, 3, 4, 9
};

static const char _ini_parser_trans_actions[] = {
	0, 0, 0, 0, 0, 5, 0, 5, 
	0, 0, 1, 1, 1, 7, 7, 7, 
	11, 7, 0, 0, 0, 0, 0, 1, 
	3, 0, 3, 0, 0, 7, 7, 0, 
	0, 0, 0, 0, 0, 0, 0, 1, 
	9, 9, 9, 9, 14, 9
};

static const char _ini_parser_eof_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	9, 0
};

static const int ini_parser_start = 23;
static const int ini_parser_first_final = 23;
static const int ini_parser_error = 0;

static const int ini_parser_en_main = 23;


#line 77 "src/ini_parser.rl"






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

char *section, *key, *value;
 size_t len;
 char *data, *ts, *te, *p, *pe, *eof;
 int cs;

void parse_file(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("Ошибка открытия файла");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long len = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    data = malloc(len + 1);
    fread(data, 1, len, fp);
    data[len] = '\0';

    fclose(fp);

    p  = data;
    pe = data + len;

    
#line 157 "src/ini_parser.c"
	{
	cs = ini_parser_start;
	}

#line 124 "src/ini_parser.rl"
    
#line 160 "src/ini_parser.c"
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
#line 262 "src/ini_parser.c"
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
#line 282 "src/ini_parser.c"
		}
	}
	}

	_out: {}
	}

#line 125 "src/ini_parser.rl"

    free(data);
    free(section);

    if (cs == ini_parser_error) {
        fprintf(stderr, "Parse error!\n");
        exit(2);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Использование: %s <config_file.toml>\n", argv[0]);
        return 1;
    }

    parse_file(argv[1]);
    return 0;
}