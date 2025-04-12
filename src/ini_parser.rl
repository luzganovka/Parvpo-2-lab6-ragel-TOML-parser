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
    printf("Section:{%s}\nKey:\t{%s}\nValue:\t{%s}\n%s", section, key, value, DELIMETER);
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
  value = (val_chars >start_token %store_value);

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

    %%write init;
    %%write exec;

    if (cs == ini_parser_error) {
        fprintf(stderr, "Parse error!\n");
        return 1;
    }

    return 0;
}