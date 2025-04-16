#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
vector<int> vret;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end()); // 값을 받아서 벡터에 저장
	for(int i = 0; i < v.size(); i++){
		for(int j = i; j < v.size(); j++){
			int ret = v[i] + v[j];
			vret.push_back(ret);	
		}
	}
	sort(vret.begin(),vret.end()); // 벡터의 항목들을 2개씩 더한 값들을 저장하는 ㅍret을 정의 및 정렬
	for(int i = n-1; i > 0; i--){
		for(int j = 0; j < i; j++){
			if(binary_search(vret.begin(), vret.end(), v[i]-v[j])){ // (v의 요소) - (v의 요소) 가 vret에 있다면 v요소값을 출력 후, 종료.
				cout << v[i];
				return 0; // v의 뒷부분부터 시작하였기 때문에 제일 먼저 나오는 값이 가장 큰 수이다.
			}
		}
	}
}