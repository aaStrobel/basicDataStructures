#ifndef COOKIE_H
#define COOKIE_H

/* Professor Scott, cookie.h

who doesn't like cookies?

Simple example that displays a message when objects are constructed and deconstructed
to show when constructors are run (when they come in scope) and what happens when
deconstructs run (when they go out of scope)

*/

class CookieMon {

   public:

  CookieMon(char c = 'C');  // constructor
  ~CookieMon();             // deconstructor!

 private:

  char myc;


};

#endif
