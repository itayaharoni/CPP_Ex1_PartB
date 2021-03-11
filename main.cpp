#include <iostream>
#include <string>
#include <time.h>
using namespace std;
#include "snowman.hpp"
using namespace ariel;
int generate_random_combination(){
    int ans=0;
    int digit_number=0;
    while(digit_number<8)
    {
        float rand=(float) std::rand()/RAND_MAX;
        int rand_digit=(int)(10*rand);
        if(rand_digit>0 && rand_digit<5){
            ans*=10;
            ans+=rand_digit;
            digit_number++;
        }
    }
    return ans;
}
int main(){
    for (int i = 0; i < 10; i++){
        printf("random snowman #%d: \n",(i+1));
        std::string str=snowman(generate_random_combination());
        std::cout<<str<<'\n';
    }
    return 0;
}