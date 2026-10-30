#include <iostream>
using namespace std;

int main()
{   //指令輸入第一層障礙物
    cout<<"======Welcome to the Dinosaur Game======"<<endl;
    int base_obs1F;
    cout<<"Please enter the first layer initial obstacle setup of the Dinosaur Game. Enter -1 to quit: ";
    cin>>base_obs1F;

    if(base_obs1F==-1){
        cout<<"The game ended when it just started."<<endl;
        cout<<"======Thanks for playing Dinosaur Game, see you next time======"<<endl;
        return 0;
    }

    //指令輸入第二層障礙物
    int base_obs2F;
    cout<<"Please enter the second layer initial obstacle setup of the Dinosaur Game: ";
    cin>>base_obs2F;
    //令輸入兩層間格設定
    int base_gap;
    cout<<"Please enter the initial distribution of gap in the ceiling, 0 for gap, 1 for complete ceiling: ";
    cin>>base_gap;
    //位置&狀態初始化
    int dinoTop=1; //y=1
    int dinoBottom=0;//y=0
    int jumpstep=0;
    int fallstep=0;
    bool isJumping=false;
    bool isFalling=false;
    bool canDoubleJump=false;
    bool crouch=false;
    bool alive=true;
    bool on_1F=true;
    bool on_2F = false;
    // 取出第一層八位數字（從左到右對應第2~9欄）
    int c0_obs1F = 0;
    int c1_obs1F = base_obs1F / 10000000 % 10 ;
    int c2_obs1F = base_obs1F / 1000000 % 10 ;
    int c3_obs1F = base_obs1F / 100000 % 10 ;
    int c4_obs1F = base_obs1F / 10000 % 10 ;
    int c5_obs1F = base_obs1F / 1000 % 10 ;
    int c6_obs1F = base_obs1F / 100 % 10 ;
    int c7_obs1F = base_obs1F / 10 % 10 ;
    int c8_obs1F = base_obs1F % 10;
    //取出間隔
    int c0_gap = base_gap / 100000000 % 10;
    int c1_gap = base_gap / 10000000 % 10;
    int c2_gap = base_gap / 1000000 % 10;
    int c3_gap = base_gap / 100000 % 10;
    int c4_gap = base_gap / 10000 % 10;
    int c5_gap = base_gap / 1000 % 10;
    int c6_gap = base_gap / 100 % 10;
    int c7_gap = base_gap / 10 % 10;
    int c8_gap = base_gap % 1000;
    // 取出第二層八位數字（從左到右對應第2~9欄）
    int c0_obs2F = 0;
    int c1_obs2F = base_obs2F / 10000000 % 10;
    int c2_obs2F = base_obs2F / 1000000 % 10;
    int c3_obs2F = base_obs2F / 100000 % 10;
    int c4_obs2F = base_obs2F / 10000 % 10;
    int c5_obs2F = base_obs2F / 1000 % 10;
    int c6_obs2F = base_obs2F / 100 % 10;
    int c7_obs2F = base_obs2F / 10 % 10;
    int c8_obs2F = base_obs2F % 10;

    while (alive == true){

    //第一層碰撞判定
        bool hit = false;
        //站著撞到矮仙人掌
        if (c0_obs1F == 1 && dinoBottom == 0 && crouch == false)
                hit = true;
        //蹲下撞到矮仙人掌
        if (c0_obs1F == 1 && dinoBottom == 0 && crouch == true)
                hit = true;
        //站著撞到高仙人掌
        if (c0_obs1F == 2 && (dinoBottom == 0 && dinoTop == 1) && crouch == false)
                hit = true;
        //蹲下撞到高仙人掌
        if (c0_obs1F == 2 && dinoBottom == 0 && crouch == true)
                hit = true;
        //跳躍撞到高仙人掌
        if (c0_obs1F == 2 && (dinoBottom == 1 && dinoTop == 2) && crouch == false)
                hit = true;
        //站著撞到低飛行物
        if (c0_obs1F == 3 && (dinoBottom == 0 && dinoTop == 1) && crouch == false)
                hit = true;
         //跳躍撞到低飛行物
        if (c0_obs1F == 3 && (dinoBottom == 1 && dinoTop == 2) && crouch == false)
                hit = true;
        //跳躍中撞到高飛行物
        if (c0_obs1F == 4 && (dinoBottom == 1 && dinoTop == 2) && crouch == false)
                hit = true;
        //跳躍最高點撞到高飛行物
        if (c0_obs1F == 4 && (dinoBottom == 2 && dinoTop == 3) && crouch == false)
                hit = true;

    //第二層碰撞判定
        //站著撞到矮仙人掌
        if (c0_obs2F == 1 && dinoBottom == 4 && crouch == false)
                hit = true;
        //蹲下撞到矮仙人掌
        if (c0_obs2F == 1 && dinoBottom == 4 && crouch == true)
                hit = true;
        //站著撞到高仙人掌
        if (c0_obs2F == 2 && (dinoBottom == 4 && dinoTop == 5) && crouch == false)
                hit = true;
        //蹲下撞到高仙人掌
        if (c0_obs2F == 2 && dinoBottom == 4 && crouch == true)
                hit = true;
        //跳躍撞到高仙人掌
        if (c0_obs2F == 2 && (dinoBottom == 5 && dinoTop == 6) && crouch == false)
                hit = true;
        //站著撞到低飛行物
        if (c0_obs2F == 3 && (dinoBottom == 4 && dinoTop == 5) && crouch == false)
                hit = true;
         //跳躍撞到低飛行物
        if (c0_obs2F == 3 && (dinoBottom == 5 && dinoTop == 5) && crouch == false)
                hit = true;
        //跳躍中撞到高飛行物
        if (c0_obs2F == 4 && (dinoBottom == 5 && dinoTop == 6) && crouch == false)
                hit = true;
        //跳躍最高點撞到高飛行物
        if (c0_obs2F == 4 && (dinoBottom == 6 && dinoTop == 7) && crouch == false)
                hit = true;

    //特殊碰撞情況
        //頭撞到二樓低仙人掌
        if(c0_obs2F == 1&&(dinoBottom == 3 && dinoTop == 4)&& crouch == false)
                hit = true;
         //頭撞到二樓高仙人掌
        if(c0_obs2F == 2&&(dinoBottom == 3 && dinoTop == 4)&& crouch == false)
                hit = true;


        if (hit == true){
            cout << "What a pity, it was close :( " << endl;
            cout << "======Thanks for playing Dinosaur Game, see you next time======";
            return 0;
        }
    // 第2層地圖 (4行 x 9欄)
        for (int row = 7; row >= 4; row--) {//y=7~y=4
            for (int column = 0; column < 9; column++) {
                char cell = ' ';

    // 第二層初始障礙物
                int Here_obs2F;
                if (column == 0)
                    Here_obs2F = c0_obs2F;
                else if (column == 1)
                    Here_obs2F = c1_obs2F;
                else if (column == 2)
                    Here_obs2F = c2_obs2F;
                else if (column == 3)
                    Here_obs2F = c3_obs2F;
                else if (column == 4)
                    Here_obs2F = c4_obs2F;
                else if (column == 5)
                    Here_obs2F = c5_obs2F;
                else if (column == 6)
                    Here_obs2F = c6_obs2F;
                else if (column == 7)
                    Here_obs2F = c7_obs2F;
                else if (column == 8)
                    Here_obs2F = c8_obs2F;

                if (Here_obs2F == 1 && row == 4)
                    cell = ' C';             // 小仙人掌
                else if (Here_obs2F == 2 && (row == 4 || row == 5))
                    cell = ' C';            // 大仙人掌
                else if (Here_obs2F == 3 && row == 5)
                    cell = ' P';            // 低飛行物
                else if (Here_obs2F == 4 && row == 6)
                    cell = ' P';            // 高飛行物

                // 恐龍（固定第1欄）
                if (column == 0 && (row == dinoTop || row == dinoBottom)) {
                    cell = 'D';
                }
                cout << "| " << cell;

            }// end for
        cout << "|"<<endl;
    }//end for

    //初始間隔
    for(int fake_col=0 ; fake_col < 9 ; fake_col ++){
        char cell = ' ';
        int Here_gap;
                if (fake_col == 0)
                    Here_gap = c0_gap;
                else if (fake_col == 1)
                    Here_gap = c1_gap;
                else if (fake_col == 2)
                    Here_gap = c2_gap;
                else if (fake_col == 3)
                    Here_gap = c3_gap;
                else if (fake_col == 4)
                    Here_gap = c4_gap;
                else if (fake_col == 5)
                    Here_gap = c5_gap;
                else if (fake_col == 6)
                    Here_gap = c6_gap;
                else if (fake_col == 7)
                    Here_gap = c7_gap;
                else if (fake_col == 8)
                    Here_gap = c8_gap;

                cout << "=";
                if (Here_gap == 1)
                    cout<<"==";
                else if (Here_gap == 0)
                    cout<<"  ";
                }
                cout<<"="<<endl;


    // 第一層地圖 (4行 x 9欄)
        for (int row = 3; row >= 0; row--) { //y=3 ~ y=0
            for (int column = 0; column < 9; column++) {
                char cell = ' ';

    // 第一層初始障礙物
                int Here_obs1F;
                if (column == 0)
                    Here_obs1F = c0_obs1F;
                else if (column == 1)
                    Here_obs1F = c1_obs1F;
                else if (column == 2)
                    Here_obs1F = c2_obs1F;
                else if (column == 3)
                    Here_obs1F = c3_obs1F;
                else if (column == 4)
                    Here_obs1F = c4_obs1F;
                else if (column == 5)
                    Here_obs1F = c5_obs1F;
                else if (column == 6)
                    Here_obs1F = c6_obs1F;
                else if (column == 7)
                    Here_obs1F = c7_obs1F;
                else if (column == 8)
                    Here_obs1F = c8_obs1F;

                if (Here_obs1F == 1 && row == 0)
                    cell = 'C';             // 小仙人掌
                else if (Here_obs1F == 2 && (row == 0 || row == 1))
                    cell = ' C';            // 大仙人掌
                else if (Here_obs1F == 3 && row == 1)
                    cell = ' P';            // 低飛行物
                else if (Here_obs1F == 4 && row == 2)
                    cell = ' P';            // 高飛行物

                // 恐龍（固定第1欄）
                if (column == 0 && (row == dinoTop || row == dinoBottom)) {
                    cell = 'D';
                }
                cout << "| " << cell;

            }// end for
        cout << "|"<<endl;
    }//end for


        //二段跳解鎖
        if(dinoBottom==2&&dinoTop==3&&isFalling==false&&isJumping==true&&c1_gap==0)
            canDoubleJump=true;

        //輸入指令
        float command;
        cout << "Please enter a command to control the dinosaur, 0 for no action, 1=jump, 2=crouch: ";
        cin >> command;

        //指令+跳躍防呆
        while (command != 0 && command != 1 && command != 2){
            cout << "The dinosaur doesn't understand this command, try another one: ";
            cin >> command;
            while ( command == 1 && (isJumping==true || isFalling==true)&&canDoubleJump==false){
            cout << "The dinosaur cannot jumping again, please enter another command: ";
            cin >> command;
            }
             while ( command == 1 && (dinoBottom==4&&dinoTop==5)&&c0_gap==0){
            cout << "The dinosaur cannot jumping again, please enter another command: ";
            cin >> command;
            }
        }
        //跳躍防呆+指令防呆
        while (command == 1&& (isJumping==true||isFalling==true)&&canDoubleJump==false){
            cout << "The dinosaur cannot jump again, please enter another command: ";
            cin >> command;
            while (command != 0 && command != 1 && command != 2){
            cout << "The dinosaur doesn't understand this command, try another one: ";
            cin >> command;
            }
        }
        //第二層地板空無法跳
         while ( command == 1 &&(dinoBottom==4&&dinoTop==5)&&c0_gap==0&&isJumping==false){
            cout << "The dinosaur cannot jumping again, please enter another command: ";
            cin >> command;
            while (command != 0 && command != 1 && command != 2){
            cout << "The dinosaur doesn't understand this command, try another one: ";
            cin >> command;
            }
        }

        //指令對應動作&條件
        if (command == 1&&on_1F==true){ //第一層跳躍
            jumpstep = 1;
            isJumping = true;
            crouch = false;
        }else if(command==1&&on_2F==true){//第二層跳躍
            jumpstep = 5;
            isJumping = true;
            crouch = false;
        } else if (command == 2&&on_1F==true&&crouch==false){//第一層蹲下
            isJumping = false;
            canDoubleJump=false;
            crouch = true;
            dinoTop = 0;
            dinoBottom = 0;
            jumpstep = 0;
        }else if (command == 2&&on_2F==true&&c1_gap==1&&crouch==false){//第二層蹲下(有地板不會掉下去)
            crouch = true;
            isJumping = false;
            dinoTop = 4;
            dinoBottom = 4;
            jumpstep = 0;
        }else if (command == 2&&on_2F==true&&c1_gap==0&&crouch==false){//在第二層蹲下(沒有地板掉到第一層)
            crouch = true;
            isJumping = false;
            dinoTop = 0;
            dinoBottom = 0;
            jumpstep = 0;
        }else if (command == 2&&isFalling==true&&crouch==false){//下落中蹲下
            crouch = true;
            isFalling = false;
            dinoTop = 0;
            dinoBottom = 0;
            fallstep = 0;
        }else if (command == 0 && crouch == true&&isJumping==false&&on_1F==true){//第一層蹲下變成站立
            crouch = false;
        }else if (command == 0 && crouch == true&&isJumping==false&&on_2F==true){//第二層蹲下變成站立
            crouch = false;
        }

    //第一層動作改變(
        //跳躍
        if (isJumping == true && on_1F == true) {//二段跳，為什麼放這裡，因為如果放在指令區的話會印不出來
                if(command==1&&canDoubleJump==true){
                dinoBottom=3;
                dinoTop=4;
                canDoubleJump=false;
                jumpstep=8;    //二段跳的結果其實和正常跳躍的tick4相同
            }else if (jumpstep == 1) {//tick1
                dinoTop = 2;
                dinoBottom = 1;
                jumpstep++;
            } else if (jumpstep == 2) {//tick2
                dinoTop = 3;
                dinoBottom = 2;
                jumpstep++;
            } else if (jumpstep == 3) {//tick3
                dinoTop = 2;
                dinoBottom = 1;
                jumpstep++;
            } else if (jumpstep == 4) {//tick4
                 dinoTop = 1;
                 dinoBottom = 0;
                 jumpstep=0;
                 isJumping = false;
            }
        } else if (crouch == false&&on_1F==true&&isFalling==false) {//在第一層且沒跳沒蹲沒在落下
                dinoTop = 1;
                dinoBottom = 0;
        } else if(isFalling==true&&crouch==false){//落下
             if (fallstep==1) {
                dinoTop = 3;
                dinoBottom = 2;
                fallstep++;
            } else if (fallstep==2) {
                dinoTop = 2;
                dinoBottom = 1;
                fallstep++;
            } else if (fallstep==3) {
                dinoTop = 1;
                dinoBottom = 0;
                fallstep=0;
                isFalling=false; //落下結束
            }
        }

        //第二層動作改變(1~4 tick)
        if (isJumping == true && on_2F == true) {//跳躍
            if (jumpstep == 5) {//tick1
                dinoTop = 6;
                dinoBottom = 5;
                jumpstep++;
            } else if (jumpstep == 6) {//tick2
                dinoTop = 7;
                dinoBottom = 6;
                jumpstep++;
            } else if (jumpstep == 7) {//tick3
                dinoTop = 6;
                dinoBottom = 5;
                jumpstep++;
            } else if (jumpstep == 8) {//tick4
                 dinoTop = 5;
                 dinoBottom = 4;
                 jumpstep=0;
                 isJumping = false;
            }
        } else if (crouch == false&& c1_gap ==1&&isJumping==false&&on_2F==true) { //沒跳沒蹲但有地板
                dinoTop = 5;
                dinoBottom = 4;
                jumpstep=0;
        } else if(crouch == false&& c1_gap ==0&&isJumping==false&&on_2F==true&&isFalling==false){//沒跳沒蹲但沒地板，開始落下
                dinoTop=4;
                dinoBottom=3;
                fallstep=1;
                isFalling=true; //開始掉落

        }



         if(dinoTop>=4){
            on_1F=false;
            on_2F=true;
         }else{
            on_1F=true;
            on_2F=false;
         }

        if(isFalling==true){
            on_1F=true;
            on_2F=false;
        }


        //輸入第一層新一輪障礙物
        int new_obs1F;
        cout << "Please enter the next round's first layer obstacle setup of the Dinosaur Game. Enter -1 to quit: ";
        cin >> new_obs1F;
        //輸入-1顯示訊息
        if (new_obs1F==-1){
        cout << "Congratulations, you WIN the game!!!"<<endl;
        cout << "======Thanks for playing Dinosaur Game, see you next time======"<<endl;
        return 0;
        }
        //輸入第二層新一輪障礙物
        int new_obs2F;
        cout << "Please enter the next round's second layer obstacle setup of the Dinosaur Game: ";
        cin >> new_obs2F;

        //輸入新一輪間隔
        int new_gap;
        cout << "Please enter the next round's ceiling or gap status: ";
        cin >> new_gap;


        //推動第一層障礙物
        c0_obs1F = c1_obs1F;
        c1_obs1F = c2_obs1F;
        c2_obs1F= c3_obs1F;
        c3_obs1F = c4_obs1F;
        c4_obs1F = c5_obs1F;
        c5_obs1F = c6_obs1F;
        c6_obs1F = c7_obs1F;
        c7_obs1F = c8_obs1F;
        c8_obs1F = new_obs1F;

        //推動第二層障礙物
        c0_obs2F = c1_obs2F;
        c1_obs2F = c2_obs2F;
        c2_obs2F = c3_obs2F;
        c3_obs2F = c4_obs2F;
        c4_obs2F = c5_obs2F;
        c5_obs2F = c6_obs2F;
        c6_obs2F = c7_obs2F;
        c7_obs2F = c8_obs2F;
        c8_obs2F = new_obs2F;

        //推動間隔
        c0_gap = c1_gap;
        c1_gap = c2_gap;
        c2_gap = c3_gap;
        c3_gap = c4_gap;
        c4_gap = c5_gap;
        c5_gap = c6_gap;
        c6_gap = c7_gap;
        c7_gap = c8_gap;
        c8_gap = new_gap;
    }// end while
    return 0;
}//end main

// :(

