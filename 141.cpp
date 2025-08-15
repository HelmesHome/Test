#include "141.h"

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

const int MAX_LINES = 5;         
const int MAX_LINE_LENGTH = 100;

// Task 0: Read input file
int checkrange_LF (int &LF1,int &LF2){
  if(LF1<0){
   LF1=0;
  }
  if(LF2<0){
   LF2=0;
  }
    return 0;
 }
int checkrange_EXP(int &EXP1, int &EXP2){
  if(EXP1>600){
   EXP1=600;
  }
  if(EXP1<0){
   EXP1=0;
  }
  if(EXP2>600){
   EXP2=600;   
  }
  if(EXP2<0){
   EXP2=0;
  }
  return 0;
}
int checkrange_E(int &E){
 if(E>100){
    E=100;
 }
 if(E<0){
    E=0;
 }
 return 0;
}
int checkrange_T(int &T1, int &T2){
  if(T1>3000){
      T1=3000;
   }
   if(T1<0){
      T1=0;
   }
   if(T2>3000){
      T2=3000;
   }
   if(T2<0){
      T2=0;
   }
   return 0;
}
bool readFile(
    const string &filename,
    int LF1[], int LF2[],
    int &EXP1, int &EXP2,
    int &T1, int &T2, int &E)
{
  char data[MAX_LINES][MAX_LINE_LENGTH];
  int numLines = 0;

  ifstream ifs(filename);
  if (!ifs.is_open())
  {
    return false;
  }

  while (numLines < MAX_LINES && ifs.getline(data[numLines], MAX_LINE_LENGTH))
  {
    numLines++;
  }
  ifs.close();

  if (numLines < MAX_LINES)
  {
    return false;
  }

  // TODO: Extract values from the `data` array and store them in respective variables
  string Subtract=data[0];
  string LF="";
  for(int i=1; i<Subtract.size()-1;i++){
     LF+=Subtract[i];
  }
  istringstream ss0(LF);
  string LF11;
  int count=0;
  while(getline(ss0,LF11,',')){
     LF1[count]=stoi(LF11);      
     count++;
  }
  

  Subtract=data[1];
  count=0;
  LF="";
  LF11="";
  for(int i=1; i<Subtract.size()-1;i++){
    LF+=Subtract[i];
 }
  istringstream ss1(LF);
  while(getline(ss1,LF11,',')){
    LF2[count]=stoi(LF11);      
    count++;
 }
 for(int i=0;i<17;i++){
  if(LF1[i]<0){ 
   LF1[i]=0;
  }  
  if(LF1[i]>1000){  
   LF1[i]=1000;
  }
  if(LF2[i]<0){
   LF2[i]=0; 
  }
   if(LF2[i]>1000){
   LF2[i]=1000;
  }
} 

  Subtract=data[2];
  istringstream ss2(Subtract);
  int EXP[2];
  LF11="";
  count=0;
  while(getline(ss2,LF11,' ')){
    EXP[count]=stoi(LF11);
    count++;
  }
  EXP1=EXP[0];
  EXP2=EXP[1];
  checkrange_EXP(EXP1,EXP2);

  Subtract=data[3];
  istringstream ss3(Subtract);
  LF11="";
  count=0;
  int T[2];
  count=0;
  while(getline(ss3,LF11,' ')){
    T[count]=stoi(LF11);
    count++;
  }
  T1=T[0];
  T2=T[1];
  checkrange_T(T1,T2);
  
  Subtract=data[4];
  istringstream ss4(Subtract);
  ss4>>E;
  checkrange_E(E);
return true;
}

// Task 1
int gatherForces(int LF1[], int LF2[])
{
  const int trong_so[]={1,2,3,4,5,7,8,9,10,
  12,15,18,20,30,40,50,70};
  
for(int i=0;i<17;i++){
   if(LF1[i]<0){ 
    LF1[i]=0;
   }  
   if(LF1[i]>1000){  
    LF1[i]=1000;
   }
   if(LF2[i]<0){
    LF2[i]=0; 
   }
    if(LF2[i]>1000){
    LF2[i]=1000;
   }
}  
int tong_LF1=0;
int tong_LF2=0;
for(int i=0;i<17;i++){
 tong_LF1+=LF1[i]*trong_so[i];
 tong_LF2+=LF2[i]*trong_so[i];
}
checkrange_LF(tong_LF1,tong_LF2);

return tong_LF1+tong_LF2; 
}

// Task 2
bool checknumber(string c){
  if(c.size()>0){   
    return true;
  } 
  return false;
}

void ID_target(int e,string &s){
  switch(e){
    case 0:s="DECOY";break;
    case 1:s="DECOY";break;
    case 2:s="DECOY";break;
    case 3:s="Buon Ma Thuot"; break;
    case 4:s="Duc Lap"; break;
    case 5:s="Dak Lak"; break;
    case 6: s="National Route 21"; break;
    case 7: s="National Route 14"; break;
  }
}
int tim_max(int a, int b, int c){
int max;
if(a>b) max=a; 
else max=b;
if(max>c) max=max;
else max=c;
return max;
} 
void danhsach(string &s){
    string a="KON TUM";
    string b="PLEIKU";
    string c="GIA LAI"; 
    string d="BUON MA THUOT";       
    string e="DUC LAP";     
    string f="DAK LAK";       
    string g="NATIONAL ROUTE 21";        
    string h="NATIONAL ROUTE 14";   
    if(s==a){
        s="Kon Tum";     
    
    }
    else if(s==b){
        s="Pleiku";   

    }
    else if(s==c){
        s="Gia Lai";    
    }
    else if(s==d){
        s="Buon Ma Thuot";
    }
    else if(s==e){
        s="Duc Lap";       
    }
    else if(s==f){
        s="Dak Lak";     
    }
    else if(s==g){
        s="National Route 21";    
    }
    else if(s==h){
        s="National Route 14";     
    }   
    else{
        s="INVALID";
    }
  }
  string reverse(string s){
    string r="";
    int n=s.size();
    for(int i=s.size()-1; i>=0;i--){
        r+=s[i];

    }
    return r;
  }
string determineRightTarget(const string &target)
{
  string b="";
int num=0,dem=0;
int so[10];
int ID;
char a1[target.size()];

for(int i=0;i<target.size();i++){
 a1[i]=target[i];  
}

for(int i=0;i<target.size();i++){
    if(isdigit(a1[i])) 
    b+=target[i];
    else{
        if(checknumber(b)){
         for(char b1:b){
            num=num*10+(b1-'0');
         }
            if(num<0||num>100){
                num=0;
            }
            else{
                so[dem]=num;
                dem++;
                num=0;
            }   
         b="";     
    }
 }

}
if(checknumber(b)){
    for(char b1:b){
       num=num*10+(b1-'0');
    }
       if(num<0||num>100){
           num=0;
       }
       else{
           so[dem]=num;
           dem++;
           num=0;
       }
 }  
 
if(dem==1){ 
    
    if(so[0]>=0&&so[0]<=7){
        ID_target(so[0],b);
    }
    else {
        return b="INVALID";
    }    
}
else if(dem==2){
    ID=(so[0]+so[1])%5+3;
    ID_target(ID,b);
}
else if(dem==3){
    ID=tim_max(so[0],so[1],so[2])%5;
    ID+=3;
    ID_target(ID,b);

}
else b="INVALID";

  return b;
}

string decodeTarget(const string &message, int EXP1, int EXP2)
{
  string a1="";
  if(EXP1>=300&&EXP2>=300){

    checkrange_EXP(EXP1,EXP2);
    int shift=(EXP1+EXP2)%26;
    char b;

    for(int i=0;i<message.size();i++){
        if(!isalpha(message[i])) {
            a1+=message[i];
            continue;
        }
        else{
         if(isupper(message[i])){
                b='A';
            }
         else{
                b='a';
            }
            a1+=(message[i]-b+shift)%26+b;
        
         if(!isalpha(a1[i])){
            a1+=message[i];
            }
        }
      
    }
    
        for(int i=0;i<a1.size();i++){       
        a1[i]=toupper(a1[i]);               
        }
        danhsach(a1);
        for(int i=0; i<message.size();i++){
         if(isalpha(message[i]==0||isdigit(message[i])==0)){
            if (message[i]==' '){
                continue;
            }
            else{
                a1="INVALID";
            }
          }
        }
    
  }
  else{
    if(EXP1<300||EXP2<300){
    string r="";
    r=reverse(message);
    for(int i=0;i<r.size();i++){
         r[i]=toupper(r[i]);
 }
    a1=r;
    danhsach(a1);
    }
 }  
   return a1;
}

// Task 3
void manageLogistics(int LF1, int LF2, int EXP1, int EXP2, int &T1, int &T2, int E)
{
  double delT1,delT2,T11,T21,LF11,LF21,EXP11,EXP21;
  checkrange_LF(LF1,LF2);
  checkrange_E(E);
  checkrange_EXP(EXP1,EXP2);
  checkrange_T(T1,T2);
  T11=T1;
  T21=T2;
  EXP11=EXP1;
  EXP21=EXP2;
  LF11=LF1;
  LF21=LF2;
 if(E==0){
  delT1 =((LF11/(LF11+LF21))*(T11+T21))*(1+ (EXP11-EXP21)/100.0);
  delT2 =(T11+T21)-delT1;
  T11+=delT1;      
  T21+=delT2;
  }
 else if(E<=9){
  T11-=T11*(E*0.01);
  T21-=T21*(E*0.005);
  }
  else if(E<=29){
     T11+=E*50;
     T21+=E*50;
  }
  else if(E<=59){
     T11+=T11*(E*0.005);
     T21+=T21*(E*0.002);
  }
  else {
     if(E<=99)
     T11=T11;
     T21=T21;
  }
 T1=ceil(T11);
 T2=ceil(T21);
 checkrange_T(T1,T2);
                     
 }

// Task 4
int planAttack(int LF1, int LF2, int EXP1, int EXP2, int T1, int T2, int battleField[10][10])
{
  double S;
  checkrange_LF(LF1,LF2);
  checkrange_T(T1,T2);
  checkrange_EXP(EXP1,EXP2);
  S=(LF1+LF2)+(EXP1+EXP2)*5+(T1+T2)*2;
  double battle[10][10];
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      battle[i][j]=battleField[i][j];
    }
  }
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      if((i%2)==1){
        S-=(battle[i][j]*3/2);
      }
      else {
        S-=(battle[i][j]*2/3);
      }
    }
  }
  S=ceil(S-1e-10);
  return S;
}

// Task 5
int resupply(int shortfall, int supply[5][5])
{
  int newsupply[25];
  int minf=INT_MAX;
  int count=0;
  int sum;
  int find;
  for(int i=0; i<5; i++){
   for(int j=0; j<5; j++){
    newsupply[count]=supply[i][j];
    count++;
   } 
  }
for(int i=0;i<25;i++){
   find=i;
   for(int j=i+1;j<25;j++){
      if(newsupply[j]<newsupply[find]){
         find=j;
      }
   }
   swap(newsupply[find],newsupply[i]);
}
 
    for(int i=0; i<21;i++){
       for(int j=i+1;j<22;j++){
          for(int k=j+1;k<23;k++){
             for(int l=k+1;l<24;l++){
                for(int m=l+1; m<25;m++){
                   sum = newsupply[i]+newsupply[j]+newsupply[k]+newsupply[l]+newsupply[m];
                   if(sum>=shortfall && sum<minf){
                      minf=sum;
                   }
                }
             }
          }
       }
    }
 return minf;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
