/*
Copyright (c) 2021 Sebastian Ullrich. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.

Author: Sebastian Ullrich
*/
#include <cstdlib>
#include <iostream>
#include <emscripten.h>

// The actual main function is in `util/shell.cpp` and compiled into `libleanshared` to avoid issues with cross-lib C++.
// It will eventually be replaced by Lean code anyway.
// We put `main` in this separate file included only in `lean` so linking against `libleanshared` does not accidentally use it.

extern "C" int lean_main(int argc, char ** argv);

// int main(int argc, char ** argv) {
//     return lean_main(argc, argv);
// }

#if defined(EMSCRIPTEN)
EM_ASYNC_JS(char*, wait_for_stdin, (), {
    var jsString = 'Hello with some exotic Unicode characters: Tässä on yksi lumiukko: ☃, ole hyvä.';

    var res = await new Promise((resolve, reject) => {
            setTimeout(() => {
                resolve(stringToNewUTF8(jsString));
            }, 1000);
        });

    // out("waiting for a fetch");
    // const res = await fetch("index.html");
    // out("got the fetch response");
    return res;
})
#endif

int main(void)
{
  char *line =NULL;
  size_t len = 0;
  ssize_t lineSize = 0;

  printf("Start:\n");
  
#if defined(EMSCRIPTEN)
  const char* a = wait_for_stdin();
#endif
  printf("%s\n",a);

  printf("End:\n");

  free(line);

  return 0;
}
