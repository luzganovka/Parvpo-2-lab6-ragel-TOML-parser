%%{
  machine ini_parser;
  

  # === Действия ===
  action start_token { ts = p; }

  action store_section {
    te = p;
    store(&section, te, ts);
    // printf("PARSED| Section: \"%s\"\n", section);
  }

  action store_key {
    te = p;
    store(&key, te, ts);
    // printf("PARSED|  Key: \"%s\"\n", key);
  }

  action store_value {
    te = p;
    store(&value, te, ts);
    // printf("PARSED|  Value: \"%s\"\n", value);
  }
  action store_kv {
#ifdef PRINT_OUTPUT
    printf("Section:{%s}\nKey:\t{%s}\nValue:\t{%s}\n%s", section, key, value, DELIMETER);
#endif    
  }

  # === Правила ===
  newline = '\r\n' | '\n';
  ws_char = ' ' | '\t';
  spaces = ws_char*;

  comment = '#' [^\n\r]* newline;

  section_name = (alnum | '_' | '-')+;
  key_name = (alnum | '_' | '-')+;
  val_chars = (print - '\n' - '\r')+;

  section = '[' spaces (section_name >start_token %store_section) spaces ']' spaces (newline | comment)?;
  key = (key_name >start_token %store_key);
  

  # Многострочные строки: """ ... """
  multiline_string = '"""' (
      [^"]            |     # любой символ, кроме "
      '"' [^"]        |     # одинарная кавычка, но не двойная
      '""' [^"]             # две кавычки, но не три
  )* '"""';

  # Обычные строки: "..."
  quoted_string = '"' ( ([^"])  )* '"';

  # Простая строка без кавычек (до первого пробела/перевода строки)
  bare_string = (print - '\n' - '\r' - '=' - '"' -'#')+;

  # Целое число (знак + цифры)
  integer = ['+' | '-']? digit+;

  # === Объединение всех поддерживаемых значений ===

  value = 
    (multiline_string >start_token %store_value) |
    (quoted_string    >start_token %store_value) |
    (integer          >start_token %store_value) |
    (bare_string      >start_token %store_value);



  kv_pair = (key spaces '=' spaces value spaces (newline | comment) %store_kv);

  line = (comment | section | kv_pair | spaces newline)+;

  main := line*;

  write data;
}%%





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

    %% write init;
    %% write exec;

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