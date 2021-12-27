#include<bits/stdc++.h>
using namespace std;
template <typename T> void inputArray(T& arr, int n);
template <typename T> void inputArray(T& arr, int n, int m);
template <typename T> void inputVector(vector<T>& vet, int type=0);
template <typename T> void inputVector(vector<vector<T>>& vet, int type=0, int n=-1);
template <typename T> void outputArray(T& arr, int n);
template <typename T> void outputVector(vector<T>& vet);
template <typename T> void outputVector(vector<vector<T>>& vet);

int main(){

	return 0;
} 

template <typename T>
void inputArray(T& arr, int n){
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	return;
}

template <typename T>
void inputArray(T& arr, int n, int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	return;
}

template <typename T>
void inputVector(vector<T>& vet, int type){
	T val;
	bool isInt=false;
	bool preValIsNum=false;//用于检测是否有多位数字 
	if(sizeof(T)==sizeof(int)) isInt=true;
	switch(type){
		case 0://以末尾EOF作为结束输入条件 
			while(cin>>val){
				vet.push_back(val);
			}
		break;
		case 1://借助cin.get()输入，以末尾换行符作为结束输入条件 
			char ch;
			while((ch=cin.get())!='\n'){
				if(ch==' '){
					preValIsNum=false;
					continue;
				}
				if(!isInt) vet.push_back(ch);
				else{
					if(!preValIsNum) vet.push_back(ch-'0');
					else{
						vet.back()=vet.back()*10+ch-'0';
					}
					preValIsNum=true;
				}

			}
		break;
		case 2://借助getline()输入一整行 
			string line;
			getline(cin,line);
			for(string::iterator iter=line.begin();iter!=line.end();iter++){
				if(*iter==' '){
					preValIsNum=false;
					continue;
				}
				if(!isInt) vet.push_back(*iter);
				else{
					if(!preValIsNum) vet.push_back(*iter-'0');
					else{
						vet.back()=vet.back()*10+*iter-'0';
					}
					preValIsNum=true;			
				}
			}
		break;
	}

}

template <typename T>
void inputVector(vector<vector<T>>& vet, int type, int n){//n行 
	T val;
	vector<T> innerVet;
	bool isInt=false;
	bool preValIsNum=false;//用于检测是否有多位数字 
	if(sizeof(T)==sizeof(int)) isInt=true;
	switch(type){
		case 0:
		case 1://借助cin.get()输入，以末尾换行符作为结束输入条件 
			char ch;
			while(n--){
				preValIsNum=false;
				innerVet.clear();
				while((ch=cin.get())!='\n'){
					if(ch==EOF) goto inputVectorEnd;
					if(ch==' '){
						preValIsNum=false;
						continue;
					}
					if(!isInt) innerVet.push_back(ch);
					else{
						if(!preValIsNum) innerVet.push_back(ch-'0');
						else{
							innerVet.back()=innerVet.back()*10+ch-'0';
						}
						preValIsNum=true;
					}
				}
				vet.push_back(innerVet);
			}
		break;
		case 2://借助getline()输入一整行 
			string line;
			while(n--){
				preValIsNum=false;
				innerVet.clear();
				getline(cin,line);
				if(line.empty()) goto inputVectorEnd;
				for(string::iterator iter=line.begin();iter!=line.end();iter++){
					if(*iter==' '){
						preValIsNum=false;
						continue;
					}
					if(!isInt) innerVet.push_back(*iter);
					else{
						if(!preValIsNum) innerVet.push_back(*iter-'0');
						else{
							innerVet.back()=innerVet.back()*10+*iter-'0';
						}
						preValIsNum=true;			
					}
				}
				vet.push_back(innerVet);		
			}
		break;
	}
	inputVectorEnd:return;
}

template <typename T>
void outputArray(T& arr, int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" "; 
	}
	cout<<endl;
	return;
}

template <typename T>
void outputArray(T& arr, int m, int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" "; 
		}
		cout<<endl;
	}
	return;
}

template <typename T>
void outputVector(vector<T>& vet){
	for(typename vector<T>::iterator iter=vet.begin();iter!=vet.end();iter++){
		cout<<*iter<<" ";
	}
	cout<<endl;
	return;
}

template <typename T>
void outputVector(vector<vector<T>>& vet){
	for(typename vector<vector<T>>::iterator iter1=vet.begin();iter1!=vet.end();iter1++){
		for(typename vector<T>::iterator iter2=iter1->begin();iter2!=iter1->end();iter2++){
			cout<<*iter2<<" ";
		}
		cout<<endl;
	}
	return;
}
