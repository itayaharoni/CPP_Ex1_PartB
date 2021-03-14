#include <string>
#include <stdexcept>
#include <iostream>
#include <array>
using namespace std;
namespace ariel{
    const int ROW=5;
    const int COL=7;
    const int TEN=10;
    const int ONE=1;
    const int TWO=2;
    const int THREE=3;
    const int FOUR=4;
    const int INPUT_LEN=8;
    const int ZERO=0;
int reverse_number(int x){
    int i=ZERO;
    while(x>ZERO){
        i*=TEN;
        i+=x%TEN;
        x/=TEN;
    }
    return i;
}
bool is_size(int x){
    int count=ZERO;
    while(x>ZERO){
        count++;
        x/=TEN;
    }
    return count==INPUT_LEN;
}
bool is_bound(int x){
    while(x>ZERO){
        if(x%TEN==ZERO || x%TEN>FOUR){
         return false;
        }
        x/=TEN;
    }
    return true;
}
int hat(array<array<char,COL>,ROW>* mat,int choice,int line){
    std::string hat_choice;
    switch(choice){
        case ONE:
        hat_choice="_===_";
        break;
        case TWO:
        hat_choice=" ___\n.....";
        break;
        case THREE:
        hat_choice="  _\n /_\\";
        break;
        case FOUR:
        hat_choice=" ___\n(_*_)";
        break;
        default:
        throw std:: out_of_range{"An unvalid choice of an hat!\n"};
    }
    int j=ZERO;
    for (int i = ZERO; i <(int)hat_choice.length(); i++){
        if(hat_choice.at(i)=='\n'){ 
            line++;
            j=ZERO;
        }
        else{ (*mat).at(line).at(j++)=hat_choice.at(i);}
    }
    return line+ONE;
}
int nose_or_mouth(array<array<char,COL>,ROW>* mat,int choice,int line){
       std::string nose_or_mouth_choice;
    switch(choice){
        case ONE:
        nose_or_mouth_choice="( , )";
        break;
        case TWO:
        nose_or_mouth_choice="( . )";
        break;
        case THREE:
        nose_or_mouth_choice="( _ )";
        break;
        case FOUR:
        nose_or_mouth_choice="(   )";
        break;
        default:
        throw std:: out_of_range{"An unvalid choice of a nose/mouth!\n"};
    }
    for (int i = ZERO; i <(int)nose_or_mouth_choice.length(); i++){
        (*mat).at(line).at(i)=nose_or_mouth_choice.at(i);
    }
    return line;
}
int left_eye(array<array<char,COL>,ROW>* mat,int choice,int line){
       char left_eye_choice=ZERO;
    switch(choice){
        case ONE:
        left_eye_choice='.';
        break;
        case TWO:
        left_eye_choice='o';
        break;
        case THREE:
        left_eye_choice='O';
        break;
        case FOUR:
        left_eye_choice='-';
        break;
        default:
        throw std:: out_of_range{"An unvalid choice of a left eye!\n"};
    }
    for (int i = ZERO; i <COL; i++){
        if((*mat).at(line).at(i)=='('){
            (*mat).at(line).at(i+ONE)=left_eye_choice;
            break;
        }
    }
    return line;
}
int right_eye(array<array<char,COL>,ROW>* mat,int choice,int line){
       char right_eye_choice=ZERO;
    switch(choice){
        case ONE:
        right_eye_choice='.';
        break;
        case TWO:
        right_eye_choice='o';
        break;
        case THREE:
        right_eye_choice='O';
        break;
        case FOUR:
        right_eye_choice='-';
        break;
        default:
        throw std:: out_of_range{"An unvalid choice of a right eye!\n"};
    }
    for (int i = ZERO; i <COL; i++){
        if((*mat).at(line).at(i)==')'){
            (*mat).at(line).at(i-ONE)=right_eye_choice;
            break;
        }
    }
    return line+ONE;
}

void shift_mat_right_by_one(array<array<char,COL>,ROW>* mat, int line){

    // Shifting every element in the char mat to the right by ONE.
    for (int i = ZERO; i < line ; i++){
        for (int j = COL-1; j>ZERO; j--){
            (*mat).at(i).at(j)=(*mat).at(i).at(j-ONE);
            }
        }
    // Resetting the value of all the first collom chars to the value - " ".    
    for (int i = ZERO; i < line; i++){
        (*mat).at(i).at(ZERO)=' ';
    }
}
int left_arm(array<array<char,COL>,ROW>* mat,int choice,int line){
       char left_arm_choice=ZERO;
    switch(choice){
        case ONE:
        left_arm_choice='<';
        break;
        case TWO:
        left_arm_choice='\\';
        break;
        case THREE:
        left_arm_choice='/';
        break;
        case FOUR:
        return line;
        default:
        throw std:: out_of_range{"An unvalid choice of a left arm!\n"};
    }
    shift_mat_right_by_one(mat,line+ONE);
    if(choice==TWO){ 
        (*mat).at(line-ONE).at(ZERO)=left_arm_choice;
    }
    else{ 
        (*mat).at(line).at(ZERO)=left_arm_choice;
    }
    return line;
}
int right_arm(array<array<char,COL>,ROW>* mat,int choice,int line){
       char right_arm_choice=ZERO;
    switch(choice){
        case ONE:
        right_arm_choice='>';
        break;
        case TWO:
        right_arm_choice='/';
        break;
        case THREE:
        right_arm_choice='\\';
        break;
        case FOUR:
        return line+ONE;
        default:
        throw std:: out_of_range{"An unvalid choice of a right arm!\n"};
    }
    for (int i = ZERO; i < COL; i++)
    {
        if((*mat).at(line).at(i)==')'){
            if(choice==TWO){ (*mat).at(line-ONE).at(i+ONE)=right_arm_choice;}
            else{ (*mat).at(line).at(i+ONE)=right_arm_choice;}
            break;
        }
    }
    return line+ONE;
}
int get_index_of(array<char,COL> str, char c){
    for (int i = ZERO; i < COL; i++)
    {
        if(str.at(i)==c){ return i;}
    }
    return -ONE;
}
int torso(array<array<char,COL>,ROW>* mat,int choice,int line){
    std::string torso_choice;
    switch(choice){
        case ONE:
        torso_choice="( : )";
        break;
        case TWO:
        torso_choice="(] [)";
        break;
        case THREE:
        torso_choice="(> <)";
        break;
        case FOUR:
        torso_choice="(   )";
        break;
        default:
        throw std:: out_of_range{"An unvalid choice of a torso!\n"};
    }

    int col=get_index_of((*mat).at(line-ONE),'(');
    for (int i = ZERO; i < ((int)torso_choice.length()) ; i++){
        (*mat).at(line).at(i+col)=torso_choice.at(i);
    }
    return line;
}
int base(array<array<char,COL>,ROW>* mat,int choice,int line){
    std::string torso_choice;
    switch(choice){
        case ONE:
        torso_choice="( : )";
        break;
        case TWO:
        torso_choice="(\" \")";
        break;
        case THREE:
        torso_choice="(___)";
        break;
        case FOUR:
        torso_choice="(   )";
        break;
        default:
        throw std:: out_of_range{"An unvalid choice of a base!\n"};
    }
    int col=get_index_of((*mat).at(line-ONE),'(');
    for (int i = ZERO; i <((int)torso_choice.length()) ; i++){
        (*mat).at(line).at(i+col)=torso_choice.at(i);
    }
    return line+ONE;
}
std::string mat_to_string(array<array<char,COL>,ROW>* mat,int line){
    std::string ans;
    for (int i = ZERO; i < line; i++)
    {
        if(i!=ZERO){ ans.push_back('\n');}
        for (int j = ZERO; j < COL; j++)
        {
           if((*mat).at(i).at(j)==' '&& j>FOUR){ break;}
            ans.push_back((*mat).at(i).at(j));
        }
    }
    ans.push_back('\n');
    return ans;
}
void reset_mat(array<array<char,COL>,ROW>* mat){
    for (int i = ZERO; i < ROW; i++){
        for (int j = ZERO; j < COL; j++){
            (*mat).at(i).at(j)=' ';
    }
}
}
std::string snowman(int combination){
    if(combination<ZERO){ throw std:: out_of_range{"Combination must be positive!\n"};}
    if(!is_size(combination)){ throw std:: out_of_range{"Combination must consist of=INPUT_LEN digits.\n"};}
    if(!is_bound(combination)){ throw std:: out_of_range{"Combination must consist of the digits: {ONE,TWO,THREE,FOUR} !\n"};}
    int reverse_combination=reverse_number(combination);
    array<array<char,COL>,ROW> mat{};
    array<array<char,COL>,ROW>* snowman_mat=&mat;
    reset_mat(snowman_mat);
    int line=hat(snowman_mat,reverse_combination%TEN,ZERO);
    reverse_combination/=TEN;
    line=nose_or_mouth(snowman_mat,reverse_combination%TEN,line);
    reverse_combination/=TEN;
    line=left_eye(snowman_mat,reverse_combination%TEN,line);
    reverse_combination/=TEN;
    line=right_eye(snowman_mat,reverse_combination%TEN,line);
    reverse_combination/=TEN;
    line=left_arm(snowman_mat,reverse_combination%TEN,line);
    reverse_combination/=TEN;
    int right_arm_num=reverse_combination%TEN;
    reverse_combination/=TEN;
    line=torso(snowman_mat,reverse_combination%TEN,line);
    line=right_arm(snowman_mat,right_arm_num,line);
    reverse_combination/=TEN;
    line=base(snowman_mat,reverse_combination%TEN,line);
    return mat_to_string(snowman_mat,line);
    }
};