#include"compiler.h"
#include"builtin_class.h"
string flag="Balsn{U_r_C0Mp1LeR_h4cKer}";
//string flag="Balsn{}";
Begin
    #include"builtin_lib.h"
    Output::Init();
    Math::Init();
    Array::Init();
    Output::Clean();
    Input::Clean();
    Var p,p2,trig;
    p=Array::Alloc(50);
    String::Set(p,"Input the FLAG(Use ESC for capslock):\n");
    Output::PrintString(p);
    p2=p;
    trig=0;
    Var caps,tmp;
    caps=0;
    Loop
        Input::Update();
        Var key;
        key=Input::Key();
        If(key,==,0)
            If(trig,==,1)
                trig=0;
            End
        End
        If(key,!=,0)
            If(trig,==,0)
                If(key,==,128)
                    Output::PrintChar(key);
                    Break
                End
                If(key,==,'\n')
                    Output::PrintChar(key);
                    Break
                End
                trig=1;
                If(key,==,140)
                    tmp=1;
                    tmp-=caps;
                    caps=tmp;
                End
                If(key,!=,140)
                    If(caps,==,1)
                        tmp=key;
                        If(key,>=,'A')
                            If(key,<=,'Z')
                                tmp+=32;
                            End
                        End
                        If(key,>=,'a')
                            If(key,<=,'z')
                                tmp-=32;
                            End
                        End
                        If(key,==,'[')
                            tmp='{';
                        End
                        If(key,==,']')
                            tmp='}';
                        End
                        If(key,==,'1')
                            tmp='!';
                        End
                        If(key,==,'2')
                            tmp='@';
                        End
                        If(key,==,'3')
                            tmp='#';
                        End
                        If(key,==,'4')
                            tmp='$';
                        End
                        If(key,==,'5')
                            tmp='%';
                        End
                        If(key,==,'6')
                            tmp='^';
                        End
                        If(key,==,'7')
                            tmp='&';
                        End
                        If(key,==,'8')
                            tmp='*';
                        End
                        If(key,==,'9')
                            tmp='(';
                        End
                        If(key,==,'0')
                            tmp=')';
                        End
                        If(key,==,'-')
                            tmp='_';
                        End
                        If(key,==,'=')
                            tmp='+';
                        End
                        key=tmp;
                    End
                    If(key,==,129)
                        If(p2,>,p)
                            Global["Output_cursor_x"]-=8;
                            Output::PrintChar(' ');
                            Global["Output_cursor_x"]-=8;
                            p2--;
                        End
                    End
                    If(key,!=,129)
                        Output::PrintChar(key);
                        mem[p2]=key;
                        p2++;
                    End
                End
            End
        End
        Input::Clean();
    End
    Var ans;
    ans=1;
    Var len;
    len=p2;
    len-=p;
    const int flag_length=flag.length();
    If(len,!=,flag_length)
        ans=0;
    End
    vector<int>poss[6];
    for(int j=0;j<6;j++){
        auto &pos=poss[j];
        for(int i=0;i<flag_length;i++)
            pos.push_back(i);
        for(int i=0;i<flag_length;i++)
            pos.push_back(i);
        for(int i=0;i<flag_length;i++)
            pos.push_back(i);
        random_shuffle(pos.begin(),pos.end());
    }
    for(int i=0;i<flag_length*3;i++){
        Loop
            int arl=rand()%2+3;
            int ar[arl],val;
            for(int j=0;j<arl;j++)
                ar[j]=poss[j][i];
            val=rand()%1000-500;
            int sum=val;
            Var sig;
            sig=val;
            for(int j=0;j<arl;j++){
                Var x,y;
                x=p;
                x+=ar[j];
                y=mem[x];
                sig+=y;
                sum+=flag[ar[j]];
            }
            If(sig,!=,sum)
                ans=0;
            End
        Break
        End
    }
    Var result;
    result=Array::Alloc(10);
    If(ans,==,1)
        String::Set(result,"Success!");
    End
    If(ans,==,0)
        String::Set(result,"Fail!");
    End
    Output::PrintString(result);
Finish
