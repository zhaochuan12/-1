#include<bits/stdc++.h>  //����bվ���������c++�̳̣����������������壬����дһ��ɨ��  2025.4.22 
using namespace std;   // ��deepseek������д��һ��ɨ��С��Ϸ ����ʱһ������д����ӵڶ���һ����������bug ����Ϸ�ɹ��������ˣ��о��ɳ��˺ܶ� 
                      //���ҵ���ȫ��bug�ɹ���������ʱ�������ˬ�����о��Լ��·������ţ��Ҿ��ǹھ�������
//int hang,lie,x;    ������Ȼ�ܽ����ĵ㲻�㣬�Լ�Ŀǰ���Ǹ�С���������޷�ͻ�ƣ�ϣ���Ժ��Լ����ǿ����������� 
#define hang 8    //1.�������ɱ����飬��ʵ���û��Զ���ɨ����������ʵ�����ޣ���̫���պ�Ŭ��
#define lie 8    //2.����ͨ���ı�곣����ֵ���ı�ɨ�׵�����������������Ľ������ֻ��ǸĲ��ˣ��պ�Ŭ�� 
int x;          //3.��ʼд��ʱ�� ��������Ժܹ����������߼�һĿ��Ȼ����������д����һ�����飬���Ƕ�ף�ӷ�׵�һ�磬�ѱ� �������� 
char y;         //4.��дһ���ݹ鵫������ˣ�ֻ���ñ��취���ú����� �����޷�ʵ��������ɨ����Ϸ��Ч�� 
int h=1;       //5.����һ�����⣬����������9����λ��������ʱ��ԭ�����õ������ʽ�ͻ᲻ƥ�䣬Ҳ��һ�����⣬���Ҫ�޸�������⣬�����뵽�ķ�ʽ�� 
char arr[hang][lie];//���Ǽ�if�жϣ��������9������һ�������ʽ�����Ǵ���99�أ�����999�أ�Ҳȫ����дһ�׸�ʽ?��Ҳ̫ӷ���ˣ���֪�����Ժ� 
int arr1[hang][lie]={0};//�洢����           ���ܲ����뵽���õĽ����ʽ 
void b(){//�����ʼ�� 
	 for(int i=0;i<hang;i++) {
	 	for(int j=0;j<lie;j++) {
		 arr[i][j]='*';
	 }
	 }
}

void pro(){//������� 
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
			if(y=='&') y='*';//���ʱ�������� 
			cout<<y<<" ";}
		}
		cout<<endl;
	}
}


void c(char arr[][lie],int han,int li,int x){
	srand(time(NULL));  // �����������������Ӻͺ�����deepseek�ṩ�ģ�����֮�ⶼ���Լ�д�� 
	part2:for(int i=1;i<=x;i++){
		int rand1=rand()%han;
		int rand2=rand()%li;
		if(arr[rand1][rand2]=='&')  i--;
		else arr[rand1][rand2]='&';
	}
}

void cox(int p,int q){

	int o=0;   //����Χ�˸�����û�� 
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
	int o=0;   //����Χ�˸�����û�� 
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
		cox(p+1,q+1);//���ﱾ������дһ���ݹ飬���ǵݹ����̫��ջ��������.....����ֻ��д��һ��mini��cox�����������޷���ȫʵ��ɨ���� 
		cox(p+1,q-1);//һ���ӾͿ��԰�û�׵ط�ɨ�յ�Ч�������ǲ����˼ 
		cox(p-1,q+1);
		cox(p-1,q-1);
		cox(p,q+1);
		cox(p,q-1);
		cox(p+1,q);
		cox(p-1,q);
	}}
		int ad=0;//У���Ƿ�Ӯ�� 
	
	for(int i=0;i<hang;i++){
		for(int j=0;j<lie;j++)
		if(arr[i][j]=='#'||arr[i][j]=='@')	ad++;
	}
	if(ad==64)  h=0;
}

void pin(){//�ж�����û 
    int o=0;
	int p,q;
	do {
    cout << ",�����ʽ�����к��У����������꣨1-8����";
    cin >> p >> q;
    if(arr[p-1][q-1]=='@'){
    	cout<<"�����ˣ���Ϲ��ȥ�Σ����¸�������"; 
	}
} while (p < 1 || p > hang || q < 1 || q > lie||arr[p-1][q-1]=='@ ');
	
	for(int i=0;i<hang;i++){
	 	for(int j=0;j<lie;j++){
	 		if(arr1[i][j]!=0) o++;
		 }
	 }
	
	if(arr[p-1][q-1]=='&') {
		arr[p-1][q-1]='#';
	 cout<<"�������������";
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
			if(y=='&') y='#';//���ʱ�������� 
			cout<<y<<" ";}
		}
		cout<<endl;
	}
	 
	 }
/*	 else if(o+x==63) {
	 cout<<"ţ����Ӯ��" ;
	 h=0;
}
	 */
	 else{
	 cex(p,q);
	 cout<<endl;
	 int ad=0;//У���Ƿ�Ӯ�� 
	
	for(int i=0;i<hang;i++){
		for(int j=0;j<lie;j++)
		if(arr[i][j]=='&'||arr[i][j]=='@')	ad++;
	}
	if(ad==hang*lie){
	 h=0;
	 cout<<"ţ����Ӯ��"<<endl ;
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
			if(y=='&') y='#';//���ʱ�������� 
			cout<<y<<" ";}
		}
		cout<<endl;
	}	 }
	if(h!=0) pro();}
}

void a(){ 
//	part:cout<<"�����漸�м��е�ɨ��";
//	cin>>hang>>lie;
	cout<<"Сͬ־��8x8��ɨ���������񼸸��ף�"<<endl;
	 part:cin>>x;
	 if(x>64||x==0) {
	 cout<<"��tm�������˸�ʲô���⣿�׷ŵ����𣿸���������ɵ��"<<endl;
	 goto part;}
	
	c(arr,hang,lie,x);   //��������������׵� 
	pro();//��һ�����
	while(h){
	
	cout<<"��ѡ����Ҫ�����λ��"; 
	pin();//���� �����ж���Ӯ 
	
}
}


int main(){
	int n;
	b();
	//��Ϸ��ʼ
	cout<<"----ɨ����Ϸ----"<<endl;
	cout<<"-----0.����-----"<<endl;
	cout<<"-----1.��ʼ-----"<<endl;
	cout<<"----------------"<<endl;
	cout<<"�Ͻ�������ѡ��";
	do{
	cin>>n;
	
	if(n==1){
		cout<<"��Ϸ��ʼ"<<endl<<"*Ϊ�հ׸��ӣ�#Ϊ�׵�"<<endl;
		a();//��Ϸ���� 
		break;
	}
	else if(n==0){
		cout<<"������͹�"<<endl;
	}
	else cout<<"ɵ�ưɣ�����������?��������"<<endl;

}	while(n);
    cout<<"��Ϸ����";

	return 0; 
}
