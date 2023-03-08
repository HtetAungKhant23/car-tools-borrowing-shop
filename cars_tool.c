//
// Created by User on 3/7/2023.
//

//git remote add origin https://github.com/HtetAungKhant23/iuhkj.git
//git branch -M main
//git push -u origin main



#include "stdio.h"
#include "stdlib.h"

struct tools{
    char *tool;
};

struct categories{
    struct tools tool_cat[12];
//    struct tools hand[3];
//    struct tools cordless[3];
//    struct tools diagnostic[3];
};

struct info{
    char name[30];
    char ph_num[20];
    char address[20];
    int amount;
    struct tools borrow_tools[5];
};

struct categories in_stock;
struct info users_info[100];
int amount[5] = {1000,5000,20000,30000};
int br_tool_index = 0;
int user_index = 0;
int tool_index = 0;
int amount_index = 0;
void fill_tool_name();
void choose_cate();
char option_checking(char op[2]);
void view_tools(int idx);
int char_count(char arr[30]);
void user_database();
void main_page();


int main(){
    printf("\n*** Welcome from car tools borrowing shop ***\n");
    fill_tool_name();
    main_page();

    return 0;
}

void main_page(){
    char option[2];
    printf("Enter 1 to view tools categories\n");
    printf("Enter 2 to quit : ");
    scanf(" %[^\n]",&option[0]);
    char res = option_checking(option);
    if(res == '1'){
        choose_cate();
    } else if(res == '2'){
        printf("Thank you!!!");
        exit(1);
    } else{
        printf("Invalid option!!!\n");
        main_page();
    }

}

char option_checking(char op[2]){
    if (op[0] && op[1] == '\0'){
        return op[0];
    }
    return 'n';
}

void choose_cate(){
    char option[2];
    printf("\n**********Categories**********\n");
    printf("enter 1 for automotive tools\n");
    printf("enter 2 for hand tools\n");
    printf("enter 3 for cordless tools\n");
    printf("enter 4 for diagnostic tools : ");
    scanf(" %[^\n]",&option[0]);
    char result = option_checking(option);
    if(result == '1'){
        int cate_index = 3;
        view_tools(cate_index);
    } else if(result == '2'){
        int cate_index = 6;
        view_tools(cate_index);
    } else if(result == '3'){
        int cate_index = 9;
        view_tools(cate_index);
    } else if(result == '4'){
        int cate_index = 12;
        view_tools(cate_index);
    } else {
        printf("Invalid option!!\n\n");
        choose_cate();
    }

}


void view_tools(int idx){
    char option[2];
    int start = idx - 3;
    amount_index = start;
    int j = 1;
    for(int i=start; i<idx; i++){
        printf("%d - %s\n",j, in_stock.tool_cat[i].tool);
        j++;
    }
    printf("choose your tools(1 or 2 or 3) : ");
    scanf(" %[^\n]",&option[0]);
    char ind = option_checking(option);
    if(ind == '1'){
        tool_index = start;
        user_database();
    } else if(ind == '2'){
        tool_index = start+1;
        user_database();
    } else if(ind == '3'){
        tool_index = start+2;
        user_database();
    } else{
        printf("Invalid option!!");
        view_tools(idx);
    }

}

int char_count(char arr[50]){
    int count = 0;
    while (arr[count] != '\0'){
        count++;
    }
    return count;
}

void user_database(){

    int amount_arr[4] = {0,3,6,9};


    users_info[user_index].borrow_tools[br_tool_index].tool = in_stock.tool_cat[tool_index].tool;

    for (int i=0; i<4; i++){
        if (amount_index == amount_arr[i]){
            amount_index = i;
            break;
        }
    }

    printf("your borrow tool is : %s and amount is %d\n\n",users_info[user_index].borrow_tools[br_tool_index].tool,amount[amount_index]);
    user_index++;
    br_tool_index++;
    main_page();

}


void fill_tool_name(){

    in_stock.tool_cat[0].tool = "socket sets";
    in_stock.tool_cat[1].tool = "screwdrivers";
    in_stock.tool_cat[2].tool = "spanner sets";
    in_stock.tool_cat[3].tool = "hammers";
    in_stock.tool_cat[4].tool = "pliers set";
    in_stock.tool_cat[5].tool = "hex key";
    in_stock.tool_cat[6].tool = "cordless 12V";
    in_stock.tool_cat[7].tool = "ratchet mini";
    in_stock.tool_cat[8].tool = "polisher 16V";
    in_stock.tool_cat[9].tool = "battery tester 12V";
    in_stock.tool_cat[10].tool = "antifreeze tester";
    in_stock.tool_cat[11].tool = "power jump 1600A";

}


































//    in_stock.automotive[0].tool = "socket sets";
//    in_stock.automotive[1].tool = "screwdrivers";
//    in_stock.automotive[2].tool = "spanner sets";
//    in_stock.hand[0].tool = "hammers";
//    in_stock.hand[1].tool = "pliers set";
//    in_stock.hand[2].tool = "hex key";
//    in_stock.cordless[0].tool = "cordless 12V";
//    in_stock.cordless[1].tool = "ratchet mini";
//    in_stock.cordless[2].tool = "polisher 16V";
//    in_stock.diagnostic[0].tool = "battery tester 12V";
//    in_stock.diagnostic[1].tool = "antifreeze tester";
//    in_stock.diagnostic[2].tool = "power jump 1600A";