//
//  nthFibonacci.cpp
//  nthFibonacci using reccursion 
//
//  Created by Priyabrata Das on 27/06/21.
//

#include <iostream>

using namespace std ;


int nthFibonacci(int n){

  if (n == 1){
    return 1 ;
  } else if (n == 2 ){
    return 1 ;
  }

  return nthFibonacci(n-1) + nthFibonacci(n-2);
}

int main(int argc, const char * argv[]) {

    int n = 18 ;
    cout << nthFibonacci(n) << endl ;
    return 0;
}
