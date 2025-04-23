#include<bits/stdc++.h>  //看了b站比特鹏哥的c++教程，完整看完了三子棋，自行写一个扫雷  2025.4.22 
using namespace std;   // 在deepseek辅助下写的一个扫雷小游戏 ，用时一个下午写代码加第二天一个晚上修完bug ，游戏成功跑起来了，感觉成长了很多 
                      //而且当完全无bug成功跑起来的时候，是真的爽啊，感觉自己仿佛就是天才，我就是冠军！！！
//int hang,lie,x;    但是仍然总结了四点不足，自己目前还是个小弱鸡，暂无法突破，希望以后自己变得强大后再来改正 
#define hang 8    //1.想做个可变数组，以实现用户自定义扫雷行列数，实力有限，不太行日后努力
#define lie 8    //2.可以通过改变宏常量的值来改变扫雷的行列数，但是输出的介绍文字还是改不了，日后努力 
int x;          //3.开始写的时候 。幻想可以很规整，很有逻辑一目了然，但是最终写成了一团乱麻，层层嵌套，臃肿的一坨，难绷 。进步吧 
char y;         //4.想写一个递归但是溢出了，只得用笨办法调用函数， 导致无法实现真正的扫雷游戏的效果 
int h=1;       //5.还有一个问题，当遇到大于9的两位数字行列时，原先设置的输出格式就会不匹配，也是一个问题，如果要修改这个问题，我能想到的方式就 
char arr[hang][lie];//就是加if判断，如果大于9就另用一套输出格式，但是大于99呢，大于999呢，也全部另写一套格式?这也太臃肿了，不知道我以后 
int arr1[hang][lie]={0};//存储数字           还能不能想到更好的解决方式 
void b(){//数组初始化 
	 for(int i=0;i<hang;i++) {
	 	for(int j=0;j<lie;j++) {
		 arr[i][j]='*';
	 }
	 }
}

void pro(){//输出函数 
        cout<<"   ";
        for(int j=0;j<lie;j++) {
		cout<<j+1<<" ";}
		cout<<endl;
		for(int i=0;i<hang;i++){
			cout<<i+1<<" "<<" ";
		for(int j=0;j<lie;j++){
			if(arr[i][j]=='@') cout<<arr1[i][j]<<' ';
		    else{
			y=arr[i][j];
			if(y=='&') y='*';//输出时把雷隐藏 
			cout<<y<<" ";}
		}
		cout<<endl;
	}
}


void c(char arr[][lie],int han,int li,int x){
	srand(time(NULL));  // 这个生成随机数的种子和函数是deepseek提供的，除此之外都是自己写的 
	part2:for(int i=1;i<=x;i++){
		int rand1=rand()%han;
		int rand2=rand()%li;
		if(arr[rand1][rand2]=='&')  i--;
		else arr[rand1][rand2]='&';
	}
}

void cox(int p,int q){

	int o=0;   //看周围八个数有没雷 
	for(int i=p;i>=p-2;i--){
		for(int j=q;j>=q-2;j--){
			if(i>=0&&j>=0&&i<hang&&j<lie){
			
			if(arr[i][j]=='&') o++;}
		}
	}if(p-1>=0&&q-1>=0&&p-1<hang&&q-1<lie){
	
	arr1[p-1][q-1]=o;
	arr[p-1][q-1]='@';}
}
void cex(int p,int q){
	int o=0;   //看周围八个数有没雷 
	for(int i=p;i>=p-2;i--){
		for(int j=q;j>=q-2;j--){
			if(i>=0&&j>=0&&i<hang&&j<lie){
			if(arr[i][j]=='&') o++;}
		}
	}
	arr1[p-1][q-1]=o;
	arr[p-1][q-1]='@';
	
	if(p-1>=0||q-1>=0){
	
	 if(o==0){
		cox(p+1,q+1);//这里本来是想写一个递归，但是递归次数太多栈溢出会崩掉.....所以只能写了一个mini版cox函数，但是无法完全实现扫雷中 
		cox(p+1,q-1);//一下子就可以把没雷地方扫空的效果，还是差点意思 
		cox(p-1,q+1);
		cox(p-1,q-1);
		cox(p,q+1);
		cox(p,q-1);
		cox(p+1,q);
		cox(p-1,q);
	}}
		int ad=0;//校验是否赢了 
	
	for(int i=0;i<hang;i++){
		for(int j=0;j<lie;j++)
		if(arr[i][j]=='#'||arr[i][j]=='@')	ad++;
	}
	if(ad==64)  h=0;
}

void pin(){//判断输了没 
    int o=0;
	int p,q;
	do {
    cout << ",输入格式：先行后列，请输入坐标（1-8）：";
    cin >> p >> q;
    if(arr[p-1][q-1]=='@'){
    	cout<<"输重了，眼瞎就去治，重新给老子输"; 
	}
} while (p < 1 || p > hang || q < 1 || q > lie||arr[p-1][q-1]=='@ ');
	
	for(int i=0;i<hang;i++){
	 	for(int j=0;j<lie;j++){
	 		if(arr1[i][j]!=0) o++;
		 }
	 }
	
	if(arr[p-1][q-1]=='&') {
		arr[p-1][q-1]='#';
	 cout<<"你个蠢货，输了";
	 h=0;
	  cout<<endl;
	  cout<<"   ";
        for(int j=0;j<lie;j++) {
		cout<<j+1<<" ";}
		cout<<endl;
	 for(int i=0;i<hang;i++){
	 	cout<<i+1<<" "<<" ";
		for(int j=0;j<lie;j++){
			if(arr[i][j]=='@') cout<<arr1[i][j]<<' ';
		    else{
			y=arr[i][j];
			if(y=='&') y='#';//输出时把雷隐藏 
			cout<<y<<" ";}
		}
		cout<<endl;
	}
	 
	 }
/*	 else if(o+x==63) {
	 cout<<"牛逼你赢了" ;
	 h=0;
}
	 */
	 else{
	 cex(p,q);
	 cout<<endl;
	 int ad=0;//校验是否赢了 
	
	for(int i=0;i<hang;i++){
		for(int j=0;j<lie;j++)
		if(arr[i][j]=='&'||arr[i][j]=='@')	ad++;
	}
	if(ad==hang*lie){
	 h=0;
	 cout<<"牛逼你赢了"<<endl ;
	 cout<<"   ";
        for(int j=0;j<lie;j++) {
		cout<<j+1<<" ";}
		cout<<endl;
	 for(int i=0;i<hang;i++){
	 	cout<<i+1<<" "<<" ";
		for(int j=0;j<lie;j++){
			if(arr[i][j]=='@') cout<<arr1[i][j]<<' ';
		    else{
			y=arr[i][j];
			if(y=='&') y='#';//输出时把雷隐藏 
			cout<<y<<" ";}
		}
		cout<<endl;
	}	 }
	if(h!=0) pro();}
}

void a(){ 
//	part:cout<<"你想玩几行几列的扫雷";
//	cin>>hang>>lie;
	cout<<"小同志，8x8的扫雷阵，你想埋几个雷？"<<endl;
	 part:cin>>x;
	 if(x>64||x==0) {
	 cout<<"你tm看你输了个什么玩意？雷放的下吗？给老子重输傻狗"<<endl;
	 goto part;}
	
	c(arr,hang,lie,x);   //在阵中生成随机雷点 
	pro();//第一次输出
	while(h){
	
	cout<<"请选择你要点击的位置"; 
	pin();//输入 并且判断输赢 
	
}
}


int main(){
	int n;
	b();
	//游戏开始
	cout<<"----扫雷游戏----"<<endl;
	cout<<"-----0.结束-----"<<endl;
	cout<<"-----1.开始-----"<<endl;
	cout<<"----------------"<<endl;
	cout<<"赶紧给老子选择；";
	do{
	cin>>n;
	
	if(n==1){
		cout<<"游戏开始"<<endl<<"*为空白格子，#为雷点"<<endl;
		a();//游戏内容 
		break;
	}
	else if(n==0){
		cout<<"不想玩就滚"<<endl;
	}
	else cout<<"傻逼吧，看不懂规则?重新输入"<<endl;

}	while(n);
    cout<<"游戏结束";

	return 0; 
}
