#include <string>
#include <stack>
#include <algorithm>
using namespace std;



int longestValidParentheses(string s) {
	int imax = 0,last = -1;//学会使用-1
	stack<int> stk;
	for(int index = 0; index < s.length(); index++){
		if(s.at(index) == '('){
			stk.push(index);
		}else{
			if(stk.empty()){
				last = index;			
			}else{	 
				stk.pop();
				if(stk.empty()){
					imax = (imax > index - last)?imax : index-last;
				}else{
					imax = (imax > index - stk.top())?imax :index - stk.top() ;
				}
				
				
			}
		}
	} 
	return imax;
}

int main(){
	string str1 = "())";//2
	string str2 = "()(()";//2
	string str3 = "(()))())(";
	int lenth = longestValidParentheses(str3);
	return lenth;
}