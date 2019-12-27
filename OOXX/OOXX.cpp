#include<iostream>
using namespace std;
/*勝利判斷*/
bool winner(char map[3][3]){
    for(int i=0;i<3;i++) if(map[i][0]!=' '&&map[i][0]==map[i][1]&&map[i][1]==map[i][2]) return true;//列勝利判斷
    for(int i=0;i<3;i++) if(map[0][i]!=' '&&map[0][i]==map[1][i]&&map[1][i]==map[2][i]) return true;//行勝利判斷
    if(map[0][0]!=' '&&map[0][0]==map[1][1]&&map[1][1]==map[2][2]) return true;//左上右下斜勝利判斷
    if(map[0][2]!=' '&&map[0][2]==map[1][1]&&map[1][1]==map[2][0]) return true;//右上左下斜勝利判斷
    return false;//如果沒有勝利出現
}
/*判斷是否能在這個位置放置棋子*/
bool TFset(char Player,int Switch,char map[3][3]){
/*第一列 判斷*/
    if(Switch==7&&map[0][0]==' '){map[0][0]=Player; return true;}
    else if(Switch==8&&map[0][1]==' '){map[0][1]=Player; return true;}
    else if(Switch==9&&map[0][2]==' '){map[0][2]=Player; return true;}
/*第二列 判斷*/
    else if(Switch==4&&map[1][0]==' '){map[1][0]=Player; return true;}
    else if(Switch==5&&map[1][1]==' '){map[1][1]=Player; return true;}
    else if(Switch==6&&map[1][2]==' '){map[1][2]=Player; return true;}
/*第三列 判斷*/
    else if(Switch==1&&map[2][0]==' '){map[2][0]=Player; return true;}
    else if(Switch==2&&map[2][1]==' '){map[2][1]=Player; return true;}
    else if(Switch==3&&map[2][2]==' '){map[2][2]=Player; return true;}
/*錯誤提示*/
    else{ cout<<"按錯了啦 蛤啊你是目洨膩？"<<endl; return false;}
}
/*顯示閘*/
void show(char map[3][3]){
    for(int i=0;i<3;i++){
        cout<<" －－－－－－－－－"<<endl;
        for(int j=0;j<3;j++) { cout<<"|  "<<map[i][j]<<"  "; } cout<<"|"<<endl;
    }cout<<" －－－－－－－－－"<<endl;
}

int main(){
    char map[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};//空地圖
    char Player='O';//第一顆棋子為O  
    int Switch;//按下的數字鍵控制項
    
    show(map);//地圖顯示
    while(1){//遊戲無限迴圈
        cout<<"（按０退出，數字鍵比照九宮格）"<<endl;
        cin>>Switch;
        if(Switch==0) break;//如果輸入0，結束迴圈
        
        system("CLS");//清除畫面的系統字
        bool TFSet=TFset(Player, Switch, map);//判斷是否能夠放置棋子，並放進棋子
        show(map);//更新地圖顯示
    /*判斷是否有玩家獲勝*/
        if(winner(map)==true){//如果獲勝，輸出地圖與獲勝提示後結束迴圈
            cout<<Player<<" 贏了。\n";
            break;                    
        }
    /*判斷是否滿圖*/
        bool mapover=true;
        for(int i=0;i<3;i++)//搜尋全地圖
            for(int j=0;j<3;j++)
                if(map[i][j]==' ') mapover=false;//只要有一個是空的，地圖就不為滿  
                
        if(mapover==true){//如果滿圖，輸出滿圖提示後結束迴圈
            cout<<"滿圖，不分勝負。";
            break;
        }
    /*迴圈繼續，更替棋子*/
        if(TFSet==true){//如果方才放入棋子的選項有正常執行
            if(Player=='O') Player='X';//更替棋子
            else Player='O';            
        }
    }
}
