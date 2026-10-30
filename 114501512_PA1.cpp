#include <iostream>
using namespace std;

int main()
{
    cout<<"======Welcome to the Dinosaur Game======"<<endl;
    int base_obs;
    cout<<"Please enter the initial obstacle setup of the Dinosaur Game. Enter -1 to quit: ";
    cin>>base_obs;

    if(base_obs==-1){
        cout<<"The game ended when it just started."<<endl;
        cout<<"======Thanks for playing Dinosaur Game, see you next time======"<<endl;
        return 0;
    }

    //位置&狀態初始化
    int dinoTop=1; //y=1
    int dinoBottom=0;//y=0
    bool isJumping=false;
    int jumpstep=0;
    bool crouch=false;
    bool alive=true;

    // 取出八位數字（從左到右對應第2~9欄）
    int c0_obs = 0;
    int c1_obs = base_obs / 10000000 % 10;
    int c2_obs = base_obs / 1000000 % 10;
    int c3_obs = base_obs / 100000 % 10;
    int c4_obs = base_obs / 10000 % 10;
    int c5_obs = base_obs / 1000 % 10;
    int c6_obs = base_obs / 100 % 10;
    int c7_obs = base_obs / 10 % 10;
    int c8_obs = base_obs % 10;


    while (alive == true){

    //碰撞判定
        bool hit = false;
        //站著撞到矮仙人掌
        if (c0_obs == 1 && dinoBottom == 0 && crouch == false)
                hit = true;
        //蹲下撞到矮仙人掌
        if (c0_obs == 1 && dinoBottom == 0 && crouch == true)
                hit = true;
        //站著撞到高仙人掌
        if (c0_obs == 2 && (dinoBottom == 0 && dinoTop == 1) && crouch == false)
                hit = true;
        //蹲下撞到高仙人掌
        if (c0_obs == 2 && dinoBottom == 0 && crouch == true)
                hit = true;
        //跳躍撞到高仙人掌
        if (c0_obs == 2 && (dinoBottom == 1 && dinoTop == 2) && crouch == false)
                hit = true;
        //站著撞到低飛行物
        if (c0_obs == 3 && (dinoBottom == 0 && dinoTop == 1) && crouch == false)
                hit = true;
         //跳躍撞到低飛行物
        if (c0_obs == 3 && (dinoBottom == 1 && dinoTop == 2) && crouch == false)
                hit = true;
        //跳躍中撞到高飛行物
        if (c0_obs == 4 && (dinoBottom == 1 && dinoTop == 2) && crouch == false)
                hit = true;
        //跳躍最高點撞到高飛行物
        if (c0_obs == 4 && (dinoBottom == 2 && dinoTop == 3) && crouch == false)
                hit = true;

        if (hit == true){
            cout << "What a pity, it was close :( " << endl;
            cout << "======Thanks for playing Dinosaur Game, see you next time======"<<endl;
            return 0;
        }
    // 地圖 (4行 x 9欄)
        for (int row = 3; row >= 0; row--) {
            for (int column = 0; column < 9; column++) {
                char cell = '  ';//two spaces

    // 初始障礙物
                int Here_obs;
                if (column == 0)
                    Here_obs = c0_obs;
                else if (column == 1)
                    Here_obs = c1_obs;
                else if (column == 2)
                    Here_obs = c2_obs;
                else if (column == 3)
                    Here_obs = c3_obs;
                else if (column == 4)
                    Here_obs = c4_obs;
                else if (column == 5)
                    Here_obs = c5_obs;
                else if (column == 6)
                    Here_obs = c6_obs;
                else if (column == 7)
                    Here_obs = c7_obs;
                else if (column == 8)
                    Here_obs = c8_obs;

                if (Here_obs == 1 && row == 0)
                    cell = ' C';             // 小仙人掌
                else if (Here_obs == 2 && (row == 0 || row == 1))
                    cell = ' C';            // 大仙人掌
                else if (Here_obs == 3 && row == 1)
                    cell = ' P';            // 低飛行物
                else if (Here_obs == 4 && row == 2)
                    cell = ' P';            // 高飛行物

                // 恐龍（固定第1欄）
                if (column == 0 && (row == dinoTop || row == dinoBottom)) {
                    cell = 'D';
                }
                cout << "| " << cell;

            }// end for
        cout << "|"<<endl;
    }//end for

        //輸入指令
        float command;
        cout << "Please enter a command to control the dinosaur, 0 for no action, 1=jump, 2=crouch: ";
        cin >> command;

        //指令+跳躍防呆
        while (command != 0 && command != 1 && command != 2){
            cout << "The dinosaur doesn't understand this command, try another one: ";
            cin >> command;
            while ( command == 1 && jumpstep > 0){
            cout << "The dinosaur cannot jumping again, please enter another command: ";
            cin >> command;
            }
        }
        //跳躍防呆+指令防呆
        while (command == 1 && jumpstep > 0){
            cout << "The dinosaur cannot jump again, please enter another command: ";
            cin >> command;
            while (command != 0 && command != 1 && command != 2){
            cout << "The dinosaur doesn't understand this command, try another one: ";
            cin >> command;
            }
        }

        //改變動作
        if (command == 1){ //跳躍
            jumpstep = 1;
            isJumping = true;
            crouch = false;
        } else if (command == 2){//蹲下
            crouch = true;
            isJumping = false;
            dinoTop = 0;
            dinoBottom = 0;
            jumpstep = 0;
        } else if (command == 0 && crouch == true)
            crouch = false;

        //跳躍改變(1~4 tick)
        if (isJumping == true) {
            if (jumpstep == 1) {//tick1
                dinoTop = 2;
                dinoBottom = 1;
                 jumpstep = 2;
            } else if (jumpstep == 2) {//tick2
                dinoTop = 3;
                dinoBottom = 2;
                jumpstep = 3;
            } else if (jumpstep == 3) {//tick3
                dinoTop = 2;
                dinoBottom = 1;
                 jumpstep = 4;
            } else if (jumpstep == 4) {//tick4
                 dinoTop = 1;
                 dinoBottom = 0;
                 jumpstep = 0;
                 isJumping = false;
            }
        } else if (crouch == false) {
                dinoTop = 1;
                dinoBottom = 0;
        }

        //輸入新一輪障礙物
        int new_obs;
        cout << "Please enter the next round's obstacle setup of the Dinosaur Game. Enter -1 to quit: ";
        cin >> new_obs;
        //輸入-1顯示訊息
        if (new_obs==-1){
        cout << "Congratulations, you WIN the game!!!"<<endl;
        cout << "======Thanks for playing Dinosaur Game, see you next time======"<<endl;
        return 0;
        }

        //推動障礙物
        c0_obs = c1_obs;
        c1_obs = c2_obs;
        c2_obs = c3_obs;
        c3_obs = c4_obs;
        c4_obs = c5_obs;
        c5_obs = c6_obs;
        c6_obs = c7_obs;
        c7_obs = c8_obs;
        c8_obs = new_obs;
    }// end while
    return 0;
}//end main
