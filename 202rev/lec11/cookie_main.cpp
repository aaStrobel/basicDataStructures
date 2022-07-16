// Prof. Scott

// Simple main program for constructor/deconstructor example

#include "cookie.cpp"

int main() {

  CookieMon * a;   // default cookie                                                             
  
  int * ptr;

  ptr = new int[1000];
  

  a = new CookieMon;
  delete a;

  a = new CookieMon('^');
  delete a;

  if (1) {

    CookieMon b ('+');  // non-default cookie, still yummy                                     

  }  // b is deconstructed here when it goes out of scope                                      

  delete [] ptr;

}  // a is deconstructed here    all memory goes back to the heap
