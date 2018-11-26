// checkersGame

#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
class checkers;
void board(checkers c[5][5]);
void spaces();
void spaces2(checkers c[5][5] , int val);
void line();
void assigning(checkers c[5][5]);
void swapping(int cord1,int cord2,int dest1,int dest2,checkers c[5][5]);
void error2();
void error1();

class checkers
{
private:
    string pawn;
    int state;
public:
    void assignblack()
    {
        pawn=" *BLACK*  ";
        state=2;
    }
    void assignred()
    {
        pawn="   =RED=  ";
        state=1;
    }
    void assignspace()
    {
        pawn="          ";
        state=0;
    }
    string getpawn()
    {
        return pawn;
    }
    int getstate()
    {
        return state;
    }

};


int main()
{
    int reds=10,blacks=10,turn,cord1,cord2,dest1,dest2;
    checkers c[5][5];
    cout<<"                      ==================="<<endl;
    cout<<"                      =  Checkers Game  ="<<endl;
    cout<<"                      ==================="<<endl<<endl;
    assigning(c);
    board(c);
    cout<<"\n 1st Player plays for =RED= pawns 2nd Player plays for *Black* pawns"<<endl;
    cout<<"                   -----------------------------"<<endl<<endl;
    for(;;)
    {
        if(reds==0 || blacks ==0)
        {
            cout<<" ^^^^^^^^^^^^^^^^^^^^^^"<<endl;
            cout<<" Player "<<turn<<" Wins Congrats "<<endl;
            cout<<" ^^^^^^^^^^^^^^^^^^^^^^"<<endl<<endl;
            break;
        }
        else
        {
            for(int i=1;i<=2;i++)
            {
                                                                                                  //Reds Turn and its conditions
                            turn=1;
                            cout<<" ^^ Players "<<turn<<" turns ^^"<<endl;
                            cout<<" Enter the coordinates of the pawn you want to move (row,column) : ";cin>>cord1>>cord2;
                            cout<<" Enter the coordinates of the destination of the place where you want to move the pawn (row,column) : ";cin>>dest1>>dest2;
                            if(cord1>4 || cord2>4 || dest1>4 || dest2>4)
                            {
                                if(i==1)
                                    error1();
                                else
                                    error2();
                            }
                            else
                            {
                                        if(c[cord1][cord2].getstate()==turn && c[dest1][dest2].getstate()==0)
                                        {
                                                    if((dest1==cord1+1 || dest1==cord1-1 || dest1==cord1)&&(dest2==cord2+1 || dest2==cord2-1 || dest2==cord2))
                                                    {
                                                        swapping(cord1,cord2,dest1,dest2,c);
                                                        board(c);
                                                        break;
                                                    }
                                                    else if(dest1==cord1-2)
                                                    {
                                                                if(dest2==cord2+2)
                                                                {
                                                                    if(c[cord1-1][cord2+1].getstate()==2)
                                                                    {
                                                                        c[cord1-1][cord2+1].assignspace();
                                                                        blacks--;
                                                                        swapping(cord1,cord2,dest1,dest2,c);
                                                                        board(c);
                                                                        break;
                                                                    }
                                                                    else
                                                                    {
                                                                        if(i==1)
                                                                            error1();
                                                                        else
                                                                            error2();
                                                                    }
                                                                }
                                                                else if(dest2==cord2)
                                                                {
                                                                    if(c[cord1-1][cord2].getstate()==2)
                                                                    {
                                                                        c[cord1-1][cord2].assignspace();
                                                                        blacks--;
                                                                        swapping(cord1,cord2,dest1,dest2,c);
                                                                        board(c);
                                                                        break;
                                                                    }
                                                                    else
                                                                    {
                                                                        if(i==1)
                                                                            error1();
                                                                        else
                                                                            error2();
                                                                    }
                                                                }
                                                                else if(dest2==cord2-2)
                                                                {
                                                                    if(c[cord1-1][cord2-1].getstate()==2)
                                                                    {
                                                                        c[cord1-1][cord2-1].assignspace();
                                                                        blacks--;
                                                                        swapping(cord1,cord2,dest1,dest2,c);
                                                                        board(c);
                                                                        break;
                                                                    }
                                                                    else
                                                                    {
                                                                        if(i==1)
                                                                            error1();
                                                                        else
                                                                            error2();
                                                                    }
                                                                }
                                                                else
                                                                {
                                                                    if(i==1)
                                                                        error1();
                                                                    else
                                                                        error2();
                                                                }
                                                    }
                                                    else if(dest1==cord1)
                                                    {
                                                                if(dest2==cord2+2)
                                                                {
                                                                    if(c[cord1][cord2+1].getstate()==2)
                                                                    {
                                                                        c[cord1][cord2+1].assignspace();
                                                                        blacks--;
                                                                        swapping(cord1,cord2,dest1,dest2,c);
                                                                        board(c);
                                                                        break;
                                                                    }
                                                                    else
                                                                    {
                                                                        if(i==1)
                                                                            error1();
                                                                        else
                                                                            error2();
                                                                    }
                                                                }
                                                                else if(dest2==cord2-2)
                                                                {
                                                                    if(c[cord1][cord2-1].getstate()==2)
                                                                    {
                                                                        c[cord1][cord2-1].assignspace();
                                                                        blacks--;
                                                                        swapping(cord1,cord2,dest1,dest2,c);
                                                                        board(c);
                                                                        break;
                                                                    }
                                                                    else
                                                                    {
                                                                        if(i==1)
                                                                            error1();
                                                                        else
                                                                            error2();
                                                                    }
                                                                }
                                                                else
                                                                {
                                                                    if(i==1)
                                                                        error1();
                                                                    else
                                                                        error2();
                                                                }
                                                    }
                                                    else if(dest1==cord1+2)
                                                    {
                                                                if(dest2==cord2+2)
                                                                {
                                                                    if(c[cord1+1][cord2+1].getstate()==2)
                                                                    {
                                                                        c[cord1+1][cord2+1].assignspace();
                                                                        blacks--;
                                                                        swapping(cord1,cord2,dest1,dest2,c);
                                                                        board(c);
                                                                        break;
                                                                    }
                                                                    else
                                                                    {
                                                                        if(i==1)
                                                                            error1();
                                                                        else
                                                                            error2();
                                                                    }
                                                                }
                                                                else if(dest2==cord2)
                                                                {
                                                                    if(c[cord1+1][cord2].getstate()==2)
                                                                    {
                                                                        c[cord1+1][cord2].assignspace();
                                                                        blacks--;
                                                                        swapping(cord1,cord2,dest1,dest2,c);
                                                                        board(c);
                                                                        break;
                                                                    }
                                                                    else
                                                                    {
                                                                        if(i==1)
                                                                            error1();
                                                                        else
                                                                            error2();
                                                                    }
                                                                }
                                                                else if(dest2==cord2-2)
                                                                {
                                                                    if(c[cord1+1][cord2-1].getstate()==2)
                                                                    {
                                                                        c[cord1+1][cord2-1].assignspace();
                                                                        blacks--;
                                                                        swapping(cord1,cord2,dest1,dest2,c);
                                                                        board(c);
                                                                        break;
                                                                    }
                                                                    else
                                                                    {
                                                                        if(i==1)
                                                                            error1();
                                                                        else
                                                                            error2();
                                                                    }
                                                                }
                                                                else
                                                                {
                                                                    if(i==1)
                                                                        error1();
                                                                    else
                                                                        error2();
                                                                }
                                                    }
                                                    else
                                                    {
                                                        if(i==1)
                                                            error1();
                                                        else
                                                            error2();
                                                    }
                                        }
                                        else
                                        {
                                            if(i==1)
                                                error1();
                                            else
                                                error2();
                                        }
                            }
            }
        }

        if(reds==0 || blacks ==0)
        {
            cout<<" ^^^^^^^^^^^^^^^^^^^^^^"<<endl;
            cout<<" Player "<<turn<<" Wins Congrats "<<endl;
            cout<<" ^^^^^^^^^^^^^^^^^^^^^^"<<endl<<endl;
            break;
        }
        else
        {
            for(int i=1;i<=2;i++)
            {
                                                                                                  //Blacks Turn and its conditions
                            turn=2;
                            cout<<" ^^ Players "<<turn<<" turns ^^"<<endl;
                            cout<<" Enter the coordinates of the pawn you want to move (row,column) : ";cin>>cord1>>cord2;
                            cout<<" Enter the coordinates of the destination of the place where you want to move the pawn (row,column) : ";cin>>dest1>>dest2;
                            if(cord1>4 || cord2>4 || dest1>4 || dest2>4)
                            {
                                if(i==1)
                                    error1();
                                else
                                    error2();
                            }
                            else
                            {
                                        if(c[cord1][cord2].getstate()==turn && c[dest1][dest2].getstate()==0)
                                        {
                                                    if((dest1==cord1+1 || dest1==cord1-1 || dest1==cord1)&&(dest2==cord2+1 || dest2==cord2-1 || dest2==cord2))
                                                    {
                                                        swapping(cord1,cord2,dest1,dest2,c);
                                                        board(c);
                                                        break;
                                                    }
                                                    else if(dest1==cord1-2)
                                                    {
                                                                if(dest2==cord2+2)
                                                                {
                                                                    if(c[cord1-1][cord2+1].getstate()==1)
                                                                    {
                                                                        c[cord1-1][cord2+1].assignspace();
                                                                        reds--;
                                                                        swapping(cord1,cord2,dest1,dest2,c);
                                                                        board(c);
                                                                        break;
                                                                    }
                                                                    else
                                                                    {
                                                                        if(i==1)
                                                                            error1();
                                                                        else
                                                                            error2();
                                                                    }
                                                                }
                                                                else if(dest2==cord2)
                                                                {
                                                                    if(c[cord1-1][cord2].getstate()==1)
                                                                    {
                                                                        c[cord1-1][cord2].assignspace();
                                                                        reds--;
                                                                        swapping(cord1,cord2,dest1,dest2,c);
                                                                        board(c);
                                                                        break;
                                                                    }
                                                                    else
                                                                    {
                                                                        if(i==1)
                                                                            error1();
                                                                        else
                                                                            error2();
                                                                    }
                                                                }
                                                                else if(dest2==cord2-2)
                                                                {
                                                                    if(c[cord1-1][cord2-1].getstate()==1)
                                                                    {
                                                                        c[cord1-1][cord2-1].assignspace();
                                                                        reds--;
                                                                        swapping(cord1,cord2,dest1,dest2,c);
                                                                        board(c);
                                                                        break;
                                                                    }
                                                                    else
                                                                    {
                                                                        if(i==1)
                                                                            error1();
                                                                        else
                                                                            error2();
                                                                    }
                                                                }
                                                                else
                                                                {
                                                                    if(i==1)
                                                                        error1();
                                                                    else
                                                                        error2();
                                                                }
                                                    }
                                                    else if(dest1==cord1)
                                                    {
                                                                if(dest2==cord2+2)
                                                                {
                                                                    if(c[cord1][cord2+1].getstate()==1)
                                                                    {
                                                                        c[cord1][cord2+1].assignspace();
                                                                        reds--;
                                                                        swapping(cord1,cord2,dest1,dest2,c);
                                                                        board(c);
                                                                        break;
                                                                    }
                                                                    else
                                                                    {
                                                                        if(i==1)
                                                                            error1();
                                                                        else
                                                                            error2();
                                                                    }
                                                                }
                                                                else if(dest2==cord2-2)
                                                                {
                                                                    if(c[cord1][cord2-1].getstate()==1)
                                                                    {
                                                                        c[cord1][cord2-1].assignspace();
                                                                        reds--;
                                                                        swapping(cord1,cord2,dest1,dest2,c);
                                                                        board(c);
                                                                        break;
                                                                    }
                                                                    else
                                                                    {
                                                                        if(i==1)
                                                                            error1();
                                                                        else
                                                                            error2();
                                                                    }
                                                                }
                                                                else
                                                                {
                                                                    if(i==1)
                                                                        error1();
                                                                    else
                                                                        error2();
                                                                }
                                                    }
                                                    else if(dest1==cord1+2)
                                                    {
                                                                if(dest2==cord2+2)
                                                                {
                                                                    if(c[cord1+1][cord2+1].getstate()==1)
                                                                    {
                                                                        c[cord1+1][cord2+1].assignspace();
                                                                        reds--;
                                                                        swapping(cord1,cord2,dest1,dest2,c);
                                                                        board(c);
                                                                        break;
                                                                    }
                                                                    else
                                                                    {
                                                                        if(i==1)
                                                                            error1();
                                                                        else
                                                                            error2();
                                                                    }
                                                                }
                                                                else if(dest2==cord2)
                                                                {
                                                                    if(c[cord1+1][cord2].getstate()==1)
                                                                    {
                                                                        c[cord1+1][cord2].assignspace();
                                                                        reds--;
                                                                        swapping(cord1,cord2,dest1,dest2,c);
                                                                        board(c);
                                                                        break;
                                                                    }
                                                                    else
                                                                    {
                                                                        if(i==1)
                                                                            error1();
                                                                        else
                                                                            error2();
                                                                    }
                                                                }
                                                                else if(dest2==cord2-2)
                                                                {
                                                                    if(c[cord1+1][cord2-1].getstate()==1)
                                                                    {
                                                                        c[cord1+1][cord2-1].assignspace();
                                                                        reds--;
                                                                        swapping(cord1,cord2,dest1,dest2,c);
                                                                        board(c);
                                                                        break;
                                                                    }
                                                                    else
                                                                    {
                                                                        if(i==1)
                                                                            error1();
                                                                        else
                                                                            error2();
                                                                    }
                                                                }
                                                                else
                                                                {
                                                                    if(i==1)
                                                                        error1();
                                                                    else
                                                                        error2();
                                                                }
                                                    }
                                                    else
                                                    {
                                                        if(i==1)
                                                            error1();
                                                        else
                                                            error2();
                                                    }
                                        }
                                        else
                                        {
                                            if(i==1)
                                                error1();
                                            else
                                                error2();
                                        }
                            }
            }



        }

    }
    return 0;
}
                                                                                       // printing whole board
void board(checkers c[5][5])
{

    for(int i=0;i<5;i++)
    {
        cout<<"         "<<i<<"  ";
    }
    cout<<endl;
    for(int loop=0;loop<5;loop++)
    {
        line();
        spaces();
        spaces2(c,loop);
        spaces();
        line();
    }
}
void line()
{
    cout<<"    ";
    for(int i=0;i<60;i++)
    {
        cout<<"-";
    }
    cout<<endl;
}
void spaces()
{
    for(int i=0;i<2;i++)
    {
        cout<<"    ";
        for(int j=0;j<5;j++)
        {
            cout<<"|";
            for(int k=0;k<10;k++)
            {
                cout<<" ";
            }
            cout<<"|";
        }
        cout<<endl;
    }
}
void spaces2(checkers c[5][5] , int val)
{
                                                                               //printing the string of the class
    cout<<" "<<val<<"  ";
    for(int i=0;i<5;i++)
    {
        cout<<"|";
        cout<<c[val][i].getpawn();
        cout<<"|";
    }
    cout<<endl;
}
                                                                              //assigning values
void assigning(checkers c[5][5])
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(i<2)
                c[i][j].assignblack();
            else if(i<3)
                c[i][j].assignspace();
            else
                c[i][j].assignred();
        }
    }
}
                                                                                 //swapping
void swapping(int cord1,int cord2,int dest1,int dest2,checkers c[5][5])
{
    swap(c[cord1][cord2],c[dest1][dest2]);
    system("clear");
}
                                                                                   //errors
void error1()
{
    cout<<"\n ** [You entered WRONG PAWN COORDINATES OR DESTINATION your have 1 more try] **"<<endl<<endl;
}
void error2()
{
    cout<<"\n ** [You entered WRONG PAWN COORDINATES OR DESTINATION your turn is lost] **"<<endl<<endl;
}