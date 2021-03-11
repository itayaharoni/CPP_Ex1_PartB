#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;
#define ROW 5
#define COL 7
#define TEN 10
namespace ariel{
int reverse_number(int x){
    int i=0;
    while(x>0){
        i*=TEN;
        i+=x%TEN;
        x/=TEN;
    }
    return i;
}
bool is_size(int x){
    int count=0;
    while(x>0){
        count++;
        x/=TEN;
    }
    return count==8;
}
bool is_bound(int x){
    while(x>0){
        if(x%TEN==0 || x%TEN>4) return false;
        x/=TEN;
    }
    return true;
}
int hat(char mat[][COL],int choice,int line){
    std::string hat_choice;
    switch(choice){
        case 1:
        hat_choice="_===_";
        break;
        case 2:
        hat_choice=" ___\n.....";
        break;
        case 3:
        hat_choice="  _\n /_\\";
        break;
        case 4:
        hat_choice=" ___\n(_*_)";
        break;
        default:
        throw std:: out_of_range{"An unvalid choice of an hat!\n"};
    }
    int j=0;
    for (int i = 0; i <(int)hat_choice.length(); i++){
        if(hat_choice.at(i)=='\n'){ 
            line++;
            j=0;
        }
        else mat[line][j++]=hat_choice.at(i);
    }
    return line+1;
}
int nose_or_mouth(char mat[][COL],int choice,int line){
       std::string nose_or_mouth_choice;
    switch(choice){
        case 1:
        nose_or_mouth_choice="( , )";
        break;
        case 2:
        nose_or_mouth_choice="( . )";
        break;
        case 3:
        nose_or_mouth_choice="( _ )";
        break;
        case 4:
        nose_or_mouth_choice="(   )";
        break;
        default:
        throw std:: out_of_range{"An unvalid choice of a nose/mouth!\n"};
    }
    for (int i = 0; i <(int)nose_or_mouth_choice.length(); i++)
        mat[line][i]=nose_or_mouth_choice.at(i);
    return line;
}
int left_eye(char mat[][COL],int choice,int line){
       char left_eye_choice;
    switch(choice){
        case 1:
        left_eye_choice='.';
        break;
        case 2:
        left_eye_choice='o';
        break;
        case 3:
        left_eye_choice='O';
        break;
        case 4:
        left_eye_choice='-';
        break;
        default:
        throw std:: out_of_range{"An unvalid choice of a left eye!\n"};
    }
    for (int i = 0; i <COL; i++){
        if(mat[line][i]=='('){
            mat[line][i+1]=left_eye_choice;
            break;
        }
    }
    return line;
}
int right_eye(char mat[][COL],int choice,int line){
       char right_eye_choice;
    switch(choice){
        case 1:
        right_eye_choice='.';
        break;
        case 2:
        right_eye_choice='o';
        break;
        case 3:
        right_eye_choice='O';
        break;
        case 4:
        right_eye_choice='-';
        break;
        default:
        throw std:: out_of_range{"An unvalid choice of a right eye!\n"};
    }
    for (int i = 0; i <COL; i++){
        if(mat[line][i]==')'){
            mat[line][i-1]=right_eye_choice;
            break;
        }
    }
    return line+1;
}

void shift_mat_right_by_one(char mat[][COL], int line){

    // Shifting every element in the char mat to the right by 1.
    for (int i = 0; i < line ; i++)
        for (int j = ROW; j>0; j--)
            mat[i][j]=mat[i][j-1];

    // Resetting the value of all the first collom chars to the value - " ".    
    for (int i = 0; i < line; i++)
        mat[i][0]=' ';
}
int left_arm(char mat[][COL],int choice,int line){
       char left_arm_choice;
    switch(choice){
        case 1:
        left_arm_choice='<';
        break;
        case 2:
        left_arm_choice='\\';
        break;
        case 3:
        left_arm_choice='/';
        break;
        case 4:
        return line;
        default:
        throw std:: out_of_range{"An unvalid choice of a left arm!\n"};
    }
    shift_mat_right_by_one(mat,line+1);
    if(choice==2) mat[line-1][0]=left_arm_choice;
    else mat[line][0]=left_arm_choice;
    return line;
}
int right_arm(char mat[][COL],int choice,int line){
       char right_arm_choice;
    switch(choice){
        case 1:
        right_arm_choice='>';
        break;
        case 2:
        right_arm_choice='/';
        break;
        case 3:
        right_arm_choice='\\';
        break;
        case 4:
        return line+1;
        default:
        throw std:: out_of_range{"An unvalid choice of a right arm!\n"};
    }
    for (int i = 0; i < COL; i++)
    {
        if(mat[line][i]==')'){
            if(choice==2) mat[line-1][i+1]=right_arm_choice;
            else mat[line][i+1]=right_arm_choice;
            break;
        }
    }
    return line+1;
}
int get_index_of(char* str, char c){
    for (int i = 0; i < COL; i++)
    {
        if(str[i]==c) return i;
    }
    return -1;
}
int torso(char mat[][COL],int choice,int line){
    std::string torso_choice;
    switch(choice){
        case 1:
        torso_choice="( : )";
        break;
        case 2:
        torso_choice="(] [)";
        break;
        case 3:
        torso_choice="(> <)";
        break;
        case 4:
        torso_choice="(   )";
        break;
        default:
        throw std:: out_of_range{"An unvalid choice of a torso!\n"};
    }
    int col=get_index_of(mat[line-1],'(');
    for (int i = 0; i < (int)torso_choice.length() ; i++)
        mat[line][i+col]=torso_choice.at(i);
    return line;
}
int base(char mat[][COL],int choice,int line){
    std::string torso_choice;
    switch(choice){
        case 1:
        torso_choice="( : )";
        break;
        case 2:
        torso_choice="(\" \")";
        break;
        case 3:
        torso_choice="(___)";
        break;
        case 4:
        torso_choice="(   )";
        break;
        default:
        throw std:: out_of_range{"An unvalid choice of a base!\n"};
    }
    int col=get_index_of(mat[line-1],'(');
    for (int i = 0; i <(int)torso_choice.length() ; i++)
        mat[line][i+col]=torso_choice.at(i);
    return line+1;
}
std::string mat_to_string(char mat[][COL],int line){
    std::string ans="";
    for (int i = 0; i < line; i++)
    {
        if(i!=0) ans.push_back('\n');
        for (int j = 0; j < COL; j++)
        {
            if(mat[i][j]=='\n') printf("Hello");
           if(mat[i][j]==' '&& j>4) break;
            ans.push_back(mat[i][j]);
        }
    }
    ans.push_back('\n');
    return ans;
}
void reset_mat(char mat[][COL]){
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            mat[i][j]=' ';
}
std::string snowman(int combination){
    if(combination<0) throw std:: out_of_range{"Combination must be positive!\n"};
    else if(!is_size(combination)) throw std:: out_of_range{"Combination must consist of 8 digits.\n"};
    else if(!is_bound(combination)) throw std:: out_of_range{"Combination must consist of the digits: {1,2,3,4} !\n"};
    int reverse_combination=reverse_number(combination);
    char snowman_mat[ROW][COL];
    reset_mat(snowman_mat);
    int line=hat(snowman_mat,reverse_combination%TEN,0);
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