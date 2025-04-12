%%{
  machine ini_parser;
  

  # === Действия ===
  action start_token { ts = p; }
  action store_section {
    te = p;
    printf("PARSED| Section: \"%.*s\"\n", (int)(te - ts), ts);
  }
  action store_key {
    te = p;
    printf("PARSED|  Key: \"%.*s\"\n", (int)(te - ts), ts);
  }
  action store_value {
    te = p;
    printf("PARSED|  Value: \"%.*s\"\n", (int)(te - ts), ts);
  }
  action store_kv {
    // printf("PARSED| KV| Value: \"%.*s\"\n", (int)(te - ts), ts);
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

    %%write init;
    %%write exec;

    if (cs == ini_parser_error) {
        fprintf(stderr, "Parse error!\n");
        return 1;
    }

    return 0;
}