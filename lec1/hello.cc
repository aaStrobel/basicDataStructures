/*  Professor Scott, hello.cc

    simple hello world! example

    First CS140 lecture : 1/21/21 */

#include <iostream>  // preprocessor directive; includes io headers

int main() {   // main just like C; first function run

  // Note that C-style comments are allowed in c++ :)

  /* send the hello world string to the cout object
     end statement with a ";" just like C
     explictly define namespace std using namespace operator ::
     is called a stream insertion operator in C++    */

  std::cout << "Hello world!!!" << std::endl;  

  // no problems encountered, so return 0 to notify this after termination
  return (0);

}
